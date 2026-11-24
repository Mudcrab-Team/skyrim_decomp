"""Join the shape index with `data/progress.json`: groups, exemplar choice, twin candidates.

Reads only repository files plus the private index and function table. Prints counts and RVAs.
"""
import collections
import json
from pathlib import Path
import re
import subprocess

import twin_shapes as shapes
import twin_unit as U

BUILD = 'sse-steam-1-7-104'
INDEX_ROW = re.compile(r'^\| `([^`]+)` \| `?([^|`]*?)`? \((\w+)\) \| `[^`]+` / `0x([0-9a-f]+)` / (\d+) \|')


def load_progress(root):
    data = json.loads((Path(root) / 'data/progress.json').read_text())
    return {f['rva']: f for f in data['functions']}


def load_units(root):
    """{rva: unit stem} of matched functions from reconstruction/INDEX.md."""
    out = {}
    for line in (Path(root) / 'reconstruction/INDEX.md').read_text().split('\n'):
        m = INDEX_ROW.match(line)
        if m and ' matched ' in line:
            out[int(m.group(4), 16)] = m.group(1)
    return out


def load_table(path):
    """{rva: {kind, names, v2}} from the private function table."""
    table = {}
    with open(path) as handle:
        for line in handle:
            row = json.loads(line)
            table[row['rva']] = {'kind': row['kind'], 'names': row.get('names') or [],
                                 'v2': (row.get('v2') or {}).get('verdict'), 'owner': row.get('owner')}
    return table


def strong_name(names):
    """A community or vtable-slot name beyond a placeholder method of an address-library class."""
    return any(not (n.get('how') == 'placeholder' and n.get('source') == 'meh321') for n in names)


KEYS = {'strict': lambda r: (r['masked'], r['pattern']), 'loose': lambda r: (r['shape'], r['pattern'])}


def groups(index, level):
    out = collections.defaultdict(list)
    for row in index.values():
        if 'error' in row:
            continue
        out[KEYS[level](row)].append(row['rva'])
    return out


def coverage(index, progress, table, level, supported_only=False):
    mixed = covered = 0
    for members in groups(index, level).values():
        if supported_only:
            members = [m for m in members if table.get(m, {}).get('v2') == 'supported']
        matched = [m for m in members if progress.get(m, {}).get('status') == 'matched']
        rest = [m for m in members if progress.get(m, {}).get('status') != 'matched']
        if matched and rest:
            mixed += 1
            covered += len(rest)
    return {'mixed_groups': mixed, 'unmatched_covered': covered}


def open_pr_rvas(repo_slug=None, cwd=None):
    """RVAs named by the files or added header lines of open pull requests."""
    out = set()
    try:
        listing = json.loads(subprocess.run(['gh', 'pr', 'list', '--state', 'open', '--limit', '200', '--json', 'number,files'],
                                            capture_output=True, text=True, cwd=cwd, check=True).stdout)
    except (subprocess.CalledProcessError, ValueError, OSError):
        return out
    for pr in listing:
        for f in pr.get('files') or []:
            name = f['path'].rsplit('/', 1)[-1]
            out.update(int(h, 16) for h in re.findall(r'(?<![0-9a-zA-Z])([0-9a-f]{4,8})(?![0-9a-zA-Z])', name))
            out.update(int(h, 16) for h in re.findall(r'[A-Za-z_]([0-9a-f]{4,8})(?![0-9a-zA-Z])', name))
        try:
            patch = subprocess.run(['gh', 'pr', 'diff', str(pr['number']), '--patch'], capture_output=True, text=True,
                                   cwd=cwd, check=True).stdout
        except (subprocess.CalledProcessError, OSError):
            continue
        out.update(int(h, 16) for h in re.findall(r'^\+//[ \t]*0x([0-9a-fA-F]+)\b', patch, re.M))
    return out


