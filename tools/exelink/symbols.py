#!/usr/bin/env python3
"""Build, export and look up reconstruction-only symbols at the matched RVAs."""

import argparse
from bisect import bisect_right
from collections import Counter
from copy import copy
from functools import cache
import hashlib
import json
import os
from pathlib import Path, PurePosixPath, PureWindowsPath
import posixpath
import re
import sys

import units
from codeview import debug_records
from compare import code_section_sha256, find_function
from compare_internal import find_internal_function, internal_code_sha256
from lint_reconstruction import LABEL
from pecoff import CoffObject, Reject
from source_digest import INCLUDE_ROOTS, quoted_includes

SCHEMA = 1
ORIGIN = re.compile(rf'(?<![\w]){LABEL}(?![\w])')
CHECKSUM_NAMES = {1: 'md5', 2: 'sha1', 3: 'sha256'}


def local_path(path):
    path = Path(path).resolve()
    if '.local' not in path.parts:
        raise ValueError('symbol output and build objects must be under a .local directory')
    return path


class SourceFiles:
    """Validate source paths and compiler checksums against the local reconstruction tree."""

    def __init__(self, repo, build_root=None):
        self.repo = Path(repo).resolve()
        self.build_root = str(build_root or self.repo)
        self.paths = {}
        for directory, _, files in os.walk(self.repo / 'reconstruction'):
            for name in files:
                path = Path(directory) / name
                if path.is_symlink():
                    continue
                rel = path.relative_to(self.repo).as_posix()
                if rel.casefold() in self.paths:
                    raise ValueError(f'ambiguous case in reconstruction path {rel}')
                self.paths[rel.casefold()] = rel

    def normalize(self, name):
        style = PureWindowsPath if PureWindowsPath(self.build_root).drive else PurePosixPath
        path = style(name.replace('\\', '/'))
        if path.is_absolute():
            try:
                path = path.relative_to(style(self.build_root))
            except ValueError:
                return None
        if path.anchor or '..' in path.parts:
            return None
        return self.paths.get(path.as_posix().casefold())

    @cache
    def metadata(self, path):
        data = (self.repo / path).read_bytes()
        text = data.decode('utf-8', 'replace')
        labels = {label for line in text.splitlines() if line.lstrip().startswith(('//', '/*', '*'))
                  for label in ORIGIN.findall(line.split(';', 1)[0])}
        try:
            includes = quoted_includes(data, path)
        except ValueError:
            includes = []
        return len(data.splitlines()), labels, includes

    @cache
    def checksum(self, path, algorithm):
        return hashlib.new(algorithm, (self.repo / path).read_bytes(), usedforsecurity=False).digest()

    @cache
    def verified_file(self, record):
        raw, kind, wanted = record
        path = self.normalize(raw)
        algorithm = CHECKSUM_NAMES.get(kind)
        if path and algorithm and self.checksum(path, algorithm) == wanted:
            return path
        return None

    def provenance(self, paths):
        labels, seen = set(), set()
        stack = [(path, ()) for path in paths if path]
        while stack:
            path, parents = stack.pop()
            if path in seen:
                continue
            seen.add(path)
            _, found, includes = self.metadata(path)
            labels.update(found)
            dirs = (posixpath.dirname(path), *parents)
            for kind, name in includes:
                bases = (*dirs, *INCLUDE_ROOTS) if kind == '"' else INCLUDE_ROOTS
                for base in bases:
                    candidate = posixpath.normpath(posixpath.join(base, name))
                    hit = self.paths.get(candidate.casefold())
                    if hit:
                        stack.append((hit, dirs))
                        break
        return sorted(labels)


def source_ranges(contributions, size, sources):
    """Keep only bounded, checksum-verified lines, with gaps for unknown or external locations."""
    rows = []
    for base, length, entries in sorted(contributions, key=lambda table: table[0]):
        if not 0 <= base < base + length <= size:
            continue
        for index, (offset, item) in enumerate(entries):
            if item is None:
                continue
            record, line, statement = item
            path = sources.verified_file(record)
            if path is None or line > sources.metadata(path)[0]:
                continue
            end = entries[index + 1][0] if index + 1 < len(entries) else length
            rows.append({'offset': base + offset, 'length': end - offset, 'file': path,
                         'line': line, 'statement': statement})
    rows.sort(key=lambda row: row['offset'])
    if any(a['offset'] + a['length'] > b['offset'] for a, b in zip(rows, rows[1:])):
        return []
    return rows


