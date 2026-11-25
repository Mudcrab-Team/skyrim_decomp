#!/usr/bin/env python3
"""Advisory PR compilation using trusted base tools and target-hash commitments only.

Never run PR tools or resulting objects. Compiler output remains in scratch. No image input,
acceptance record, network credential, artifact upload or cache is part of this check.
"""
import argparse
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import record_store
import ci_hash_check as public
import contrib
import draft_bundle
import giveup
import pdb_types
import lint_reconstruction as lint
import compare
from pecoff import CoffObject, Reject
from rva_headers import claimed_rvas
from source_digest import include_closure
import digest_v2
from digest_v2 import tu_digest
import target_hashes as hashes
import unit_deletion

DEFAULT_RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
# Optional source-header request for a new unit with no accepted symbol binding yet. It is a
# claim about which public target to try, never evidence of identity or acceptance.
# Horizontal whitespace after the colon is optional: a hint typed without it must still bind
# rather than fail the whole unit.
REQUEST = re.compile(r'^// CI hash:[ \t]*(0x[0-9a-fA-F]+)[ \t]+(\S+)\s*$', re.M)
SHA = re.compile(r'[0-9a-f]{40}')
UNIT_RECIPE = re.compile(r'\breconstruction/recipes/[a-zA-Z0-9_.-]+\.json')
# A header can claim any number of RVAs; each claim costs a scan of the unit's object.
MAX_CLAIMS_PER_UNIT = 2000
# Same pattern as cookbook_notes.NOTE_FILE (a test keeps them equal); that module pulls in POSIX-only imports
# that this job's Windows runner cannot load.
NOTE_FILE = re.compile(r'docs/cookbook-notes/[0-9a-f]{3,8}-[a-z0-9][a-z0-9-]{0,60}\.md\Z')
CI_INPUTS = ('data/target-hashes/', 'tools/toolchain/', 'tools/ci_',
             'tools/target_hashes.py', 'tools/contrib.py', 'tools/contributor_standing.py',
             'tools/build_leaderboard.py', 'tools/build_model_trend.py', '.gitattributes',
             '.github/workflows/ci-target-hash.yml')


# Files an owner PR carries beside its units (match records, inventory, generated images and index). The hash job
# reads none of them as source: it neither compiles nor trusts them, and the scope job judges their presence.
CARRIED_RECORD = re.compile(r'reports/[^/]+/0x(?P<rva>[0-9a-f]+)\.json')
CARRIED = re.compile(r'reports/[^/]+/0x[0-9a-f]+(?:\.review)?\.json|data/progress\.json|docs/progress(?:-map)?\.svg'
                     r'|reconstruction/INDEX\.md')


def git(root, *args):
    return subprocess.run(['git', *args], cwd=root, capture_output=True, check=True).stdout


def trusted_inputs(root):
    manifest = hashes.load_manifest(root)
    return dict(manifest_sha256=hashes.digest((root / hashes.MANIFEST).read_bytes()),
                normalizer_sha256=manifest['normalizer_sha256'],
                comparator_sha256=manifest['comparator_sha256'],
                compiler_pins_sha256=hashes.digest((root / 'tools/verifier/pinned.sha256').read_bytes()))


def comment_only_change(root, base, name, blob):
    """Whether head's `blob` equals the base file at `name` once prose comments are removed.

    Provenance comments stay in the compared text, and anything the comment scan cannot classify
    counts as a real change, so this can only skip a compile whose result cannot differ.
    """
    old = subprocess.run(['git', '-C', str(root), 'show', f'{base}:{name}'], capture_output=True)
    if old.returncode != 0:
        return False
    def requests(text):
        return REQUEST.findall(text.decode('utf-8-sig', 'replace')[:8192])

    # A `// CI hash:` line is a request to compare, not prose: stripping it as a comment would let a PR that
    # only adds the request skip the very compile the request asks for.
    if requests(old.stdout) != requests(blob):
        return False
    try:
        return digest_v2.strip_comments(old.stdout, name) == digest_v2.strip_comments(blob, name)
    except ValueError:
        return False


def base_text(root, rev, name):
    shown = subprocess.run(['git', '-C', str(root), 'show', f'{rev}:{name}'], capture_output=True)
    return shown.stdout.decode('utf-8-sig', 'replace') if shown.returncode == 0 else None


class LintFailure(ValueError):
    """The changed units fail the source lint; `findings` are the lint's own file:line messages."""

    def __init__(self, findings):
        super().__init__('contributor source lint failed')
        self.findings = findings


