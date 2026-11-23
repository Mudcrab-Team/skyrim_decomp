#!/usr/bin/env python3
"""Squash-merge an owner tooling PR, refusing a red `tests`/`check` job or a stale-base clobber.

    python3 tools/merge_tooling_pr.py N [--dry-run]

Use this instead of a raw `gh pr merge --admin`. The admin merge skips branch protection, so these two
checks are the only thing between a stale branch and a main that silently loses other people's changes.

Clobber check: the merge GitHub would make is built locally (`git merge-tree`). For each file that both the
PR and main changed since their merge base, every hunk main added (or deleted) after the base must still be
present (or absent) in that merged file. A hunk that is not means the PR's version of the region wins over
main's, i.e. a main change is being undone. The check is conservative about what it reports (whole-hunk
contiguous matches only) and does not look at changes main made before the merge base.
"""
import argparse
import json
import re
import subprocess
import sys

REQUIRED_WORKFLOW = 'Infrastructure checks'
HUNK = re.compile(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@')


def git(*args, check=True):
    out = subprocess.run(['git', *args], capture_output=True, text=True, errors='replace')
    if check and out.returncode:
        raise SystemExit(f'git {args[0]} failed: {out.stderr.strip()}')
    return out


def job_problems(rollup):
    """Why the PR's `check`/`tests` jobs do not allow a merge; empty when every one of them succeeded."""
    jobs = [j for j in rollup if j.get('workflowName') == REQUIRED_WORKFLOW
            and (j.get('name') == 'check' or j.get('name', '').startswith('tests'))]
    problems = [f'{j["name"]}: {j.get("conclusion") or j.get("status") or "unknown"}'
                for j in jobs if j.get('conclusion') != 'SUCCESS']
    for need in ('check', 'tests'):
        if not any(j['name'].startswith(need) for j in jobs):
            problems.append(f'{need}: no run found')
    return problems


def hunks(diff_text):
    """[(header, removed lines, added lines)] from a zero-context unified diff."""
    out = []
    for line in diff_text.splitlines():
        if HUNK.match(line):
            out.append((line, [], []))
        elif out and line.startswith('-') and not line.startswith('---'):
            out[-1][1].append(line[1:])
        elif out and line.startswith('+') and not line.startswith('+++'):
            out[-1][2].append(line[1:])
    return out


def contains_block(lines, block):
    n = len(block)
    return n > 0 and any(lines[i:i + n] == block for i in range(len(lines) - n + 1))


def undone_hunks(main_hunks, merged_lines):
    """Main hunks the merged file no longer reflects: added text gone, or deleted text back."""
    bad = []
    for header, removed, added in main_hunks:
        if added and not contains_block(merged_lines, added):
            bad.append((header, removed, added))
        elif not added and removed and contains_block(merged_lines, removed):
            bad.append((header, removed, added))
    return bad


def clobbers(base, main, head):
    """[(path, header, removed, added)] for main hunks the squash merge of `head` into `main` would undo."""
    mine = set(git('diff', '--no-renames', '--name-only', base, head).stdout.split('\n')) - {''}
    theirs = set(git('diff', '--no-renames', '--name-only', base, main).stdout.split('\n')) - {''}
    both = sorted(mine & theirs)
    if not both:
        return []
    merged = git('merge-tree', '--write-tree', main, head, check=False)
    if merged.returncode:
        raise SystemExit('the PR does not merge cleanly into main; update the branch first\n' + merged.stdout)
    tree = merged.stdout.split('\n')[0].strip()
    found = []
    for path in both:
        shown = git('show', f'{tree}:{path}', check=False)
        lines = shown.stdout.split('\n') if shown.returncode == 0 else []
        diff = git('diff', '--no-renames', '-U0', base, main, '--', path).stdout
        found += [(path, *h) for h in undone_hunks(hunks(diff), lines)]
    return found


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('number', type=int)
    ap.add_argument('--dry-run', action='store_true', help='run the checks, do not merge')
    args = ap.parse_args(argv)
    view = json.loads(subprocess.run(
        ['gh', 'pr', 'view', str(args.number), '--json', 'state,baseRefName,headRefOid,statusCheckRollup'],
        capture_output=True, text=True, check=True).stdout)
    if view['state'] != 'OPEN' or view['baseRefName'] != 'main':
        raise SystemExit(f'PR {args.number} is not an open PR against main')
    problems = job_problems(view['statusCheckRollup'])
    if problems:
        raise SystemExit('refusing: required jobs are not green: ' + '; '.join(problems))
    head = view['headRefOid']
    git('fetch', '-q', 'origin', 'main')
    git('fetch', '-q', 'origin', f'pull/{args.number}/head')
    if git('rev-parse', 'FETCH_HEAD').stdout.strip() != head:
        raise SystemExit('refusing: the PR head moved while checking; run again')
    main_sha = git('rev-parse', 'origin/main').stdout.strip()
    base = git('merge-base', main_sha, head).stdout.strip()
    bad = clobbers(base, main_sha, head)
    if bad:
        for path, header, removed, added in bad:
            print(f'refusing: main changed this after the merge base ({base[:10]}) and the PR undoes it\n'
                  f'  {path} {header}\n' + ''.join(f'  main removed: {x}\n' for x in removed)
                  + ''.join(f'  main added:   {x}\n' for x in added), file=sys.stderr)
        raise SystemExit('rebase or merge main into the branch and keep main\'s side, then run again')
    if args.dry_run:
        print('checks passed; not merging (--dry-run)')
        return 0
    subprocess.run(['gh', 'pr', 'merge', str(args.number), '--squash', '--admin', '--match-head-commit', head],
                   check=True)
    return 0


if __name__ == '__main__':
    sys.exit(main())