def plain_coff_view(obj):
    """Recreate ordinary COFF section numbering for accepted internal-function selectors."""
    view = copy(obj)
    # Ordinary builds retain the first symbol subsection with compiler metadata.
    leader = next((s for s in obj.sections if s.name == '.debug$S'), None)
    sections = [s for s in obj.sections
                if s is leader or not (s.name.startswith('.debug$') or s.name == '.chks64')]
    renumber = {sec.index: index for index, sec in enumerate(sections, 1)}
    view.sections = [copy(sec) for sec in sections]
    for index, sec in enumerate(view.sections, 1):
        sec.index = index
    view.symbols = {i: copy(sym) for i, sym in obj.symbols.items() if sym.section <= 0 or sym.section in renumber}
    for sym in view.symbols.values():
        sym.section = renumber.get(sym.section, sym.section)
    return view


def collect_unit(unit, obj, sources):
    functions, missing = [], []
    try:
        names, lines = debug_records(obj)
    except Reject:
        names, lines = {}, {}
    path = sources.normalize(unit['compiled'])
    ordinary = plain_coff_view(obj) if any('internal_identity' in spec for spec in unit['functions']) else obj
    for spec in unit['functions']:
        try:
            internal = 'internal_identity' in spec
            sym, sec = (find_internal_function(ordinary, spec) if internal else find_function(obj, spec['symbol']))
            size = len(sec.data) - sym.value
            if size != spec['size']:
                raise Reject('code-size-mismatch', 'function size differs from the accepted record')
            verified = spec.get('record_code_sections') == 1 and bool(spec.get('record_code_section_sha256'))
            if verified:
                digest = (internal_code_sha256(ordinary, [sec], spec) if internal else code_section_sha256(obj, [sec]))
                if digest != spec['record_code_section_sha256']:
                    raise Reject('code-hash-mismatch', 'function code differs from the accepted record')
            debug_section = obj.symbols[sym.index].section
            locations = source_ranges(lines.get(debug_section, []), size, sources)
            provenance = [path, sources.normalize(spec['source_path']), *(line['file'] for line in locations)]
            functions.append({'rva': spec['rva'], 'size': size, 'name': names.get((debug_section, sym.value)) or sym.name,
                              'linkage_name': sym.name, 'unit': path, 'lines': locations,
                              'labels': sources.provenance(provenance), 'code_hash_verified': verified})
        except Reject as exc:
            missing.append({'rva': spec['rva'], 'reason': exc.reason})
    return functions, missing


def collect(plan, objects, sources):
    functions, missing = [], []
    for unit in plan['units']:
        compiled = sources.normalize(unit['compiled'])
        if compiled is None:
            missing.extend({'rva': spec['rva'], 'reason': 'source-not-found'} for spec in unit['functions'])
            continue
        try:
            obj = CoffObject(units.object_path(objects, unit).read_bytes())
        except (OSError, Reject) as exc:
            reason = exc.reason if isinstance(exc, Reject) else 'no-object'
            missing.extend({'rva': spec['rva'], 'reason': reason} for spec in unit['functions'])
        else:
            found, absent = collect_unit(unit, obj, sources)
            functions.extend(found)
            missing.extend(absent)
    functions.sort(key=lambda row: row['rva'])
    if any(a['rva'] + a['size'] > b['rva'] for a, b in zip(functions, functions[1:])):
        raise ValueError('plan contains overlapping function ranges')
    coverage = {'planned': len(functions) + len(missing), 'symbols': len(functions),
                'with_lines': sum(bool(row['lines']) for row in functions),
                'code_hash_verified': sum(row['code_hash_verified'] for row in functions),
                'missing': dict(sorted(Counter(row['reason'] for row in missing).items()))}
    return {'schema': SCHEMA, 'build_id': plan['build_id'], 'coverage': coverage, 'functions': functions,
            'missing': sorted(missing, key=lambda row: row['rva'])}


def lookup(functions, rva):
    index = bisect_right(functions, rva, key=lambda row: row['rva']) - 1
    if index < 0:
        return None
    function = functions[index]
    offset = rva - function['rva']
    if offset >= function['size']:
        return None
    line = next((row for row in function['lines'] if row['offset'] <= offset < row['offset'] + row['length']), None)
    return {**{k: v for k, v in function.items() if k != 'lines'}, 'line': line}