def prepare(root, base, head, work):
    if not SHA.fullmatch(base) or not SHA.fullmatch(head):
        raise ValueError('revision must be a full SHA')
    if git(root, 'rev-parse', 'HEAD').decode().strip() != base:
        raise ValueError('tools must be from the trusted base revision')
    merge_base = git(root, 'merge-base', base, head).decode().strip()
    diff = git(root, 'diff', '--no-renames', '--name-status', '-z', merge_base, head).split(b'\0')
    rows, comment_only, deleted, carried = [], set(), [], []
    # Generated CrashLogger PDB output and lesson notes are neither units nor read by this job: never compiled.
    # A lesson note is a file a function PR may carry (the scope check admits it), so it must not fail intake.
    names = [n for i in range(0, len(diff) - 1, 2)
             if not (pdb_types.is_generated(n := diff[i + 1].decode('utf-8')) or CARRIED.fullmatch(n)
                     or NOTE_FILE.fullmatch(n) or giveup.RECORD_FILE.fullmatch(n) or draft_bundle.owner(n))]
    if names and not any(contrib.UNIT_PATH.fullmatch(n) for n in names):
        # No unit file at all (tooling, docs or data): nothing of the PR is read or compiled, and the
        # trusted-base sample runs instead, as for a PR that changes only CI inputs.
        return root, []
    for i in range(0, len(diff) - 1, 2):
        status, name = diff[i].decode('ascii'), diff[i + 1].decode('utf-8')
        if (pdb_types.is_generated(name) or NOTE_FILE.fullmatch(name) or giveup.RECORD_FILE.fullmatch(name)
                or draft_bundle.owner(name)):
            continue
        if CARRIED.fullmatch(name):
            carried.append(name)
            continue
        if not contrib.UNIT_PATH.fullmatch(name):
            if name.startswith(CI_INPUTS):
                continue  # Never read or execute PR tooling; test trusted base references instead.
            raise ValueError('outside contributor intake scope')
        if status == 'D':
            deleted.append(name)
            continue
        if status not in ('A', 'M'):
            raise ValueError('outside contributor intake scope')
        # Read only bounded, regular source blobs. Never follow a PR symlink or check out head.
        meta = git(root, 'ls-tree', head, '--', name).decode().split()
        if len(meta) < 3 or meta[0] != '100644' or meta[1] != 'blob':
            raise ValueError('source is not a regular file')
        size = int(git(root, 'cat-file', '-s', meta[2]))
        if size > contrib.MAX_UNIT_FILE_BYTES:
            raise ValueError('source exceeds contributor file cap')
        blob = git(root, 'cat-file', 'blob', meta[2])
        if b'\0' in blob:
            raise ValueError('source is not text')
        blob.decode('utf-8-sig')
        rows.append((name, blob))
        if status == 'M' and comment_only_change(root, merge_base, name, blob):
            comment_only.add(name)
    if deleted:
        def head_file(path):
            # Only what the PR itself carries is read from its head; everything else is the trusted base's.
            if path not in carried:
                return None
            shown = subprocess.run(['git', '-C', str(root), 'show', f'{head}:{path}'], capture_output=True)
            return shown.stdout.decode('utf-8-sig', 'replace') if shown.returncode == 0 else None
        found = unit_deletion.problems(root, deleted, lambda n: base_text(root, merge_base, n),
                                       lambda n: bool(git(root, 'ls-tree', head, '--', n).strip()), head_file)
        if found:
            raise ValueError('unit deletion would orphan an accepted function: ' + '; '.join(found))
    if not rows:
        return root, []
    tree = work / 'source'
    tree.mkdir(parents=True)
    for name in ('reconstruction', 'builds', 'findings', 'reports'):
        shutil.copytree(root / name, tree / name, symlinks=False)
    target = json.loads((root / 'builds/target.json').read_text())['build_id']
    for name, blob in rows:
        path = tree / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(blob)
    found = [line for name, _blob in rows for line in lint.lint_file(tree, name, target)]
    if found:
        raise LintFailure(found)
    # A file whose text differs from base only in comments (digest_v2.strip_comments) compiles to the
    # same code, so it asks for no compile of its own; it is still linted and still in the tree above.
    return tree, [name for name, _ in rows if name not in comment_only]


