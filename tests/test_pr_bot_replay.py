"""pr_bot end to end: the real poll, process, review, hash-check and landing code against scripted outside worlds.

Everything the bot reaches over a boundary is a script here: `gh` (a small in-memory GitHub), the CI hash job, the
Codex and Claude reviewers, the compile host, bind.py and record.py. Git is real, against local bare repositories, so
the squash, the record commit, the merge of main into a branch and the tree cleans behave as they do live. Only the
stages that inspect source content (lints, leak scan, origin check) are stubbed. Every fixture is invented: unit names,
hashes and RVAs are synthetic and no game byte appears anywhere.
"""
import contextlib
import io
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import threading
import time
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import pr_bot  # noqa: E402

REAL_RUN = subprocess.run  # captured before any test patches it, for the scripted git
IDENTITY = {'GIT_AUTHOR_NAME': 'fixture', 'GIT_AUTHOR_EMAIL': 'fixture@example.invalid',
            'GIT_COMMITTER_NAME': 'fixture', 'GIT_COMMITTER_EMAIL': 'fixture@example.invalid'}
BUILD = 'sse-test'
CLAUDE_NAME = Path(pr_bot.CLAUDE_BIN).name
OLD = '2000-01-01T00:00:00Z'
FUTURE = '2999-01-01T00:00:00Z'  # a run that started after any probe the bot requests


def git(cwd, *args, check=True):
    done = REAL_RUN(['git', *args], cwd=cwd, capture_output=True, env={**os.environ, **IDENTITY})
    if check and done.returncode:
        raise AssertionError(f'git {args}: {done.stderr.decode()}')
    return done.stdout.decode().strip()


def unit(rva, extra=''):
    return f'// 0x{rva:x} Func{rva:x}\n{extra}// Original fixture code.\nint Func{rva:x}() {{ return 1; }}\n'


def unit_path(rva):
    return f'reconstruction/fx/U{rva:x}.cpp'


class FakeCI:
    """Check runs and artifacts of the hash job, per head."""

    def __init__(self):
        self.runs = {}  # head -> [run]
        self.artifacts = {}  # run id -> {rva: status} | None
        self.skipped = set()  # run ids whose compile step was skipped
        self.ids = 100
        self.policy = {}  # head -> callable run when the bot requests a probe on that head

    def add(self, head, artifact, started=OLD, conclusion='success', skipped=False):
        self.ids += 1
        run = dict(id=self.ids, name='hash', head_sha=head, status='completed', conclusion=conclusion,
                   started_at=started, details_url=f'https://ci.invalid/runs/{self.ids}')
        self.runs.setdefault(head, []).append(run)
        self.artifacts[self.ids] = artifact
        if skipped:
            self.skipped.add(self.ids)
        return run


class FakeGitHub:
    def __init__(self, world):
        self.world = world
        self.prs = {}  # number -> dict
        self.comments = {}  # number -> [{id, login, body}]
        self.calls = []
        self.merges = []
        self.merge_failures = 0
        self.close_on_merge = False  # the PR is closed by someone while the merge request is in flight
        self.labels = {}
        self.lock = threading.Lock()

    def view(self, n):
        pr = self.prs[n]
        return dict(number=n, headRefOid=pr['head'], author={'login': pr['author']}, baseRefName='main',
                    isDraft=pr.get('draft', False), mergeable=pr['mergeable'], state=pr['state'],
                    labels=[{'name': x} for x in pr.get('labels', [])], maintainerCanModify=True,
                    headRefName=pr['branch'], headRepository={'name': 'fork'}, headRepositoryOwner={'login': pr['author']})

    def handle(self, argv):
        a = [str(x) for x in argv[1:]]
        with self.lock:
            self.calls.append(a)
            return self.route(a)

    def ok(self, value=b''):
        if not isinstance(value, bytes):
            value = json.dumps(value).encode()
        return subprocess.CompletedProcess([], 0, value, b'')

    def route(self, a):
        w, ci = self.world, self.world.ci
        line = ' '.join(a)
        m = re.search(r'pulls/(\d+)/files', line)
        if m:
            return self.ok([w.files_of(int(m[1]))])
        m = re.search(r'issues/(\d+)/comments', line)
        if m and a[0] == 'api' and '-X' not in a:
            return self.ok(''.join(json.dumps(c) + '\n' for c in self.comments.get(int(m[1]), [])).encode())
        if a[:2] == ['api', '-X'] and a[2] == 'PATCH' and 'issues/comments/' in line:
            cid = int(a[3].rsplit('/', 1)[1])
            for rows in self.comments.values():
                for row in rows:
                    if row['id'] == cid:
                        row['body'] = a[-1].split('=', 1)[1]
            return self.ok()
        if a[:2] == ['pr', 'comment']:
            rows = self.comments.setdefault(int(a[2]), [])
            rows.append(dict(id=900 + sum(map(len, self.comments.values())), login=pr_bot.OWNER, body=a[-1]))
            return self.ok()
        if a[:2] == ['pr', 'edit']:
            self.prs[int(a[2])].setdefault('labels', []).append(a[a.index('--add-label') + 1])
            return self.ok()
        if a[:2] == ['pr', 'merge']:
            n = int(a[2])
            self.merges.append(n)
            if self.close_on_merge:
                self.prs[n]['state'] = 'CLOSED'
                return subprocess.CompletedProcess([], 1, b'', b'PR is closed')
            if self.merge_failures:
                self.merge_failures -= 1
                return subprocess.CompletedProcess([], 1, b'', b'merge refused')
            if a[a.index('--match-head-commit') + 1] != self.prs[n]['head']:
                return subprocess.CompletedProcess([], 1, b'', b'head moved')
            w.squash_into_main(n, a[a.index('--subject') + 1])
            self.prs[n]['state'] = 'MERGED'
            return self.ok()
        if a[:2] == ['pr', 'list']:
            if '--head' in a:
                return self.ok([])
            if '--limit' in a:
                return self.ok([])
            return self.ok([self.view(n) for n, p in sorted(self.prs.items()) if p['state'] == 'OPEN'])
        if a[:2] == ['pr', 'view']:
            return self.ok(self.view(int(a[2])))
        if a[:2] == ['pr', 'create']:
            return self.ok()
        m = re.search(r'users/(\w+)', line)
        if m:
            return self.ok({'id': 4242})
        if 'git/refs' in line:
            sha = next((x[4:] for x in a if x.startswith('sha=')), None)
            if sha and sha in ci.policy:
                ci.policy[sha]()
            return self.ok()
        if 'check-runs' in line:
            head = re.search(r'commits/(\w+)/check-runs', line)[1]
            return self.ok([{'check_runs': ci.runs.get(head, [])}])
        m = re.search(r'actions/runs/(\d+)/artifacts', line)
        if m:
            found = ci.artifacts.get(int(m[1]))
            return self.ok({'artifacts': [{'name': 'hash-result', 'expired': False}] if found else []})
        m = re.search(r'actions/runs/(\d+)/jobs', line)
        if m:
            skipped = int(m[1]) in ci.skipped
            return self.ok({'jobs': [{'name': 'hash', 'steps': [
                {'name': 'Compile at base and head', 'conclusion': 'skipped' if skipped else 'success'}]}]})
        m = re.search(r'actions/runs/(\d+)$', line)
        if m:
            rid = int(m[1])
            head = next(h for h, rs in ci.runs.items() if any(r['id'] == rid for r in rs))
            return self.ok({'id': rid, 'head_sha': head, 'run_attempt': 1, 'event': 'pull_request'})
        if 'actions/runs?head_sha' in line:
            return self.ok({'workflow_runs': []})
        if a[:2] == ['run', 'download']:
            target = Path(a[a.index('-D') + 1])
            found = ci.artifacts.get(int(a[2]))
            if found:
                target.mkdir(parents=True, exist_ok=True)
                (target / 'hash-result.json').write_text(json.dumps({f'0x{k:x}': v for k, v in found.items()}))
            return self.ok()
        raise AssertionError(f'unscripted gh call: {line}')


