"""Move reconstruction units from single-level class folders into the subsystem layout.

A move keeps every tu-sha256-v2 digest: files keep their bytes except that an `#include "..."`
path is rewritten to reach the target's new place, in the same order and the same graph, and a
file that would put its path into the code (`__FILE__`, `#line`) is refused. The match records
get their `source.translation_unit`, `source.compiled` and `build.hosts.*.repository_files_opened`
rewritten in place (text edits, so the rest of each record stays byte for byte); the paths a
comparator or CI run embedded stay as they were and are read through `data/source-moves.json`
(tools/source_moves.py). The map is extended on every run, so a unit moved twice still resolves.

Files named with `--pin` (and what they include, and their same-named .cpp/.h partner) stay where
they are: they are the files of open outside changes, which are still written against the old
layout and must keep compiling. Run again after those land to move the rest.

    python3 tools/migrate_layout.py [--apply] [--pin FILE ...] [--pin-list LIST] [--plan OUT.json]
"""
import argparse
import collections
import hashlib
import json
import os
import posixpath
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import digest_v2  # noqa: E402
import source_digest as v1  # noqa: E402
import source_moves  # noqa: E402
import unit_paths as up  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
BASE = 'reconstruction'
INCLUDE = re.compile(r'^([ \t]*#[ \t]*include[ \t]*)"([^"<>\n]+)"([ \t]*\r?)$')
# When several old folders hold a unit of the same class, the one from the earliest folder in this
# list keeps the plain name; the others take `_<lowest rva>`.
CANON_ORDER = ('forms', 'magic', 'actors', 'netimmerse', 'bsengine', 'inventory', 'havok', 'scaleform',
               'shaders', 'layouts', 'unknown', 'fo4hints')
EXTRA_FILES = {f'{BASE}/INDEX.md', f'{BASE}/README.md'}


class Refusal(Exception):
    pass


def legacy_dir(path):
    """The single-level folder of a source file still in the earlier layout, else None."""
    parts = path.split('/')
    if (len(parts) == 3 and parts[0] == BASE and parts[1] != 'recipes' and parts[1] not in up.KIT_DIRS
            and parts[1] not in up.AREAS and path.endswith(('.cpp', '.h'))):
        return parts[1]
    return None


def tree_files(root):
    out = []
    for dirpath, _dirs, names in os.walk(Path(root) / BASE):
        for name in names:
            rel = (Path(dirpath) / name).relative_to(root).as_posix()
            if rel.endswith(('.cpp', '.h')):
                out.append(rel)
    return sorted(out)


def resolve(path, target, fileset):
    """(resolved file, 'own' | 'root') for a quoted include, by the same tiers the closure scan uses."""
    own = posixpath.normpath(posixpath.join(posixpath.dirname(path), target))
    if own in fileset:
        return own, 'own'
    rooted = posixpath.normpath(posixpath.join(BASE, target))
    if rooted in fileset:
        return rooted, 'root'
    return None, None


def includes_of(root, path, fileset):
    """[(line index, prefix, target, suffix, resolved, tier)] for the file's include lines."""
    text = (Path(root) / path).read_bytes().decode('utf-8')
    found = []
    for index, line in enumerate(text.split('\n')):
        m = INCLUDE.match(line)
        if m:
            resolved, tier = resolve(path, m.group(2), fileset)
            found.append((index, m.group(1), m.group(2), m.group(3), resolved, tier))
    wanted = [t for kind, t in v1.quoted_includes(text.encode(), path) if kind == '"']
    if wanted != [f[2] for f in found]:
        raise Refusal(f'{path}: an include line this tool cannot rewrite safely')
    for found_line in found:
        if found_line[4] is None:
            raise Refusal(f'{path}: include "{found_line[2]}" is not a file of the tree')
    return text, found


def load_units(root):
    """({compiled: {rva}}, {file: {compiled}}) from the match records."""
    comp, units_of = collections.defaultdict(set), collections.defaultdict(set)
    for path in sorted((Path(root) / 'reports').glob('*/0x*.json')):
        if path.name.endswith('.review.json'):
            continue
        record = json.loads(path.read_text())
        source = record.get('source')
        if not isinstance(source, dict) or 'compiled' not in source:
            continue
        match = re.fullmatch(r'0x([0-9a-f]+)', path.stem)
        if not match:
            continue
        comp[source['compiled']].add(int(match.group(1), 16))
        for name in source['translation_unit']:
            units_of[name].add(source['compiled'])
    return comp, units_of


