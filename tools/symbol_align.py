"""Propose names for unnamed inventory functions from the order of a sibling build's linker map. Local input.

A linker map lists functions in address order, and the functions of one object file are
contiguous. The pinned image was built from largely the same sources, so inside one object file
the order of member functions is usually the same. Where two functions the inventory already
names are also in the map, and the inventory holds exactly as many functions between them as
the map holds between the two map entries, the unnamed ones are paired by position.

The map is read locally and never by CI (the tool refuses to run when `CI` is set). What it writes
(`data/symbol-alignment.json`) is derived data only: an inventory RVA, a proposed `Class::Method`,
a prototype, a confidence tier, the object file and the source key. It holds no map address and no
excerpt. A proposal is a hint labelled `SYMBOLS(tesv-2013-map)`; a byte match stays the only
acceptance (`docs/authorizations.md`, Notes).

    python3 tools/symbol_align.py --map PATH [--holdout N]
    python3 tools/symbol_align.py --map PATH --write

`--holdout N` hides the name of N sampled named functions one at a time and reports how often the
alignment gives the name back, per confidence tier. Prototypes come from `llvm-undname` when it is
on PATH (or given with `--undname`).
"""
import argparse
import bisect
import json
import os
import random
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from check_code_rules import PLACEHOLDERS  # noqa: E402

OUTPUT = 'data/symbol-alignment.json'
SOURCE = 'tesv-2013-map'
SCHEMA_VERSION = 1
MAP_LINE = re.compile(r'^ [0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+[0-9a-fA-F]{8,16}( f)?( i)?\s+(\S+)\s*$')
SCOPES = re.compile(r'^\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@')
SPECIAL = re.compile(r'^\?\?([01])((?:[A-Za-z_]\w*@)+)@')


def is_placeholder(name):
    return not name or any(rx.search(name) for rx in PLACEHOLDERS)


def member_of(decorated):
    """(qualified class, method) for a plain member function or constructor/destructor, else None."""
    m = SCOPES.match(decorated)
    if m:
        method = m.group(1)
    else:
        m = SPECIAL.match(decorated)
        if not m:
            return None
        method = None
    scopes = m.group(2).rstrip('@').split('@')
    cls = '::'.join(reversed(scopes))
    if method is None:
        base = scopes[0]
        method = base if m.group(1) == '0' else '~' + base
    return cls, method


def parse_map(lines, inline=True):
    """Function entries in address order as (decorated name, object file); the addresses are dropped.

    inline=False keeps only functions that are not inline duplicates."""
    entries = []
    for line in lines:
        m = MAP_LINE.match(line)
        if not m or not m.group(2):
            continue
        if m.group(3) and not inline:
            continue
        entries.append((m.group(1), m.group(4)))
    return entries


def split_name(name):
    """(class, method) of an inventory `Class::Method` name; the class keeps its own scopes."""
    if not name or '::' not in name:
        return None
    cls, _, method = name.rpartition('::')
    return cls, method


class Aligner:
    """Holds the map sequence and the inventory so one target can be proposed at a time."""

    def __init__(self, entries, inventory):
        # inventory: list of (rva, name) in any order
        self.entries = entries
        self.members = [member_of(d) for d, _ in entries]
        self.by_member = {}
        for index, member in enumerate(self.members):
            if member:
                self.by_member.setdefault(member, []).append(index)
        self.rvas = sorted(r for r, _ in inventory)
        self.position = {r: i for i, r in enumerate(self.rvas)}
        self.names = dict(inventory)
        self.anchor_index = {}
        for rva, name in inventory:
            if is_placeholder(name):
                continue
            parts = split_name(name)
            if not parts:
                continue
            cls, method = parts
            hits = None
            # Inventory classes may omit the namespace the map carries.
            for (mcls, mmethod), idx in self._candidates(method):
                if mmethod == method and (mcls == cls or mcls.endswith('::' + cls)):
                    hits = (idx if hits is None else hits + idx)
            if hits and len(hits) == 1:
                self.anchor_index[rva] = hits[0]
        self.anchor_rvas = sorted(self.anchor_index)

    def _candidates(self, method):
        cache = self.__dict__.setdefault('_by_method', None)
        if cache is None:
            cache = {}
            for key, idx in self.by_member.items():
                cache.setdefault(key[1], []).append((key, idx))
            self._by_method = cache
        return cache.get(method, ())

    def propose(self, rva, hide=False):
        """(map index, tier, gap) for an unnamed `rva`, or None.

        hide=True treats a named function as unnamed so a name can be checked against the map."""
        i = bisect.bisect_left(self.anchor_rvas, rva)
        j = i + 1 if (i < len(self.anchor_rvas) and self.anchor_rvas[i] == rva) else i
        if i == 0 or j >= len(self.anchor_rvas):
            return None
        before, after = self.anchor_rvas[i - 1], self.anchor_rvas[j]
        a, b = self.anchor_index[before], self.anchor_index[after]
        if b <= a or self.entries[a][1] != self.entries[b][1]:
            return None
        gap = self.position[after] - self.position[before] - 1
        if gap != b - a - 1:
            return None
        offset = self.position[rva] - self.position[before]
        index = a + offset
        if not self.members[index]:
            return None
        tier = 'high' if gap <= 2 else 'medium' if gap <= 6 else 'low'
        return index, tier, gap


