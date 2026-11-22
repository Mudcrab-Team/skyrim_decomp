#!/usr/bin/env python3
"""Refresh public contributor-target boundaries locally; never publishes function bytes/names.

Only claim URLs/scopes and boundary metadata leave this command. The image stays local and is
hash checked. Private function-table input is resolved only for the pinned build's open claims, and
for the RVAs an open pull request's headers claim (`--extra-rva`, see select_on_demand).
"""
import argparse
import datetime as dt
import json
from pathlib import Path
import sys

import claimable
import contrib
from pecoff import PeImage
import target_hashes as hashes

ROOT=Path(__file__).resolve().parents[1]


LOW_WATER = 2000  # claimable functions left below which the next slice is published
SLICE = 2000  # unmapped functions added per refill
VERDICT_RANK = {'supported': 0, 'caution': 1}
SIZE_TIERS = (64, 256, 1024)  # small, small-medium, medium; above is large
UNNAMED_HOW = {'placeholder'}
RESERVED_DIRS = ('.local/twins', '.local/stamp-sweep')  # private plans of internal workers, relative to the bot root
ON_DEMAND_MAX = 128  # PR-claimed functions published per run; a PR is capped at far fewer
MIN_RVA = 0x1000  # nothing below the first section holds a function; keeps sizes in plan files from reading as RVAs
PDB_DIR = 'reconstruction/generated/crashlogger_pdb'  # generated layout headers, label CRASHLOGGER_PDB(59818@version)


def size_tier(size):
    return next((tier for tier, limit in enumerate(SIZE_TIERS) if size < limit), len(SIZE_TIERS))


def is_hard(fn):
    """A shape contributors rarely get to match: unresolved EH, jump tables, split bodies, unrecovered jumps."""
    v2 = fn.get('v2') or {}
    return bool(v2.get('reasons')) or any('indirect jump' in str(c) for c in v2.get('cautions') or ())


def is_named(fn):
    """The table holds a name from a source better than the RVA placeholder (community, RTTI, address library)."""
    owner = fn.get('owner')
    how = owner.get('how') if isinstance(owner, dict) else None
    return any(n.get('how') not in UNNAMED_HOW for n in fn.get('names') or ()) or how in {'rtti-adjacent', 'community-id'}


def pdb_layout_classes(root):
    """Classes that have a generated CrashLogger layout header: the fullest PDB type of a plain class name, a
    struct or class (not an enum or union) with a size and its header on disk. These are community
    reconstructions, so they stand in for a layout unit only when a function is offered, never as evidence."""
    base = Path(root) / PDB_DIR
    try:
        lines = (base / 'types.tsv').read_text().splitlines()
    except OSError:
        return set()
    out = set()
    for line in lines:
        parts = line.split('\t')
        if line.startswith('#') or len(parts) < 5:
            continue
        name, ident, kind, size, variant = parts[:5]
        if (name == ident and variant == '-' and kind in ('struct', 'class') and size.isdigit() and int(size) > 0
                and contrib.PLAIN_NAME.fullmatch(f'{name}::Function') and (base / 'types' / f'{ident}.h').is_file()):
            out.add(name)
    return out


def rank_key(fn, siblings, cls, pdb_only=False):
    """Lower is offered earlier: classes with a real layout unit before classes that only have a generated PDB
    layout; within each, ordinary shapes by size tier, named before unnamed, more matched siblings first; very
    large and known-hard functions last."""
    tier = size_tier(fn['size'])
    last = is_hard(fn) or tier == len(SIZE_TIERS)
    return (pdb_only, last, tier, not is_named(fn), -siblings.get(cls, 0), VERDICT_RANK[fn['v2']['verdict']], fn['size'],
            fn['rva'])


def matched_siblings(progress):
    """{class: matched functions} from the inventory; the class is the part of the name before the last `::`."""
    out = {}
    for fn in progress['functions']:
        name = fn.get('name') or ''
        if fn['status'] == 'matched' and '::' in name:
            cls = name.rsplit('::', 1)[0]
            out[cls] = out.get(cls, 0) + 1
    return out


def _rvas(node, out):
    if isinstance(node, bool):
        return
    if isinstance(node, int):
        if node >= MIN_RVA:
            out.add(node)
    elif isinstance(node, list):
        for item in node:
            _rvas(item, out)
    elif isinstance(node, dict):
        for key, value in node.items():
            if key in ('rvas', 'members', 'exemplars'):
                _rvas(value, out)
            elif str(key).isdigit():
                _rvas(int(key), out)


