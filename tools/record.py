#!/usr/bin/env python3
"""Record newly matched functions on main right after the bot merged their source.

    python3 tools/record.py --build ID --rva 0x1000 [--rva ...] --review review.json \
        --author LOGIN [--records DIR] [--root TREE] [--push]

For each function it writes the sanitized Reviewer record next to the function's own match
record, flips that one inventory row to `matched` pointing at its own report, and patches that
one line of reconstruction/INDEX.md. Nothing else in the inventory is touched or regenerated:
the cost of one acceptance stays proportional to the functions it names.

`build_match_record` is how the bot makes the match record that `--records` supplies: the Mac
comparator output of one function plus the pr-check.yml `hash` run as the second host, never a
per-function CI dispatch.

A function is recorded only if the validator accepts the result; anything it refuses is left
as it was and reported. `--push` commits and pushes to main, and on a non-fast-forward fetches,
rebases and tries again, re-applying from the new main when the rebase conflicts.
"""
import argparse
import copy
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build_index  # noqa: E402
import claimable  # noqa: E402
import symbol_map  # noqa: E402
from check import _json_or_none  # noqa: E402
from digest_v2 import review_binds  # noqa: E402
from check import (ROOT, DIGEST_METHOD, REVIEW_RECORD_SCHEMA, TOOLCHAIN_PIN, file_sha256,  # noqa: E402
                   record_code_section, review_record_path, validate_match, validate_review)

PROGRESS = 'data/progress.json'
TARGET = 'builds/target.json'
PUSH_ATTEMPTS = 6


def _load(root, name):
    return json.loads((Path(root) / name).read_text())


def review_blob_digest(blob):
    return hashlib.sha256(blob).hexdigest()


def review_record(fn, record, model, task_id, blob, when):
    """The same fields tools/accept_function.py writes for a full, naming-clean approval."""
    return {
        'review_record_schema': REVIEW_RECORD_SCHEMA,
        'function_id': fn['id'], 'build_id': fn['build_id'], 'rva': fn['rva'], 'size': fn['size'],
        'source_digest_method': record['source']['digest_method'], 'source_digest': record['source']['digest'],
        'reviewer_model': model, 'review_task_id': task_id,
        'verdict': 'approve', 'escalation_category': 'none',
        'review_sha256': review_blob_digest(blob), 'review_date': when.date().isoformat(),
        'review_kind': 'full',
        'previous_source_digest': None, 'previous_review_sha256': None,
        'previous_code_section_sha256': None,
        'code_section_sha256': record_code_section(record),
        'naming_findings': [],
    }


def assemble_record(root, task, unit, fn, report, build, ci):
    """A match record: the first host's comparator report verbatim plus the CI host's confirmation."""
    root = Path(root)
    rva = fn['rva']
    record = dict(
        match_record_schema=3 if 'internal_selector' in fn else 2,
        function_id=f'{task["build_id"]}-0x{rva:x}',
        source=dict(translation_unit=unit['closure'], compiled=unit['unit'], digest_method=DIGEST_METHOD,
                    digest=unit['source_sha256']),
        recipe=dict(path=task['recipe'], sha256=unit['recipe_sha256']),
        toolchain_pin=dict(path=TOOLCHAIN_PIN, sha256=file_sha256(root, TOOLCHAIN_PIN)),
        symbol_map=dict(path=task['symbols_repo'], sha256=hashlib.sha256(Path(task['symbols_local']).read_bytes()).hexdigest()),
        reproduction='Compile with the pinned recipe and compare with tools/verifier/attempt on a registered '
                     'first host; the second host is the pr-check.yml hash job of the recorded run, which '
                     'compiles the same source and checks the published target hashes.',
        build=build,
        notes=['Second host: the pr-check hash job (target-hash commitments, no game bytes in CI); '
               'the first host\'s comparator report is verbatim.'] + list(task.get('record_notes') or []),
        runs=[dict(compiled_on=unit['first_host']['host_id'], compared_on=unit['first_host']['host_id'],
                   report=report)])
    if fn.get('family_metadata'):
        record.update(fn['family_metadata'])
    record['ci_confirmation'] = ci
    return record


