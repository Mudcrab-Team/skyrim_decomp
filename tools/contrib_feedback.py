"""Read-only GitHub feedback for the signed-in contributor; no private inputs or git writes."""
from datetime import datetime, timezone
import json
import re
import subprocess


class Unavailable(Exception):
    pass


THREAD_FIELDS = '''id path line originalLine isResolved isOutdated
    comments(first:100) { nodes { id body createdAt updatedAt url author { login } }
                          pageInfo { hasNextPage endCursor } }'''
THREAD_QUERY = '''query($owner:String!, $name:String!, $number:Int!, $after:String) {
  repository(owner:$owner, name:$name) { pullRequest(number:$number) {
    headRefOid commits(last:1) { nodes { commit { committedDate } } }
    reviewThreads(first:100, after:$after) { nodes { ''' + THREAD_FIELDS + ''' }
      pageInfo { hasNextPage endCursor } }
  } }
}'''
COMMENT_QUERY = '''query($id:ID!, $after:String) {
  node(id:$id) { ... on PullRequestReviewThread {
    comments(first:100, after:$after) {
      nodes { id body createdAt updatedAt url author { login } }
      pageInfo { hasNextPage endCursor }
    }
  } }
}'''
MAINTAINERS = {'OWNER', 'MEMBER', 'COLLABORATOR'}
FAILED_CHECKS = {'failure', 'timed_out', 'cancelled', 'action_required', 'stale', 'startup_failure'}
# The intake bot keeps one comment per PR that starts with this marker and is edited on every head.
# Older bot comments carried the full head in the marker (`<!-- pr-bot sha=... -->`); the current form
# names the head on its status line instead.
STICKY = re.compile(r'\A\s*<!-- pr-bot(?: sha=([0-9a-f]{7,40}))? -->[^\n]*\n?')
STATUS_LINE = re.compile(r'^Bot status for head ([0-9a-f]{7,40})\b[^\n]*\n?', re.M)
BATCH_REQUEST = re.compile(r'^Small request: please batch\b[^\n]*$', re.M | re.I)
# Outcomes that ask nothing of the contributor while the PR stays open.
NO_ACTION = ('Nothing to report.', 'stays open for the maintainer')


class Reader:
    def __init__(self, github):
        self.ctx, self.repo = github.ctx, github.repo
        if self.ctx.env.get('SR_CONTRIB_OFFLINE'):
            raise Unavailable('Feedback unavailable: offline mode (SR_CONTRIB_OFFLINE).')
        self.gh = github.gh()
        if not self.gh:
            raise Unavailable('Feedback unavailable: install GitHub CLI (gh) and run gh auth login.')

    def read(self, path, *fields):
        try:
            proc = self.ctx.run([self.gh, 'api', path, *fields], capture_output=True, text=True,
                                encoding='utf-8', timeout=20)
        except (OSError, subprocess.SubprocessError):
            raise Unavailable('Feedback unavailable: GitHub could not be reached; check the network and gh auth status.') from None
        if proc.returncode:
            raise Unavailable('Feedback unavailable: GitHub request failed; check the network, gh auth status and repository access.')
        try:
            value = json.loads(proc.stdout)
        except ValueError:
            raise Unavailable('Feedback unavailable: GitHub returned an invalid response; retry later.') from None
        if isinstance(value, dict) and value.get('errors'):
            raise Unavailable('Feedback unavailable: GitHub GraphQL request failed; check gh auth status and retry.')
        return value

    def pages(self, path, key=None):
        rows = []
        for page in range(1, 101):
            value = self.read(path + ('&' if '?' in path else '?') + f'per_page=100&page={page}')
            batch = value[key] if key else value
            rows.extend(batch)
            if len(batch) < 100:
                return rows
        raise Unavailable('Feedback incomplete: GitHub pagination limit reached; no clean result can be reported.')

    def graphql(self, query, **variables):
        fields = ['-f', 'query=' + query]
        for key, value in variables.items():
            if value is not None:
                fields += ['-F' if isinstance(value, int) else '-f', f'{key}={value}']
        return self.read('graphql', *fields)['data']

    def threads(self, number):
        owner, name = self.repo.split('/')
        threads, after, head, committed = [], None, None, None
        for _ in range(100):
            pr = self.graphql(THREAD_QUERY, owner=owner, name=name, number=number, after=after)['repository']['pullRequest']
            if pr is None:
                raise Unavailable('Feedback unavailable: the PR is no longer accessible; retry.')
            if head is not None and head != pr['headRefOid']:
                raise Unavailable('Feedback changed during pagination: the PR has a new commit; retry.')
            head = pr['headRefOid']
            commits = pr['commits']['nodes']
            committed = commits[-1]['commit']['committedDate'] if commits else None
            connection = pr['reviewThreads']
            threads.extend(connection['nodes'])
            if not connection['pageInfo']['hasNextPage']:
                break
            after = connection['pageInfo']['endCursor']
        else:
            raise Unavailable('Feedback incomplete: review thread pagination limit reached.')
        for thread in threads:
            connection = thread['comments']
            comments = list(connection['nodes'])
            for _ in range(100):
                if not connection['pageInfo']['hasNextPage']:
                    break
                connection = self.graphql(COMMENT_QUERY, id=thread['id'],
                                          after=connection['pageInfo']['endCursor'])['node']['comments']
                comments.extend(connection['nodes'])
            else:
                raise Unavailable('Feedback incomplete: thread comment pagination limit reached.')
            thread['comments'] = comments
        return head, committed, threads


