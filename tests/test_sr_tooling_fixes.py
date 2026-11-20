"""./sr tooling: claim conflicts, worktree private-store fallback, unit recipe, relative includes,
class filter on next and multi-task submission, on synthetic inputs."""
import contextlib
from datetime import datetime, timedelta, timezone
import io
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
import unittest.mock

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import contrib  # noqa: E402
import check_labels  # noqa: E402
from local_paths import local_path  # noqa: E402
from test_contrib import FakeGitHub  # noqa: E402

MAPPED_TWO = [f['rva'] for f in json.loads((ROOT / 'data/progress.json').read_text())['functions']
              if f['status'] == 'mapped' and contrib.PLAIN_NAME.fullmatch(f.get('name') or '')][:2]


def git(cwd, *args):
    subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', *args], cwd=cwd, check=True,
                   capture_output=True)


def claim_item(rva, number, author='someone', days_ago=0):
    when = (datetime.now(timezone.utc) - timedelta(days=days_ago)).isoformat().replace('+00:00', 'Z')
    return {'number': number, 'title': f'claim 0x{rva:x}', 'url': f'https://github.com/x/y/issues/{number}',
            'author': author, 'updated_at': when, 'pull_request': False}


class ClaimConflictTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.first, self.second = MAPPED_TWO

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def claim(self, gh, *extra):
        ctx = contrib.Ctx(interactive=False, as_json=True, private=self.tmp / 'private', github=gh)
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'claim', '--model', 'synthetic-agent',
                                 f'0x{self.first:x}', f'0x{self.second:x}', *extra], ctx=ctx)
        return code, json.loads(out.getvalue())

    def test_error_names_the_conflicting_function_and_its_issue(self):
        gh = FakeGitHub({self.second: [claim_item(self.second, 162)]})
        code, out = self.claim(gh)
        self.assertEqual(code, contrib.CLAIMED)
        self.assertIn(f'0x{self.second:x}', out['error'])
        self.assertNotIn(f'0x{self.first:x} (', out['error'])
        self.assertIn('#162', out['error'])
        self.assertEqual(gh.created, [])

    def test_lapsed_claim_error_names_the_function_not_the_first_claim(self):
        gh = FakeGitHub({self.second: [claim_item(self.second, 7, days_ago=3)]})
        code, out = self.claim(gh)
        self.assertEqual(code, contrib.CLAIMED)
        self.assertIn(f'0x{self.second:x}', out['error'])
        self.assertIn('#7', out['error'])

    def test_skip_conflicts_claims_the_rest(self):
        gh = FakeGitHub({self.second: [claim_item(self.second, 162)]})
        code, out = self.claim(gh, '--skip-conflicts')
        self.assertEqual(code, 0)
        self.assertEqual(len(gh.created), 1)
        self.assertIn('(1 functions)', gh.created[0])
        saved = contrib.local_claims(contrib.Ctx(private=self.tmp / 'private'))
        self.assertIn(f'0x{self.first:x}', saved)
        self.assertNotIn(f'0x{self.second:x}', saved)
        self.assertTrue(any(f'0x{self.second:x}' in line and '#162' in line for line in out['messages']))

    def test_skip_conflicts_with_everything_claimed_is_still_refused(self):
        gh = FakeGitHub({self.first: [claim_item(self.first, 5)], self.second: [claim_item(self.second, 6)]})
        code, out = self.claim(gh, '--skip-conflicts')
        self.assertEqual(code, contrib.CLAIMED)
        self.assertEqual(gh.created, [])
        self.assertIn('#5', out['error'])
        self.assertIn('#6', out['error'])


class WorktreePrivateStoreTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.main = self.tmp / 'main'
        self.main.mkdir()
        git(self.main, 'init', '-q', '-b', 'main')
        (self.main / 'f').write_text('x')
        git(self.main, 'add', 'f')
        git(self.main, 'commit', '-q', '-m', 'c')
        self.linked = self.tmp / 'linked'
        git(self.main, 'worktree', 'add', '-q', '-b', 'w', str(self.linked))
        (self.main / '.local/sources/NG/include').mkdir(parents=True)
        (self.main / '.local/contrib/tasks/contrib-a').mkdir(parents=True)
        (self.main / '.local/contrib/tasks/contrib-a/task.json').write_text(json.dumps({
            'task_id': 'contrib-a', 'compiled': 'reconstruction/x/A.cpp', 'functions': [],
            'contrib': {'unit': ['reconstruction/x/A.h', 'reconstruction/x/A.cpp']}}))
        (self.main / '.local/verifier').mkdir()
        (self.main / '.local/verifier/config.json').write_text(json.dumps(
            {'community_checkouts': {'CharmedBaryon/CommonLibSSE-NG': '/somewhere/NG'}}))
        # Something created a .local in the worktree; it holds none of the above.
        (self.linked / '.local/contrib').mkdir(parents=True)

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def ctx(self):
        return contrib.Ctx(repo=self.linked, env={'PATH': ''}, platform='darwin', interactive=False)

    def test_sources_resolve_in_the_main_checkout(self):
        self.assertEqual(local_path(self.linked, '.local/sources/NG', {}), self.main / '.local/sources/NG')

    def test_own_files_win_and_missing_ones_keep_the_own_path(self):
        (self.linked / '.local/sources/NG').mkdir(parents=True)
        self.assertEqual(local_path(self.linked, '.local/sources/NG', {}), self.linked / '.local/sources/NG')
        self.assertEqual(local_path(self.linked, '.local/sources/none', {}), self.linked / '.local/sources/none')

    def test_explicit_override_is_not_second_guessed(self):
        other = self.tmp / 'other'
        other.mkdir()
        self.assertEqual(local_path(self.linked, '.local/sources/NG', {'SR_LOCAL_DIR': str(other)}),
                         other / 'sources/NG')

    def test_main_checkout_tasks_are_found(self):
        tdir, task = contrib.load_task(self.ctx())
        self.assertEqual(tdir, (self.main / '.local/contrib/tasks/contrib-a'))
        self.assertEqual(task['task_id'], 'contrib-a')

    def test_own_task_shadows_the_main_one(self):
        own = self.linked / '.local/contrib/tasks/contrib-a'
        own.mkdir(parents=True)
        (own / 'task.json').write_text(json.dumps({'task_id': 'contrib-a', 'compiled': 'c', 'functions': [],
                                                   'contrib': {'unit': []}}))
        tdir, task = contrib.load_task(self.ctx())
        self.assertEqual(tdir, own)
        self.assertEqual(task['compiled'], 'c')

    def test_label_checker_reads_the_main_checkouts_verifier_config(self):
        self.assertEqual(check_labels.configured_checkouts(self.linked, {}),
                         {'CharmedBaryon/CommonLibSSE-NG': '/somewhere/NG'})


class UnitRecipeTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        (self.tmp / 'reconstruction/recipes').mkdir(parents=True)
        (self.tmp / 'reconstruction/recipes/other.json').write_text('{}')
        (self.tmp / 'reconstruction/x').mkdir()

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def unit(self, text):
        (self.tmp / 'reconstruction/x/A.cpp').write_text(text)
        return 'reconstruction/x/A.cpp'

    def test_declared_recipe_beats_the_task_recipe(self):
        unit = self.unit('// Recipe: reconstruction/recipes/other.json\n')
        self.assertEqual(contrib.unit_recipe(self.tmp, unit, 'reconstruction/recipes/default.json'),
                         'reconstruction/recipes/other.json')

    def test_no_declaration_keeps_the_task_recipe(self):
        unit = self.unit('// nothing here\n')
        self.assertEqual(contrib.unit_recipe(self.tmp, unit, 'reconstruction/recipes/default.json'),
                         'reconstruction/recipes/default.json')

    def test_declared_recipe_that_does_not_exist_is_refused(self):
        unit = self.unit('// Recipe: reconstruction/recipes/absent.json\n')
        with self.assertRaises(contrib.Stop) as cm:
            contrib.unit_recipe(self.tmp, unit, 'reconstruction/recipes/default.json')
        self.assertIn('absent.json', cm.exception.message)

    def test_it_reads_the_unit_the_way_ci_does(self):
        import pr_bot  # noqa: F401  (the same pattern is used there)
        text = '// Recipe: reconstruction/recipes/other.json\n'
        self.assertEqual(contrib.UNIT_RECIPE.search(text).group(0), 'reconstruction/recipes/other.json')