def build_match_record(root, task_dir, ci_run, out):
    """Write reports/<build>/0x<rva>.json under `out` for a one-function task the Mac compared.

    `ci_run` is {'run', 'report', 'row', 'map_status'} from the hash run of the reviewed head. Raises
    ValueError when either host's evidence is missing or the validator refuses the record.
    """
    root = Path(root)
    sys.path[:0] = [str(root / 'tools/verifier'), str(root / 'tools')]
    import ci_confirm as client
    import ci_confirmation
    import lint_reconstruction
    import pipeline
    task = pipeline.load_task(task_dir, repo=root)
    ci_confirmation.require(task['symbols_repo'] is not None and len(task['functions']) == 1,
                            'a record needs one function and a public symbol map')
    base = client.base_module()
    base.REPO = root
    unit, reports, build = client.local_inputs(root, task, base)
    fn = task['functions'][0]
    target = _load(root, TARGET)
    for name in unit['closure']:
        ci_confirmation.require(not lint_reconstruction.lint_file(root, name, target['build_id']),
                                'source lint failed')
    ci = ci_confirmation.pr_check_evidence(root, ci_run['run'], ci_run['report'], ci_run['row'],
                                           ci_run['map_status'], unit['first_host'])
    record = assemble_record(root, task, unit, fn, json.loads(Path(reports[fn['rva']]).read_text()), build, ci)
    inventory = {f['rva']: f for f in _load(root, PROGRESS)['functions'] if f['build_id'] == task['build_id']}
    if fn['rva'] not in inventory:
        # A function claimed without an inventory entry is validated as the entry record.apply will add.
        fresh = claimable.resolve(root, task['build_id'], fn['rva'], set(inventory), private_table(root))
        ci_confirmation.require(fresh is not None, 'function is in neither the inventory nor the published target list')
        inventory[fn['rva']] = fresh
    dest = Path(out) / task['build_id'] / f'0x{fn["rva"]:x}.json'
    scratch = root / 'reports' / task['build_id'] / f'.pr-{fn["rva"]:x}.json'
    scratch.parent.mkdir(parents=True, exist_ok=True)
    try:
        scratch.write_text(json.dumps(record, indent=2, sort_keys=True) + '\n')
        validate_match(dict(inventory[fn['rva']], report=scratch.relative_to(root).as_posix()), target, root)
        dest.parent.mkdir(parents=True, exist_ok=True)
        scratch.replace(dest)
    finally:
        scratch.unlink(missing_ok=True)
    return dest


def build_carried_record(root, build_id, rva, out, note):
    """Match record for an accepted function whose unit changed from base only in comments.

    The runs stay as they were: they compared the old text, which the caller has shown to be the same
    code, and only the record's digest moves to the new text. That is possible only for a record that
    already keeps its runs' own digest (`run_digest`); the validator then checks the new digest against
    the integrated source as for any record. Raises ValueError when the record cannot be carried.
    """
    root = Path(root)
    from digest_v2 import tu_digest
    from source_digest import include_closure
    fn = next((f for f in _load(root, PROGRESS)['functions'] if f['build_id'] == build_id and f['rva'] == rva), None)
    if fn is None or fn.get('status') != 'matched' or not fn.get('report'):
        raise ValueError('only an accepted function has a record to carry')
    old = _load(root, fn['report'])
    source = old.get('source') or {}
    if 'run_digest' not in source or 'ci_confirmation' in old:
        raise ValueError('the record binds its runs to the current digest, so its runs cannot carry to new text')
    closure = include_closure(root, source['compiled'])
    if set(closure) != set(source['translation_unit']):
        raise ValueError('the translation unit changed')
    record = copy.deepcopy(old)
    record['source'] = dict(source, digest=tu_digest(root, closure, DIGEST_METHOD), digest_method=DIGEST_METHOD)
    record['notes'] = list(old.get('notes') or []) + [note]
    dest = Path(out) / build_id / f'0x{rva:x}.json'
    scratch = root / 'reports' / build_id / f'.pr-{rva:x}.json'
    scratch.parent.mkdir(parents=True, exist_ok=True)
    try:
        scratch.write_text(json.dumps(record, indent=2, sort_keys=True) + '\n')
        validate_match(dict(fn, report=scratch.relative_to(root).as_posix()), _load(root, TARGET), root)
        dest.parent.mkdir(parents=True, exist_ok=True)
        scratch.replace(dest)
    finally:
        scratch.unlink(missing_ok=True)
    return dest