class Reviewers:
    """The Codex and Claude CLIs. Each outcome is 'ok', 'credits' (an account failure) or 'crash'."""

    def __init__(self):
        self.codex = self.claude = 'ok'
        self.calls = []
        self.verdict = 'approve'

    def text(self, prompt):
        rvas = re.search(r'Functions under review: ([0-9a-fx, ]+)', prompt)[1].split(', ')
        return json.dumps({'leak': 'no', 'functions': {r.strip(): {'verdict': self.verdict, 'ground': 'none'}
                                                        for r in rvas}})

    def handle(self, argv, input):
        tool = Path(str(argv[0])).name
        self.calls.append(tool)
        outcome = self.codex if tool == 'codex' else self.claude
        if outcome == 'ok':
            body = self.text(input.decode())
            if tool == 'codex':
                Path(argv[argv.index('--output-last-message') + 1]).write_text(body)
            return subprocess.CompletedProcess(argv, 0, b'' if tool == 'codex' else body.encode(), b'')
        error = b'ERROR: you have run out of credits' if outcome == 'credits' else b'ERROR: the model crashed'
        return subprocess.CompletedProcess(argv, 1, b'', error)


class World:
    """Local bare origin, a contributor clone, the bot's checkout and every scripted boundary."""

    def __init__(self, test):
        tmp = tempfile.TemporaryDirectory()
        test.addCleanup(tmp.cleanup)
        self.dir = Path(tmp.name)
        self.origin = self.dir / 'origin.git'
        git(self.dir, 'init', '-q', '--bare', '-b', 'main', str(self.origin))
        self.src = self.dir / 'src'
        git(self.dir, 'clone', '-q', str(self.origin), str(self.src))
        for name, text in {
                'builds/target.json': json.dumps({'build_id': BUILD}),
                'data/progress.json': json.dumps({'functions': []}),
                'docs/reviewer-runbook.md': '## Checklist (per function)\n- check it\nFor a change to the comparator\n',
                f'reports/{BUILD}/.keep': '', 'reconstruction/fx/.keep': ''}.items():
            path = self.src / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
        git(self.src, 'add', '-A')
        git(self.src, 'commit', '-q', '-m', 'base')
        git(self.src, 'push', '-q', 'origin', 'HEAD:main')
        self.root = self.dir / 'root'
        git(self.dir, 'clone', '-q', str(self.origin), str(self.root))
        (self.root / '.local').mkdir()
        self.github, self.ci, self.reviewers = FakeGitHub(self), FakeCI(), Reviewers()
        self.on_compile = None
        self.compiled = []  # (number, head8) per compile
        self.compile_error = None
        self.bound = []
        self.bind_fails = False
        self.stale_hints = set()  # hint names bind ignores: not defined in the compiled object
        self.recorded = []
        self.wipe_maps_on_merge = False
        self.bots = []
        self.patches = [mock.patch.object(subprocess, 'run', self.route),
                        mock.patch.object(pr_bot.time, 'sleep', lambda s: None)]
        for p in self.patches:
            p.start()
            test.addCleanup(p.stop)

    # ---- the contributor side ----
    def make_pr(self, number, files, author='alice', ci='pass', merge_commit=False, **extra):
        branch = f'pr{number}'
        git(self.src, 'fetch', '-q', 'origin')
        git(self.src, 'checkout', '-q', '-B', branch, 'origin/main')
        base = git(self.src, 'rev-parse', 'HEAD')
        self.write(files)
        git(self.src, 'add', '-A')
        git(self.src, 'commit', '-q', '-m', f'work {number}')
        if merge_commit:
            git(self.src, 'checkout', '-q', '-B', f'side{number}', base)
            (self.src / 'reconstruction/fx/side.txt').write_text('x')
            git(self.src, 'add', '-A')
            git(self.src, 'commit', '-q', '-m', 'side')
            git(self.src, 'checkout', '-q', branch)
            git(self.src, 'merge', '-q', '--no-ff', '-m', 'merge side', f'side{number}')
        head = git(self.src, 'rev-parse', 'HEAD')
        git(self.src, 'push', '-q', '-f', 'origin', f'HEAD:refs/heads/{branch}', f'HEAD:refs/pull/{number}/head')
        self.github.prs[number] = dict(head=head, base=base, author=author, branch=branch, state='OPEN',
                                       mergeable='MERGEABLE', ci=ci, **extra)
        self.new_head_ci(number)
        return head

    def write(self, files):
        for name, text in files.items():
            path = self.src / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)

    def push_to_pr(self, number, files):
        pr = self.github.prs[number]
        git(self.src, 'checkout', '-q', pr['branch'])
        self.write(files)
        git(self.src, 'add', '-A')
        git(self.src, 'commit', '-q', '-m', 'more work')
        pr['head'] = git(self.src, 'rev-parse', 'HEAD')
        git(self.src, 'push', '-q', '-f', 'origin', f'HEAD:refs/heads/{pr["branch"]}', f'HEAD:refs/pull/{number}/head')
        self.new_head_ci(number)
        return pr['head']

    def new_head_ci(self, number):
        pr = self.github.prs[number]
        if pr['ci'] == 'pass':
            self.ci.add(pr['head'], {r: 'pass' for r in self.rvas_of(number)})

    def move_main(self, files):
        git(self.src, 'fetch', '-q', 'origin')
        git(self.src, 'checkout', '-q', '-B', 'mainline', 'origin/main')
        self.write(files)
        git(self.src, 'add', '-A')
        git(self.src, 'commit', '-q', '-m', 'main moves')
        git(self.src, 'push', '-q', 'origin', 'HEAD:main')

    def files_of(self, number):
        pr = self.github.prs[number]
        rows = git(self.origin, 'diff', '--name-status', '--no-renames', pr['base'], pr['head']).splitlines()
        status = {'A': 'added', 'M': 'modified', 'D': 'removed'}
        return [dict(filename=r.split('\t')[1], status=status[r[0]]) for r in rows]

    def rvas_of(self, number):
        rvas = set()
        for item in self.files_of(number):
            text = git(self.origin, 'show', f'{self.github.prs[number]["head"]}:{item["filename"]}', check=False)
            rvas.update(int(m, 16) for m in re.findall(r'^// (0x[0-9a-f]+) ', text, re.M))
        return sorted(rvas)

    def squash_into_main(self, number, subject):
        """What GitHub's own squash button does; the map wipe stands for a later PR's tree clean on the bot."""
        scratch = self.dir / f'squash{number}'
        git(self.dir, 'clone', '-q', str(self.origin), str(scratch))
        git(scratch, 'fetch', '-q', 'origin', f'refs/pull/{number}/head')
        git(scratch, 'merge', '--squash', 'FETCH_HEAD')
        git(scratch, 'commit', '-q', '-m', subject)
        git(scratch, 'push', '-q', 'origin', 'HEAD:main')
        if self.wipe_maps_on_merge:
            for bot in self.bots:
                for tree in bot.work.glob('tree*'):
                    for stale in tree.glob('reports/unit-symbols/*'):
                        stale.unlink()

    def main_files(self):
        return set(git(self.origin, 'ls-tree', '-r', '--name-only', 'main').splitlines())

    def main_log(self):
        return git(self.origin, 'log', '--format=%s', 'main').splitlines()

    # ---- the scripted subprocess boundary ----
    def route(self, argv, **kw):
        names = [str(a) for a in argv]
        tool = Path(names[0]).name
        if tool == 'gh':
            return self.github.handle(names)
        if tool in ('codex', CLAUDE_NAME):
            return self.reviewers.handle(names, kw.get('input') or b'')
        if tool.startswith('python') and any(n.endswith('bind.py') for n in names):
            return self.bind(names, kw)
        if tool.startswith('python') and any(n.endswith('record.py') for n in names):
            return self.record(names, kw)
        if tool.startswith('python') and any(n.endswith('leakgrep.py') for n in names):
            return REAL_RUN(names, cwd=kw.get('cwd'), capture_output=True, input=kw.get('input'))
        if tool == 'git':
            return self.git(names, kw)
        raise AssertionError(f'unscripted command: {names[:3]}')

    def git(self, names, kw):
        if 'push' in names and any(n.startswith('https://') for n in names):
            names = [str(self.origin) if n.startswith('https://') else n for n in names]
        done = REAL_RUN(names, cwd=kw.get('cwd'), capture_output=True, input=kw.get('input'),
                        env={**os.environ, **IDENTITY})
        if 'push' in names:
            self.sync_pr_heads()
        return done

    def sync_pr_heads(self):
        for number, pr in self.github.prs.items():
            # GitHub marks a PR merged once its head is reachable from main, whoever pushed it there.
            if pr['state'] == 'OPEN' and REAL_RUN(['git', 'merge-base', '--is-ancestor', pr['head'], 'main'],
                                                  cwd=self.origin).returncode == 0:
                pr['state'] = 'MERGED'
                continue
            head = git(self.origin, 'rev-parse', f'refs/heads/{pr["branch"]}')
            if head != pr['head'] and pr['state'] == 'OPEN':
                pr['head'], pr['mergeable'] = head, 'MERGEABLE'
                git(self.origin, 'update-ref', f'refs/pull/{number}/head', head)
                self.new_head_ci(number)

    def bind(self, names, kw):
        self.bound.append(Path(kw['cwd']).name)
        if self.bind_fails:
            return subprocess.CompletedProcess(names, 1, b'', b'')
        list_file = Path(names[names.index('--list') + 1])
        task = Path(list_file.parent)
        info = json.loads((task / 'task.json').read_text())
        hints = json.loads((task / 'bind-hints.json').read_text()) if (task / 'bind-hints.json').is_file() else {}
        ignored = sorted(set(hints) & self.stale_hints)
        if ignored:
            out = ''.join(f'  WARNING bind hint {h} -> {hints[h]} ignored: not defined in the compiled object\n'
                          for h in ignored)
            return subprocess.CompletedProcess(names, 1, out.encode(), b'')
        symbols = Path(kw['cwd']) / info['symbols']
        symbols.parent.mkdir(parents=True, exist_ok=True)
        symbols.write_text('{}')
        return subprocess.CompletedProcess(names, 0, b'', b'')

    def record(self, names, kw):
        """tools/record.py: refuses a function whose unit symbol map is not on disk, as the real one does."""
        root = Path(names[names.index('--root') + 1]) if '--root' in names else Path(kw['cwd'])
        rvas = [names[i + 1] for i, n in enumerate(names) if n == '--rva']
        task_id = names[names.index('--task-id') + 1]
        maps = [json.loads(t.read_text())['symbols'] for t in root.glob('.local/tasks/*/task.json')]
        if any(not (root / m).is_file() for m in maps):
            out = json.dumps({'recorded': [], 'refused': {r: 'symbol map does not exist' for r in rvas}, 'files': []})
            return subprocess.CompletedProcess(names, 1, out.encode(), b'')
        files = []
        for r in rvas:
            for suffix, body in (('.json', '{}'), ('.review.json', json.dumps({'review_task_id': task_id}))):
                name = f'reports/{BUILD}/{r}{suffix}'
                (root / name).write_text(body)
                files.append(name)
        self.recorded.append(rvas)
        if '--push' in names:
            git(root, 'add', '--', *files)
            git(root, 'commit', '-q', '-m', f'record {task_id}')
            git(root, 'push', '-q', 'origin', 'HEAD:main')
        return subprocess.CompletedProcess(names, 0, json.dumps({'recorded': rvas, 'refused': {}, 'files': files}).encode(), b'')

    # ---- the bot ----
    def bot(self, dry_run=False, **config):
        bot = ReplayBot(self, dry_run=dry_run, config={**dict(hash_wait=1, download_retry_wait=0), **config})
        bot.work.mkdir(parents=True, exist_ok=True)
        self.bots.append(bot)
        return bot

    def poll(self, bot, times=1):
        """`times` ticks of the real poll loop; each waits for the PRs it started. Returns the log text."""
        out, err = io.StringIO(), io.StringIO()
        with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
            for _ in range(times):
                pr_bot.poll(bot, 1, sleep=lambda s: None, rounds=1)
        return out.getvalue() + err.getvalue()

    def state(self, bot, number, head=None):
        head = head or self.github.prs[number]['head']
        return pr_bot.State(bot.work / 'state', number, head)

    def sticky(self, number):
        return [c['body'] for c in self.github.comments.get(number, [])]


