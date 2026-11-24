#!/usr/bin/env python3
"""Give-up records: what a drafter learned about a function it could not match.

    python3 tools/giveup.py add 0x1004350 --category register-schedule --tried "..." --still-differs "..." \\
        --suspected-cause "..." --best-similarity 92.7 --model <id> --harness <name> [--best-from FILE...]
    python3 tools/giveup.py show 0x1004350        # every earlier give-up for the function, in words
    python3 tools/giveup.py list [--category C]   # functions with give-ups, best similarity first
    python3 tools/giveup.py check [FILE...]       # validate the committed records (or the named ones)

A drafter that stops on a function used to lose everything it learned. A record keeps the words and the
numbers: the category of the wall, what was tried, what still differs, the suspected cause, the best
similarity, the model and harness, and a pointer to the best code. The next drafter that gets the RVA sees
the records first (`./sr next`, `./sr start`, `./sr facts`, `tools/claims.py check`, the unit sheet) and does not
repeat the tries.

Where things live (docs/contributing-agent.md, "If you can't match it"):

- `data/giveups/<build id>/<rva without 0x>.json` holds the records of one function, words and numbers only.
  A contributor PR may carry them (the scope check allows exactly this path), together with its units or with
  lesson notes; the bot validates them with `validate` below and the leak scan, with no model review.
- The best source never goes in a record. An internal worker keeps it under `.local/giveups/` (`--best-from`
  copies the files there and the record points at them); a contributor keeps it in the task folder, and when
  the near-miss has a cause the cookbook does not cover, writes it as a lesson note (`./sr note`) and points the
  record at the note. Neither is evidence of a match; only a byte match is acceptance.

A record never says which instructions differ. It is words in plain sentences, a short list and numbers; the
same leak rules as for every committed text refuse anything that reads as bytes, disassembly or a private path.
"""
import argparse
import json
from pathlib import Path
import re
import shutil
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import leakgrep  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
DIR = 'data/giveups'
CATEGORIES = ('control-flow', 'register-schedule', 'inline-set', 'layout-unknown', 'eh-frame', 'callee-missing',
              'signature-wrong', 'other')
LANES = ('internal', 'contributor')
BEST_KINDS = ('local', 'note', 'none')
KEYS = ('category', 'tried', 'still_differs', 'suspected_cause', 'best_similarity', 'similarity_basis', 'model',
        'harness', 'lane', 'best_code')
REQUIRED = ('category', 'tried', 'still_differs', 'suspected_cause', 'model', 'harness', 'lane', 'best_code')
MAX_RECORDS = 20
MAX_TRIED, MAX_TRIED_LEN, MAX_TEXT = 12, 160, 400
RECORD_FILE = re.compile(r'data/giveups/[a-z0-9][a-z0-9-]{0,63}/[0-9a-f]{3,8}\.json\Z')
RVA = re.compile(r'0x[0-9a-f]{3,8}\Z')
LABEL = re.compile(r'[A-Za-z0-9][A-Za-z0-9 ._:/@+-]{0,59}\Z')
INSTRUCTION = re.compile(r'\b(?:mov|movzx|movss|movaps|lea|cmp|test|xor|call|jmp|push|pop|add|sub|imul)\s+'
                         r'(?:[re]?[abcd]x\b|r\d{1,2}\b|[re]?[sd]i\b|xmm\d|\[|(?:byte|word|dword|qword)\s+ptr)', re.I)
HEX_RUN = re.compile(r'0x[0-9a-fA-F]{9,}|\b[0-9a-fA-F]{16,}\b')
NOTE_REF = re.compile(r'docs/cookbook-notes/[0-9a-f]{3,8}-[a-z0-9][a-z0-9-]{0,60}\.md\Z')
LOCAL_REF = re.compile(r'\.local/giveups/[A-Za-z0-9._/-]{1,200}\Z')


def build_id(root=ROOT):
    return json.loads((Path(root) / 'builds/target.json').read_text())['build_id']


def norm_rva(text):
    value = int(str(text), 16) if isinstance(text, str) else int(text)
    return f'0x{value:x}'


