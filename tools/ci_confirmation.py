"""Public, fail-closed bindings for the p148 CI second-host exception.

No comparator report is synthesized. The local full comparison remains verbatim; CI commits
all non-debug COFF content and independently checks the public normalized target commitment.
"""
import hashlib
import json
import re
import subprocess
from pathlib import Path

import compare
from pecoff import CoffObject
import target_hashes
from digest_v2 import run_revision

WORKFLOW = '.github/workflows/ci-confirm.yml'
PR_WORKFLOW = '.github/workflows/pr-check.yml'
PR_JOB = 'hash'
CI_HOST = dict(host_id='github-windows-native', machine='github-hosted-windows', loader='native', os='windows')
TOOLS = (WORKFLOW, 'tools/ci_confirm_batch.py', 'tools/ci_confirmation.py',
         'tools/ci_toolchain.py', 'tools/ci_hash_check.py', 'tools/lint_reconstruction.py',
         'tools/target_hashes.py', 'tools/pecoff.py', 'tools/contrib.py', 'tools/source_digest.py',
         'tools/verifier/unit_build.py', 'tools/compare_internal.py', 'tools/compare_runtime.py')


def sha(blob):
    return hashlib.sha256(blob).hexdigest()


def tools_digest(root):
    return sha(b''.join(name.encode() + b'\0' + (root / name).read_bytes() for name in TOOLS))


def tools_digest_at(root, rev):
    try:
        return sha(b"".join(name.encode() + b"\0" + subprocess.run(
            ["git", "-C", str(root), "show", f"{rev}:{name}"],
            check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE).stdout for name in TOOLS))
    except subprocess.CalledProcessError as exc:
        raise ValueError("CI confirmation: CI tools revision unavailable") from exc


def content_digest(blob):
    """Whole non-debug object content, including relocation identities and EH/unwind data.

    COFF timestamps, symbol-table indices and debug/path records are immaterial to execution.
    Section order, flags, zero-fill sizes, all other bytes, and every symbol/relocation binding
    remain committed. A relocation into an excluded section is refused.
    """
    obj = CoffObject(blob)
    sections = [s for s in obj.sections if not (s.name.startswith('.debug$') or s.name == '.chks64')]
    indices = {s.index: i + 1 for i, s in enumerate(sections)}
    def symbol(s):
        if s.section > 0 and s.section not in indices:
            raise ValueError('non-debug content refers to debug section')
        return [s.name, s.value, indices.get(s.section, s.section), s.kind, s.storage]
    rows = []
    for sec in sections:
        rows.append([sec.name, sec.flags, sec.vsize, sec.raw_size,
                     sha(sec.data) if sec.data is not None else None,
                     sorted([r.offset, r.kind, symbol(obj.symbols[r.symbol])] for r in sec.relocs)])
    symbols = sorted(symbol(s) for s in obj.symbols.values()
                     if s.section >= 0 and (s.section == 0 or s.section in indices))
    return sha(b'coff-content-sha256-v1\0' + json.dumps([rows, symbols], sort_keys=True).encode())


def require(value, reason):
    if not value:
        raise ValueError('CI confirmation: ' + reason)


def first_host_check(record, c):
    """The comparator runs must come from one machine that is independent of the CI host."""
    first = c.get('first_host')
    if first is None:  # Existing Mac attestations keep their original identity and field names.
        first = dict(host_id='mac-wine', machine='maintainer-mac', loader='wine', os='macos')
    require(isinstance(first, dict) and isinstance(first.get('host_id'), str)
            and isinstance(first.get('machine'), str) and bool(first['machine'])
            and first['host_id'] != c['host_id'] and first['machine'] != c['machine'],
            'first host is not an independent machine')
    require((first.get('loader'), first.get('os')) in {('wine', 'macos'), ('wine', 'linux'), ('native', 'windows')},
            'first host loader/OS differs')
    runs = record['runs']
    require({r['compiled_on'] for r in runs} == {first['host_id']}
            and {r['compared_on'] for r in runs} == {first['host_id']}, 'first host differs from comparator runs')


def is_sha(value):
    return isinstance(value, str) and re.fullmatch('[0-9a-f]{40}', value) is not None


