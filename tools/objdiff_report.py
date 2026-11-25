#!/usr/bin/env python3
"""Export accepted progress as a version 2 report using only public inventory metadata."""
import argparse
from collections import defaultdict
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
TEXT_CATEGORY = 'text'
TEXT_LABEL = 'Lower bound (% of .text, includes CRT/import code)'
INDEX_ROW = re.compile(
    r'^\| (?:`(?P<unit>[^`]+)`|-) \| .*? \| `(?P<build>[^`]+)` / `(?P<rva>0x[0-9a-f]+)` / '
    r'\d+ \| [^|]* \| [^|]* \| (?P<status>[^|]*) \|'
)


def measures(functions, total_code=None, total_functions=None):
    matched_code = sum(fn['size'] for fn, matched in functions if matched)
    matched_functions = sum(matched for _, matched in functions)
    result = {'matched_code': str(matched_code), 'matched_functions': matched_functions}
    if total_code is not None:
        result['total_code'] = str(total_code)
        if total_code:
            result['matched_code_percent'] = 100 * matched_code / total_code
    if total_functions is not None:
        result['total_functions'] = total_functions
        if total_functions:
            result['matched_functions_percent'] = 100 * matched_functions / total_functions
    return result


def build_report(root):
    progress = json.loads((root / 'data/progress.json').read_text(encoding='utf-8'))
    census = json.loads((root / 'data/scope.json').read_text(encoding='utf-8'))
    build_id = census['build_id']
    code_section = census.get('image', {}).get('pe_code_virtual_size')
    if code_section is not None and (code_section['basis'] != 'measured'
                                     or type(code_section['value']) is not int or code_section['value'] <= 0):
        raise ValueError('PE code section size must be a positive measured byte count')
    index = {}
    for line in (root / 'reconstruction/INDEX.md').read_text(encoding='utf-8').splitlines():
        match = INDEX_ROW.match(line)
        if match and match['build'] == build_id:
            index[int(match['rva'], 16)] = match['unit'], match['status']

    functions = []
    groups = defaultdict(list)
    for fn in sorted(progress['functions'], key=lambda fn: fn['rva']):
        if fn['build_id'] != build_id:
            continue
        unit, status = index[fn['rva']]
        entry = (fn, fn['status'] == status == 'matched')
        functions.append(entry)
        if unit:
            groups[unit].append(entry)

    units = []
    for unit, entries in sorted(groups.items()):
        units.append({
            'name': unit,
            'metadata': {'source_path': f'reconstruction/{unit}.cpp'},
            'measures': measures(entries, sum(fn['size'] for fn, _ in entries), len(entries)),
            'functions': [{'name': fn['name'], 'size': str(fn['size'])} for fn, _ in entries],
        })
    scope = progress['scope']
    total_code = code_section['value'] if code_section is not None else scope['bytes']
    overall = {**measures(functions, total_code, scope['functions']), 'total_units': len(units)}
    report = {
        'version': 2,
        'measures': overall,
        'units': units,
    }
    if code_section is not None:
        report['categories'] = [{'id': TEXT_CATEGORY, 'name': TEXT_LABEL, 'measures': overall}]
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--output', type=Path, default=Path('report.json'))
    args = parser.parse_args()
    report = build_report(args.root)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, separators=(',', ':')) + '\n', encoding='utf-8')


if __name__ == '__main__':
    main()