def record_path(root, build, rva):
    return Path(root) / DIR / build / f'{norm_rva(rva)[2:]}.json'


def text_problems(value, limit=MAX_TEXT):
    """Fixed reason codes for one free-text value: words only."""
    if not isinstance(value, str) or not value.strip():
        return ['empty']
    codes = []
    if len(value) > limit:
        codes.append('too-long')
    if '\n' in value or '\r' in value or '`' in value:
        codes.append('not-one-line-of-words')
    if INSTRUCTION.search(value) or HEX_RUN.search(value):
        codes.append('instruction-or-bytes')
    if leakgrep.scan_line(value) or leakgrep.scan_line('// ' + value):
        codes.append('leak-pattern')
    return codes


def record_problems(rec):
    """Fixed reason codes for one record (never the text); [] when it is acceptable."""
    if not isinstance(rec, dict):
        return ['not-an-object']
    codes = []
    if any(k not in KEYS for k in rec):
        codes.append('unknown-key')
    if any(k not in rec for k in REQUIRED):
        codes.append('missing-key')
        return sorted(set(codes))
    if rec['category'] not in CATEGORIES:
        codes.append('category')
    if not isinstance(rec['tried'], list) or not 1 <= len(rec['tried']) <= MAX_TRIED:
        codes.append('tried-list')
    else:
        for item in rec['tried']:
            codes += ['tried-' + c for c in text_problems(item, MAX_TRIED_LEN)]
    for key in ('still_differs', 'suspected_cause'):
        codes += [f'{key}-{c}' for c in text_problems(rec[key])]
    sim = rec.get('best_similarity')
    if sim is not None and (isinstance(sim, bool) or not isinstance(sim, (int, float)) or not 0 <= sim <= 100):
        codes.append('best-similarity')
    if rec.get('similarity_basis') is not None:
        codes += ['similarity-basis-' + c for c in text_problems(rec['similarity_basis'], 80)]
    for key in ('model', 'harness'):
        if not isinstance(rec[key], str) or not LABEL.fullmatch(rec[key]):
            codes.append(key)
    if rec['lane'] not in LANES:
        codes.append('lane')
    best = rec['best_code']
    if not isinstance(best, dict) or set(best) - {'kind', 'ref'} or best.get('kind') not in BEST_KINDS:
        codes.append('best-code')
    elif best['kind'] == 'none':
        if best.get('ref'):
            codes.append('best-code')
    elif best['kind'] == 'note':
        if not NOTE_REF.fullmatch(str(best.get('ref', ''))):
            codes.append('best-code-note')
    elif not LOCAL_REF.fullmatch(str(best.get('ref', ''))) or '..' in str(best.get('ref')).split('/'):
        codes.append('best-code-local')
    return sorted(set(codes))


def validate(name, text, build=None):
    """Fixed reason codes for a record file, for the bot and the tests: [] when it is acceptable."""
    codes = []
    if name is not None and not RECORD_FILE.fullmatch(name):
        codes.append('bad-name')
    try:
        doc = json.loads(text)
    except ValueError:
        return sorted(set(codes + ['not-json']))
    if not isinstance(doc, dict) or set(doc) != {'schema', 'build_id', 'rva', 'records'} or doc['schema'] != 1:
        return sorted(set(codes + ['shape']))
    if not isinstance(doc['build_id'], str) or not isinstance(doc['rva'], str) or not RVA.fullmatch(doc['rva']):
        codes.append('identity')
    elif name is not None and RECORD_FILE.fullmatch(name):
        parts = name.split('/')
        if parts[2] != doc['build_id'] or parts[3] != doc['rva'][2:] + '.json':
            codes.append('identity')
    if build is not None and doc['build_id'] != build:
        codes.append('identity')
    if not isinstance(doc['records'], list) or not 1 <= len(doc['records']) <= MAX_RECORDS:
        codes.append('records-list')
    else:
        for rec in doc['records']:
            codes += record_problems(rec)
    if text != dump(doc):
        codes.append('format')
    return sorted(set(codes))


def dump(doc):
    return json.dumps(doc, indent=2) + '\n'