class RelativeIncludeTests(unittest.TestCase):
    def test_dotdot_include_resolves_before_the_closure_check(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            (root / 'reconstruction/skyrim/ai').mkdir(parents=True)
            (root / 'reconstruction/gamebryo/nimain').mkdir(parents=True)
            header = root / 'reconstruction/gamebryo/nimain/NiObject.h'
            header.write_text('// header\n')
            printed = str(root / 'reconstruction/skyrim/ai/../../gamebryo/nimain/NiObject.h').lower()
            if not os.path.exists(printed):
                self.skipTest('case-sensitive file system: a lower-cased path opens nothing')
            repo_files = []
            rest = contrib.fold_case_includes([printed], root, ['reconstruction/gamebryo/nimain/NiObject.h'],
                                              repo_files)
            self.assertEqual(rest, [])
            self.assertEqual(repo_files, ['reconstruction/gamebryo/nimain/NiObject.h'])

    def test_dotdot_that_leaves_the_closure_is_still_refused(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            (root / 'reconstruction/skyrim').mkdir(parents=True)
            (root / 'secret.h').write_text('//\n')
            raw = str(root / 'reconstruction/skyrim/../../secret.h')
            self.assertEqual(contrib.fold_case_includes([raw], root, ['reconstruction/skyrim/A.h'], []), [raw])


class NextClassFilterTests(unittest.TestCase):
    def test_filter_skips_other_classes_before_unit_lookup(self):
        data = {'target_build_id': 'b', 'functions': [
            {'rva': 0x100, 'size': 8, 'name': 'NiNode::A', 'status': 'mapped', 'build_id': 'b'},
            {'rva': 0x200, 'size': 8, 'name': 'Actor::B', 'status': 'mapped', 'build_id': 'b'},
            {'rva': 0x300, 'size': 8, 'name': 'NiObject::C', 'status': 'mapped', 'build_id': 'b'}]}
        looked_up = []
        real = contrib.unit_files

        def spy(repo, cls, area=None, index=None):
            looked_up.append(cls)
            return real(repo, cls, area, index)
        with tempfile.TemporaryDirectory() as tmp, unittest.mock.patch.object(contrib, 'unit_files', spy):
            rows = contrib.candidates(tmp, data, class_filter=contrib.re.compile('^Ni'))
        self.assertEqual(sorted(r['name'] for r in rows), ['NiNode::A', 'NiObject::C'])
        self.assertNotIn('Actor', looked_up)

    def test_option_is_parsed_and_a_bad_regex_is_a_usage_error(self):
        args = contrib.parser().parse_args(['next', '--class', '^Ni'])
        self.assertEqual(args.class_regex, '^Ni')
        ctx = contrib.Ctx(interactive=False, as_json=True, private=Path(tempfile.mkdtemp()),
                          github=FakeGitHub(offline=True))
        bad = contrib.parser().parse_args(['next', '--class', '('])
        with self.assertRaises(contrib.Stop) as cm:
            contrib.cmd_next(ctx, bad)
        self.assertEqual(cm.exception.code, contrib.USAGE)


class MultiTaskSubmitTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.repo = self.tmp / 'repo'
        self.repo.mkdir()
        git(self.repo, 'init', '-q', '-b', 'main')
        for name in ('A', 'B', 'C'):
            unit = self.repo / f'reconstruction/forms/{name}.cpp'
            unit.parent.mkdir(parents=True, exist_ok=True)
            unit.write_text('//\n')
            unit.with_suffix('.h').write_text('//\n')
        git(self.repo, 'add', '.')
        git(self.repo, 'commit', '-q', '-m', 'c')
        self.ctx = contrib.Ctx(repo=self.repo, env={}, private=self.tmp / 'private', interactive=False)
        for name in ('A', 'B', 'C'):
            tdir = self.tmp / 'private/tasks' / f'contrib-{name.lower()}'
            tdir.mkdir(parents=True)
            path = f'reconstruction/forms/{name}.cpp'
            (tdir / 'task.json').write_text(json.dumps({
                'task_id': tdir.name, 'compiled': path, 'functions': [],
                'contrib': {'practice': False, 'unit': [path.replace('.cpp', '.h'), path]}}))

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def names(self, *argv):
        args = contrib.parser().parse_args(['submit', *argv])
        return [d.name for d, _t in contrib.select_tasks(self.ctx, args)]

    def test_several_names_make_one_selection(self):
        self.assertEqual(self.names('contrib-a', 'contrib-c', 'contrib-a'), ['contrib-a', 'contrib-c'])

    def test_all_dirty_takes_only_tasks_with_changed_units(self):
        (self.repo / 'reconstruction/forms/A.cpp').write_text('// changed\n')
        (self.repo / 'reconstruction/forms/C.h').write_text('// changed\n')
        self.assertEqual(self.names('--all-dirty'), ['contrib-a', 'contrib-c'])

    def test_all_dirty_skips_submitted_tasks_and_refuses_names_with_it(self):
        (self.repo / 'reconstruction/forms/A.cpp').write_text('// changed\n')
        path = self.tmp / 'private/tasks/contrib-a/task.json'
        task = json.loads(path.read_text())
        task['contrib']['submitted'] = 'branch'
        path.write_text(json.dumps(task))
        with self.assertRaises(contrib.Stop):
            self.names('--all-dirty')
        with self.assertRaises(contrib.Stop):
            self.names('--all-dirty', 'contrib-b')

    def test_pr_body_carries_every_tasks_functions_and_report(self):
        (self.repo / '.github/PULL_REQUEST_TEMPLATE').mkdir(parents=True)
        (self.repo / '.github/PULL_REQUEST_TEMPLATE/function.md').write_text(
            '{{functions_table}}\n{{report_json}}\n{{drafted_by}}\n{{label_findings}}\n{{origin_findings}}\n{{tool_revision}}\n')

        def summary(unit, rva):
            return {'unit': unit, 'source_revision': 's', 'recipe': 'r', 'recipe_sha256': 'h', 'compiler': 'pinned',
                    'image_sha256_pinned': True, 'comparator': 'c', 'contract_version': 1,
                    'functions': [{'rva': rva, 'name': 'X::y', 'result': 'pass', 'reason': 'ok', 'candidate_size': 1,
                                   'target_size': 1, 'coverage': 1, 'code_section_sha256': 'ab' * 32}]}
        args = contrib.parser().parse_args(['submit', '--drafted-by', 't'])
        body = contrib.pr_body(self.ctx, {}, [summary('A.cpp', '0x1'), summary('B.cpp', '0x2')], args, [], [])
        self.assertIn('`0x1`', body)
        self.assertIn('`0x2`', body)
        self.assertEqual(len(json.loads(body[body.index('['):body.rindex(']') + 1])), 2)


if __name__ == '__main__':
    unittest.main()