class ReplayBot(pr_bot.Bot):
    """The real bot with only content inspection and the compile host stubbed."""

    def __init__(self, world, dry_run=False, config=None):
        super().__init__(root=world.root, work=world.dir / 'work', dry_run=dry_run, config=config)
        self.world = world
        self.history_note = None

    # Content inspection is covered by its own suites; each of these would need real source and tool pins.
    def header_problems(self, base, head):
        return []

    def lint_problems(self, files):
        return []

    def leakgrep(self, base, head):
        return (False, [])

    def leakgrep_units(self, base, head):
        return (False, [])

    def leakgrep_text(self, text):
        return []

    def header_sizes(self, units):
        return {}

    def companions(self, units, files, functions):
        return {}

    def stale_accepted(self, units, files):
        return []

    def removed_accepted(self, units, files, named):
        return []

    def precheck(self, tag, files, units, functions, host1, host2, state):
        return {}

    def settle_ci_debt(self, host1):
        return host1

    def classify_debt(self, host2, host1, base, units, state):
        return host2

    def carry_host1(self, base, files, functions, units, host1, host2, state):
        return {}

    def pdb_advisory(self, units):
        return []

    def review_context(self, units, functions, evidence=None, changed=None, old_flags=()):
        return 'context'

    def base_origin_flags(self, units, base, tag):
        return set()

    def autofix(self, pr, state, files):
        return False

    def retry_records(self, directory):
        return []

    def close_done_claims(self):
        return []

    def build_records(self, tag, units, rvas, state):
        records = self.work / 'records' / tag.replace('/', '-')
        records.mkdir(parents=True, exist_ok=True)
        return records, set()

    def compare_on_host(self, units, tag):
        """The compile host: leaves the comparator reports and the task's unit symbol map where the real one does."""
        world = self.world
        number, head8 = tag.split('-')[:2]
        world.compiled.append((int(number), head8))
        if world.compile_error:
            raise world.compile_error
        if world.on_compile:
            hook, world.on_compile = world.on_compile, None
            hook()
        out = {}
        for index, (cpp, rvas) in enumerate(sorted(units.items())):
            task = self.tree / '.local/tasks' / f'prbot-{tag}-{index}'
            symbols = f'reports/unit-symbols/{abs(hash(cpp)) % 10 ** 8:08d}.json'
            task.mkdir(parents=True, exist_ok=True)
            (task / 'task.json').write_text(json.dumps(dict(
                task_id=task.name, symbols=symbols, functions=[dict(rva=hex(r)) for r in rvas])))
            (self.tree / symbols).parent.mkdir(parents=True, exist_ok=True)
            (self.tree / symbols).write_text('{}')
            for r in rvas:
                report = task / 'attempts/0' / f'0x{r:x}/report.json'
                report.parent.mkdir(parents=True, exist_ok=True)
                report.write_text('{}')
                out[r] = 'pass'
        return out


class Replay(unittest.TestCase):
    def setUp(self):
        self.w = World(self)
        self.bot = self.w.bot()

    def merged(self, number):
        return self.w.github.prs[number]['state'] == 'MERGED'