def rebound_units(root, base, head):
    """{rva: unit} for match records the PR carries, from the head's own record files.

    A PR that moves a function's definition and carries the rebound record must not be held to the base binding
    to the unit it left: that unit no longer defines the function, which is not a regression of it.
    """
    merge_base = git(root, 'merge-base', base, head).decode().strip()
    out = {}
    for name in git(root, 'diff', '--name-only', '-z', merge_base, head).decode().split('\0'):
        match = CARRIED_RECORD.fullmatch(name)
        if not match:
            continue
        shown = subprocess.run(['git', '-C', str(root), 'show', f'{head}:{name}'], capture_output=True)
        try:
            unit = (json.loads(shown.stdout).get('source') or {}).get('compiled')
        except ValueError:
            continue
        if shown.returncode == 0 and isinstance(unit, str):
            out[int(match['rva'], 16)] = unit
    return out


def without_rebound(known, rebound):
    """`known` bindings minus the entries whose carried record binds another unit."""
    return {unit: [e for e in entries if rebound.get(e['rva'], unit) == unit] for unit, entries in known.items()}


def bindings(root):
    """Only public main records provide existing symbol/recipe bindings."""
    inventory = json.loads((root / 'data/progress.json').read_text())
    result = {}
    for fn in inventory['functions']:
        if not fn.get('report') or not record_store.is_file(root / fn['report']):
            continue
        record = json.loads(record_store.read_text(root / fn['report']))
        if not record.get('source', {}).get('compiled') or not record.get('runs'):
            continue
        report = record['runs'][0]['report']
        # Contract v3 internal selectors require more than a bare symbol; report no-target.
        if report.get('contract_version') != 2:
            continue
        result.setdefault(record['source']['compiled'], []).append(
            dict(rva=fn['rva'], symbol=report['function']['symbol'], recipe=record['recipe']['path']))
    return result


def requests(tree, changed, known):
    from check_source_digest import include_closure as cached_closure, source_digest_cache
    import revision_cache
    tree = Path(tree)
    key = None
    # Scratch CI trees have no git metadata; scoped resolution still avoids repeated directory scans.
    if (tree / '.git').exists():
        key = revision_cache.snapshot(tree)
    index = revision_cache.read(tree, 'include-index', key) if key else None
    if index is None:
        index = {}
        with source_digest_cache():
            for path in sorted((tree / 'reconstruction').rglob('*.cpp')):
                unit = path.relative_to(tree).as_posix()
                for name in cached_closure(tree, unit):
                    index.setdefault(name, []).append(unit)
        if key and revision_cache.snapshot(tree) == key:
            revision_cache.save(tree, 'include-index', key, index)
    units = {name for name in changed if name.endswith('.cpp')}
    for name in changed:
        units.update(index.get(name, []))
    result = []
    for unit in sorted(units):
        unit_text = (tree / unit).read_text(encoding='utf-8-sig')
        declared = UNIT_RECIPE.search(unit_text)
        entries = {r['rva']: dict(r) for r in known.get(unit, [])}
        # The first host compiles the whole unit with the recipe the unit declares, or the default one when
        # it declares none; an accepted function's older recorded recipe would give a second-host row whose
        # recipe the record cannot bind.
        for entry in entries.values():
            entry['recipe'] = declared[0] if declared else DEFAULT_RECIPE
        # New source may request an RVA/symbol, but cannot select the target mask, size or recipe.
        for rva, symbol in REQUEST.findall((tree / unit).read_text(encoding='utf-8-sig')[:8192]):
            value = int(rva, 16)
            if value not in entries:
                entries[value] = dict(rva=value, symbol=symbol, recipe=DEFAULT_RECIPE)
        # A new function has no accepted record to name its symbol. Its header claims the RVA and
        # the object is searched for the function whose hash equals that published target, so the
        # symbol is found by the comparison, never taken from the PR.
        recipe = (UNIT_RECIPE.search((tree / unit).read_text(encoding='utf-8-sig')) or [DEFAULT_RECIPE])[0]
        stem = unit.rsplit('.', 1)[0]
        texts = [(tree / (stem + ext)).read_text(encoding='utf-8-sig') for ext in ('.h', '.cpp')
                 if (tree / (stem + ext)).is_file()]
        for value in sorted(claimed_rvas(texts))[:MAX_CLAIMS_PER_UNIT]:
            entries.setdefault(value, dict(rva=value, symbol=None, recipe=recipe))
        if not entries:
            result.append(dict(unit=unit, rva=None, symbol=None, recipe=DEFAULT_RECIPE))
        else:
            result += [dict(unit=unit, **r) for r in entries.values()]
    return result