def load(root, rva, build=None):
    """The records of one function ([] when none), oldest first."""
    try:
        path = record_path(root, build or build_id(root), rva)
        doc = json.loads(path.read_text())
    except (OSError, ValueError, KeyError):
        return []
    return doc.get('records', []) if isinstance(doc, dict) else []


def all_records(root):
    """{rva text: [records]} for every committed record file of the target build."""
    try:
        folder = Path(root) / DIR / build_id(root)
    except (OSError, ValueError, KeyError):
        return {}
    out = {}
    for path in sorted(folder.glob('*.json')) if folder.is_dir() else ():
        try:
            doc = json.loads(path.read_text())
            out[doc['rva']] = doc['records']
        except (OSError, ValueError, KeyError, TypeError):
            continue
    return out


def best(records):
    sims = [r['best_similarity'] for r in records if r.get('best_similarity') is not None]
    return max(sims) if sims else None


def brief(root, rva):
    """One short phrase for a listing row, or '' when the function has no give-up."""
    records = load(root, rva)
    if not records:
        return ''
    sim = best(records)
    cats = ', '.join(dict.fromkeys(r['category'] for r in records))
    return f'{len(records)} earlier give-up{"s" if len(records) != 1 else ""}: {cats}' + (f' (best {sim:g}%)' if sim is not None else '')


def lines_for(root, rvas, cli='python3 tools/giveup.py'):
    """The block a drafter reads first for the RVAs it was given; [] when none has a give-up."""
    out = []
    for rva in rvas:
        records = load(root, norm_rva(rva))
        if not records:
            continue
        out.append(f'Earlier give-ups for {norm_rva(rva)} (read these before drafting; they are words, not evidence):')
        for i, rec in enumerate(records, 1):
            sim = f', best {rec["best_similarity"]:g}%' if rec.get('best_similarity') is not None else ''
            out.append(f'  {i}. {rec["category"]}{sim}; {rec["model"]} via {rec["harness"]}')
            out.append('     tried: ' + '; '.join(rec['tried']))
            out.append('     still differs: ' + rec['still_differs'])
            out.append('     suspected cause: ' + rec['suspected_cause'])
            ref = rec['best_code']
            if ref['kind'] != 'none':
                out.append(f'     best code: {ref["kind"]} {ref["ref"]}')
        out.append(f'  (all of them: {cli} show {norm_rva(rva)})')
    return out


def add(root, rva, rec):
    """Append `rec` to the function's file; returns (path, added) and refuses an invalid or repeated record."""
    root = Path(root)
    problems = record_problems(rec)
    if problems:
        raise ValueError('record refused: ' + ', '.join(problems))
    build = build_id(root)
    path = record_path(root, build, rva)
    records = load(root, rva, build)
    same = [r for r in records if (r['model'], r['harness'], r['category'], r['still_differs']) ==
            (rec['model'], rec['harness'], rec['category'], rec['still_differs'])]
    if same:
        return path, False
    if len(records) >= MAX_RECORDS:
        raise ValueError(f'{norm_rva(rva)} already holds {MAX_RECORDS} give-ups; read them with `show` before adding more')
    doc = dict(schema=1, build_id=build, rva=norm_rva(rva), records=records + [rec])
    codes = validate(path.relative_to(root).as_posix(), dump(doc), build)
    if codes:
        raise ValueError('record file would be refused: ' + ', '.join(codes))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(dump(doc))
    return path, True


def keep_best(root, rva, files):
    """Copy the best attempt's files under .local/giveups/<build>/<rva>/<n>/ and return the pointer.

    A linked worktree is removed when its work ends, so the copy goes to the main checkout's private folder
    when `root` is one (tools/local_paths.py); the pointer is the same repository-relative text either way.
    """
    from local_paths import main_checkout_local
    root = Path(root)
    private = main_checkout_local(root) or (root / '.local')
    build, short = build_id(root), norm_rva(rva)[2:]
    base = private / 'giveups' / build / short
    base.mkdir(parents=True, exist_ok=True)
    n = 1 + max([int(p.name) for p in base.iterdir() if p.name.isdigit()] or [0])
    dest = base / str(n)
    dest.mkdir()
    for name in files:
        shutil.copy2(name, dest / Path(name).name)
    return dict(kind='local', ref=f'.local/giveups/{build}/{short}/{n}')