def pin_closure(root, pins, files, fileset):
    """The pinned files, what they include and their same-stem partners, to a fixpoint."""
    pinned, work = set(), [p for p in pins if p in fileset]
    by_stem = collections.defaultdict(set)
    for f in files:
        by_stem[(posixpath.dirname(f), posixpath.splitext(posixpath.basename(f))[0])].add(f)
    while work:
        f = work.pop()
        if f in pinned:
            continue
        pinned.add(f)
        work += sorted(by_stem[(posixpath.dirname(f), posixpath.splitext(posixpath.basename(f))[0])])
        work += [r for *_x, r, _t in includes_of(root, f, fileset)[1]]
    return pinned


def target_dir(path):
    area = legacy_dir(path)
    name = posixpath.basename(path)
    stem = name.rsplit('.', 1)[0]
    if area in up.BULK_DIRS:
        return up.BULK_DIRS[area]
    family = up.family_dir(stem)
    if family:
        return family
    placed = up.unit_dir(up.owner_of(stem), ROOT)
    if placed is None:
        raise Refusal(f'{path}: no area rule for class {up.owner_of(stem)}; add it to {up.OVERRIDES}')
    return placed


def lowest_rva(group_files, group_dir, comp, units_of):
    """The lowest rva compared by a unit of the old folder that holds these files, else any unit."""
    local, anywhere = set(), set()
    for f in group_files:
        for unit in units_of.get(f, ()):
            anywhere |= comp.get(unit, set())
            if posixpath.dirname(unit) == group_dir:
                local |= comp.get(unit, set())
    pool = local or anywhere
    return min(pool) if pool else None


def make_plan(root, pins, extra_pins=()):
    root = Path(root)
    files = tree_files(root)
    fileset = set(files)
    comp, units_of = load_units(root)
    pinned = pin_closure(root, set(pins) | set(extra_pins), files, fileset)
    movers = [f for f in files if legacy_dir(f) and f not in pinned]
    occupied = {f for f in files if not legacy_dir(f)}
    groups = collections.defaultdict(lambda: collections.defaultdict(list))
    for f in movers:
        stem = posixpath.basename(f).rsplit('.', 1)[0]
        groups[(target_dir(f), stem)][posixpath.dirname(f)].append(f)
    new_of, tagged = {}, []
    for (dest, stem), members in sorted(groups.items()):
        taken = any(o.startswith(f'{BASE}/{dest}/{stem}.') for o in occupied)
        if len(members) > 1 or taken:
            def rank(old_dir):
                name = old_dir.split('/')[1]
                return (CANON_ORDER.index(name) if name in CANON_ORDER else len(CANON_ORDER), old_dir)
            order = sorted(members, key=rank)
            winners = [] if taken else order[:1]
        else:
            winners = list(members)
        for old_dir, fs in members.items():
            if old_dir in winners:
                tag = ''
            else:
                low = lowest_rva(fs, old_dir, comp, units_of)
                tag = '_' + (f'{low:x}' if low is not None
                             else hashlib.sha256(old_dir.encode()).hexdigest()[:8])
                tagged.append(old_dir + '/' + stem)
            for f in fs:
                ext = posixpath.splitext(f)[1]
                new_of[f] = f'{BASE}/{dest}/{stem}{tag}{ext}'
    seen = collections.defaultdict(list)
    for old, new in new_of.items():
        seen[new.casefold()].append(old)
    clash = {k: v for k, v in seen.items() if len(v) > 1 or any(o.casefold() == k for o in occupied)}
    if clash:
        raise Refusal(f'{len(clash)} target paths collide, for example {next(iter(clash.items()))}')
    return {'files': files, 'pinned': sorted(pinned), 'new_of': new_of, 'tagged': tagged}


def rewritten_text(root, path, new_of, fileset):
    """The file's text with every include path rewritten for the new places, and whether it changed."""
    text, found = includes_of(root, path, fileset)
    lines = text.split('\n')
    here = posixpath.dirname(new_of.get(path, path))
    for index, prefix, target, suffix, resolved, tier in found:
        new_target = new_of.get(resolved, resolved)
        if tier == 'root':
            spelled = posixpath.relpath(new_target, BASE)
        else:
            spelled = posixpath.relpath(new_target, here)
        lines[index] = f'{prefix}"{spelled}"{suffix}'
    out = '\n'.join(lines)
    if digest_v2.FORBIDDEN_V2.search(digest_v2.strip_comments(out.encode(), path)):
        raise Refusal(f'{path}: __FILE__ or #line makes the path part of the code')
    return out, out != text


BLOCK = re.compile(r'("(?P<key>translation_unit|repository_files_opened)": \[\n)(?P<items>(?:[ \t]+"[^"\n]*",?\n)+)(?P<close>[ \t]*\])')
SOURCE_OPEN = '\n  "source": {\n'