def matching_symbols(blob, target):
    """Names of the object's functions whose normalized hash and layout equal the published target.

    Only sections of the target's size are hashed. The validator requires the first host's symbol
    to be among these names, so a small function that shares bytes with another cannot stand in.
    """
    obj = CoffObject(blob)
    names = set()
    for sym in obj.symbols.values():
        if sym.section > 0 and sym.storage == compare.STORAGE_EXTERNAL:
            sec = obj.section(sym.section)
            if sec.data is not None and len(sec.data) == target['size']:
                names.add(sym.name)
    found = []
    for name in sorted(names):
        try:
            if hashes.candidate(blob, name, target) == 'hash-match':
                found.append(name)
        except (ValueError, Reject):
            continue
    return found


def defines(blob, name):
    """Whether the object defines `name` in one of its sections."""
    try:
        return any(sym.name == name and sym.section > 0 for sym in CoffObject(blob).symbols.values())
    except Reject:
        return False


def compile_requests(root, tree, requests_, bindir, work, manifest):
    ctx = contrib.Ctx(repo=root, platform='win32', interactive=False)
    tool = dict(status='ok', flavour='native', bin=str(bindir), root=str(bindir.parents[6]))
    targets = {row['rva']: row for row in manifest['functions']}
    built = {}
    rows = []
    for ref in requests_:
        target = targets.get(ref['rva'])
        row = dict(rva=hex(ref['rva']) if ref['rva'] is not None else None, unit=ref['unit'],
                   result='no-target')
        if ref['recipe'] not in manifest['recipe_sha256']:
            rows.append(row)
            continue
        key = ref['unit'], ref['recipe']
        if key not in built:
            try:
                recipe = json.loads((root / ref['recipe']).read_text())
                _, includes = contrib.sdk_include_dirs(ctx, tool['root'], recipe['sdk'])
                if not includes or includes[0].parent.name != recipe['sdk']:
                    raise ValueError('pinned SDK missing')
                built[key] = contrib.compile_unit(ctx, tree, ref['unit'], ref['recipe'],
                                                work / str(len(built)), tool)['object'].read_bytes()
            except (ValueError, OSError, Reject, contrib.Stop, subprocess.TimeoutExpired):
                built[key] = None
        if built[key] is None:
            row['result'], row['reason'] = 'mismatch', 'compile-failed'
        elif target is None or (ref['symbol'] is None and ref['rva'] is None) \
                or target['extraction'] == 'unmasked-unsupported':
            row['reason'] = 'published-target-or-binding-unavailable'
        else:
            try:
                # A record's or request line's decorated name goes stale when the declaration changes
                # (a void return made bool, a parameter retyped); the function is then found by its
                # hash like a header-claimed one, never by the stale name.
                if ref['symbol'] is None or not defines(built[key], ref['symbol']):
                    symbols = matching_symbols(built[key], target)
                    row['result'] = 'hash-match' if symbols else 'mismatch'
                    if not symbols:
                        row['reason'] = 'no-matching-function'
                else:
                    row['result'] = hashes.candidate(built[key], ref['symbol'], target)
                    symbols = [ref['symbol']]
                if row['result'] == 'hash-match':
                    row['symbols'] = symbols
                row['source_sha256'] = tu_digest(tree, include_closure(tree, ref['unit']))
                row['recipe_sha256'] = hashes.digest((root / ref['recipe']).read_bytes())
            except (ValueError, Reject):
                row['result'], row['reason'] = 'no-target', 'unsupported-object-layout'
        rows.append(row)
    return rows


def sample(root, bindir, work, manifest):
    rvas = json.loads((root / 'data/target-hashes/determinism-sample.json').read_text())['rvas']
    refs = [dict(public.reference(root, rva), rva=rva) for rva in rvas]
    requests_ = [dict(unit=r['unit'], rva=r['rva'], symbol=r['symbol'], recipe=r['recipe']) for r in refs]
    first = compile_requests(root, root, requests_, bindir, work / 'first', manifest)
    second = compile_requests(root, root, requests_, bindir, work / 'second', manifest)
    return [dict(row, deterministic=row['result'] == other['result'] == 'hash-match')
            for row, other in zip(first, second)]


def classify(head_rows, base_rows):
    """Label each head row against the same unit/RVA compiled from the base tree.

    Only `regressed` (hash-match at base, no match at head) may block; debt that already failed
    at base and functions that are new in the PR are reported, not enforced.
    """
    base = {(r['unit'], r['rva']): r['result'] for r in base_rows}
    rows = []
    for row in head_rows:
        before = base.get((row['unit'], row['rva']))
        if row['result'] == 'hash-match':
            status = 'pass'
        elif row['result'] == 'no-target':
            status = 'unverified'
        elif before == 'hash-match':
            status = 'regressed'
        elif before == 'mismatch':
            status = 'preexisting-fail'
        else:
            status = 'fail'
        rows.append(dict(row, status=status, base=before))
    return rows