def private_table(root):
    """The private function table by RVA when this host has one; None means the published bounds alone."""
    import claimable
    return claimable.load_table(os.environ.get('SR_FUNCTION_TABLE') or Path(root) / '.local/analysis/functions.jsonl')


def _write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


def _patch_index(root, fns):
    """Replace only the changed functions' lines; the table is sorted and one line per function."""
    path = Path(root) / build_index.INDEX
    if not path.is_file():
        return False
    lines = path.read_text().splitlines(keepends=True)
    for fn in fns:
        key = f'| `{fn["build_id"]}` / `0x{fn["rva"]:x}` / {fn["size"]} |'
        hits = [i for i, line in enumerate(lines) if key in line]
        if len(hits) != 1:
            raise ValueError(f'INDEX.md has {len(hits)} lines for {fn["id"]}')
        lines[hits[0]] = build_index.row(fn, Path(root))
    path.write_text(''.join(lines))
    return True


def apply(root, build_id, rvas, review_blob, *, model, task_id, author=None, records=None, when=None, drafter=None):
    """Record what the validator accepts. Returns {'recorded': [rva], 'refused': {rva: reason}, 'files': [...]}."""
    root = Path(root)
    when = when or datetime.now(timezone.utc).replace(microsecond=0)
    data = _load(root, PROGRESS)
    target = _load(root, TARGET)
    by_rva = {fn['rva']: (i, fn) for i, fn in enumerate(data['functions']) if fn['build_id'] == build_id}
    out = {'recorded': [], 'refused': {}, 'files': []}
    changed, created = [], set()
    table = []
    for rva in sorted(set(rvas)):
        index = None
        if rva in by_rva:
            index, fn = by_rva[rva]
        else:
            # Published bounds make a function claimable without bulk mapping; its entry is made here,
            # and only if the validator then accepts the match.
            if not table:
                table.append(private_table(root))
            fn = claimable.resolve(root, build_id, rva, set(by_rva), table[0])
            if fn is None:
                out['refused'][rva] = 'not in inventory'
                continue
        report = f'reports/{build_id}/0x{rva:x}.json'
        review_path = root / review_record_path(fn)
        written, prior = [], {}
        try:
            source = Path(records) / build_id / f'0x{rva:x}.json' if records is not None else root / report
            if not source.is_file():
                raise ValueError('no match record was produced')
            record = json.loads(source.read_text())
            if author:
                from build_leaderboard import handle
                if not handle(author):
                    raise ValueError('author has no valid public handle')
                record['submitter'] = handle(author)
            # The contributor's own statement of who drafted it, kept with the record so the
            # attribution chart never has to go back to the PR; an existing field is not overwritten.
            if drafter and not record.get('drafter_model'):
                record['drafter_model'] = drafter
            # A stacked PR re-confirms functions of a unit that grew; only the identical source is a repeat.
            previous = _json_or_none(review_path) if fn['status'] == 'matched' else None
            if previous and review_binds(previous.get('source_digest_method'), previous.get('source_digest'), record['source']):
                # A carried record keeps its runs' own digest, which the standing review still binds, so the
                # binding alone cannot tell a repeat from a record moved to edited text; only the digest the
                # record on main already carries can.
                held = (_json_or_none(root / report) or {}).get('source') or {}
                if (held.get('digest_method'), held.get('digest')) == (record['source'].get('digest_method'),
                                                                       record['source'].get('digest')):
                    raise ValueError('already matched')
            if records is not None or author or drafter:
                prior[root / report] = (root / report).read_bytes() if (root / report).is_file() else None
                _write_json(root / report, record)
                written.append(root / report)
            candidate = dict(copy.deepcopy(fn), status='matched', report=report, evidence=report)
            record = validate_match(candidate, target, root)
            prior[review_path] = review_path.read_bytes() if review_path.is_file() else None
            _write_json(review_path, review_record(candidate, record, model, task_id, review_blob, when))
            written.append(review_path)
            validate_review(candidate, record, root)
        except (ValueError, KeyError, TypeError, OSError) as exc:
            for path in written:
                if prior.get(path) is None:
                    path.unlink(missing_ok=True)
                else:
                    path.write_bytes(prior[path])
            out['refused'][rva] = str(exc).splitlines()[0][:200] if str(exc) else type(exc).__name__
            continue
        if index is None:
            data['functions'].append(candidate)
            created.add(rva)
        else:
            data['functions'][index] = candidate
        changed.append(candidate)
        out['recorded'].append(rva)
        out['files'] += [report, review_record_path(fn)]
        # A unit map is immutable and content-addressed, so a record that points at one must carry it.
        for rel in (record['symbol_map']['path'], symbol_map.history_name(record['symbol_map']['path'])):
            if '/unit-symbols/' in rel and (root / rel).is_file() and rel not in out['files']:
                out['files'].append(rel)
    if changed:
        data['updated_at'] = when.strftime('%Y-%m-%dT%H:%M:%SZ')
        (root / PROGRESS).write_text(json.dumps(data, indent=2, ensure_ascii=False) + '\n')
        if created:
            build_index.write_index(data, root)
            out['files'].append(build_index.INDEX)
        elif _patch_index(root, changed):
            out['files'].append(build_index.INDEX)
        out['files'].append(PROGRESS)
        # check.py renders the README pictures from the data; a record that moves the counts must move them.
        import build_progress_svg
        for name, render in (('docs/progress.svg', build_progress_svg.render),
                             ('docs/progress-map.svg', build_progress_svg.render_map)):
            if (root / 'data/scope.json').is_file():
                (root / name).write_text(render(root))
                out['files'].append(name)
    return out