class ConcurrentPrTests(Replay):
    def test_the_pack_export_gets_a_timeout_that_grows_with_the_rows_and_its_own_process_group(self):
        tree = self.bot.tree
        (tree / 'builds').mkdir(parents=True, exist_ok=True)
        (tree / 'builds/target.json').write_text(json.dumps({'build_id': BUILD}))
        rvas = list(range(0x1000, 0x1000 + 0x10 * 150, 0x10))
        cpp = unit_path(0x1000)
        (tree / cpp).parent.mkdir(parents=True, exist_ok=True)
        (tree / cpp).write_text(unit(0x1000))
        seen = []

        def run(argv, **kw):
            seen.append(kw)
            raise subprocess.TimeoutExpired(argv, kw.get('timeout'))
        self.bot.run = run
        with self.assertRaises(pr_bot.HostFailure):
            pr_bot.Bot.compare_on_host(self.bot, {cpp: rvas}, '7-abcdef01')
        self.assertEqual(seen[0]['timeout'], pr_bot.pack_export_timeout(150))
        self.assertGreater(seen[0]['timeout'], 900 + 150)
        self.assertTrue(seen[0]['own_group'])

    def test_two_prs_are_worked_at_once_on_their_own_trees_and_both_land_in_one_commit_each(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.make_pr(8, {unit_path(0x2000): unit(0x2000)}, author='bob')
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7) and self.merged(8), log)
        self.assertEqual({p.name for p in self.bot.work.glob('tree*')}, {'tree', 'tree-1'})
        names = self.w.main_files()
        for rva in (0x1000, 0x2000):
            self.assertIn(unit_path(rva), names)
            self.assertIn(f'reports/{BUILD}/0x{rva:x}.json', names)
        self.assertEqual(self.w.github.merges, [])  # the bot's own squash landed them, not the plain merge
        squashes = [s for s in self.w.main_log() if s.startswith('Reconstruct')]
        self.assertEqual(len(squashes), 2)
        self.assertEqual(len(re.findall(r'"merge": true', log)), 2)


class ConflictLaneTests(Replay):
    def test_a_conflicting_pr_is_answered_while_every_slot_is_busy_compiling(self):
        self.w.move_main({unit_path(0x3000): unit(0x3000)})
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, author='alice')
        self.w.make_pr(8, {unit_path(0x2000): unit(0x2000)}, author='bob')
        self.w.make_pr(9, {unit_path(0x3000): unit(0x3000).replace('return 1', 'return 2')}, author='carol')
        self.w.move_main({unit_path(0x3000): unit(0x3000).replace('return 1', 'return 3')})
        self.w.github.prs[9]['mergeable'] = 'CONFLICTING'
        released = threading.Event()
        busy_until_answered = []
        original = ReplayBot.attempt

        def attempt(bot, pr, now=None):
            # Both slots sit here until PR 9 has been answered; a bot that queues PR 9 behind them never gets there.
            if pr['number'] != 9:
                busy_until_answered.append(released.wait(15))
            return original(bot, pr, now)

        def watch():
            for _ in range(200):
                if self.w.sticky(9):
                    released.set()
                    return
                threading.Event().wait(0.05)  # the world's clock is stubbed; this wait is real
            released.set()
            busy_until_answered.append('timeout')
        watcher = threading.Thread(target=watch)
        watcher.start()
        with mock.patch.object(ReplayBot, 'attempt', attempt):
            self.w.poll(self.bot)
        watcher.join()
        self.assertEqual(busy_until_answered, [True, True])
        self.assertIn('conflicts with main', self.w.sticky(9)[0])
        self.assertTrue(self.merged(7) and self.merged(8))


class ExportGroupTests(unittest.TestCase):
    def test_ending_the_bot_kills_a_running_export_and_its_children(self):
        marker = Path(tempfile.mkdtemp()) / 'child.pid'
        script = ("import subprocess, sys, time\n"
                  "child = subprocess.Popen([sys.executable, '-c', 'import time; time.sleep(60)'])\n"
                  f"open({str(marker)!r}, 'w').write(str(child.pid))\n"
                  "time.sleep(60)\n")
        failure = []

        def export():
            try:
                pr_bot.run_in_group([sys.executable, '-c', script], None, None, 120)
            except BaseException as exc:
                failure.append(exc)
        pr_bot.TERMINATING.clear()
        thread = threading.Thread(target=export, daemon=True)
        thread.start()
        for _ in range(200):
            if marker.exists() and marker.read_text():
                break
            time.sleep(0.05)
        grandchild = int(marker.read_text())
        try:
            self.assertTrue(pr_bot.LIVE_GROUPS)
            pr_bot.kill_live_groups()
            for _ in range(100):
                try:
                    os.kill(grandchild, 0)
                except ProcessLookupError:
                    break
                time.sleep(0.05)
            else:
                os.kill(grandchild, 9)
                self.fail("the exporter's child outlived the group kill")
            self.assertEqual(failure, [])  # the killed export is not raised as a failure while the bot leaves
        finally:
            pr_bot.TERMINATING.clear()
            with pr_bot.LIVE_GROUPS_LOCK:
                pr_bot.LIVE_GROUPS.clear()


class ReviewerTests(Replay):
    def test_codex_out_of_credits_falls_back_to_sonnet_and_is_skipped_by_every_slot_afterwards(self):
        self.w.reviewers.codex = 'credits'
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertEqual(self.w.state(self.bot, 7).get('reviewer'), pr_bot.CLAUDE_REVIEW_MODEL)
        self.assertIn('codex unavailable', log)
        self.w.make_pr(8, {unit_path(0x2000): unit(0x2000)})
        self.w.reviewers.calls.clear()
        self.w.poll(self.bot)
        self.assertEqual(self.w.reviewers.calls, [CLAUDE_NAME])  # codex is paused for the whole bot
        self.assertTrue(self.merged(8))

    def test_a_codex_crash_that_is_not_an_account_problem_does_not_fall_back(self):
        self.w.reviewers.codex = 'crash'
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        log = self.w.poll(self.bot)
        self.assertFalse(self.merged(7))
        self.assertIn('codex failed (ERROR: the model crashed)', log)
        self.assertEqual(self.w.reviewers.calls, ['codex'])
        self.assertEqual(self.w.sticky(7), [])  # a bot fault is not shown as a finding

    def test_both_reviewers_failing_is_retried_and_never_merges(self):
        self.w.reviewers.codex = 'credits'
        self.w.reviewers.claude = 'crash'
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        log = self.w.poll(self.bot, times=2)
        self.assertFalse(self.merged(7))
        self.assertEqual(log.count('claude failed'), 2)

    def test_a_review_cached_by_one_worker_thread_is_used_by_a_fresh_one(self):
        # The plain merge fails once with the head unchanged; the next tick runs on a new pool thread, whose
        # thread-local reviewer was never set, and must reuse the cached review instead of paying for another.
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, merge_commit=True)
        self.w.github.merge_failures = 1
        first = self.w.poll(self.bot)
        self.assertFalse(self.merged(7), first)
        self.assertIn('merge refused with the head unchanged', first)
        second = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), second)
        self.assertNotIn('AttributeError', first + second)
        self.assertEqual(self.w.reviewers.calls, ['codex'])
        self.assertEqual(self.w.state(self.bot, 7).get('reviewer'), 'codex')