def reserved_rvas(directories):
    """RVAs that internal workers are stamping or twin-propagating, from their private plan files.

    Each `*.json` directly in a directory is read: a list of RVAs, a list of nested lists holding them
    (cluster plans, `[rva, name]` pairs), or a dict keyed by RVA. Unreadable files are skipped. The result
    only filters what is offered; it is never published.
    """
    out = set()
    for directory in directories:
        for path in sorted(Path(directory).glob('*.json')):
            try:
                node = json.loads(path.read_text())
            except (OSError, ValueError):
                continue
            if isinstance(node, list) and node and all(isinstance(i, list) for i in node):
                for item in node:
                    # `[size, id, [exemplars], [members]]` cluster rows carry a size first; keep only list members.
                    _rvas([i for i in item if isinstance(i, list)] if len(item) > 2 else item, out)
            else:
                _rvas(node, out)
    return out


def select_window(root, metadata, known, limit=SLICE, reserved=(), siblings=None, keep=()):
    """{rva: class}: up to `limit` new unmapped ordinary functions to offer for claim-time mapping, best first.

    Only classes that already have a layout unit qualify, so a claim extends reviewed work. A class with a
    generated CrashLogger layout header counts as having one, provided a unit of it can be placed
    (tools/unit_paths.py); those rank after classes with a real unit. Locally unsupported functions and
    `reserved` ones (an internal worker's plan) never qualify, nor do those already offered (`keep`).
    Ordering is rank_key: real-unit classes first; then small and medium first, known names and classes
    with matched siblings ahead of the rest, very large and known-hard functions last. The published hash list grows by
    `limit` per refill, not by the size of the function table.
    """
    layouts, ranked, siblings = {}, [], siblings or {}  # layouts: class -> pdb_only, or None when not eligible
    units = contrib.unit_index(root)  # one directory walk for every class
    pdb = pdb_layout_classes(root)
    skip = set(known) | set(keep) | set(reserved)
    for rva, fn in metadata.items():
        owner = fn.get('owner') or {}
        cls = owner.get('class') if isinstance(owner, dict) else None
        verdict = (fn.get('v2') or {}).get('verdict')
        if (rva in skip or fn.get('kind') != 'ordinary' or not fn.get('size') or not cls
                or verdict not in VERDICT_RANK or not contrib.PLAIN_NAME.fullmatch(f'{cls}::Function')):
            continue
        if cls not in layouts:
            layouts[cls] = None  # not eligible
            if cls in units:
                _area, header, cpp = contrib.unit_files(root, cls, index=units)
                if header and cpp and (Path(root) / header).is_file() and (Path(root) / cpp).is_file():
                    layouts[cls] = False  # real unit
            if layouts[cls] is None and cls in pdb and contrib.area_for(cls, root):
                layouts[cls] = True  # generated PDB layout only
        if layouts[cls] is not None:
            ranked.append((rank_key(fn, siblings, cls, layouts[cls]), rva, cls))
    return {rva: cls for _key, rva, cls in sorted(ranked)[:limit]}


def plan_window(root, metadata, progress, known, wanted, reserved, low_water, slice_size):
    """(offered {rva: class}, newly added {rva: class}, claimable left before the refill).

    Offered rows stay offered until recorded, so a claimed function never leaves the list; only an unclaimed
    one an internal worker has since reserved is withdrawn. A slice is added only when fewer than
    `low_water` functions are left to claim.
    """
    withdrawn = set(reserved) - set(wanted)
    classes = {rva: cls for rva, cls in claimable.offered_classes(root).items()
               if rva in metadata and rva not in known and rva not in withdrawn}
    left = sum(1 for c in contrib.candidates(root, progress, published=True) if c['startable'])
    added = {}
    if left < low_water:
        added = select_window(root, metadata, known, slice_size, reserved, matched_siblings(progress), classes)
        classes.update(added)
    return classes, added, left


def select_on_demand(metadata, known, extra, retained=()):
    """(accepted [rva], refused {rva: reason}) for RVAs an open PR claims that have no published row.

    The window's rules, minus its class filter (the PR brings its own unit): the RVA must be a function
    start of the private table, an ordinary function with a size that the local analysis supports, and not
    recorded yet. `retained` are earlier on-demand rows still wanted; one that has since been recorded or no
    longer qualifies is dropped without a refusal. Only these RVAs, sizes and hashes are ever published.
    """
    accepted, refused = set(), {}
    for rva in sorted(set(extra)):
        fn = metadata.get(rva)
        if rva in known:
            refused[rva] = 'already-recorded'
        elif not fn or rva < MIN_RVA:
            refused[rva] = 'not-a-function-start'
        elif fn.get('kind') != 'ordinary' or not fn.get('size'):
            refused[rva] = 'not-an-ordinary-function'
        elif (fn.get('v2') or {}).get('verdict') not in VERDICT_RANK:
            refused[rva] = 'locally-unsupported'
        else:
            accepted.add(rva)
    for rva in retained:
        fn = metadata.get(rva)
        if rva not in known and fn and fn.get('kind') == 'ordinary' and fn.get('size') \
                and (fn.get('v2') or {}).get('verdict') in VERDICT_RANK:
            accepted.add(rva)
    return sorted(accepted)[:ON_DEMAND_MAX], refused