def regress(root, tree, refs, bindir, work, manifest):
    head = compile_requests(root, tree, refs, bindir, work / 'head', manifest)
    # Units absent from the base tree are new; compiling them there would only add noise.
    old = [r for r in refs if (root / r['unit']).is_file()]
    base = compile_requests(root, root, old, bindir, work / 'base', manifest) if old else []
    return classify(head, base)


def summary_text(report):
    lines = ['Advisory target hash results; acceptance not evaluated. The current acceptance rule',
             'still requires its independent hosts and Reviewer. Hash equality omits reference identity.',
             '', '| Function RVA | Unit | Result |', '| --- | --- | --- |']
    for row in report.get('functions', []):
        result = {'hash-match': 'PASS (hash only)', 'mismatch': 'FAIL', 'no-target': 'UNVERIFIED'}.get(row['result'], 'ERROR')
        if row.get('status'):
            result = row['status'].upper()
        lines.append(f'| {row["rva"] or "unbound"} | {row["unit"]} | {result} |')
    if report.get('error'):
        lines += ['', 'Check could not complete: ' + report['error'] + '. No strike.']
        # The contributor reads this summary; without the lint's own words a bare error name gives no fix.
        lines += [f'- {finding}' for finding in report.get('findings', [])]
    return '\n'.join(lines) + '\n'


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('command', choices=('prepare', 'check', 'regress', 'sample'))
    p.add_argument('--base')
    p.add_argument('--head')
    p.add_argument('--bin', type=Path)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    p.add_argument('--map-out', type=Path, help='regress: write {rva-or-unit: status} for the PR bot')
    a = p.parse_args(argv)
    report = dict(schema=1, kind='target-hash-check', head_sha=a.head,
                  base_sha=a.base, normalization_version=hashes.VERSION, acceptance='not-evaluated')
    try:
        a.work.mkdir(parents=True, exist_ok=True)
        report.update(trusted_inputs(ROOT))
        manifest = hashes.load_manifest(ROOT)
        if a.command == 'prepare':
            tree, changed = prepare(ROOT, a.base, a.head, a.work)
            refs = requests(tree, changed, without_rebound(bindings(ROOT), rebound_units(ROOT, a.base, a.head)))
            (a.work / 'requests.json').write_text(json.dumps(refs))
            report['intake'] = 'pass'
            report['requested_functions'] = len(refs)
            if os.environ.get('GITHUB_OUTPUT'):
                with open(os.environ['GITHUB_OUTPUT'], 'a') as out:
                    out.write('mode=' + ('check' if changed else 'sample') + '\n')
        else:
            if not a.bin or public.probe(ROOT, a.bin)['toolset'] != 'MATCH':
                raise ValueError('compiler pin mismatch')
            report['toolset'] = 'MATCH'
            if a.command == 'sample':
                report['functions'] = sample(ROOT, a.bin, a.work, manifest)
            elif a.command == 'regress':
                refs = json.loads((a.work / 'requests.json').read_text())
                report['functions'] = regress(ROOT, a.work / 'source', refs, a.bin, a.work / 'objects', manifest)
                if a.map_out:
                    a.map_out.parent.mkdir(parents=True, exist_ok=True)
                    a.map_out.write_text(json.dumps({r['rva'] or r['unit']: r['status'] for r in report['functions']},
                                                    indent=2, sort_keys=True) + '\n')
            else:
                refs = json.loads((a.work / 'requests.json').read_text())
                report['functions'] = compile_requests(ROOT, a.work / 'source', refs, a.bin,
                                                       a.work / 'objects', manifest)
    except (ValueError, OSError, KeyError, StopIteration, Reject, contrib.Stop,
            subprocess.CalledProcessError, subprocess.TimeoutExpired) as exc:
        report['error'] = type(exc).__name__
        if isinstance(exc, LintFailure):
            report['findings'] = exc.findings
    a.out.parent.mkdir(parents=True, exist_ok=True)
    a.out.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))
    if os.environ.get('GITHUB_STEP_SUMMARY'):
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'a') as summary:
            summary.write(summary_text(report))
    if a.command == 'regress':
        return int('error' in report or any(r['status'] == 'regressed' for r in report.get('functions', [])))
    return int('error' in report or any(r['result'] == 'mismatch' for r in report.get('functions', []))
               or (a.command == 'sample' and any(not r['deterministic'] for r in report['functions'])))


if __name__ == '__main__':
    sys.exit(main())