def undname_all(decorated, tool):
    """Prototype text for each decorated name; '' where the tool gives none."""
    if not decorated:
        return []
    out = subprocess.run([tool], input='\n'.join(decorated) + '\n', capture_output=True, text=True, check=False)
    # llvm-undname echoes each input line before its result.
    lines = [ln for ln in out.stdout.split('\n') if ln.strip()]
    if len(lines) != 2 * len(decorated):
        return [''] * len(decorated)
    return [lines[2 * i + 1] if lines[2 * i] == d else '' for i, d in enumerate(decorated)]


def variants(lines):
    """Two readings of the map: with and without the inline duplicates. Which one matches the pinned
    image's own count of functions between two anchors differs by object file."""
    lines = list(lines)
    return [parse_map(lines, inline=True), parse_map(lines, inline=False)]


def propose_any(aligners, rva, hide=False):
    """(decorated name, object, tier, gap) when the readings that answer agree on the name, else None."""
    hits = []
    for aligner in aligners:
        hit = aligner.propose(rva, hide=hide)
        if hit:
            index, tier, gap = hit
            hits.append((aligner.entries[index][0], aligner.entries[index][1], tier, gap, aligner.members[index]))
    if not hits or len({h[4] for h in hits}) != 1:
        return None
    return hits[0][:4] + (hits[0][4],)


def build(entry_sets, inventory, tool=None):
    aligners = [Aligner(e, inventory) for e in entry_sets]
    found = []
    for rva, name in inventory:
        if is_placeholder(name):
            hit = propose_any(aligners, rva)
            if hit:
                found.append((rva, hit))
    found.sort()
    protos = undname_all([h[0] for _, h in found], tool) if tool else [''] * len(found)
    functions = {}
    for (rva, (_dec, obj, tier, _gap, (cls, method))), proto in zip(found, protos):
        functions[f'0x{rva:x}'] = {
            'name': f'{cls}::{method}',
            'prototype': proto,
            'confidence': tier,
            'object': re.split(r'[:\\/]', obj)[-1],
            'source': SOURCE,
        }
    return aligners, functions


def holdout(aligners, sample, seed=1):
    """Per tier: [right, wrong] when each sampled named anchor is hidden and re-proposed."""
    rng = random.Random(seed)
    pool = list(aligners[0].anchor_rvas)
    rng.shuffle(pool)
    stats = {}
    for rva in pool[:sample]:
        hit = propose_any(aligners, rva, hide=True)
        if not hit:
            stats.setdefault('none', [0, 0])[1] += 1
            continue
        _dec, _obj, tier, _gap, member = hit
        right = member == aligners[0].members[aligners[0].anchor_index[rva]]
        stats.setdefault(tier, [0, 0])[0 if right else 1] += 1
    return stats


def load_inventory(path):
    data = json.loads(Path(path).read_text())
    return [(f['rva'], f.get('name') or '') for f in data['functions']]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--map', required=True)
    ap.add_argument('--progress', default=str(ROOT / 'data/progress.json'))
    ap.add_argument('--undname', default=shutil.which('llvm-undname') or '/opt/homebrew/opt/llvm/bin/llvm-undname')
    ap.add_argument('--holdout', type=int, default=0)
    ap.add_argument('--write', action='store_true')
    args = ap.parse_args(argv)
    if os.environ.get('CI'):
        print('symbol_align reads a local symbol file and must not run in CI', file=sys.stderr)
        return 2
    path = Path(args.map).resolve()
    if ROOT in path.parents:
        print('refusing a symbol file inside the repository', file=sys.stderr)
        return 2
    with open(path, encoding='latin-1') as handle:
        entry_sets = variants(handle)
    inventory = load_inventory(args.progress)
    tool = args.undname if Path(args.undname).exists() else None
    aligners, functions = build(entry_sets, inventory, tool)
    tiers = {}
    for f in functions.values():
        tiers[f['confidence']] = tiers.get(f['confidence'], 0) + 1
    placeholders = sum(1 for _, n in inventory if is_placeholder(n))
    print(f'inventory {len(inventory)}, placeholders {placeholders}, anchors {len(aligners[0].anchor_rvas)}, '
          f'proposed {len(functions)} {tiers}')
    if args.holdout:
        print('holdout [right, wrong] per tier:', holdout(aligners, args.holdout))
    if args.write:
        doc = {
            'schema_version': SCHEMA_VERSION,
            'note': 'Names proposed by aligning the function order of a sibling-build linker map with the inventory. '
                    'Hints labelled SYMBOLS(tesv-2013-map); not evidence of identity. See tools/symbol_align.py.',
            'source': SOURCE,
            'functions': functions,
        }
        (ROOT / OUTPUT).write_text(json.dumps(doc, indent=1, sort_keys=True) + '\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