def retained_on_demand(root):
    """RVAs of earlier on-demand rows in the published offered list, kept until they are recorded."""
    try:
        rows = json.loads((Path(root) / hashes.OFFERED).read_text())['functions']
    except (OSError, ValueError, KeyError):
        return set()
    return {row['rva'] for row in rows if row.get('on_demand')}


def collect(root, image_bytes, function_table, claims, low_water=LOW_WATER, slice_size=SLICE, reserved=(), extra=()):
    target=contrib.target_manifest(root)
    if hashes.digest(image_bytes)!=target['image_sha256']:
        raise ValueError('image differs from pinned build')
    progress=contrib.inventory(root)
    known={f['rva']:f for f in progress['functions']}
    metadata={f['rva']:f for f in map(json.loads,function_table.read_text().splitlines())}
    image=PeImage(image_bytes);pdata={a:b-a for a,b,_ in image.runtime_functions()}
    selected=[c for c in claims if not c.get('pull_request') and c.get('build_id')==target['build_id']]
    wanted=set()
    for claim in selected:
        for a,b in claim.get('entries',[]):
            wanted.update([a] if b==a+1 else [r for r in metadata if a<=r<b])
    next_={contrib.parse_rva(c['rva']) for c in contrib.candidates(root,progress) if c['startable']}
    classes,added,left=plan_window(root,metadata,progress,known,wanted,reserved,low_water,slice_size)
    next_|=set(classes)
    claimed=len(wanted)
    on_demand,refused=select_on_demand(metadata,known,extra,retained_on_demand(root))
    on_demand=set(on_demand)-wanted-set(classes)
    wanted|=on_demand
    rows=[];unresolved=[]
    for rva in sorted((wanted|next_)-known.keys()):
        fn=metadata.get(rva)
        if fn and fn.get('size',0)>0:size,source=fn['size'],'local-function-table'
        elif rva in pdata:size,source=pdata[rva],'single-pdata-entry'
        else:unresolved.append(rva);continue
        image.read(rva,size,'offered target boundary')
        rows.append(dict(rva=rva,size=size,extent_source=source,**({'class':classes[rva]} if rva in classes else {}),
                         **({'on_demand':True} if rva in on_demand else {})))
    if unresolved:
        raise ValueError('claim boundaries unresolved; nothing published')
    return dict(schema=1,build_id=target['build_id'],snapshot_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        function_metadata_sha256=hashes.digest(function_table.read_bytes()),
        claims_snapshot_sha256=hashes.digest(json.dumps(claims,sort_keys=True).encode()),
        claims=[dict(number=c['number'],url=c['url'],entries=c['entries']) for c in selected],
        next_candidate_count=len(next_),claim_function_count=claimed,functions=rows,unresolved_rvas=[]),dict(
        left_before=left,added=len(added),low_water=low_water,slice=slice_size,reserved=len(reserved),
        on_demand=sorted(on_demand),refused={hex(r):why for r,why in refused.items()})


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--image',type=Path,required=True)
    p.add_argument('--function-table',type=Path,required=True)
    p.add_argument('--low-water',type=int,default=LOW_WATER,help='claimable functions left below which a slice is added')
    p.add_argument('--slice',type=int,default=SLICE,dest='slice_size',help='unmapped functions added per refill')
    p.add_argument('--reserved-dir',type=Path,action='append',default=[],
                   help='directory of private plan files whose functions are not offered (repeatable)')
    p.add_argument('--extra-rva',action='append',default=[],type=lambda v:int(v,0),
                   help='RVA an open PR claims that has no row yet; published when it is a real function start (repeatable)')
    a=p.parse_args(argv)
    ctx=contrib.Ctx(repo=ROOT,interactive=False)
    index=ctx.github().open_items(refresh=True)
    reserved=reserved_rvas(a.reserved_dir)
    output,window=collect(ROOT,a.image.read_bytes(),a.function_table,index.records,a.low_water,a.slice_size,reserved,a.extra_rva)
    (ROOT/hashes.OFFERED).write_text(json.dumps(output,indent=2)+'\n')
    import target_facts  # the sidecar must follow the list it describes
    (ROOT/target_facts.OUT).write_text(target_facts.render(target_facts.build(ROOT)))
    print(json.dumps(dict(extra_targets=len(output['functions']),next_candidates=output['next_candidate_count'],
                          claims=len(output['claims']),window=window,acceptance='not-evaluated')))
    return 0


if __name__=='__main__':sys.exit(main())