def stamp(value):
    return datetime.fromisoformat(value.replace('Z', '+00:00')) if value else datetime.min.replace(tzinfo=timezone.utc)


def author(row):
    return (row.get('user') or row.get('author') or {}).get('login') or '[deleted]'


def updated(row):
    return row.get('updated_at') or row.get('updatedAt') or row.get('submitted_at') or row.get('created_at') or row.get('createdAt')


def summarize(pr, me, head, committed, threads, reviews, comments, checks, statuses):
    """Unresolved threads and active change requests stay actionable after a reply or push."""
    replies = [updated(c) for c in comments + reviews + [c for t in threads for c in t['comments']]
               if author(c).casefold() == me.casefold() and updated(c)]
    reply = max(replies, key=stamp) if replies else None

    def flags(when):
        commit_new = bool(when and stamp(when) > stamp(committed))
        reply_new = bool(when and stamp(when) > stamp(reply))
        return dict(new_since_commit=commit_new, new_since_reply=reply_new, is_new=commit_new or reply_new)

    def comment(c):
        return dict(id=c['id'], author=author(c), body=c.get('body') or '',
                    url=c.get('html_url') or c.get('url'), updated_at=updated(c), **flags(updated(c)))

    unresolved = []
    for thread in threads:
        if thread['isResolved']:
            continue
        rows = [comment(c) for c in thread['comments']]
        # A contributor's reply cannot make their own thread look like fresh incoming feedback.
        incoming = [c for c in rows if c['author'].casefold() != me.casefold()]
        when = max((c['updated_at'] for c in incoming), key=stamp, default=None)
        unresolved.append(dict(id=thread['id'], file=thread['path'], line=thread.get('line') or thread.get('originalLine'),
                               outdated=thread['isOutdated'], comments=rows, needs_action=True, **flags(when)))
    latest = {}
    for review in sorted(reviews, key=lambda r: stamp(r.get('submitted_at'))):
        if review['state'] in ('APPROVED', 'CHANGES_REQUESTED', 'DISMISSED'):
            latest[author(review).casefold()] = review
    requested = [dict(comment(r), state=r['state'], commit=r.get('commit_id'), needs_action=True)
                 for r in latest.values() if r['state'] == 'CHANGES_REQUESTED']
    issue_comments = []
    for row in comments:
        if author(row).casefold() == me.casefold():
            continue
        sticky = parse_sticky(row.get('body') or '')
        maintainer = row.get('author_association') in MAINTAINERS
        bot = bool(sticky and (maintainer or (row.get('user') or {}).get('type') == 'Bot'))
        if not maintainer and not bot:
            continue
        item = comment(row)
        # Replies acknowledge general discussion. A new push also supersedes the bot's result for the old head.
        action = item['new_since_reply']
        if bot:
            action = action and same_head(sticky['head'], head) and bool(sticky['what_needs_changing'])
        issue_comments.append(dict(item, intake_bot=bot, needs_action=action))
    failures = []
    for check in checks:
        if check.get('conclusion') in FAILED_CHECKS:
            when = check.get('completed_at') or check.get('started_at')
            failures.append(dict(name=check['name'], state=check['conclusion'], url=check.get('html_url'),
                                 needs_action=True, **flags(when)))
    # The combined status endpoint returns the latest status for each legacy context.
    for status in statuses:
        if status['state'] in ('failure', 'error'):
            failures.append(dict(name=status['context'], state=status['state'], url=status.get('target_url'),
                                 needs_action=True, **flags(updated(status))))
    groups = dict(review_threads=unresolved, changes_requested=requested, issue_comments=issue_comments, failing_checks=failures)
    count = sum(item['needs_action'] for group in groups.values() for item in group)
    return dict(number=pr['number'], title=pr['title'], url=pr['html_url'], head=head,
                last_commit_at=committed, last_reply_at=reply, needs_action=bool(count), action_count=count, **groups)


