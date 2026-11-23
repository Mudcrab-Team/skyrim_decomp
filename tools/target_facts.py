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
import claimable  # noqa: E402
import pdb_facts  # noqa: E402
import pdb_types  # noqa: E402

OFFERED = 'data/target-hashes/contributor-targets.json'
OUT = 'data/target-hashes/contributor-target-facts.json'
SCHEMA = 1
FACTS_PER_PART = 1500  # a fact entry is about 600 bytes; parts stay under the 1 MiB tracked-file cap


def build(root):
    root = Path(root)
    offered = claimable.sharded_json(root, OFFERED, 'functions')
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


def read(root):
    """The facts file with its parts merged back, as `build` returns it."""
    return claimable.sharded_json(root, OUT, 'facts')


def write(root, data):
    """Write the facts as an index and parts beside it; returns the paths written."""
    return claimable.write_sharded(root, OUT, data, 'facts', FACTS_PER_PART)


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--check', action='store_true', help='fail when the committed files differ from the derived ones')
    a = p.parse_args(argv)
    data = build(ROOT)
    if a.check:
        try:
            current = read(ROOT)
        except (OSError, ValueError, KeyError):
            current = None
        if current != data:
            print(f'{OUT} is stale; run python3 tools/target_facts.py', file=sys.stderr)
            return 1
        return 0
    write(ROOT, data)
    print(f'{OUT}: {data["with_facts"]} of {data["targets"]} targets have facts')
    return 0


if __name__ == '__main__':
    sys.exit(main())
