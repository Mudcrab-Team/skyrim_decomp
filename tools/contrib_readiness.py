"""Advisory draft ordering from public declarations and optional contributor-local table facts.

This predicts preparation work, never comparator support, correctness or acceptance.
"""
import json
from pathlib import Path
import re


def local_facts(path, build_id, image_sha256):
    """Read only on explicit opt-in: our local exporter directory, or a curated public JSON list."""
    path = Path(path)
    if path.is_dir():
        meta = json.loads((path / 'table-meta.json').read_text())
        rows = (json.loads(line) for line in (path / 'functions.jsonl').read_text().splitlines() if line.strip())
    else:
        meta = json.loads(path.read_text())
        rows = meta['functions']
    if meta.get('build_id') != build_id:
        raise ValueError('local function table must name the pinned build_id')
    recorded_hash = (meta.get('inputs') or {}).get('image_sha256')
    if recorded_hash and recorded_hash != image_sha256:
        raise ValueError('local function table image hash disagrees with the pinned image')
    return {(row['rva'] if isinstance(row['rva'], int) else int(row['rva'], 16)): row for row in rows}


def declaration(text, cls, method):
    """Conservative lexical declaration check; an existing file alone is not preparation."""
    import check_labels
    clean = check_labels.strip(text)
    pairs = check_labels.braces(clean)
    for match in check_labels.scope_matches(clean):
        if match.group(1) not in ('class', 'struct') or match.group(2) != cls:
            continue
        body = clean[match.end():pairs.get(match.end() - 1, match.end())]
        found = re.search(r'(?m)^\s*([^;{}\n]*?)\b' + re.escape(method) +
                          r'\s*\(([^;{}]*)\)\s*(?:const\s*)?(?:noexcept\s*)?(?:override\s*)?(?:=\s*0\s*)?;', body)
        if found and '...' not in found.group(2):
            # Do not promote the helper's deliberately untyped starter signature.
            if 'Placeholder signature:' not in text and 'SKELETON_TODO' not in text:
                return found.group(1).strip(), found.group(2).strip()
    return None


def binding_caution(candidate, bindings, folds):
    """Flag public names that may conflict once a candidate is compiled under its offered name."""
    from bind import community_qualified, fallback_qualified
    expected = community_qualified(candidate)
    names = {symbol: fallback_qualified(symbol) or symbol for symbol in bindings}
    for symbol, name in names.items():
        if name == expected:
            declared = {symbol}.union(*(group for group in folds if symbol in group))
            if bindings <= declared:
                return None
    return 'symbol binding needs preparation; existing name(s): ' + ', '.join(sorted(set(names.values())))


def readiness(fn, cls, method, header='', facts=None, binding=None):
    """(rank, one-line reason, cautions), lower ranks first. Unknown facts stay unknown."""
    facts = {**fn, **(facts or {})}
    cautions = [binding] if binding else []
    if header:
        from contrib_screen import screen
        if screen(header.encode(), 'declarations.h'):
            cautions.append('existing header needs contributor-screen preparation')
    verdict = (facts.get('v2') or {}).get('verdict')
    if verdict == 'unsupported' or facts.get('supported') is False:
        cautions.append('locally classified unsupported')
    if facts.get('parked') or fn.get('parked'):
        cautions.append('parked pattern; preparation required')
    eh = facts.get('eh') or {}
    if eh.get('handler') or eh.get('handler_kind') or facts.get('eh_heavy'):
        cautions.append('exception-handling data; inspect lifetimes first')
    kind = str(facts.get('kind') or '')
    if kind and kind != 'ordinary':
        label = kind if kind in ('thunk', 'adjustor', 'eh-funclet', 'static-initializer', 'teardown') else 'special function'
        cautions.append('locally classified ' + label + '; special preparation required')
    if method.startswith('~') or method == cls or re.search('destruct|adjust|thunk', kind, re.I):
        cautions.append('constructor/destructor/adjustor ABI preparation required')
    decl = declaration(header, cls, method) if header else None
    if cautions:
        return 4, '; '.join(cautions), cautions
    simple = bool(re.match(r'(?:Get|Is|Has|Can|Test|Set|Clear|Reset|Forward)\w*$', method))
    if decl and simple and fn['size'] <= 64:
        return 0, 'small accessor/flag/forwarder name with a usable declaration (heuristic)', []
    if decl:
        return 1, 'usable declaration in an existing unit; behavior still needs local inspection', []
    if simple and fn['size'] <= 64:
        return 2, 'small accessor/flag/forwarder name; declaration needs preparation (heuristic)', []
    return 3, 'declaration or behavior preparation unknown; size is only a tiebreaker', []
