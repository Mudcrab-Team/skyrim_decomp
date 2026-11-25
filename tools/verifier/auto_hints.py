"""Derive `bind-hints.json` entries from the instruction alignment of an attempt (local only).

`tools/verifier/attempt` calls this after binding when references stay unbound, so a near-miss
whose hints were lost (a new checkout, a regenerated task) is bound again without a person reading
the pack table.

The evidence is the alignment `align.py` already computes: a candidate instruction that holds a
relocation to a symbol the map does not resolve, paired with a target instruction of the same
mnemonic that encodes a reference, is one vote for the RVA the target holds there (less the addend
the candidate stores). A symbol gets a hint when

1. the votes agree: one value, or one value with more votes than all others together;
2. the value is something the project already knows about the function: a reference of its pack, a
   destructor call of its object lifetimes, or a function start of the private function table;
3. no hint of that name exists yet (a person's hint is never replaced).

The same votes catch a binding that is wrong: bind binds by position when the target's own field at the
same offset is one of the pack's references, and a candidate whose code is shifted can take another
listed reference that way. With `correct=True` (attempt --hints-by-alignment), when the aligned
instructions agree on one other listed target for a name the map already resolves, that name gets a hint
too, and bind replaces the position-bound entry with it. It is a flag because it also overrides a
drafter's mistake (the wrong global used where the target uses another) instead of showing it as a
difference; it is meant for near-miss studies whose hints were lost. Only a private symbol map is
changed, and a name bound from its value (a literal, a constant) is left alone.

A thread-local variable gets `tls:0x<offset>` when the offsets agree the same way and the offset
lies inside the image's TLS template.

Nothing here decides a match. A wrong hint makes the comparator report a relocation difference and
the next attempt starts from the same alignment; the hints file stays private under the task
directory. The file records which names were derived (`_derived` note) so a later reader can tell
them from hints a person wrote.
"""
import json
from pathlib import Path
import sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import align  # noqa: E402
import bind  # noqa: E402

DERIVED_NOTE = '_derived'


def read_pairs(fdir):
    """The `reference_pairs` of a function's align.json, or None when the file or the field is missing."""
    try:
        data = json.loads((Path(fdir) / 'align.json').read_text())
    except (OSError, ValueError):
        return None
    pairs = data.get('reference_pairs') if isinstance(data, dict) else None
    return pairs if isinstance(pairs, dict) else None


def collect(task, dest, config, symbols_path=None):
    """(votes, notes): {symbol: {RVA: pairs}} and {symbol: {TLS offset: pairs}} over the compared functions.

    A function whose attempt directory carries no pairs (a host that did not align, or an older
    run) is aligned here, which writes the files next to its report.
    """
    refs, tls, notes = {}, {}, []
    objdump = config.get('objdump')
    image = config.get('image')
    for fn in task['functions']:
        # task.json holds "0x..." strings; align takes numbers, as pipeline.load_task gives them.
        fn = dict(fn, rva=bind.parse_rva(fn['rva']), size=bind.parse_rva(fn['size']))
        fdir = Path(dest) / f'0x{fn["rva"]:x}'
        pairs = read_pairs(fdir)
        if pairs is None:
            if not fdir.is_dir() or not (Path(dest) / 'candidate.obj').is_file():
                continue
            lines = align.attempt_summary(fdir, align.disasm.find_objdump(objdump), image, Path(dest) / 'candidate.obj',
                                          fn, symbols_path)
            pairs = read_pairs(fdir)
            if pairs is None:
                notes.append(f'0x{fn["rva"]:x}: no alignment to read pairs from ({lines[0][:80] if lines else "no output"})')
                continue
        for table, key in ((refs, 'references'), (tls, 'thread_locals')):
            for name, votes in (pairs.get(key) or {}).items():
                into = table.setdefault(name, {})
                for value, count in votes.items():
                    into[int(value, 16)] = into.get(int(value, 16), 0) + int(count)
    return refs, tls, notes


def known_targets(repo, task):
    """RVAs the pack lists for these functions: its references and its object-lifetime destructor calls."""
    known = set()
    for fn in task['functions']:
        known |= {rva for rva, _ in bind.pack_references(repo, fn)}
        calls, _places = bind.lifetime_calls(repo, fn)
        known |= {rva for entries in calls.values() for rva, _ in entries}
    return known


def choose(votes, allowed=None):
    """(value, reason): the value that wins the votes, or None and why not.

    `allowed` is a predicate; votes for other values are dropped before counting. A winner needs more
    votes than all the others together, so two equally supported readings give nothing.
    """
    kept = {v: n for v, n in votes.items() if allowed is None or allowed(v)}
    if not kept:
        return None, 'no vote names a target the pack or the function table lists' if votes else 'no aligned instruction'
    best, count = max(kept.items(), key=lambda item: (item[1], -item[0]))
    if count <= sum(kept.values()) - count:
        return None, 'the aligned instructions disagree'
    return best, None


