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
import time

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
ON_DEMAND_MAX = 256  # PR-claimed functions published per run; at least one PR's cap of new functions
# Kinds a PR may claim on demand. Static initializers are matched on main already and generated reflection
# initializers are claimed by whole units, so they cannot depend on the ordinary-only window.
ON_DEMAND_KINDS = claimable.ON_DEMAND_KINDS
PLAN_IDLE_HOURS = 12  # a plan directory untouched this long is treated as abandoned and stops reserving
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
    """Lower is offered earlier: classes with a real layout unit, then classes that only have a generated PDB
    layout, then functions with no layout to extend (`pdb_only` is 0/False, 1/True or 2); within each, ordinary
    shapes by size tier, named before unnamed, more matched siblings first; very large and known-hard
    functions last."""
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


def plan_idle_hours(directory, now):
    """Hours since the newest file under `directory` was written; infinite when it holds none."""
    newest = None
    for path in Path(directory).rglob('*'):
        if '__pycache__' in path.parts:
            continue
        try:
            if path.is_file():
                newest = max(newest or 0, path.stat().st_mtime)
        except OSError:
            continue
    return float('inf') if newest is None else (now - newest) / 3600


def reserved_rvas(directories, max_idle_hours=None, now=None):
    """RVAs that internal workers are stamping or twin-propagating, from their private plan files.

    Each `*.json` directly in a directory is read: a list of RVAs, a list of nested lists holding them
    (cluster plans, `[rva, name]` pairs), or a dict keyed by RVA. Unreadable files are skipped. The result
    only filters what is offered; it is never published.

    With `max_idle_hours`, a directory whose files have all been idle that long is skipped: a plan nobody is
    writing to would otherwise hold its functions out of the offered window indefinitely, and the window
    runs dry while they sit unclaimed.
    """
    out = set()
    now = time.time() if now is None else now
    for directory in directories:
        if max_idle_hours is not None and plan_idle_hours(directory, now) > max_idle_hours:
            continue
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


def select_window(root, metadata, known, limit=None, reserved=(), siblings=None, keep=(), rva_range=None):
    """{rva: class or None}: new ordinary functions to offer, best first; the class is named only when it has a layout.

    Every ordinary function with a supported or caution verdict qualifies, whatever its class: a claim without a
    layout still gets its entry when it is recorded, and the contributor gives `--class`. The class is kept on
    the row only when it has a layout to extend, a real unit or a generated CrashLogger PDB header
    (tools/unit_paths.py places a unit of it); that is the layout reason the row exists and ranks it first.
    Locally unsupported functions and `reserved` ones (an internal worker's plan) never qualify, nor do those
    already offered (`keep`).

    A chunk is an address range: `rva_range` is `(low, high)` and takes every qualifying function in
    `low <= rva < high`; `limit` takes the lowest-addressed `limit` qualifying ones. Neither depends on the
    ranking, so a chunk is a stretch of the image and the next one starts where the last ended. Ordering within
    the result is rank_key.
    """
    layouts, ranked, siblings = {}, [], siblings or {}  # layouts: class -> 0 real unit, 1 PDB layout only, 2 none
    units = contrib.unit_index(root)  # one directory walk for every class
    pdb = pdb_layout_classes(root)
    skip = set(known) | set(keep) | set(reserved)
    low, high = rva_range if rva_range else (0, None)
    for rva, fn in sorted(metadata.items()):
        owner = fn.get('owner') or {}
        cls = owner.get('class') if isinstance(owner, dict) else None
        verdict = (fn.get('v2') or {}).get('verdict')
        if (rva in skip or fn.get('kind') != 'ordinary' or not fn.get('size') or rva < low
                or (high is not None and rva >= high) or verdict not in VERDICT_RANK):
            continue
        if cls is not None and not contrib.PLAIN_NAME.fullmatch(f'{cls}::Function'):
            cls = None
        if cls not in layouts:
            layouts[cls] = 2
            if cls in units:
                _area, header, cpp = contrib.unit_files(root, cls, index=units)
                if header and cpp and (Path(root) / header).is_file() and (Path(root) / cpp).is_file():
                    layouts[cls] = 0
            if layouts[cls] == 2 and cls in pdb and contrib.area_for(cls, root):
                layouts[cls] = 1
        ranked.append((rva, cls if layouts[cls] < 2 else None, layouts[cls], fn))
        if limit is not None and len(ranked) >= limit:
            break
    ranked.sort(key=lambda r: (rank_key(r[3], siblings, r[1], r[2]), r[0]))
    return {rva: cls for rva, cls, _tier, _fn in ranked}