def rewrite_record(text, new_of):
    """The record text with the unit's paths moved, or the text unchanged; refuses what it cannot edit."""
    start = text.find(SOURCE_OPEN)
    if start < 0:
        return text
    end = text.find('\n  }', start + len(SOURCE_OPEN))
    head, source, tail = text[:start], text[start:end], text[end:]

    def swap_list(m):
        names = [json.loads(line.strip().rstrip(',')) for line in m.group('items').splitlines()]
        mapped = [new_of.get(n, n) for n in names]
        if m.group('key') == 'repository_files_opened' or names == sorted(names):
            mapped = sorted(mapped)
        indent = re.match(r'[ \t]*', m.group('items')).group(0)
        body = ',\n'.join(f'{indent}{json.dumps(n)}' for n in mapped) + '\n'
        return m.group(1) + body + m.group('close')

    def swap_compiled(m):
        return m.group(1) + json.dumps(new_of.get(json.loads(m.group(2)), json.loads(m.group(2)))) + m.group(3)

    source = BLOCK.sub(swap_list, source)
    source = re.sub(r'(\n    "compiled": )("[^"\n]*")(,?\n)', swap_compiled, source, count=1)
    head = BLOCK.sub(swap_list, head)
    tail = BLOCK.sub(swap_list, tail)
    return head + source + tail


def apply_plan(root, plan, dry=False):
    root = Path(root)
    files, new_of = plan['files'], plan['new_of']
    fileset = set(files)
    written = changed = 0
    for old in files:
        text, differs = rewritten_text(root, old, new_of, fileset)
        new = new_of.get(old, old)
        if dry:
            continue
        if new != old:
            (root / new).parent.mkdir(parents=True, exist_ok=True)
            (root / new).write_bytes(text.encode('utf-8'))
            (root / old).unlink()
            written += 1
        elif differs:
            (root / old).write_bytes(text.encode('utf-8'))
            changed += 1
    for dirpath, dirs, names in os.walk(root / BASE, topdown=False):
        if not names and not dirs and Path(dirpath) != root / BASE:
            os.rmdir(dirpath)
    records = 0
    if not dry:
        for path in sorted((root / 'reports').glob('*/0x*.json')):
            if path.name.endswith('.review.json'):
                continue
            before = path.read_text()
            after = rewrite_record(before, new_of)
            if after != before:
                json.loads(after)
                path.write_text(after)
                records += 1
    return written, changed, records


def update_moves(root, plan):
    """Extend data/source-moves.json with this run's moves of compiled files, folding earlier moves."""
    root = Path(root)
    path = root / source_moves.MOVES
    moves = json.loads(path.read_text()) if path.is_file() else {'schema': 1, 'dirs': {}, 'files': {}}
    new_of = {o: n for o, n in plan['new_of'].items() if o.endswith('.cpp')}
    by_old_dir = collections.defaultdict(list)
    for old, new in new_of.items():
        by_old_dir[posixpath.dirname(old)].append((old, new))
    every = collections.Counter(posixpath.dirname(f) for f in plan['files'] if f.endswith('.cpp'))
    earlier = {new: old for old, new in moves['files'].items()}
    for old_dir, pairs in by_old_dir.items():
        dests = {posixpath.dirname(n) for _o, n in pairs}
        same = all(posixpath.basename(o) == posixpath.basename(n) for o, n in pairs)
        whole = len(pairs) == every[old_dir]
        if len(dests) == 1 and same and whole and old_dir.split('/')[1] in up.BULK_DIRS:
            moves['dirs'][old_dir] = dests.pop()
            continue
        for old, new in pairs:
            moves['files'][earlier.get(old, old)] = new
    moves['files'] = dict(sorted(moves['files'].items()))
    moves['dirs'] = dict(sorted(moves['dirs'].items()))
    path.write_text(json.dumps(moves, indent=1, sort_keys=True) + '\n')


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--pin', action='append', default=[], metavar='FILE')
    ap.add_argument('--pin-list', metavar='LIST', help='file with one path per line')
    ap.add_argument('--plan', metavar='OUT', help='write the plan as JSON')
    args = ap.parse_args(argv)
    pins = list(args.pin)
    if args.pin_list:
        pins += [line.strip() for line in Path(args.pin_list).read_text().splitlines() if line.strip()]
    try:
        plan = make_plan(ROOT, pins)
        written, changed, records = apply_plan(ROOT, plan, dry=not args.apply)
    except (Refusal, ValueError) as exc:
        print(f'migrate_layout: {exc}', file=sys.stderr)
        return 1
    if args.plan:
        Path(args.plan).write_text(json.dumps({'new_of': plan['new_of'], 'pinned': plan['pinned'],
                                               'tagged': plan['tagged']}, indent=1, sort_keys=True) + '\n')
    moved = len(plan['new_of'])
    print(f'{moved} files to move, {len(plan["pinned"])} pinned, {len(plan["tagged"])} units renamed with an rva tag')
    if args.apply:
        update_moves(ROOT, plan)
        print(f'moved {written}, include lines rewritten in {changed} more, records updated {records}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