def read_json(path):
    with open(path, encoding='utf-8') as stream:
        return json.load(stream)


def write_map(path, mapping):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', encoding='utf-8') as stream:
        json.dump(mapping, stream, ensure_ascii=False, separators=(',', ':'))
        stream.write('\n')


def read_plan(path):
    plan = read_json(path)
    if plan.get('plan_schema') != units.PLAN_SCHEMA:
        raise ValueError('unsupported exelink plan schema')
    if plan['build_id'] != read_json(units.ROOT / 'builds/target.json')['build_id']:
        raise ValueError('plan is for a different build')
    for unit in plan['units']:
        for key in ('unit', 'compiled', 'recipe'):
            path = PurePosixPath(unit[key])
            if path.is_absolute() or '..' in path.parts or '\\' in unit[key]:
                raise ValueError('plan contains an invalid path')
        if '/' in unit['unit'] or any(not unit[k].startswith('reconstruction/') for k in ('compiled', 'recipe')):
            raise ValueError('plan must use reconstruction sources, recipes and exelink object names')
    return plan


def build(args):
    from ci_toolchain import verify_pins

    plan = read_plan(args.plan)
    objects = local_path(args.objects)
    if any(objects.glob('*.obj')):
        raise ValueError('build requires a fresh object directory')
    if not 1 <= args.jobs <= 6:
        raise ValueError('--jobs must be between 1 and 6')
    if sys.platform != 'win32':
        raise ValueError('run the pinned compiler build on the Windows build worker')
    if not verify_pins(units.ROOT, Path(args.msvc)):
        raise ValueError('MSVC compiler pins do not match')
    done = 0

    def progress(batch, failed):
        nonlocal done
        done += len(batch)
        if failed or done == len(plan['units']) or done // 1000 != (done - len(batch)) // 1000:
            print(f'{done}/{len(plan["units"])} units, {len(failed)} failed in this batch', flush=True)

    failed = units.build_units(units.ROOT, plan['units'], objects, args.msvc, jobs=args.jobs,
                               on_batch=progress, extra_flags=['/Z7'])
    return int(bool(failed))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='command', required=True)
    for command in ('build', 'map'):
        sub = commands.add_parser(command)
        sub.add_argument('--plan', required=True)
        sub.add_argument('--objects', required=True)
        if command == 'build':
            sub.add_argument('--msvc', required=True, help='root of the unpacked pinned toolchain')
            sub.add_argument('--jobs', type=int, default=1)
        else:
            sub.add_argument('--out', required=True)
            sub.add_argument('--build-root', help='source checkout used by the compiler (default: this checkout)')
    sub = commands.add_parser('pdb')
    sub.add_argument('--map', required=True)
    sub.add_argument('--out', required=True, help='output .pdb path under .local')
    sub.add_argument('--clang', default='clang')
    sub.add_argument('--lld-link', default='lld-link')
    sub.add_argument('--source-root', default=str(units.ROOT), help='checkout path as seen by the debugger')
    sub = commands.add_parser('lookup')
    sub.add_argument('--map', required=True)
    sub.add_argument('rva', nargs='+', type=lambda value: int(value, 0))
    args = parser.parse_args(argv)
    try:
        if args.command == 'build':
            return build(args)
        if args.command == 'map':
            out = local_path(args.out)
            mapping = collect(read_plan(args.plan), local_path(args.objects), SourceFiles(units.ROOT, args.build_root))
            write_map(out, mapping)
            print(json.dumps(mapping['coverage']))
            return int(bool(mapping['missing']))
        mapping = read_json(local_path(args.map))
        if mapping.get('schema') != SCHEMA:
            raise ValueError('unsupported symbol map schema')
        if args.command == 'pdb':
            from symbol_pdb import write_pdb
            write_pdb(mapping, local_path(args.out), args.source_root, args.clang, args.lld_link)
            return 0
        rows = [lookup(mapping['functions'], rva) for rva in args.rva]
        print(json.dumps(rows, indent=2))
        return int(any(row is None for row in rows))
    except (OSError, ValueError, KeyError, units.BuildError) as exc:
        parser.exit(1, f'{exc}\n')


if __name__ == '__main__':
    sys.exit(main())