def collect(github):
    reader = Reader(github)
    me = reader.read('user')['login']  # Authenticated identity, never a saved claim-name override.
    prs = [pr for pr in reader.pages(f'repos/{reader.repo}/pulls?state=open')
           if author(pr).casefold() == me.casefold()]
    results = []
    for pr in prs:
        head, committed, threads = reader.threads(pr['number'])
        prefix = f'repos/{reader.repo}'
        reviews = reader.pages(f'{prefix}/pulls/{pr["number"]}/reviews')
        comments = reader.pages(f'{prefix}/issues/{pr["number"]}/comments')
        checks = reader.pages(f'{prefix}/commits/{head}/check-runs?filter=latest', 'check_runs')
        statuses = reader.pages(f'{prefix}/commits/{head}/status', 'statuses')
        if reader.read(f'{prefix}/pulls/{pr["number"]}')['head']['sha'] != head:
            raise Unavailable('Feedback changed while checking: the PR has a new commit; retry.')
        results.append(summarize(pr, me, head, committed, threads, reviews, comments, checks, statuses))
    return dict(repository=reader.repo, contributor=me, pull_requests=results,
                needs_action_prs=sum(pr['needs_action'] for pr in results))


def display(ctx, data):
    if not data['pull_requests']:
        ctx.say('No open PRs against ' + data['repository'] + ' for ' + data['contributor'] + '.')
    for pr in data['pull_requests']:
        ctx.say(f'PR #{pr["number"]}: {pr["title"]} — {pr["url"]}')
        if not pr['needs_action']:
            ctx.say('  No unaddressed feedback.')
        for kind in ('review_threads', 'changes_requested', 'issue_comments', 'failing_checks'):
            for item in pr[kind]:
                tag = ('NEW ' if item['is_new'] else '') + ('ACTION' if item['needs_action'] else 'history')
                if kind == 'review_threads':
                    ctx.say(f'  [{tag}] thread {item["id"]} {item["file"]}:{item["line"] or "?"}')
                    for row in item['comments']:
                        ctx.say(f'    {row["author"]}: {row["body"]}')
                elif kind == 'failing_checks':
                    ctx.say(f'  [{tag}] check {item["name"]}: {item["state"]} {item["url"] or ""}')
                else:
                    ctx.say(f'  [{tag}] {kind}: {item["author"]}: {item["body"]}')
                if item.get('url'):
                    ctx.say('    ' + item['url'])


def same_head(short, head):
    return bool(short and head and len(short) >= 7 and head.startswith(short))


def parse_sticky(body):
    """The bot's sticky comment as {head, text, what_needs_changing, batch}; None for any other comment."""
    marker = STICKY.match(body)
    if not marker:
        return None
    rest = body[marker.end():]
    status = STATUS_LINE.search(rest)
    short = marker[1] or (status[1] if status else None)
    if status:
        rest = rest[:status.start()] + rest[status.end():]
    batch = bool(BATCH_REQUEST.search(rest))
    text = BATCH_REQUEST.sub('', rest).strip()
    needs = []
    for line in text.splitlines():
        if line.startswith('- '):
            needs.append(line[2:].strip())
        elif line.lstrip().startswith('- ') and needs:
            # A nested bullet is a reviewer note on the function above it.
            needs[-1] += ' (' + line.lstrip()[2:].strip() + ')'
    if not needs and text and not any(phrase in text for phrase in NO_ACTION) and not text.startswith('Merged and recorded'):
        needs = [' '.join(text.split())]
    return dict(head=short, text=text, what_needs_changing=needs, batch=batch)


def collect_outcome(github, number):
    """The bot's current result for one PR, only when it describes the PR's current head."""
    reader = Reader(github)
    pr = reader.read(f'repos/{reader.repo}/pulls/{number}')
    head = pr['head']['sha']
    comments = reader.pages(f'repos/{reader.repo}/issues/{number}/comments')
    owner = reader.repo.split('/')[0].casefold()
    stickies = [(row, parse_sticky(row.get('body') or '')) for row in comments if author(row).casefold() == owner]
    stickies = [(row, sticky) for row, sticky in stickies if sticky]
    if not stickies:
        raise Unavailable('Bot feedback is unavailable for this PR: the bot has not commented on it.')
    row, sticky = stickies[-1]
    if not same_head(sticky['head'], head):
        raise Unavailable('Bot feedback is unavailable for this PR revision: the bot has not finished the current head yet.')
    return dict(number=number, head=head, url=row.get('html_url'), updated_at=updated(row),
                needs_action=bool(sticky['what_needs_changing']), what_needs_changing=sticky['what_needs_changing'],
                batch_request=sticky['batch'], text=sticky['text'])