class ChunkedReviewTests(Replay):
    """A big PR is reviewed in chunks of whole units, three at a time, and merged into one verdict per function."""

    RVAS = list(range(0x1000, 0x1000 + 0x10 * 150, 0x10))

    def big_pr(self):
        self.w.make_pr(7, {unit_path(r): unit(r) for r in self.RVAS})

    def listed(self, prompt):
        return [int(x, 16) for x in re.search(r'Functions under review: ([0-9a-fx, ]+)', prompt)[1].split(', ')]

    def watch(self, fail_when=lambda rvas: False):
        """Record each model call's functions and the most calls in flight at once; fail the calls `fail_when` picks."""
        seen, lock = [], threading.Lock()
        live = dict(now=0, peak=0)
        real = self.w.reviewers.handle

        def handle(argv, input):
            rvas = self.listed(input.decode())
            with lock:
                seen.append(rvas)
                live['now'] += 1
                live['peak'] = max(live['peak'], live['now'])
            try:
                if fail_when(rvas):
                    return subprocess.CompletedProcess(argv, 1, b'', b'ERROR: the model crashed')
                return real(argv, input)
            finally:
                with lock:
                    live['now'] -= 1
        self.w.reviewers.handle = handle
        return seen, live

    def test_chunks_hold_whole_units_up_to_the_size_and_cover_every_function_once(self):
        units = {unit_path(r): [r] for r in self.RVAS}
        units['reconstruction/fx/Big.cpp'] = list(range(0x9000, 0x9000 + 0x10 * 95, 0x10))
        everything = self.RVAS + units['reconstruction/fx/Big.cpp'] + [0xf0000]
        chunks = pr_bot.review_chunks(everything, units, 40)
        self.assertTrue(all(0 < len(c) <= 40 for c in chunks))
        self.assertEqual(sorted(r for c in chunks for r in c), sorted(everything))
        self.assertEqual(len(chunks), 7)
        small = pr_bot.review_chunks([1, 2, 3], {'a.cpp': [1, 2], 'b.cpp': [3]}, 40)
        self.assertEqual(small, [[1, 2, 3]])

    def test_a_150_function_pr_is_reviewed_in_four_chunks_at_most_three_at_a_time_and_lands(self):
        self.big_pr()
        seen, live = self.watch()
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertEqual(len(seen), 4)
        self.assertTrue(all(len(c) <= 40 for c in seen))
        self.assertEqual(sorted(r for c in seen for r in c), self.RVAS)  # one verdict from one chunk each
        self.assertLessEqual(live['peak'], 3)
        names = self.w.main_files()
        self.assertTrue(all(f'reports/{BUILD}/0x{r:x}.json' in names for r in self.RVAS))

    def test_a_failed_chunk_is_retried_alone_and_the_finished_chunks_are_not_paid_for_again(self):
        self.big_pr()
        doomed = {}
        seen, _ = self.watch(lambda rvas: self.RVAS[0] in rvas and doomed.get('on', True))
        first = self.w.poll(self.bot)
        self.assertFalse(self.merged(7), first)
        self.assertEqual(self.w.sticky(7), [])  # a model failure is a bot fault, not a finding
        self.assertEqual(len(seen), 4)
        state = self.w.state(self.bot, 7)
        self.assertEqual(len([k for k in state.data if k.startswith('review_chunk')]), 3)
        self.assertIsNone(state.get('review_text'))
        doomed['on'] = False
        seen.clear()
        second = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), second)
        self.assertEqual(len(seen), 1)
        self.assertIn(self.RVAS[0], seen[0])

    def test_the_merged_verdicts_keep_one_decision_per_function_and_a_leak_in_any_chunk_blocks_the_pr(self):
        self.big_pr()
        target = self.RVAS[100]
        real = self.w.reviewers.text

        def text(prompt):
            rvas = self.listed(prompt)
            if target not in rvas:
                return real(prompt)
            rows = {f'0x{r:x}': {'verdict': 'reject' if r == target else 'approve', 'ground': 'plausibility',
                                 'why': 'invented'} for r in rvas}
            return json.dumps({'leak': 'yes', 'leak_evidence': ['steering'], 'functions': rows})
        self.w.reviewers.text = text
        log = self.w.poll(self.bot)
        self.assertFalse(self.merged(7), log)
        decision = self.w.state(self.bot, 7).get('decision')
        self.assertEqual(set(map(int, decision['verdicts'])), set(self.RVAS))
        whole = [p for p in (self.bot.work / 'reviews').glob('pr7-*.txt') if '-c' not in p.stem]
        self.assertEqual(len(whole), 1)
        merged = json.loads(whole[0].read_text())
        self.assertEqual(merged['leak'], 'yes')
        self.assertEqual(merged['leak_evidence'], ['steering'])
        self.assertEqual(merged['functions'][f'0x{target:x}']['verdict'], 'reject')
        self.assertEqual(len(merged['functions']), 150)

    def test_merge_takes_the_worst_leak_reading_and_an_unreadable_chunk_rejects_its_functions(self):
        good = json.dumps({'leak': 'no', 'functions': {'0x10': {'verdict': 'approve'}}})
        junk = 'no json here'
        merged = pr_bot.merge_review_texts([good, junk])
        self.assertEqual(pr_bot.parse_review(merged, [0x10, 0x20]), ('unreadable', {0x10: 'approve', 0x20: 'reject'}))
        steer = json.dumps({'leak': 'yes', 'leak_evidence': ['host-path'], 'functions': {'0x20': {'verdict': 'approve'}}})
        self.assertEqual(pr_bot.parse_review(pr_bot.merge_review_texts([good, junk, steer]), [0x10, 0x20])[0], 'yes')
        opinion = json.dumps({'leak': 'yes', 'functions': {'0x20': {'verdict': 'approve'}}})
        self.assertEqual(pr_bot.parse_review(pr_bot.merge_review_texts([good, opinion]), [0x10, 0x20])[0], 'no')


class HashJobTests(Replay):
    def test_a_job_that_leaves_no_result_is_retried_three_times_then_blocked_not_looped(self):
        head = self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, ci='none')
        self.w.ci.add(head, None)  # finished, uploaded nothing, compile step not skipped
        self.w.ci.policy[head] = lambda: self.w.ci.add(head, None, started=FUTURE)
        log = self.w.poll(self.bot, times=5)
        self.assertEqual(log.count('pr 7: Stop: hash check left no result'), 2, log)
        self.assertEqual(self.w.state(self.bot, 7).get('blocked'), 'bot-error')
        self.assertEqual(log.count('BLOCKED bot-error'), 1)
        self.assertFalse(self.merged(7))

    def test_a_job_that_requested_no_function_is_an_empty_result_and_is_not_probed_again(self):
        head = self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, ci='none')
        self.w.ci.add(head, None, skipped=True)
        log = self.w.poll(self.bot)
        probes = [c for c in self.w.github.calls if 'POST' in c and any('git/refs' in x for x in c)]
        self.assertEqual(probes, [], log)
        self.assertNotIn('left no result', log)
        summary = self.w.state(self.bot, 7).get('summary')
        self.assertEqual(summary['verdicts'], {'0x1000': 'fail:host1'})
        self.assertFalse(self.merged(7))

    def test_a_listed_artifact_that_will_not_download_is_a_stop_and_not_an_unusable_run(self):
        head = self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, ci='none')
        run = self.w.ci.add(head, {0x1000: 'pass'})
        original = self.w.github.route

        def deaf(a):
            return self.w.github.ok() if a[:2] == ['run', 'download'] else original(a)
        self.w.github.route = deaf
        log = self.w.poll(self.bot)
        self.assertIn('hash artifact is listed but did not download', log)
        self.assertEqual(run['id'], self.w.ci.runs[head][0]['id'])
        self.assertFalse(self.merged(7))

    def test_a_job_still_running_is_waited_for_without_ever_opening_the_breaker(self):
        head = self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, ci='none')
        bot = self.w.bot(hash_wait=0)
        log = self.w.poll(bot, times=4)
        self.assertIn('hash check has not finished', log)
        self.assertIsNone(self.w.state(bot, 7).get('blocked'))
        self.assertNotIn('BLOCKED', log)
        self.assertTrue(head)