def git(root, *args, check=True):
    return subprocess.run(['git', '-C', str(root), *args], capture_output=True, text=True, check=check)


def record_and_push(root, build_id, rvas, review_blob, message, push=True, **kwargs):
    """Apply, commit and push; each retry after a lost race starts from the fetched main."""
    last = None
    for attempt in range(PUSH_ATTEMPTS):
        if attempt:
            git(root, 'fetch', '-q', 'origin', 'main')
            rebased = git(root, 'rebase', 'origin/main', check=False)
            if rebased.returncode:
                git(root, 'rebase', '--abort', check=False)
                git(root, 'reset', '-q', '--hard', 'origin/main')
                last = apply(root, build_id, rvas, review_blob, **kwargs)
                if not last['recorded']:
                    return last
                git(root, 'add', '--', *last['files'])
                git(root, 'commit', '-q', '-m', message)
        else:
            last = apply(root, build_id, rvas, review_blob, **kwargs)
            if not last['recorded']:
                return last
            git(root, 'add', '--', *last['files'])
            git(root, 'commit', '-q', '-m', message)
        if not push:
            return last
        pushed = git(root, 'push', '-q', 'origin', 'HEAD:main', check=False)
        if pushed.returncode == 0:
            last['pushed'] = True
            return last
    raise RuntimeError('push to main kept losing the race')


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--build', required=True)
    p.add_argument('--rva', action='append', required=True, type=lambda s: int(s, 0))
    p.add_argument('--review', required=True, type=Path, help='the saved review, hashed into the record')
    p.add_argument('--model', default='gpt-6.1-terra')
    p.add_argument('--task-id', required=True)
    p.add_argument('--author')
    p.add_argument('--drafter', help="the PR summary's drafter claim, stored in each record")
    p.add_argument('--records', type=Path)
    p.add_argument('--root', type=Path, default=ROOT)
    p.add_argument('--message')
    p.add_argument('--push', action='store_true')
    a = p.parse_args(argv)
    kwargs = dict(model=a.model, task_id=a.task_id, author=a.author, records=a.records,
                  drafter=a.drafter)
    blob = a.review.read_bytes()
    if a.push:
        message = a.message or ('Record ' + ', '.join(f'0x{r:x}' for r in a.rva) +
                                '\n\nCo-Authored-By: Claude <noreply@anthropic.com>')
        result = record_and_push(a.root, a.build, a.rva, blob, message, **kwargs)
    else:
        result = apply(a.root, a.build, a.rva, blob, **kwargs)
    print(json.dumps({'recorded': [f'0x{r:x}' for r in result['recorded']],
                      'refused': {f'0x{r:x}': why for r, why in result['refused'].items()},
                      'files': result['files']}))
    return 0 if result['recorded'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
