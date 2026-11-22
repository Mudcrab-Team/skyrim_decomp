#!/usr/bin/env python3
"""Per-target PDB facts for the contributor target list, from committed data only.

    python3 tools/target_facts.py [--check]

Writes `data/target-hashes/contributor-target-facts.json`: for each function in
`contributor-targets.json` the CrashLogger PDB name, prototype and size and the symbol-alignment
proposal, when the committed data has them. It is a sidecar rather than extra fields on the
target list because the target-hash manifest pins the list's exact bytes, and a change there would
need the private image to regenerate. Needs no image and no `.local/` input, so CI can re-derive
it. The facts are name and prototype hints, never evidence of identity.
"""
import argparse
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import pdb_facts  # noqa: E402
import pdb_types  # noqa: E402

OFFERED = 'data/target-hashes/contributor-targets.json'
OUT = 'data/target-hashes/contributor-target-facts.json'
SCHEMA = 1


def build(root):
    root = Path(root)
    offered = json.loads((root / OFFERED).read_text())
    tree = pdb_types.load_tree(root)
    alignment = pdb_facts._load(root / 'data/symbol-alignment.json')
    facts = {}
    for row in offered['functions']:
        found = pdb_facts.committed_facts(root, row['rva'], tree=tree, alignment=alignment)
        entry = {}
        cl = found.get('crashlogger')
        if cl:
            entry['crashlogger'] = {k: cl[k] for k in ('name', 'convention', 'prototype', 'size', 'class', 'label')
                                    if cl.get(k) is not None}
        al = found.get('alignment')
        if al:
            entry['alignment'] = {k: al[k] for k in ('name', 'prototype', 'confidence', 'label') if al.get(k)}
        if entry:
            facts[f'0x{row["rva"]:x}'] = entry
    return {'schema': SCHEMA, 'build_id': offered['build_id'], 'targets': len(offered['functions']),
            'with_facts': len(facts), 'facts': facts}


def render(data):
    return json.dumps(data, indent=1, sort_keys=True) + '\n'


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--check', action='store_true', help='fail when the committed file differs from the derived one')
    a = p.parse_args(argv)
    text = render(build(ROOT))
    path = ROOT / OUT
    if a.check:
        if not path.is_file() or path.read_text() != text:
            print(f'{OUT} is stale; run python3 tools/target_facts.py', file=sys.stderr)
            return 1
        return 0
    path.write_text(text)
    print(f'{OUT}: {json.loads(text)["with_facts"]} of {json.loads(text)["targets"]} targets have facts')
    return 0


if __name__ == '__main__':
    sys.exit(main())
