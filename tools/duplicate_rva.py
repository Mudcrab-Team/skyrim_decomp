"""Find RVAs that more than one reconstruction unit names in its `// 0x<rva> <Name>` marker block.

A function's accepted record binds exactly one unit. A second unit that carries the same marker is
either a stale label or a second definition of the same function, and both mislead the unit index
and the review packets. Tooling only: it reads the tree and never compares game bytes.

    python3 tools/duplicate_rva.py            # print each duplicated RVA and its units
    python3 tools/duplicate_rva.py --count    # print only the number of duplicated RVAs
"""
import argparse
import collections
import os
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
MARKER = re.compile(r'^// 0x([0-9a-fA-F]+) ', re.M)
# Generated declarations are not reconstructed units (docs/code-rules.md).
SKIPPED = ('generated',)


def duplicates(root=ROOT):
    """{rva: [unit path, ...]} for every RVA marked in more than one distinct .cpp file."""
    root = Path(root)
    seen = collections.defaultdict(set)
    base = root / 'reconstruction'
    for folder, dirs, files in os.walk(base):
        dirs[:] = [d for d in dirs if d not in SKIPPED]
        for name in files:
            if not name.endswith('.cpp'):
                continue
            path = Path(folder) / name
            text = path.read_text(encoding='utf-8', errors='replace')
            for m in MARKER.finditer(text):
                seen[int(m.group(1), 16)].add(path.relative_to(root).as_posix())
    return {rva: sorted(units) for rva, units in sorted(seen.items()) if len(units) > 1}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--count', action='store_true')
    args = parser.parse_args(argv)
    found = duplicates()
    if args.count:
        print(len(found))
        return 0
    for rva, units in found.items():
        print(f'0x{rva:x}: ' + ', '.join(units))
    print(f'{len(found)} duplicated RVAs', file=sys.stderr)
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main())