class RejectedHeadTests(Replay):
    def test_a_rejected_head_is_said_once_and_never_looked_at_again_until_a_push(self):
        self.w.make_pr(7, {unit_path(0x1000): 'int Nothing() { return 0; }\n'})
        self.w.poll(self.bot)
        self.assertEqual(len(self.w.sticky(7)), 1)
        self.assertIn('header', self.w.sticky(7)[0])
        before = len(self.w.github.calls)
        self.w.poll(self.bot, times=3)
        later = self.w.github.calls[before:]
        self.assertEqual([c for c in later if any('pulls/' in x for x in c) or c[:2] == ['pr', 'view']], [])
        self.assertEqual(len(self.w.sticky(7)), 1)
        self.w.push_to_pr(7, {unit_path(0x1000): unit(0x1000)})
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertEqual(len(self.w.sticky(7)), 1)  # the one comment was edited, not duplicated


class ListedPathMissingTests(Replay):
    def test_a_listed_file_the_head_does_not_hold_is_not_a_stop_and_the_pr_still_lands(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        listed = self.w.files_of
        self.w.files_of = lambda number: listed(number) + [
            dict(filename='reconstruction/fx/ghost.txt', status='modified')]
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertNotIn('git failed', log)


class MainMovesTests(Replay):
    def test_main_moving_during_the_compile_does_not_stale_the_landing(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.on_compile = lambda: self.w.move_main({'reconstruction/fx/other.txt': 'moved\n'})
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        names = self.w.main_files()
        self.assertTrue({'reconstruction/fx/other.txt', unit_path(0x1000)} <= names)

    def test_a_header_only_conflict_gets_main_merged_into_the_branch_and_the_new_head_lands(self):
        base_unit = unit(0x1000)
        self.w.move_main({unit_path(0x1000): base_unit})
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000, '// pr note\n')})
        self.w.move_main({unit_path(0x1000): unit(0x1000, '// main note\n')})
        old = self.w.github.prs[7]['head']
        self.w.github.prs[7]['mergeable'] = 'CONFLICTING'
        self.w.wipe_maps_on_merge = True
        first = self.w.poll(self.bot)
        new = self.w.github.prs[7]['head']
        self.assertNotEqual(new, old, first)
        self.assertEqual(len(git(self.w.origin, 'rev-list', '--parents', '-1', new).split()), 3)  # a merge commit
        self.assertEqual(self.w.sticky(7), [])  # nothing is said when the bot repaired it
        second = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), second)
        text = git(self.w.origin, 'show', f'main:{unit_path(0x1000)}')
        self.assertIn('// main note', text)
        self.assertIn('// pr note', text)
        # A merge commit in the history takes the plain squash; its records are written afterwards, with the maps
        # the tree clean removed bound again.
        self.assertEqual(self.w.github.merges, [7])
        self.assertTrue(self.w.bound)
        self.assertIn(f'reports/{BUILD}/0x1000.json', self.w.main_files())

    def test_a_conflict_in_a_function_body_is_left_to_the_author_and_said_once(self):
        self.w.move_main({unit_path(0x1000): unit(0x1000)})
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000).replace('return 1', 'return 2')})
        self.w.move_main({unit_path(0x1000): unit(0x1000).replace('return 1', 'return 3')})
        self.w.github.prs[7]['mergeable'] = 'CONFLICTING'
        old = self.w.github.prs[7]['head']
        self.w.poll(self.bot, times=2)
        self.assertEqual(self.w.github.prs[7]['head'], old)
        self.assertEqual(len(self.w.sticky(7)), 1)
        self.assertIn('conflicts with main', self.w.sticky(7)[0])