def pr_check_evidence(root, run, report, row, map_status, first_host):
    """The record's `ci_confirmation` from one pr-check.yml `hash` run.

    `run` is what the GitHub API says about the run and its job, `report` and `row` come from the
    run's own artifact and `map_status` from its per-function status map. Anything that does not
    agree with the revision the bot reviewed raises, so no confirmation is written for it.
    """
    require(map_status == 'pass' and row.get('status') == 'pass' and row.get('result') == 'hash-match',
            'the hash run did not pass this function')
    require(isinstance(row.get('symbols'), list) and row['symbols'] and all(isinstance(n, str) for n in row['symbols']),
            'the hash run names no matching function')
    require(is_sha(run.get('head_sha')) and report.get('head_sha') == run['head_sha'],
            'artifact belongs to another revision than the run')
    require(is_sha(report.get('base_sha')) and 'error' not in report and report.get('toolset') == 'MATCH',
            'hash run did not complete on a verified toolset')
    manifest = target_hashes.load_manifest(root)
    target = next((r for r in manifest['functions'] if r['rva'] == int(row['rva'], 16)), None)
    require(target is not None, 'no published target hash')
    return dict(schema=2, kind='pr-check-hash', **CI_HOST, workflow=PR_WORKFLOW, job=PR_JOB,
                event=run['event'], conclusion=run['conclusion'], run_id=run['run_id'],
                run_attempt=run['run_attempt'], head_sha=run['head_sha'], base_sha=report['base_sha'],
                build_id=manifest['build_id'], rva=row['rva'], unit=row['unit'], status='pass',
                map_status=map_status, result=row['result'], toolset='MATCH',
                compiler_pins_sha256=report.get('compiler_pins_sha256'),
                symbols=sorted(row['symbols']),
                source_sha256=row.get('source_sha256'), recipe_sha256=row.get('recipe_sha256'),
                target=target, normalized_sha256=target['normalized_sha256'],
                layout_sha256=target['layout_sha256'], first_host=first_host)