def command_add(a):
    best_code = dict(kind='none')
    if a.best_from:
        best_code = keep_best(a.root, a.rva, a.best_from)
    elif a.note:
        best_code = dict(kind='note', ref=a.note)
    rec = dict(category=a.category, tried=a.tried, still_differs=a.still_differs, suspected_cause=a.suspected_cause,
               model=a.model, harness=a.harness, lane=a.lane, best_code=best_code)
    if a.best_similarity is not None:
        rec['best_similarity'] = a.best_similarity
    if a.similarity_basis:
        rec['similarity_basis'] = a.similarity_basis
    ordered = {k: rec[k] for k in KEYS if k in rec}
    try:
        path, added = add(a.root, a.rva, ordered)
    except ValueError as exc:
        print(f'giveup: {exc}', file=sys.stderr)
        return 2
    print(('added to ' if added else 'already recorded in ') + path.relative_to(Path(a.root)).as_posix())
    if added and best_code['kind'] == 'none' and a.lane == 'internal':
        print('note: no best code was kept; pass --best-from <files> so the next drafter can start from it')
    return 0


def command_show(a):
    lines = lines_for(a.root, [a.rva])
    print('\n'.join(lines) if lines else f'{norm_rva(a.rva)}: no give-up recorded')
    return 0


def command_list(a):
    rows = []
    for rva, records in all_records(a.root).items():
        records = [r for r in records if not a.category or r['category'] == a.category]
        if records:
            rows.append((best(records) if best(records) is not None else -1, rva, records))
    for sim, rva, records in sorted(rows, key=lambda r: (-r[0], r[1]))[:a.limit]:
        cats = ', '.join(dict.fromkeys(r['category'] for r in records))
        print(f'{rva}\t{len(records)}\t{"" if sim < 0 else f"{sim:g}"}\t{cats}')
    print(f'{len(rows)} function(s) with give-ups')
    return 0


def command_check(a):
    root = Path(a.root)
    names = a.files or sorted(p.relative_to(root).as_posix() for p in (root / DIR).glob('*/*.json'))
    bad = 0
    build = build_id(root)
    for name in names:
        path = root / name
        codes = validate(name, path.read_text(), build) if path.is_file() else ['missing']
        if codes:
            bad += 1
            print(f'{name}: {", ".join(codes)}')
    print(f'{len(names)} record file(s), {bad} refused')
    return int(bool(bad))


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--root', type=Path, default=ROOT)
    sub = p.add_subparsers(dest='cmd', required=True)
    s = sub.add_parser('add')
    s.add_argument('rva')
    s.add_argument('--category', required=True, choices=CATEGORIES)
    s.add_argument('--tried', action='append', required=True, help='one short try; repeat for each')
    s.add_argument('--still-differs', required=True, help='in words, no instructions')
    s.add_argument('--suspected-cause', required=True)
    s.add_argument('--best-similarity', type=float)
    s.add_argument('--similarity-basis', help='what the number measures, e.g. "aligned shape similarity"')
    s.add_argument('--model', required=True)
    s.add_argument('--harness', required=True)
    s.add_argument('--lane', choices=LANES, default='internal')
    where = s.add_mutually_exclusive_group()
    where.add_argument('--best-from', nargs='+', metavar='FILE', help='copy the best source files under .local/giveups/')
    where.add_argument('--note', help='docs/cookbook-notes/<rva>-<slug>.md that holds the lesson')
    s.set_defaults(func=command_add)
    s = sub.add_parser('show')
    s.add_argument('rva')
    s.set_defaults(func=command_show)
    s = sub.add_parser('list')
    s.add_argument('--category', choices=CATEGORIES)
    s.add_argument('--limit', type=int, default=50)
    s.set_defaults(func=command_list)
    s = sub.add_parser('check')
    s.add_argument('files', nargs='*')
    s.set_defaults(func=command_check)
    a = p.parse_args(argv)
    return a.func(a)


if __name__ == '__main__':
    raise SystemExit(main())