class SquashWithRecordsTests(Replay):
    def test_the_unit_symbol_maps_the_tree_clean_removed_are_bound_again_before_the_records(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertTrue(self.w.bound, 'the clean of reports/ must have forced a bind')
        self.assertEqual(self.w.github.merges, [])
        squash = git(self.w.origin, 'show', '--name-only', '--format=', 'main^1').split()
        self.assertEqual(set(squash), {f'reports/{BUILD}/0x1000.json', f'reports/{BUILD}/0x1000.review.json',
                                       unit_path(0x1000)})

    def test_without_the_rebind_the_records_are_refused_and_the_fixture_notices(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        with mock.patch.object(pr_bot.Bot, 'rebind_unit_maps', lambda *a: None):
            log = self.w.poll(self.bot)
        self.assertEqual(self.w.github.merges, [7], log)  # fell back to the plain squash: main would be stale

    def test_a_map_that_cannot_be_bound_again_stops_instead_of_taking_the_plain_squash(self):
        # The plain squash would leave every accepted record stale on main until a retry; a bind failure is
        # retried as a whole instead, and main is not touched.
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.bind_fails = True
        before = git(self.w.origin, 'rev-parse', 'main')
        log = self.w.poll(self.bot)
        self.assertIn('could not bind the unit symbol map', log)
        self.assertEqual(self.w.github.merges, [])
        self.assertEqual(git(self.w.origin, 'rev-parse', 'main'), before)
        self.w.bind_fails = False
        self.assertTrue(self.merged(7) or self.w.poll(self.bot) is not None)
        self.assertTrue(self.merged(7))


class ClosedPrTests(Replay):
    """A PR closed while the bot works on it is skipped and forgotten, never merged or retried."""

    def state_files(self, number):
        return sorted((self.bot.work / 'state').glob(f'pr{number}-*.json'))

    def test_a_pr_closed_during_the_review_is_not_merged_and_leaves_no_state(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        handle = self.w.reviewers.handle

        def close_then_review(names, data):
            self.w.github.prs[7]['state'] = 'CLOSED'
            return handle(names, data)
        with mock.patch.object(self.w.reviewers, 'handle', close_then_review):
            first = self.w.poll(self.bot)
        self.assertIn('no longer open', first)
        self.assertEqual(self.w.github.merges, [])
        self.assertEqual(self.state_files(7), [])
        main = git(self.w.origin, 'rev-parse', 'main')
        calls = len(self.w.github.calls)
        self.w.poll(self.bot, times=2)
        self.assertEqual(self.w.github.merges, [])
        self.assertEqual(git(self.w.origin, 'rev-parse', 'main'), main)
        self.assertEqual(self.state_files(7), [])
        self.assertFalse([c for c in self.w.github.calls[calls:] if c[:2] == ['pr', 'view']])

    def test_a_pr_closed_while_the_merge_request_is_in_flight_is_forgotten_not_retried(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.github.close_on_merge = True
        with mock.patch.object(pr_bot.Bot, 'land_with_records', lambda *a: False):
            first = self.w.poll(self.bot)
        self.assertEqual(self.w.github.merges, [7], first)
        self.assertIn('no longer open', first)
        self.assertNotIn('retrying next tick', first)
        self.assertEqual(self.state_files(7), [])
        self.w.poll(self.bot, times=2)
        self.assertEqual(self.w.github.merges, [7])  # no second attempt on a closed PR

    def test_a_pr_the_bot_merged_keeps_its_state_for_the_record_retry(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.poll(self.bot)
        self.assertTrue(self.merged(7))
        state = self.state_files(7)
        self.assertTrue(state)
        pr = dict(number=7, headRefOid=self.w.github.prs[7]['head'])
        self.bot.closed(pr, self.w.state(self.bot, 7))
        self.assertEqual(self.state_files(7), state)


class StaleRecordedHintTests(Replay):
    """A recorded symbol hint that the unit's new text outgrew must not stop the record of a function that bound."""
    OLD_NAME, STATED_NAME = '?Func@C@@QEAAXXZ', '?Stated@C@@QEAAXXZ'

    def task(self, hints, unit_text):
        cpp = 'reconstruction/fx/U1000.cpp'
        (self.bot.tree / cpp).parent.mkdir(parents=True, exist_ok=True)
        (self.bot.tree / cpp).write_text(unit_text)
        task = self.bot.tree / '.local/tasks/prbot-7-abcdef12-0'
        task.mkdir(parents=True, exist_ok=True)
        info = dict(task_id=task.name, symbols='reports/unit-symbols/x.json', compiled=cpp,
                    functions=[dict(rva='0x1000')])
        (task / 'task.json').write_text(json.dumps(info))
        (task / 'bind-hints.json').write_text(json.dumps(hints))
        return task, info

    def test_a_recorded_hint_bind_ignores_is_dropped_and_the_map_is_bound(self):
        self.w.stale_hints = {self.OLD_NAME}
        task, info = self.task({self.OLD_NAME: '0x1000'}, unit(0x1000))
        bound = self.bot.bind_unit_map(task, info, {0x1000})
        self.assertIsNotNone(bound)
        self.assertEqual(self.w.bound, [self.bot.tree.name] * 2)
        self.assertEqual(json.loads((task / 'bind-hints.json').read_text()), {})
        self.assertEqual([f['rva'] for f in json.loads((task / 'task.json').read_text())['functions']], ['0x1000'])

    def test_a_hint_the_unit_itself_states_stays_fatal(self):
        self.w.stale_hints = {self.STATED_NAME}
        task, info = self.task({self.STATED_NAME: '0x1000'},
                               f'// CI hash: 0x1000 {self.STATED_NAME}\n' + unit(0x1000))
        self.assertIsNone(self.bot.bind_unit_map(task, info, {0x1000}))
        self.assertEqual(json.loads((task / 'bind-hints.json').read_text()), {self.STATED_NAME: '0x1000'})

    def test_a_recorded_hint_that_still_binds_is_kept(self):
        task, info = self.task({self.OLD_NAME: '0x1000'}, unit(0x1000))
        self.assertIsNotNone(self.bot.bind_unit_map(task, info, {0x1000}))
        self.assertEqual(self.w.bound, [self.bot.tree.name])
        self.assertEqual(json.loads((task / 'bind-hints.json').read_text()), {self.OLD_NAME: '0x1000'})


class OwnerAndScopeTests(Replay):
    def test_an_owner_pr_that_changes_only_reconstruction_is_processed_without_a_label(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, author=pr_bot.OWNER)
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)

    def test_an_owner_pr_that_touches_anything_else_is_left_alone(self):
        self.w.make_pr(7, {'tools/x.py': 'print(1)\n'}, author=pr_bot.OWNER)
        self.w.make_pr(8, {unit_path(0x2000): unit(0x2000), 'docs/x.md': 'x\n'}, author=pr_bot.OWNER)
        self.w.poll(self.bot, times=2)
        self.assertEqual((self.merged(7), self.merged(8)), (False, False))
        self.assertEqual(self.w.sticky(7) + self.w.sticky(8), [])
        self.assertEqual(self.w.reviewers.calls, [])

    def test_a_labelled_owner_pr_is_processed_even_with_other_files(self):
        self.w.make_pr(7, {'tools/x.py': 'print(1)\n'}, author=pr_bot.OWNER, labels=[pr_bot.OPT_IN_LABEL])
        self.w.poll(self.bot)
        self.assertIn(pr_bot.TOOLING_LABEL, self.w.github.prs[7]['labels'])

    def test_a_contributor_tooling_pr_is_labelled_and_explained_never_merged_or_reviewed(self):
        self.w.make_pr(7, {'tools/x.py': 'print(1)\n'})
        self.w.poll(self.bot)
        self.assertIn(pr_bot.TOOLING_LABEL, self.w.github.prs[7]['labels'])
        self.assertIn('tooling PR', self.w.sticky(7)[0])
        self.assertEqual((self.merged(7), self.w.github.merges, self.w.reviewers.calls, self.w.compiled), (False, [], [], []))

    def test_a_contributor_pr_mixing_tooling_and_units_is_a_scope_finding_without_a_compile(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000), 'tools/x.py': 'print(1)\n'})
        self.w.poll(self.bot)
        self.assertEqual(self.w.state(self.bot, 7).get('decision')['blocked'], 'scope')
        self.assertEqual(len(self.w.sticky(7)), 1)
        self.assertEqual(self.w.compiled, [])


class CarriedRecordsTests(Replay):
    """An owner PR that brings its own match records, inventory and images lands without a new compile or review."""

    def carried_files(self, rva=0x1000, review=True, listed=True, verdict='approve'):
        name = f'reports/{BUILD}/0x{rva:x}'
        files = {unit_path(rva): unit(rva), f'{name}.json': json.dumps(dict(
            function_id=f'{BUILD}-0x{rva:x}', source=dict(compiled=unit_path(rva)))),
            'data/progress.json': json.dumps({'functions': [dict(
                build_id=BUILD, rva=rva, status='matched', report=f'{name}.json')] if listed else []}),
            'docs/progress-map.svg': '<svg/>\n', 'reconstruction/INDEX.md': 'index\n'}
        if review:
            files[f'{name}.review.json'] = json.dumps(dict(function_id=f'{BUILD}-0x{rva:x}', verdict=verdict))
        return files

    def add_check(self, number, conclusion='success'):
        head = self.w.github.prs[number]['head']
        self.w.ci.runs.setdefault(head, []).append(dict(
            id=900 + number, name='check', head_sha=head, status='completed', conclusion=conclusion,
            started_at=OLD, details_url='https://ci.invalid/runs/1'))

    def test_the_poll_takes_an_owner_pr_with_records_and_merges_it_with_no_compile_or_review(self):
        self.w.make_pr(7, self.carried_files(), author=pr_bot.OWNER)
        self.add_check(7)
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertEqual((self.w.reviewers.calls, self.w.compiled, self.w.recorded), ([], [], []))
        self.assertTrue(self.w.main_log()[0].startswith('Land 1 carried match record'))

    def test_a_missing_review_record_blocks_the_merge_and_says_which(self):
        self.w.make_pr(7, self.carried_files(review=False), author=pr_bot.OWNER)
        self.add_check(7)
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))
        self.assertEqual(self.w.state(self.bot, 7).get('decision')['blocked'], 'carried')
        self.assertIn('0x1000', self.w.sticky(7)[0])

    def test_a_function_listed_as_matched_without_a_record_in_the_pr_blocks_the_merge(self):
        files = self.carried_files()
        files['data/progress.json'] = json.dumps({'functions': [
            dict(build_id=BUILD, rva=0x1000, status='matched', report=f'reports/{BUILD}/0x1000.json'),
            dict(build_id=BUILD, rva=0x2000, status='matched', report=f'reports/{BUILD}/0x2000.json')]})
        self.w.make_pr(7, files, author=pr_bot.OWNER)
        self.add_check(7)
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))
        self.assertIn('0x2000 is newly matched', ' '.join(self.w.state(self.bot, 7).get('decision')['problems']))

    def test_an_unapproved_review_record_blocks_the_merge(self):
        self.w.make_pr(7, self.carried_files(verdict='reject'), author=pr_bot.OWNER)
        self.add_check(7)
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))

    def test_a_failed_check_job_blocks_the_merge(self):
        self.w.make_pr(7, self.carried_files(), author=pr_bot.OWNER)
        self.add_check(7, conclusion='failure')
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))
        self.assertEqual(self.w.state(self.bot, 7).get('decision')['blocked'], 'ci')

    def test_the_leak_scan_of_a_carried_pr_reads_unit_source_and_not_the_digests_in_records(self):
        digest = '0123456789abcdef' * 4
        files = self.carried_files()
        files[f'reports/{BUILD}/0x1000.json'] = json.dumps(dict(
            function_id=f'{BUILD}-0x1000', source=dict(compiled=unit_path(0x1000)), code_section_sha256=digest))
        head = self.w.make_pr(7, files, author=pr_bot.OWNER)
        base = self.w.github.prs[7]['base']
        # the bot's checkout needs the PR's objects, as the lane's own fetch gives it
        git(self.w.root, 'fetch', '-q', 'origin', 'refs/pull/7/head')
        self.assertEqual(pr_bot.Bot.leakgrep_units(self.bot, base, head), (False, []))
        full = pr_bot.Bot.leakgrep(self.bot, base, head)
        self.assertTrue(full[0], 'the full scan is expected to flag the digest, which is why the lane scopes it')

    def test_a_contributor_pr_with_the_same_files_is_a_scope_finding_not_a_carried_merge(self):
        self.w.make_pr(7, self.carried_files(), author='alice')
        self.add_check(7)
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))
        self.assertEqual(self.w.state(self.bot, 7).get('decision')['blocked'], 'scope')