def validate_pr_check(root, record, fn, target, c):
    """The pr-check.yml `hash` job as the second host: a pass bound to one run, one head and the source.

    The run compiled the PR head and compared published target commitments; the bot builds this
    evidence only after checking that the run's head is the revision it reviewed and merged. The
    source and recipe digests come from the run's own rows, so they must equal what the first
    host compared, which is how both hosts are tied to the same source content.
    """
    require({k: c.get(k) for k in CI_HOST} == CI_HOST and c.get('kind') == 'pr-check-hash', 'unapproved host')
    require(c.get('workflow') == PR_WORKFLOW and c.get('job') == PR_JOB and c.get('event') == 'pull_request'
            and c.get('conclusion') == 'success', 'workflow job did not succeed')
    require(type(c.get('run_id')) is int and c['run_id'] > 0
            and type(c.get('run_attempt')) is int and c['run_attempt'] > 0, 'invalid run identity')
    require(is_sha(c.get('head_sha')) and is_sha(c.get('base_sha')) and c['head_sha'] != c['base_sha'],
            'invalid revision')
    ancestry = subprocess.run(['git', '-C', str(root), 'merge-base', '--is-ancestor',
                               c['base_sha'], 'HEAD'], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    require(ancestry.returncode == 0, 'CI tools revision is not an ancestor')
    require(c.get('build_id') == target['build_id'] and c.get('rva') == hex(fn['rva'])
            and c.get('unit') == record['source']['compiled'], 'function or unit binding differs')
    require(c.get('status') == c.get('map_status') == 'pass' and c.get('result') == 'hash-match',
            'hash did not pass')
    require(c.get('toolset') == 'MATCH' and c.get('compiler_pins_sha256') ==
            sha((root / 'tools/verifier/pinned.sha256').read_bytes()), 'compiler pins differ')
    manifest = target_hashes.load_manifest(root)
    row = next((r for r in manifest['functions'] if r['rva'] == fn['rva']), None)
    require(row is not None and row['size'] == fn['size'] and row['extraction'] != 'unmasked-unsupported',
            'no supported published target hash')
    require(c.get('target') == row and c.get('normalized_sha256') == row['normalized_sha256']
            and c.get('layout_sha256') == row['layout_sha256'], 'target binding differs')
    require(c.get('source_sha256') == run_revision(record['source'])
            and c.get('recipe_sha256') == record['recipe']['sha256'], 'source or recipe differs')
    # CI found the function by hash, so it must be the one the first host's comparator bound.
    symbols = {(run['report'].get('function') or {}).get('symbol') for run in record['runs']}
    require(isinstance(c.get('symbols'), list) and len(symbols) == 1 and symbols <= set(c['symbols']),
            'CI matched another function than the first host compared')
    require(isinstance(c.get('first_host'), dict), 'first host is not named')
    first_host_check(record, c)


def validate(root, record, fn, target):
    """Validate explicit CI evidence in addition to every ordinary local comparator check."""
    c = record.get('ci_confirmation')
    if isinstance(c, dict) and c.get('schema') == 2:
        return validate_pr_check(root, record, fn, target, c)
    require(isinstance(c, dict) and c.get('schema') == 1, 'unknown evidence schema')
    require(c.get('kind') == 'ci-hash' and c.get('host_id') == 'github-windows-native'
            and c.get('machine') == 'github-hosted-windows' and c.get('loader') == 'native'
            and c.get('os') == 'windows', 'unapproved host')
    require(c.get('workflow') == WORKFLOW and c.get('conclusion') == 'success'
            and type(c.get('run_id')) is int and c['run_id'] > 0
            and c.get('run_attempt') == 1, 'workflow did not succeed in a fresh run')
    for key in ('base_sha', 'candidate_sha'):
        require(isinstance(c.get(key), str) and re.fullmatch('[0-9a-f]{40}', c[key]), 'invalid revision')
    digest = tools_digest_at(root, c['base_sha'])
    ancestry = subprocess.run(['git', '-C', str(root), 'merge-base', '--is-ancestor',
                               c['base_sha'], 'HEAD'], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    require(ancestry.returncode == 0, 'CI tools revision is not an ancestor')
    require(c.get('tools_sha256') == digest, 'stale CI tools')
    require(c.get('toolchain_manifest_sha256') == sha((root / 'tools/toolchain/v141-manifest.json').read_bytes())
            and c.get('cache_verified') is True and c.get('toolset') == 'MATCH', 'toolchain not verified')
    pins = {name: digest for digest, name in
            (line.split() for line in (root / 'tools/verifier/pinned.sha256').read_text().splitlines() if line.strip())}
    require(c.get('compiler_sha256') == pins, 'compiler pins differ')
    manifest = target_hashes.load_manifest(root)
    row = next((r for r in manifest['functions'] if r['rva'] == fn['rva']), None)
    require(row is not None and row['size'] == fn['size'] and row['extraction'] != 'unmasked-unsupported',
            'no supported published target hash')
    require(c.get('target') == row and c.get('build_id') == target['build_id'], 'target binding differs')
    require(c.get('source_sha256') == run_revision(record['source'])
            and c.get('unit') == record['source']['compiled']
            and c.get('recipe_sha256') == record['recipe']['sha256'], 'source or recipe differs')
    require(c.get('result') == 'hash-match' and c.get('deterministic') is True,
            'hash mismatch or nondeterminism')
    prefix = 'first' if 'first_host' in c else 'mac'
    for key in (prefix + '_content_sha256', 'content_sha256', 'object_sha256', 'request_sha256'):
        require(compare.is_hash(c.get(key)), 'missing content/object/request commitment')
    require(c['content_sha256'] == c[prefix + '_content_sha256'], 'CI object content differs from local object')
    require(c.get('normalized_sha256') == row['normalized_sha256']
            and c.get('layout_sha256') == row['layout_sha256'], 'normalized target commitment differs')
    runs = record['runs']
    first = c.get('first_host')
    if first is None:  # Existing Mac attestations keep their original identity and field names.
        first = dict(host_id='mac-wine', machine='maintainer-mac', loader='wine', os='macos')
    require(isinstance(first, dict) and isinstance(first.get('host_id'), str)
            and isinstance(first.get('machine'), str) and bool(first['machine'])
            and first['host_id'] != c['host_id'] and first['machine'] != c['machine'],
            'first host is not an independent machine')
    require((first.get('loader'), first.get('os')) in {('wine', 'macos'), ('wine', 'linux'), ('native', 'windows')},
            'first host loader/OS differs')
    require({r['compiled_on'] for r in runs} == {first['host_id']}
            and {r['compared_on'] for r in runs} == {first['host_id']}, 'first host differs from comparator runs')
    require(c.get(prefix + '_object_sha256') == runs[0]['report']['candidate']['object_sha256']
            and c['object_sha256'] != c[prefix + '_object_sha256'], 'local object binding differs or object reused')