def claim_rvas(issue_numbers, cwd=None):
    """RVAs listed in the bodies of the given claim issues."""
    out = set()
    for number in issue_numbers:
        try:
            body = json.loads(subprocess.run(['gh', 'issue', 'view', str(number), '--json', 'body'], capture_output=True,
                                             text=True, cwd=cwd, check=True).stdout)['body']
        except (subprocess.CalledProcessError, ValueError, OSError):
            continue
        out.update(int(h, 16) for h in re.findall(r'^0x([0-9a-fA-F]+)\s*$', body, re.M))
    return out


class Planner:
    def __init__(self, root, index, table, skip=(), skip_names=None, level='strict'):
        self.root = Path(root)
        self.index = index
        self.table = table
        self.progress = load_progress(root)
        self.units = load_units(root)
        self.skip = set(skip)
        self.skip_names = re.compile(skip_names) if skip_names else None
        self.level = level
        self._exemplars = {}

    def exemplar(self, rva):
        if rva not in self._exemplars:
            try:
                self._exemplars[rva] = U.load_exemplar(self.root, rva, self.units[rva])
            except (U.Unsupported, OSError, UnicodeDecodeError, KeyError) as exc:
                self._exemplars[rva] = U.Unsupported(getattr(exc, 'reason', type(exc).__name__))
        return self._exemplars[rva]

    def rank(self, ex):
        """Smaller is better: stamped first, then few functions, then small headers."""
        return (0 if U.is_stamped(ex) else 1, len(ex.functions), len(ex.header or ''), ex.rva)

    def twin_reason(self, rva):
        """None when `rva` may be stamped, else why not (a short key)."""
        row = self.table.get(rva)
        if row is None:
            return 'not-in-function-table'
        if row['kind'] != 'ordinary':
            return 'kind:' + row['kind']
        if row['v2'] == 'unsupported':
            return 'contract-unsupported'
        if strong_name(row['names']):
            return 'community-named'
        if rva in self.skip:
            return 'skipped-claim-or-open-pr'
        entry = self.progress.get(rva)
        if entry and entry['status'] == 'matched':
            return 'matched'
        if self.skip_names:
            labels = [(entry or {}).get('name') or ''] + [n.get('name') or '' for n in row['names']]
            if any(self.skip_names.search(x) for x in labels):
                return 'skipped-name'
        return None

    def run(self, probe=True):
        """(plan rows, stats). A row: {rva, exemplar, group, mode}; `probe` builds one twin per exemplar to test support."""
        stats = collections.Counter()
        plan = []
        for key, members in groups(self.index, self.level).items():
            matched = [m for m in members if self.progress.get(m, {}).get('status') == 'matched']
            rest = [m for m in members if self.progress.get(m, {}).get('status') != 'matched']
            if not (matched and rest):
                continue
            stats['mixed_groups'] += 1
            twins = []
            for t in sorted(rest):
                why = self.twin_reason(t)
                if why:
                    stats['twin-skipped:' + why] += 1
                else:
                    twins.append(t)
            if not twins:
                continue
            cands = []
            for m in matched:
                if m not in self.units:
                    stats['exemplar:no-unit'] += 1
                    continue
                ex = self.exemplar(m)
                if isinstance(ex, U.Unsupported):
                    stats['exemplar:' + ex.reason] += 1
                    continue
                cands.append(ex)
            cands.sort(key=self.rank)
            chosen, last = None, 'no-candidate'
            for ex in cands[:6]:
                if not probe:
                    chosen = ex
                    break
                try:
                    U.build(self.root, ex, twins[0])
                    chosen = ex
                    break
                except U.Unsupported as exc:
                    last = exc.reason
                except Exception as exc:  # noqa: BLE001 - a text shape this slicer does not know
                    last = 'error:' + type(exc).__name__
            if chosen is None:
                stats['groups-unsupported:' + last] += 1
                stats['twins-unsupported:' + last] += len(twins)
                continue
            stats['groups-with-exemplar'] += 1
            for t in twins:
                plan.append({'rva': t, 'exemplar': chosen.rva, 'stem': chosen.stem, 'level': self.level,
                             'mode': 'stamped' if U.is_stamped(chosen) else 'standin', 'size': self.index[t]['size']})
        stats['twins-planned'] = len(plan)
        return plan, stats
