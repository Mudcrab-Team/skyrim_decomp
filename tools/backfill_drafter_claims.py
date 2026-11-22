"""Recover drafter claims for accepted functions from the merged PR summaries that listed them.

Records written before the bot kept the PR's `Drafted by` line carry no model, so the chart lists their
bytes as unreported. For each such function this finds the merged PR that listed it, written by the
record's own submitter and merged no later than the record, and keeps that PR's stated drafter in
`data/drafter-claims.json`. Nothing is inferred: a function with no such PR, or a PR whose line names no
model and no explicit "not stated"/"human", stays unreported. Existing entries are never changed.
"""
import argparse
from datetime import datetime, timedelta
import json
from pathlib import Path
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build_model_trend as trend  # noqa: E402
import drafter_claim  # noqa: E402

ROOT = trend.ROOT
# The bot's record commit lands seconds before GitHub stamps the PR as merged.
SLACK = timedelta(minutes=30)


def load_prs(path, repo):
    if path:
        return json.loads(Path(path).read_text())
    out = subprocess.check_output(['gh', 'pr', 'list', '-R', repo, '--state', 'merged', '--limit', '5000', '--json',
                                   'number,author,mergedAt,body,title'], text=True)
    return json.loads(out)


def index_prs(prs):
    """{rva: [(merged_at, author, number, claim)]} for each merged PR whose summary states a drafter."""
    by_rva = {}
    for pr in prs:
        claim = drafter_claim.from_body(pr.get('body'))
        if not claim or not pr.get('mergedAt'):
            continue
        merged = datetime.fromisoformat(pr['mergedAt'].replace('Z', '+00:00'))
        for rva in drafter_claim.rvas_from_body(pr.get('body'), pr.get('title')):
            by_rva.setdefault(rva, []).append((merged, (pr.get('author') or {}).get('login', '').casefold(), pr['number'], claim))
    return by_rva


def pick(by_rva, rva, submitter, when):
    """The latest PR by `submitter` that listed `rva` and merged by `when`, else None."""
    fits = [p for p in by_rva.get(rva, []) if p[1] == (submitter or '').casefold() and p[0] <= when + SLACK]
    return max(fits, key=lambda p: p[0]) if fits else None


def backfill(revision, prs, existing):
    by_rva, found, left = index_prs(prs), {}, []

    def gap(fn, report, commit, stamp):
        if fn['id'] in existing:
            return
        when = datetime.fromisoformat(stamp)
        hit = pick(by_rva, fn['rva'], report.get('submitter'), when)
        if hit and trend.model_claim(hit[3], True)[0] != 'Not reported':
            found[fn['id']] = {'claim': hit[3], 'pr': hit[2]}
        else:
            left.append(fn['id'])
    blobs = trend.GitBlobs()
    try:
        rows, _current = trend.history(revision, blobs, on_gap=gap)
    finally:
        blobs.close()
    return found, left


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--revision', default='HEAD')
    parser.add_argument('--prs', help='merged PRs as `gh pr list --json number,author,mergedAt,body,title` writes them')
    parser.add_argument('--repo', default='Mudcrab-Team/skyrim_decomp')
    parser.add_argument('--out', default=str(ROOT / trend.CLAIMS))
    args = parser.parse_args()
    path = Path(args.out)
    existing = json.loads(path.read_text())['claims'] if path.is_file() else {}
    # Existing entries stay as they were; the history reads them as attributed.
    found, left = backfill(args.revision, load_prs(args.prs, args.repo), existing)
    claims = {**existing, **found}
    path.write_text(json.dumps({'schema': 1, 'claims': dict(sorted(claims.items()))}, indent=1, sort_keys=True) + '\n')
    print(f'{len(found)} claims added ({len(claims)} total); {len(left)} functions still unreported.')


if __name__ == '__main__':
    main()