def value_named(name):
    """True for a name that spells its own value (a pool constant, a string literal): bind checks those against the image."""
    return bind.pool_constant_bytes(name) is not None or bind.string_literal_bytes(name) is not None


def tls_extent(image):
    """Size of the image's TLS template, or None."""
    try:
        start, end, _ = image.tls_template()
        return end - start
    except Exception:  # noqa: BLE001 - without a template the offset is simply not checked against its size
        return None


def derive(task_dir, dest, report, config=None, repo=bind.REPO, correct=False):
    """Write hints for the unbound references in `report` that the alignment names; (added, skipped, notes).

    `added` maps symbol -> hint value as written ("0x<rva>" or "tls:0x<offset>"), `skipped` maps
    symbol -> why not. `dest` is the attempt directory (candidate.obj and the function directories).
    """
    task_dir = Path(task_dir)
    config = config or {}
    task = json.loads((task_dir / 'task.json').read_text())
    wanted = list(report.get('unbound_references') or [])
    wanted_tls = list(report.get('unbound_thread_locals') or [])
    if not wanted and not wanted_tls and not correct:
        return {}, {}, []
    unbound = set(wanted)
    mapped = {}
    public = str(task.get('symbols', '')).startswith('reports/')
    symbols_path = (Path(repo) / task['symbols']) if public else task_dir / task.get('symbols', 'symbols.json')
    refs, tls, notes = collect(task, dest, config, symbols_path)
    if correct and not public:
        # Names the map resolves that the alignment contradicts (see the module doc); decided below.
        mapped = align.load_symbols(symbols_path)
        already = set(bind.load_hints(task_dir)) | set(wanted)
        wanted += sorted(n for n in refs if n in mapped and n not in already and not value_named(n))
    if not wanted and not wanted_tls:
        return {}, {}, notes
    starts = bind.function_starts(repo)
    known = known_targets(repo, task)

    def listed(value):
        return value in known or (starts is not None and value in starts)

    added, skipped = {}, {}
    for name in wanted:
        value, why = choose(refs.get(name, {}), listed)
        if value is None:
            if name in unbound:
                skipped[name] = why or 'no aligned instruction'
        elif name in unbound or value != mapped.get(name):
            added[name] = f'0x{value:x}'
    extent = None
    if wanted_tls:
        image_path = config.get('image')
        if image_path and Path(image_path).is_file():
            try:
                extent = tls_extent(bind.PeImage(Path(image_path).read_bytes()))
            except (OSError, bind.Reject):
                extent = None
    for name in wanted_tls:
        value, why = choose(tls.get(name, {}), lambda v: extent is None or v < extent)
        if value is None:
            skipped[name] = why or 'no aligned instruction'
        else:
            added[name] = f'tls:0x{value:x}'
    if added:
        write(task_dir, added)
    return added, skipped, notes


def write(task_dir, added):
    """Merge `added` into bind-hints.json without touching an entry that is already there."""
    path = Path(task_dir) / bind.HINTS
    raw = json.loads(path.read_text()) if path.is_file() else {}
    if not isinstance(raw, dict):
        raise ValueError(f'{path}: must be a JSON object of name -> RVA')
    fresh = {k: v for k, v in added.items() if k not in raw}
    if fresh:
        before = {n for n in str(raw.get(DERIVED_NOTE) or '').split(', ') if n}
        raw.update(fresh)
        raw[DERIVED_NOTE] = ', '.join(sorted(before | set(fresh)))
        path.write_text(json.dumps(raw, indent=1) + '\n')
    return fresh


def describe(added, skipped, notes=()):
    """Lines for the attempt output."""
    lines = []
    if added:
        shown = ', '.join(f'{align.display_name(n)[:50]} -> {v}' for n, v in list(added.items())[:6])
        lines.append(f'  derived {len(added)} bind hint(s) from the instruction alignment (written to bind-hints.json): '
                     + shown + (f' ... {len(added) - 6} more' if len(added) > 6 else ''))
    if skipped:
        by_reason = {}
        for name, why in skipped.items():
            by_reason.setdefault(why, []).append(name)
        for why, names in sorted(by_reason.items()):
            lines.append(f'  no hint derived for {len(names)} reference(s) ({why}): '
                         + ', '.join(align.display_name(n)[:50] for n in names[:4]) + (' ...' if len(names) > 4 else ''))
    lines += [f'  auto hints: {n}' for n in notes]
    return lines


def merge_reports(first, second):
    """One report for a bind followed by a second bind that read the derived hints."""
    out = dict(second)
    for key in ('functions', 'references', 'renamed', 'destructor_choices', 'warnings'):
        out[key] = list(first.get(key) or []) + list(second.get(key) or [])
    out['changed'] = bool(first.get('changed') or second.get('changed'))
    return out