class CircuitBreakerTests(Replay):
    def setUp(self):
        super().setUp()
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.compile_error = AttributeError("'_thread._local' object has no attribute 'reviewer'")

    def test_the_third_identical_error_blocks_the_head_with_one_log_line_and_a_clean_comment(self):
        log = self.w.poll(self.bot, times=3)
        state = self.w.state(self.bot, 7)
        self.assertEqual(state.get('blocked'), 'bot-error')
        self.assertIn('AttributeError', state.get('bot_error')['signature'])
        self.assertEqual(state.get('bot_error')['count'], 3)
        self.assertEqual(log.count('BLOCKED bot-error'), 1)
        body = self.w.sticky(7)
        self.assertEqual(len(body), 1)
        self.assertIn('internal error', body[0])
        self.assertIn('maintainer agent will look', body[0])
        for leak in ('Traceback', 'File "', 'AttributeError', '_thread'):
            self.assertNotIn(leak, body[0])
        seen = len(self.w.compiled)
        quiet = self.w.poll(self.bot, times=3)
        self.assertEqual(len(self.w.compiled), seen)
        self.assertNotIn('BLOCKED', quiet)
        self.assertEqual(len(self.w.sticky(7)), 1)

    def test_a_new_head_starts_counting_again(self):
        self.w.poll(self.bot, times=3)
        self.w.push_to_pr(7, {unit_path(0x1000): unit(0x1000, '// again\n')})
        seen = len(self.w.compiled)
        self.w.poll(self.bot, times=2)
        self.assertEqual(len(self.w.compiled), seen + 2)
        new = self.w.state(self.bot, 7)
        self.assertEqual(new.get('bot_error')['count'], 2)
        self.assertIsNone(new.get('blocked'))

    def test_a_deploy_lifts_the_block_and_restarts_the_count(self):
        self.w.poll(self.bot, times=3)
        seen = len(self.w.compiled)
        redeployed = self.w.bot(code_sha='f' * 40)
        self.w.poll(redeployed, times=1)
        self.assertEqual(len(self.w.compiled), seen + 1)
        self.assertEqual(self.w.state(redeployed, 7).get('bot_error')['count'], 1)

    def test_errors_that_differ_do_not_add_up(self):
        for error in (KeyError('a'), ValueError('b'), KeyError('a'), ValueError('b')):
            self.w.compile_error = error
            self.w.poll(self.bot)
        self.assertIsNone(self.w.state(self.bot, 7).get('blocked'))

    def test_a_good_tick_clears_the_count(self):
        self.w.poll(self.bot, times=2)
        self.w.compile_error = None
        self.w.poll(self.bot)
        state = self.w.state(self.bot, 7)
        self.assertIsNone(state.get('bot_error'))
        self.assertTrue(self.merged(7))


class SignatureTests(unittest.TestCase):
    def test_numbers_hashes_and_hex_do_not_split_one_error_into_many(self):
        a = error_of(pr_bot.Stop('hash run 123456 for deadbeefcafe0123 failed at 0x1f40'))
        b = error_of(pr_bot.Stop('hash run 9 for 0123456789abcdef failed at 0xabc'))
        self.assertEqual(pr_bot.error_signature(a), pr_bot.error_signature(b))

    def test_an_unexpected_error_names_where_it_was_raised(self):
        def one():
            raise KeyError('x')

        def two():
            raise KeyError('x')
        self.assertNotEqual(pr_bot.error_signature(error_of(one)), pr_bot.error_signature(error_of(two)))
        self.assertNotIn('Traceback', pr_bot.error_signature(error_of(one)))


def error_of(raiser):
    try:
        if isinstance(raiser, BaseException):
            raise raiser
        raiser()
    except Exception as exc:
        return exc


class DryRunTests(Replay):
    def test_every_open_pr_is_run_without_one_write_and_without_touching_the_live_state(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        self.w.make_pr(8, {unit_path(0x2000): 'int Nothing() { return 0; }\n'})
        self.w.make_pr(9, {'tools/x.py': 'print(1)\n'})
        before = git(self.w.origin, 'rev-parse', 'main')
        bot = self.w.bot(dry_run=True)
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            failures = pr_bot.dry_run_open_prs(bot)
        self.assertEqual(failures, 0, out.getvalue())
        self.assertIn('dry run pr 7', out.getvalue())
        self.assertIn('stopped before spending on: local compare', out.getvalue())
        self.assertIn('rejected', out.getvalue())
        executed = [c for c in self.w.github.calls if pr_bot.is_write(['gh', *c])]
        self.assertEqual(executed, [])
        self.assertEqual(self.w.github.comments, {})
        self.assertEqual(self.w.reviewers.calls, [])
        self.assertEqual(git(self.w.origin, 'rev-parse', 'main'), before)
        self.assertFalse((bot.work / 'state').exists())

    def test_any_exception_in_the_code_under_test_fails_the_run(self):
        self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)})
        bot = self.w.bot(dry_run=True)
        bot.units = lambda files: (_ for _ in ()).throw(AttributeError('broken'))
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            failures = pr_bot.dry_run_open_prs(bot)
        self.assertEqual(failures, 1)
        self.assertIn('FAILED AttributeError: broken', out.getvalue())

    def test_a_probe_the_bot_would_request_is_refused_not_sent(self):
        head = self.w.make_pr(7, {unit_path(0x1000): unit(0x1000)}, ci='none')
        bot = self.w.bot(dry_run=True)
        with self.assertRaises(pr_bot.WouldSpend):
            bot.host1(7, head, [0x1000])
        self.assertEqual([c for c in self.w.github.calls if 'POST' in c and any('git/refs' in x for x in c)], [])
        self.assertTrue(bot.blocked_writes)

    def test_the_write_filter_lets_reads_through_and_refuses_everything_that_changes_state(self):
        writes = [['gh', 'pr', 'merge', '1'], ['gh', 'pr', 'comment', '1', '--body', 'x'], ['gh', 'pr', 'edit', '1'],
                  ['gh', 'api', '-X', 'PATCH', 'repos/o/r/issues/comments/1', '-f', 'body=x'],
                  ['gh', 'api', 'repos/o/r/git/refs', '-f', 'ref=x'], ['gh', 'api', '--method', 'DELETE', 'x'],
                  ['gh', 'workflow', 'run', 'x'], ['gh', 'run', 'rerun', '1'], ['git', 'push', 'origin', 'main'],
                  ['python3', 'tools/record.py', '--push']]
        reads = [['gh', 'pr', 'view', '1'], ['gh', 'pr', 'list'], ['gh', 'api', 'repos/o/r/pulls/1/files'],
                 ['gh', 'api', '-X', 'GET', 'repos/o/r/x', '-f', 'a=b'], ['gh', 'run', 'download', '1'],
                 ['git', 'fetch', 'origin'], ['git', 'merge', '--squash', 'x'], ['python3', 'tools/record.py']]
        for argv in writes:
            self.assertTrue(pr_bot.is_write(argv), argv)
        for argv in reads:
            self.assertFalse(pr_bot.is_write(argv), argv)


if __name__ == '__main__':
    unittest.main()