def plan_window(root, metadata, progress, known, wanted, reserved, low_water, slice_size, rva_range=None):
    """(offered {rva: class or None}, newly added {rva: class or None}, claimable left before the refill).

    Offered rows stay offered until recorded, so a claimed function never leaves the list; only an unclaimed
    one an internal worker has since reserved is withdrawn. A chunk is added when fewer than `low_water`
    functions are left to claim (the next `slice_size` by address) or, whatever is left, when `rva_range`
    names one.
    """
    withdrawn = set(reserved) - set(wanted)
    classes = {rva: cls for rva, cls in claimable.offered_window(root).items()
               if rva in metadata and rva not in known and rva not in withdrawn}
    left = sum(1 for c in contrib.candidates(root, progress, published=True) if c['startable'])
    added = {}
    if rva_range or left < low_water:
        added = select_window(root, metadata, known, None if rva_range else slice_size, reserved,
                              matched_siblings(progress), classes, rva_range)
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
        elif fn.get('kind') not in ON_DEMAND_KINDS or not fn.get('size'):
            refused[rva] = 'not-an-ordinary-function'
        elif (fn.get('v2') or {}).get('verdict') not in VERDICT_RANK:
            refused[rva] = 'locally-unsupported'
        else:
            accepted.add(rva)
    # The cap bounds what one run newly publishes. A retained row belongs to a claim already published, and
    # cutting it by RVA order would drop the rows of a PR that is still being checked or has merged unrecorded.
    # Retained rows are not new, so they must not use up the cap: a claim larger than the cap would otherwise
    # re-select the same lowest RVAs on every run and never publish the rest.
    fresh = sorted(accepted - set(retained))[:ON_DEMAND_MAX]
    kept = set()
    for rva in retained:
        fn = metadata.get(rva)
        if rva not in known and fn and fn.get('kind') in ON_DEMAND_KINDS and fn.get('size') \
                and (fn.get('v2') or {}).get('verdict') in VERDICT_RANK:
            kept.add(rva)
    return sorted(set(fresh) | kept), refused


def retained_on_demand(root):
    """RVAs of earlier on-demand rows in the published offered list, kept until they are recorded."""
    try:
        rows = claimable.sharded_json(root, hashes.OFFERED, 'functions')['functions']
    except (OSError, ValueError, KeyError):
        return set()
    return {row['rva'] for row in rows if row.get('on_demand')}


def collect(root, image_bytes, function_table, claims, low_water=LOW_WATER, slice_size=SLICE, reserved=(), extra=(),
            rva_range=None):
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
    classes,added,left=plan_window(root,metadata,progress,known,wanted,reserved,low_water,slice_size,rva_range)
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
        rows.append(dict(rva=rva,size=size,extent_source=source,**({'class':classes[rva]} if classes.get(rva) else {}),
                         **({'window':True} if rva in classes else {}),
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
    p.add_argument('--slice',type=int,default=SLICE,dest='slice_size',help='unmapped functions added per refill: the lowest-addressed ones')
    p.add_argument('--reserved-dir',type=Path,action='append',default=[],
                   help='directory of private plan files whose functions are not offered (repeatable)')
    p.add_argument('--plan-idle-hours',type=float,default=PLAN_IDLE_HOURS,
                   help='a --reserved-dir with no file written for this many hours stops reserving; 0 keeps every plan')
    p.add_argument('--range',dest='rva_range',type=lambda v:tuple(int(x,0) for x in v.split('-')),
                   help='LOW-HIGH: offer every qualifying function with LOW <= RVA < HIGH, ignoring the low-water mark')
    p.add_argument('--extra-rva',action='append',default=[],type=lambda v:int(v,0),
                   help='RVA an open PR claims that has no row yet; published when it is a real function start (repeatable)')
    a=p.parse_args(argv)
    ctx=contrib.Ctx(repo=ROOT,interactive=False)
    index=ctx.github().open_items(refresh=True)
    reserved=reserved_rvas(a.reserved_dir,a.plan_idle_hours or None)
    output,window=collect(ROOT,a.image.read_bytes(),a.function_table,index.records,a.low_water,a.slice_size,reserved,a.extra_rva,a.rva_range)
    claimable.write_sharded(ROOT,hashes.OFFERED,output,'functions',claimable.OFFERED_ROWS)
    import target_facts  # the sidecar must follow the list it describes
    target_facts.write(ROOT,target_facts.build(ROOT))
    print(json.dumps(dict(extra_targets=len(output['functions']),next_candidates=output['next_candidate_count'],
                          claims=len(output['claims']),window=window,acceptance='not-evaluated')))
    return 0


if __name__=='__main__':sys.exit(main())
