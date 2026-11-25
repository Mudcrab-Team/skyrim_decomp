"""Tests for tools/contrib.py, the contributor helper, with synthetic inputs only.

No game file, compiler or network is used: the executable is a synthetic PE image, the compiler is
tests/stub_cl.py, GitHub is a fake object, and Windows paths are exercised through the pure path
helpers on any host.
"""
import contextlib
import hashlib
from datetime import datetime, timedelta, timezone
import io
import json
import os
from pathlib import Path, PureWindowsPath
import shutil
import subprocess
import sys
import tempfile
import unittest
import unittest.mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tests'))
sys.path.insert(0, str(ROOT / 'tools'))
import contrib  # noqa: E402
import lint_reconstruction  # noqa: E402
import synthetic_pecoff as sp  # noqa: E402

STUB = json.dumps([sys.executable, str(ROOT / 'tests' / 'stub_cl.py')])
TARGET = json.loads((ROOT / 'builds/target.json').read_text())
# A function still open for claims; the inventory changes as functions are accepted.
MAPPED = next(f['rva'] for f in json.loads((ROOT / 'data/progress.json').read_text())['functions']
              if f['status'] == 'mapped' and contrib.PLAIN_NAME.fullmatch(f.get('name') or ''))


class FakeGitHub:
    def __init__(self, items=None, me='me', offline=False, can_create=True, after_create=None):
        self.items, self.me, self.offline, self.can_create = items or {}, me, offline, can_create
        self.repo, self.created, self.comments, self.closed = contrib.UPSTREAM, [], [], []
        self.after_create = after_create

    def open_items(self, refresh=False):
        if self.offline:
            raise contrib.Offline('no network in tests')
        if refresh and self.created and self.after_create is not None:
            return self.after_create
        return self.items

    def close(self, number, body):
        self.closed.append(number)
        return True

    def user(self):
        return self.me

    def gh(self):
        return 'gh' if self.can_create else None

    def feedback(self):
        return {'needs_action_prs': 0}

    def create_issue(self, title, body):
        if not self.can_create:
            return None
        self.created.append(title)
        return 'https://github.com/x/y/issues/99'

    def new_issue_link(self, title, body):
        return 'https://github.com/x/y/issues/new?title=' + title

    def comment(self, number, body):
        self.comments.append(number)
        return True


def item(author, days_ago, number=1):
    when = (datetime.now(timezone.utc) - timedelta(days=days_ago)).isoformat().replace('+00:00', 'Z')
    return {'number': number, 'title': f'claim: x 0x{MAPPED:x} A::B', 'url': f'https://github.com/x/y/issues/{number}',
            'author': author, 'updated_at': when, 'pull_request': False}


class Base(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.private = self.tmp / 'private'

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def ctx(self, **kw):
        kw.setdefault('interactive', False)
        kw.setdefault('as_json', True)
        kw.setdefault('private', self.private)
        return contrib.Ctx(**kw)


class LocalDirectoryTests(Base):
    def test_default_and_shared_worktree_storage(self):
        shared = (self.tmp / 'shared').resolve()
        shared.mkdir()
        first = contrib.Ctx(repo=self.tmp / 'one', env={'SR_LOCAL_DIR': str(shared)})
        second = contrib.Ctx(repo=self.tmp / 'two', env={'SR_LOCAL_DIR': str(shared)})
        self.assertEqual(contrib.Ctx(repo=self.tmp, env={}).private, self.tmp / '.local/contrib')
        self.assertEqual(first.private, shared / 'contrib')
        self.assertEqual(first.private, second.private)
        contrib.save_config(first, drafted_by='synthetic tester')
        self.assertEqual(contrib.load_config(second)['drafted_by'], 'synthetic tester')
        self.assertEqual(contrib.toolchain_root(first), shared / 'contrib/msvc')
        self.assertFalse((self.tmp / 'one/.local').exists())

    def test_override_must_exist_and_be_a_directory(self):
        file = self.tmp / 'file'
        file.write_text('synthetic')
        for path in (self.tmp / 'absent', file):
            with self.subTest(path=path):
                ctx = contrib.Ctx(repo=ROOT, env={'SR_LOCAL_DIR': str(path)}, as_json=True)
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    code = contrib.main(['--json', '--redact', 'doctor'], ctx=ctx)
                self.assertEqual(code, contrib.MISSING)
                self.assertIn('existing directory', json.loads(out.getvalue())['error'])
                self.assertFalse((self.tmp / 'absent').exists())

    def test_redact_hides_shared_storage_outside_checkout(self):
        ctx = contrib.Ctx(repo=ROOT, env={'SR_LOCAL_DIR': str(self.tmp)}, as_json=True)
        ctx.redact = True
        self.assertEqual(ctx.scrub(str(ctx.local / 'contrib/config.json')).replace('\\', '/'), '<local>/contrib/config.json')

    def test_source_fetch_uses_shared_storage_and_passes_environment(self):
        calls = []
        ctx = contrib.Ctx(repo=ROOT, env={'SR_LOCAL_DIR': str(self.tmp)}, as_json=True,
                          runner=lambda cmd, **kw: calls.append((cmd, kw)) or
                          subprocess.CompletedProcess(cmd, 0, '', ''))
        contrib.fetch_sources(ctx, {'Example/Headers': ('.local/sources/headers', 'abc1234', 'MIT')})
        self.assertTrue(calls)
        self.assertTrue(all(kw['cwd'] == ctx.local / 'sources/headers' for _, kw in calls))
        self.assertTrue(all(kw['env']['SR_LOCAL_DIR'] == str(self.tmp) for _, kw in calls))

    def test_sibling_pointers_are_generic_when_requested(self):
        import export_pack
        ctx = self.ctx(env={'SR_NO_SIBLING_NAMES': '1'})
        with unittest.mock.patch.object(export_pack, 'sibling_lines', return_value=['SecretClass::SecretMethod secret.cpp']):
            self.assertEqual(contrib.sibling_section(ctx, 'PublicClass', [0x1000]),
                             ['A sibling declaration exists for this name (details omitted).'])
        with unittest.mock.patch.object(export_pack, 'sibling_lines', return_value=[]):
            self.assertEqual(contrib.sibling_section(ctx, 'PublicClass', [0x1000]), [])


class ExecutableTests(Base):
    def test_hash_and_version(self):
        blob = bytearray(b'MZ' + bytes(200))
        blob[64:68] = b'\xbd\x04\xef\xfe'
        blob[72:80] = (7 | 1 << 16).to_bytes(4, 'little') + (0 | 104 << 16).to_bytes(4, 'little')
        exe = self.tmp / 'SkyrimSE.exe'
        exe.write_bytes(bytes(blob))
        self.assertEqual(contrib.pe_version(exe), '1.7.104.0')
        target = dict(TARGET, image_sha256=contrib.sha256_file(exe))
        self.assertEqual(contrib.inspect_exe(exe, target)['status'], 'ok')

    def test_wrong_build_names_the_pinned_version_only(self):
        exe = self.tmp / 'SkyrimSE.exe'
        exe.write_bytes(b'MZ not the pinned image')
        info = contrib.inspect_exe(exe, TARGET)
        self.assertEqual(info['status'], 'wrong-build')
        text = contrib.wrong_build_message(info, TARGET)
        self.assertIn(TARGET['version'], text)
        self.assertIn(TARGET['image_sha256'][:16], text)
        for word in ('crack', 'patcher', 'downgrade', 'depot'):
            self.assertNotIn(word, text.lower())

    def test_missing_executable(self):
        self.assertEqual(contrib.inspect_exe(self.tmp / 'nope.exe', TARGET)['status'], 'missing')
        ctx = self.ctx(env={'PATH': '', 'HOME': str(self.tmp), 'ProgramFiles': str(self.tmp), 'ProgramFiles(x86)': str(self.tmp)})
        with self.assertRaises(contrib.Stop) as cm:
            contrib.require_exe(ctx, TARGET)
        self.assertEqual(cm.exception.code, contrib.MISSING)
        self.assertIn('setup --exe', cm.exception.next_action)

    def test_windows_steam_libraries(self):
        vdf = '"libraryfolders"\n{\n "1"\n {\n  "path"  "D:\\\\Games\\\\SteamLibrary"\n }\n}\n'
        dirs = {r'C:\Program Files (x86)\Steam'}
        files = {r'D:\Games\SteamLibrary\steamapps\common\Skyrim Special Edition\SkyrimSE.exe'}
        ctx = self.ctx(platform='win32', env={'ProgramFiles(x86)': r'C:\Program Files (x86)',
                                              'ProgramFiles': r'C:\Program Files', 'USERPROFILE': r'C:\Users\a'})
        found = contrib.exe_candidates(ctx, exists=lambda p: p in files, dir_exists=lambda p: p in dirs,
                                       read=lambda p: vdf)
        self.assertEqual(found, [r'D:\Games\SteamLibrary\steamapps\common\Skyrim Special Edition\SkyrimSE.exe'])
        self.assertEqual(ctx.cli, '.\\sr.cmd')

    def test_steamcmd_route_never_carries_credentials(self):
        lines = contrib.steamcmd_route(self.ctx())
        self.assertIn('login <your-steam-login>', lines)
        self.assertTrue(any(contrib.STEAM_APP_ID in line for line in lines))
        self.assertFalse(any('password' in line.lower() and '<' not in line and 'asks' not in line for line in lines))


class ToolchainTests(Base):
    def test_missing_compiler(self):
        ctx = self.ctx(env={'SR_MSVC': str(self.tmp / 'msvc'), 'PATH': ''})
        self.assertEqual(contrib.check_toolchain(ctx)['status'], 'missing')

    def test_mismatching_compiler(self):
        bin_dir = self.tmp / 'msvc/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64'
        bin_dir.mkdir(parents=True)
        for name in ('cl.exe', 'c1xx.dll', 'c2.dll', 'link.exe'):
            (bin_dir / name).write_bytes(b'not the pinned binary')
        state = contrib.check_toolchain(self.ctx(env={'SR_MSVC': str(self.tmp / 'msvc')}))
        self.assertEqual(state['status'], 'mismatch')
        self.assertEqual(sorted(state['differing']), ['c1xx.dll', 'c2.dll', 'cl.exe', 'link.exe'])

    @unittest.skipIf(sys.platform == 'win32', 'simulates a Linux host with shell stubs and a colon-separated PATH')
    def test_doctor_names_one_next_step(self):
        ctx = self.ctx(env={'SR_MSVC': str(self.tmp / 'msvc'), 'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp),
                            'SR_SKYRIM_EXE': str(self.tmp / 'none.exe')}, platform='linux')
        code, data, nxt = contrib.cmd_doctor(ctx, type('A', (), {'exe': None})())
        self.assertEqual(code, contrib.MISSING)
        self.assertIn('setup --exe', nxt)
        self.assertTrue(all({'check', 'ok', 'required', 'detail', 'fix'} <= set(c) for c in data['checks']))

    def test_recipe_constants_come_from_the_verifier_recipe(self):
        pins = contrib.recipe_constants(ROOT)
        self.assertEqual(len(pins['VSMAN_SHA256']), 64)
        self.assertTrue(pins['VSMAN_URL'].startswith('https://download.visualstudio.microsoft.com/'))

    def test_classify_windows_paths(self):
        repo = r'C:\Users\a\skyrim-research'
        opened = [r'c:\users\a\skyrim-research\reconstruction\forms\A.h',
                  r'C:\tools\msvc\VC\Tools\MSVC\14.16.27023\include\cstdint',
                  r'C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\stdio.h',
                  r'C:\Users\a\Desktop\secret.txt']
        files, tools, outside = contrib.classify_windows(opened, repo, [r'C:\tools\msvc',
                                                                         r'C:\Program Files (x86)\Windows Kits\10'])
        self.assertEqual(files, ['reconstruction/forms/A.h'])
        self.assertEqual(tools, 2)
        self.assertEqual(outside, [r'C:\Users\a\Desktop\secret.txt'])

    def test_classify_windows_relative_includes(self):
        opened = ['reconstruction/a/B.h', r'.\reconstruction\a\B.h',
                  'reconstruction/a/../C.h']
        self.assertEqual(contrib.classify_windows(opened, 'C:/repo', ['C:/msvc']),
                         (['reconstruction/C.h', 'reconstruction/a/B.h'], 0, []))

    def test_classify_windows_relative_escapes_and_drive_forms(self):
        outside = ['../escape.h', r'..\escape.h', 'reconstruction/../../escape.h',
                   r'C:relative.h', r'D:relative.h', r'D:\repo\a.h',
                   r'C:\repository\a.h', r'C:\msvc-extra\a.h']
        self.assertEqual(contrib.classify_windows(outside, 'C:/repo', ['C:/msvc']),
                         ([], 0, outside))

    @unittest.skipIf(sys.platform == 'win32', 'the test stands in for ntpath.realpath with the POSIX one, which on Windows is the same function')
    def test_classify_windows_link_escapes(self):
        repo, tool, outside = (self.tmp / name for name in ('repo', 'msvc', 'outside'))
        for root in (repo, tool, outside / 'child'):
            root.mkdir(parents=True)
        (repo / 'link').symlink_to(outside / 'child', target_is_directory=True)
        (tool / 'link').symlink_to(outside, target_is_directory=True)
        paths = ['link/a.h', 'link/../a.h', 'C:' + str(tool / 'link/a.h')]

        def windows_realpath(path):
            posix = path.removeprefix('C:').replace('\\', '/')
            return 'C:' + os.path.realpath(posix).replace('/', '\\')

        with unittest.mock.patch.object(contrib.ntpath, 'realpath', side_effect=windows_realpath):
            self.assertEqual(contrib.classify_windows(paths, 'C:' + str(repo), ['C:' + str(tool)]),
                             ([], 0, paths))

    def test_install_needs_licence_without_terminal(self):
        ctx = self.ctx(env={'PATH': ''})
        with self.assertRaises(contrib.Stop) as cm:
            ctx.ask('Install wine?', '--yes')
        self.assertEqual(cm.exception.code, contrib.CONSENT)
        self.assertIn('--yes', cm.exception.next_action)
        self.assertTrue(self.ctx(assume_yes=True).ask('Install wine?', '--yes'))

    @unittest.skipIf(sys.platform == 'win32', 'simulates a Linux host with shell stubs and a colon-separated PATH')
    def test_setup_without_yes_does_not_install_when_not_a_terminal(self):
        bin_dir = self.tmp / 'bin'
        bin_dir.mkdir()
        for tool in ('git', 'apt-get'):
            (bin_dir / tool).write_text('#!/bin/sh\nexit 0\n')
            (bin_dir / tool).chmod(0o755)
        ran = []
        ctx = self.ctx(env={'PATH': str(bin_dir), 'HOME': str(self.tmp), 'SR_MSVC': str(self.tmp / 'msvc')},
                       platform='linux', runner=lambda cmd, **kw: ran.append(cmd))
        args = contrib.parser().parse_args(['setup'])
        with self.assertRaises(contrib.Stop) as cm:
            contrib.cmd_setup(ctx, args)
        self.assertEqual(cm.exception.code, contrib.CONSENT)
        self.assertEqual(ran, [])

    def test_install_commands(self):
        ctx = self.ctx(interactive=False)
        cmds = contrib.install_command(ctx, 'apt-get', [['wine', 'wine64'], ['msitools']])
        self.assertIn('-n', cmds[0])  # sudo never waits for a password without a terminal
        self.assertEqual(contrib.install_command(ctx, 'brew', [['msitools'], ['--cask', 'wine-stable']]),
                         [['brew', 'install', 'msitools'], ['brew', 'install', '--cask', 'wine-stable']])
        self.assertEqual(contrib.install_command(ctx, 'winget', [['LLVM.LLVM']])[0][-1], 'LLVM.LLVM')


class ClaimTests(Base):
    def run_claim(self, gh, *extra):
        ctx = self.ctx(github=gh)
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'claim', '--model', 'synthetic-agent', f'0x{MAPPED:x}', *extra], ctx=ctx)
        return code, json.loads(out.getvalue())

    def test_json_shape(self):
        code, out = self.run_claim(FakeGitHub())
        self.assertEqual(code, 0)
        for key in ('command', 'ok', 'exit_code', 'error', 'next', 'messages'):
            self.assertIn(key, out)
        self.assertEqual(out['claim'], 'https://github.com/x/y/issues/99')
        self.assertEqual(contrib.local_claims(self.ctx())[f'0x{MAPPED:x}']['model'], 'synthetic-agent')
        self.assertEqual(contrib.load_config(self.ctx())['model'], 'synthetic-agent')

    def test_collision_is_refused(self):
        gh = FakeGitHub({MAPPED: [item('someone', 0)]})
        code, out = self.run_claim(gh)
        self.assertEqual(code, contrib.CLAIMED)
        self.assertEqual(gh.created, [])
        self.assertIn('someone', out['error'])

    def test_lapsed_claim_needs_take_over(self):
        gh = FakeGitHub({MAPPED: [item('someone', 2, 7)]})
        self.assertEqual(self.run_claim(gh)[0], contrib.CLAIMED)
        code, _ = self.run_claim(gh, '--take-over')
        self.assertEqual(code, 0)
        self.assertEqual(gh.comments, [7])

    def test_own_claim_is_reused(self):
        gh = FakeGitHub({MAPPED: [item('me', 30)]})
        code, out = self.run_claim(gh)
        self.assertEqual(code, 0)
        self.assertEqual(gh.created, [])

    def test_offline(self):
        code, out = self.run_claim(FakeGitHub(offline=True))
        self.assertEqual(code, contrib.NETWORK)
        code, out = self.run_claim(FakeGitHub(offline=True), '--offline-ok')
        self.assertEqual((code, out['claim']), (0, 'unpublished'))

    def test_without_gh_gives_a_link(self):
        code, out = self.run_claim(FakeGitHub(can_create=False))
        self.assertEqual(code, 0)
        self.assertIn('issues/new', out['link'])

    def claim_with(self, gh, functions, entries):
        data = contrib.inventory(ROOT)
        build = data['target_build_id']
        rows = [{'rva': r, 'build_id': build, 'status': 'mapped'} for r in functions]
        out = io.StringIO()
        with unittest.mock.patch.object(contrib, 'claim_selection', return_value=(rows, entries)), \
                contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'claim', '--model', 'synthetic-agent', f'0x{MAPPED:x}'],
                                ctx=self.ctx(github=gh))
        return code, json.loads(out.getvalue())

    def test_offered_function_outside_the_inventory_is_counted(self):
        held = {f['rva'] for f in contrib.inventory(ROOT)['functions']}
        offered = next(r for r in range(0x7f000000, 0x7f001000, 0x10) if r not in held)
        gh = FakeGitHub()
        code, _ = self.claim_with(gh, [offered], [(offered, offered + 1)])
        self.assertEqual(code, 0)
        self.assertEqual(len(gh.created), 1)
        self.assertIn('(1 functions)', gh.created[0])
        self.assertNotIn('(0 functions)', gh.created[0])

    def test_a_claim_that_resolves_to_no_function_opens_no_issue(self):
        gh = FakeGitHub()
        nothing = 0x7f800000
        code, out = self.claim_with(gh, [MAPPED], [(nothing, nothing + 0x10)])
        self.assertEqual(code, contrib.USAGE)
        self.assertIn('0 functions', out['error'])
        self.assertEqual(gh.created, [])

    def test_a_range_without_unmatched_functions_is_refused(self):
        gh = FakeGitHub()
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'claim', '--model', 'synthetic-agent', '--range', '0x1-0x2'],
                                ctx=self.ctx(github=gh))
        self.assertEqual(code, contrib.USAGE)
        self.assertIn('nothing to claim', json.loads(out.getvalue())['error'])
        self.assertEqual(gh.created, [])

    def test_matched_function_cannot_be_claimed(self):
        ctx = self.ctx(github=FakeGitHub())
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(contrib.main(['--json', 'claim', '--model', 'synthetic-agent', f'0x{contrib.SELF_TEST_RVA:x}'], ctx=ctx), contrib.USAGE)


def filled_skeleton(*args):
    """Synthetic source for intake tests; an untouched draft must remain unpublishable."""
    h, cpp = contrib.skeleton(*args, code_origin='original synthetic fixture')
    return h, cpp.replace('SKELETON_TODO_BODY;', '').replace('SKELETON_TODO_ORIGIN', 'none')


class MergeHeaderTests(unittest.TestCase):
    EXISTING = ('// Source exposure: mixed (community headers; the pinned image listing).\n'
                '// Code origin: original; the listing only\n'
                '// SPDX-License-Identifier: CC0-1.0\n'
                '// 0x1000 Widget::A\n'
                '// CI hash: 0x1000 ?A@Widget@@QEAAXXZ\n'
                '// Adapted bodies: none\n'
                '// Widget, Widget::A: GUESS(low)\n'
                '#include "Widget.h"\n\nvoid Widget::A() {}\n')
    NEW = ('// Source exposure: mixed (community headers; the pinned image listing).\n'
           '// Code origin: SKELETON_TODO_CODE_ORIGIN (state the actual origin)\n'
           '// SPDX-License-Identifier: CC0-1.0\n'
           '// 0x2000 Widget::B\n'
           '// Adapted bodies: SKELETON_TODO_ORIGIN (write "none" when attempt prints no line;\n'
           '// otherwise name each adapted body).\n'
           '// Widget::B: GUESS(low)\n'
           '#include "Widget.h"\n')

    def merge(self, text, *blocks):
        return contrib.merge_header_additions(text, [b.split('#include', 1)[0] for b in blocks])

    def test_append_adds_the_new_function_and_label_without_repeating_boilerplate(self):
        out = self.merge(self.EXISTING, self.NEW)
        for key in ('Source exposure:', 'Code origin:', 'SPDX-License-Identifier:', 'Adapted bodies:'):
            self.assertEqual(out.count(key), 1, key)
        self.assertEqual(out.count('SKELETON_TODO_CODE_ORIGIN'), 1)  # still to be stated for the new function
        self.assertEqual(out.count('SKELETON_TODO_ORIGIN'), 1)
        self.assertIn('// Code origin: original; the listing only; SKELETON_TODO_CODE_ORIGIN', out)
        self.assertIn('// 0x2000 Widget::B\n', out)
        self.assertIn('// Widget::B: GUESS(low)\n', out)
        self.assertIn('// CI hash: 0x1000 ?A@Widget@@QEAAXXZ\n', out)
        self.assertTrue(out.endswith('#include "Widget.h"\n\nvoid Widget::A() {}\n'))
        lead = out.split('#include', 1)[0]
        self.assertNotIn('\n\n', lead)  # the compared lines stay in the unbroken leading run
        import rva_headers
        self.assertEqual(rva_headers.claimed_rvas([out]), {0x1000, 0x2000})

    def test_merging_twice_or_several_blocks_is_stable(self):
        once = self.merge(self.EXISTING, self.NEW)
        self.assertEqual(self.merge(once, self.NEW), once)
        other = self.NEW.replace('0x2000 Widget::B', '0x3000 Widget::C').replace('Widget::B: GUESS', 'Widget::C: GUESS')
        out = self.merge(self.EXISTING, self.NEW, other)
        self.assertEqual(out.count('Adapted bodies:'), 1)
        self.assertIn('// 0x3000 Widget::C\n', out)

    def test_a_file_without_a_header_receives_the_whole_block(self):
        out = self.merge('#include "Widget.h"\n', self.NEW)
        self.assertTrue(out.startswith('// Source exposure:'))
        self.assertIn('// 0x2000 Widget::B\n', out)
        self.assertTrue(out.endswith('#include "Widget.h"\n'))

    def test_a_missing_one_per_unit_line_is_added_once(self):
        text = self.EXISTING.replace('// SPDX-License-Identifier: CC0-1.0\n', '')
        out = self.merge(text, self.NEW)
        self.assertEqual(out.count('SPDX-License-Identifier'), 1)

    def test_merged_header_passes_the_budget(self):
        import lint_reconstruction as lint
        out = self.merge(self.EXISTING, self.NEW)
        self.assertEqual(lint.header_budget_problems('Widget.cpp', lint.leading_comment(out)), [])


class SkeletonTests(Base):
    def test_skeleton_header_carries_cc0_only_without_a_third_party_notice(self):
        data = contrib.inventory(ROOT)
        seen = set()
        for fn in data['functions']:
            if fn['status'] != 'mapped' or not contrib.PLAIN_NAME.fullmatch(fn['name']):
                continue
            cls, method = contrib.PLAIN_NAME.fullmatch(fn['name']).groups()
            h, _cpp = contrib.skeleton(fn, cls, method, 'forms', 'tester, no AI', contrib.DEFAULT_RECIPE)
            third_party = 'SPDX-License-Identifier: MIT' in h or 'GPL-3.0' in h
            self.assertEqual('SPDX-License-Identifier: CC0-1.0' in h, not third_party, fn['name'])
            seen.add(third_party)
            if len(seen) == 2:
                break
        self.assertTrue(seen)

    def test_skeleton_passes_the_lint(self):
        data = contrib.inventory(ROOT)
        fn = next(f for f in data['functions'] if f['status'] == 'mapped' and 'powerof3' in f['name_source']
                  and contrib.PLAIN_NAME.fullmatch(f['name']))
        cls, method = contrib.PLAIN_NAME.fullmatch(fn['name']).groups()
        h, cpp = contrib.skeleton(fn, cls, method, 'forms', 'tester, no AI', contrib.DEFAULT_RECIPE)
        self.assertIn('SKELETON_TODO_BODY;', cpp)
        self.assertIn('SKELETON_TODO_ORIGIN', cpp)
        self.assertIn('SKELETON_TODO_CODE_ORIGIN', h)
        self.assertIn('SKELETON_TODO_CODE_ORIGIN', cpp)
        h = h.replace('SKELETON_TODO_CODE_ORIGIN', 'original synthetic fixture')
        cpp = cpp.replace('SKELETON_TODO_BODY;', '').replace('SKELETON_TODO_ORIGIN', 'none').replace(
            'SKELETON_TODO_CODE_ORIGIN', 'original synthetic fixture')
        root = self.tmp / 'repo'
        for rel in ('builds/target.json', contrib.DEFAULT_RECIPE, fn['evidence'], 'licenses/CommonLibSSE-NG.txt'):
            (root / rel).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy(ROOT / rel, root / rel)
        unit = root / 'reconstruction' / 'forms'
        unit.mkdir(parents=True, exist_ok=True)
        (unit / f'{cls}.h').write_text(h)
        (unit / f'{cls}.cpp').write_text(cpp)
        for rel in (f'reconstruction/forms/{cls}.h', f'reconstruction/forms/{cls}.cpp'):
            self.assertEqual(lint_reconstruction.lint_file(root, rel, TARGET['build_id']), [])
        self.assertIn('GPL-3.0', h)
        self.assertIn(f'// 0x{fn["rva"]:x} ', cpp)

    def test_unit_files_are_written_with_lf(self):
        path = self.tmp / 'u.cpp'
        contrib.write_source(path, 'a\nb\n')
        self.assertEqual(path.read_bytes(), b'a\nb\n')

    def test_candidates_report_advisory_readiness_for_existing_units(self):
        rows = contrib.candidates(ROOT, contrib.inventory(ROOT))
        self.assertTrue(any(r['unit_exists'] and r['startable'] for r in rows))
        self.assertTrue(all(r['reason'] for r in rows))
        key = lambda r: (not r['startable'], r['size_band'], not r['has_layout'], r['readiness_rank'], r['size'],
                         int(r['rva'], 16))
        self.assertEqual([key(r) for r in rows], sorted(key(r) for r in rows))


class IntakeTests(Base):
    def git(self, *args):
        subprocess.run(['git', *args], cwd=self.repo, check=True, capture_output=True)

    def setUp(self):
        super().setUp()
        self.repo = self.tmp / 'repo'
        for rel in ('builds/target.json', contrib.DEFAULT_RECIPE, 'findings/fifth-batch-selection.md', 'licenses/CommonLibSSE-NG.txt'):
            (self.repo / rel).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy(ROOT / rel, self.repo / rel)
        self.git('init', '-q')
        self.git('-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-q', '--allow-empty', '-m', 'empty')
        self.git('add', '.')
        self.git('-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-q', '-m', 'base')
        fn = next(f for f in contrib.inventory(ROOT)['functions'] if f['rva'] == 0x1de5e0)
        h, cpp = filled_skeleton(fn, 'TESActorBaseData', 'Unk_07', 'forms', 'tester', contrib.DEFAULT_RECIPE)
        (self.repo / 'reconstruction/forms').mkdir(parents=True)
        (self.repo / 'reconstruction/forms/TESActorBaseData.h').write_text(h)
        (self.repo / 'reconstruction/forms/TESActorBaseData.cpp').write_text(cpp)

    def commit(self):
        self.git('add', '.')
        self.git('-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-q', '-m', 'change')

    def test_clean_unit_passes(self):
        self.commit()
        self.assertEqual(contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD~1', 'HEAD'), [])

    def test_out_of_scope_and_oversized_files(self):
        (self.repo / 'tools').mkdir()
        (self.repo / 'tools/x.py').write_text('print(1)\n')
        (self.repo / 'reconstruction/forms/Big.h').write_text('//' + 'x' * contrib.MAX_UNIT_FILE_BYTES)
        self.commit()
        problems = contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD~1', 'HEAD')
        text = '\n'.join(problems)
        self.assertIn('tools/x.py:1: outside contributor scope', text)
        self.assertIn('file-size-cap', text)

    def test_sibling_material_is_allowed_on_the_drafters_terms(self):
        cpp = self.repo / 'reconstruction/forms/TESActorBaseData.cpp'
        cpp.write_text(cpp.read_text().replace(
            '// Labels: v2', '// Labels: v2\n// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/a.cpp:1'))
        self.commit()
        self.assertEqual(contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD~1', 'HEAD'), [])
        # Another repository or revision is still refused by the lint.
        cpp.write_text(cpp.read_text().replace('fnv_decomp@91e1b6e8', 'fnv_decomp@0123abcd'))
        self.commit()
        self.assertTrue(contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD~1', 'HEAD'))

    def test_intake_reads_the_named_head_not_the_working_tree(self):
        self.commit()
        self.git('switch', '-q', '-c', 'crafted')
        (self.repo / 'tools').mkdir()
        (self.repo / 'tools/x.py').write_text('print(1)\n')
        self.commit()
        self.git('switch', '-q', '-')
        problems = contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD~1', 'crafted')
        self.assertTrue(any('tools/x.py' in p for p in problems))
        self.assertFalse((self.repo / 'tools/x.py').exists())


class CompareTests(Base):
    """compile -> bind -> comparator on synthetic inputs, through the stub compiler."""

    def setUp(self):
        super().setUp()
        self.repo = self.tmp / 'repo'
        inputs = sp.inputs()
        self.image = self.tmp / 'image.pe'
        self.image.write_bytes(inputs['image_bytes'])
        files = {'builds/target.json': json.dumps(dict(inputs['manifest'], version='synthetic', store='none')),
                 'reports/synthetic-fixture/symbol-map.json': json.dumps(inputs['symbol_map']),
                 'reconstruction/recipes/synthetic.json': inputs['recipe_bytes'].decode(),
                 'reconstruction/forms/Synthetic.h': '#pragma once\n',
                 'reconstruction/forms/Synthetic.cpp': '#include "Synthetic.h"\n'}
        for rel, text in files.items():
            (self.repo / rel).parent.mkdir(parents=True, exist_ok=True)
            (self.repo / rel).write_text(text)
        tdir = self.private / 'tasks' / 'contrib-synthetic'
        tdir.mkdir(parents=True)
        (tdir / 'task.json').write_text(json.dumps({
            'task_id': 'contrib-synthetic', 'build_id': 'synthetic-fixture', 'compiled': 'reconstruction/forms/Synthetic.cpp',
            'recipe': 'reconstruction/recipes/synthetic.json', 'symbols': 'symbols.json',
            'functions': [{'rva': hex(sp.LAYOUT[sp.FUNCTION]), 'size': len(sp.CODE), 'symbol': sp.FUNCTION,
                           'community_name': sp.FUNCTION}],
            'contrib': {'practice': False, 'unit': ['reconstruction/forms/Synthetic.h', 'reconstruction/forms/Synthetic.cpp']}}))
        self.ctx_ = self.ctx(repo=self.repo, env={'SR_CONTRIB_COMPILER': STUB, 'SR_SKYRIM_EXE': str(self.image),
                                                  'PATH': '/usr/bin:/bin', 'SR_OBJDUMP': '/nonexistent'})

    def test_pass_and_sanitized_summary(self):
        code, data, nxt = contrib.run_compare(self.ctx_, 'contrib-synthetic')
        self.assertEqual(code, contrib.OK, data)
        self.assertEqual(data['functions'][0]['reason'], 'all-checks-passed')
        self.assertEqual(data['compiler'], 'override')
        self.assertIn('submit', nxt)
        text = json.dumps({k: v for k, v in data.items() if k != 'private_dir'})
        self.assertNotIn(sp.CODE.hex()[:16], text)

    def test_note_bundles_declarations_and_compare_scores_the_public_draft(self):
        rva = hex(sp.LAYOUT[sp.FUNCTION])
        snapshot = self.tmp / 'snapshot'
        snapshot.mkdir()
        source = snapshot / 'Synthetic.cpp'
        source.write_text(f'// Source exposure: black-box\n// {rva} {sp.FUNCTION}\n'
                          '// Recipe: reconstruction/recipes/synthetic.json\n'
                          f'#include "Synthetic.h"\nint {sp.FUNCTION}() {{ return Value; }}\n')
        (snapshot / 'Synthetic.h').write_text('// Source exposure: black-box\n// Value: OBSERVED\n'
                                              '#pragma once\nconstexpr int Value = 2;\n')
        (self.repo / 'data').mkdir()
        (self.repo / 'data/progress.json').write_text(json.dumps(
            {'functions': [{'rva': int(rva, 16), 'size': len(sp.CODE), 'status': 'mapped'}]}))
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            self.assertEqual(contrib.main(['note', '--rva', rva, '--draft-from', str(source),
                                          '--category', 'other', '--tried', 'changed a return value',
                                          '--still-differs', 'return value differs',
                                          '--suspected-cause', 'a constant differs',
                                          '--best-distance', '1'], ctx=self.ctx_), contrib.OK)
        shutil.rmtree(snapshot)
        shutil.rmtree(self.repo / 'reconstruction/forms')
        shutil.rmtree(self.private / 'tasks')
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            code = contrib.main(['compare', '--draft', rva, '--no-retry'], ctx=self.ctx_)
        data = json.loads(output.getvalue())
        self.assertEqual(code, contrib.OK, data)
        self.assertEqual(data['unit'], f'drafts/synthetic-fixture/{rva[2:]}.cpp')
        self.assertEqual(data['progress'][rva]['value'], len(sp.CODE))
        self.assertFalse((self.private / 'tasks/contrib-synthetic/last-compare.json').exists())

    def test_shared_storage_compare_preserves_results_and_diagnostics(self):
        default_code, default_data, _ = contrib.run_compare(self.ctx_, 'contrib-synthetic')
        shared = (self.tmp / 'shared').resolve()
        (shared / 'contrib').mkdir(parents=True)
        shutil.copytree(self.private / 'tasks', shared / 'contrib/tasks')
        ctx = contrib.Ctx(repo=self.repo, env=dict(self.ctx_.env, SR_LOCAL_DIR=str(shared)), as_json=True)
        code, data, _ = contrib.run_compare(ctx, 'contrib-synthetic')
        self.assertEqual(code, default_code)
        self.assertEqual(data['functions'], default_data['functions'])
        self.assertEqual(data['comparator'], default_data['comparator'])
        self.assertTrue((shared / f'contrib/diagnostics/contrib-synthetic-{sp.LAYOUT[sp.FUNCTION]:x}.json').is_file())
        self.assertTrue(Path(data['private_dir']).is_relative_to(shared))
        # A failure must also agree with the default path, not merely a successful fixture.
        code = bytearray(sp.CODE)
        code[0x17] = 2  # Synthetic add operand differs, with the same instruction shape.
        inputs = sp.inputs(image=sp.pe_image(code=bytes(code)))
        self.image.write_bytes(inputs['image_bytes'])
        manifest = self.repo / 'builds/target.json'
        manifest.write_text(json.dumps(dict(inputs['manifest'], version='synthetic', store='none')))
        default_code, default_data, _ = contrib.run_compare(self.ctx_, 'contrib-synthetic')
        code, data, _ = contrib.run_compare(ctx, 'contrib-synthetic')
        self.assertEqual((code, data['functions']), (default_code, default_data['functions']))
        self.assertEqual(code, contrib.FAILED)

    def test_shared_compare_keeps_diagnostics_containment(self):
        import verify_function
        shared = (self.tmp / 'shared').resolve()
        shared.mkdir()
        ctx = contrib.Ctx(repo=self.repo, env={'SR_LOCAL_DIR': str(shared)}, as_json=True)
        outside = self.tmp / 'outside.json'
        outside.write_text('must remain intact')
        task_file = self.private / 'tasks/contrib-synthetic/task.json'
        # The adapter reads the same verifier task-file format as the default path.
        description = self.tmp / 'description.json'
        description.write_text(json.dumps({
            'verify_task_schema': 1, 'task': json.loads(task_file.read_text()),
            'recipe': 'unused.json', 'symbols': 'unused.json'}))
        with self.assertRaises(verify_function.TaskFileError):
            contrib.compare_with_local_dir(ctx, description, {}, self.image, shared / 'report.json', outside)
        self.assertEqual(outside.read_text(), 'must remain intact')
        with self.assertRaises(verify_function.TaskFileError):
            contrib.compare_with_local_dir(ctx, description, {}, self.image, shared / 'same.json', shared / 'same.json')

    def test_compile_failure(self):
        self.ctx_.env['SR_STUB_FAIL'] = '1'
        with self.assertRaises(contrib.Stop) as cm:
            contrib.run_compare(self.ctx_, 'contrib-synthetic')
        self.assertEqual(cm.exception.code, contrib.COMPILE)
        self.assertTrue(cm.exception.data['errors'])

    def test_include_outside_the_closure_is_refused(self):
        (self.repo / 'reconstruction/forms/Synthetic.cpp').write_text('#include "Synthetic.h"\n#include "Missing.h"\n')
        with self.assertRaises(contrib.Stop) as cm:
            contrib.run_compare(self.ctx_, 'contrib-synthetic')
        self.assertEqual(cm.exception.code, contrib.UNIT)

    def test_wrong_image_is_refused_before_compiling(self):
        self.image.write_bytes(b'MZ other build')
        with self.assertRaises(contrib.Stop) as cm:
            contrib.run_compare(self.ctx_, 'contrib-synthetic')
        self.assertEqual(cm.exception.code, contrib.MISSING)


class SubmitTests(Base):
    """submit's blockers, the sanitized PR body and commit message, and a dry run that writes no git state."""

    RVA = 0x1de5e0
    SECRETS = ('SECRET-DETAIL-TEXT', '+0x9', 'SECRET-BIND-LINE', '/private/abs/dir')

    def git(self, *args):
        return subprocess.run(['git', *args], cwd=self.repo, check=True, capture_output=True, text=True).stdout

    def setUp(self):
        super().setUp()
        self.repo = self.tmp / 'repo'
        for rel in ('builds/target.json', contrib.DEFAULT_RECIPE, 'findings/fifth-batch-selection.md',
                    '.github/PULL_REQUEST_TEMPLATE/function.md'):
            (self.repo / rel).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy(ROOT / rel, self.repo / rel)
        self.git('init', '-q')
        self.git('config', 'user.name', 'Synthetic Contributor')
        self.git('config', 'user.email', 'contributor@example.invalid')
        self.git('remote', 'add', 'fork', 'https://github.com/contributor/skyrim-research.git')
        self.git('add', '.')
        self.git('-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-q', '-m', 'base')
        fn = next(f for f in contrib.inventory(ROOT)['functions'] if f['rva'] == self.RVA)
        h, cpp = filled_skeleton(fn, 'TESActorBaseData', 'Unk_07', 'forms', 'tester', contrib.DEFAULT_RECIPE)
        self.unit = ['reconstruction/forms/TESActorBaseData.h', 'reconstruction/forms/TESActorBaseData.cpp']
        (self.repo / 'reconstruction/forms').mkdir(parents=True)
        (self.repo / self.unit[0]).write_text(h)
        (self.repo / self.unit[1]).write_text(cpp)
        self.tdir = self.private / 'tasks' / 'contrib-tesactorbasedata'
        self.tdir.mkdir(parents=True)
        self.task = {'task_id': self.tdir.name, 'build_id': TARGET['build_id'], 'compiled': self.unit[1],
                     'recipe': contrib.DEFAULT_RECIPE, 'symbols': 'symbols.json',
                     'functions': [{'rva': f'0x{self.RVA:x}', 'size': fn['size'], 'symbol': 'x',
                                    'community_name': fn['name']}],
                     'contrib': {'practice': False, 'unit': self.unit}}
        from source_digest import include_closure
        from digest_v2 import tu_digest
        digest = tu_digest(self.repo, include_closure(self.repo, self.unit[1]))
        self.summary = {
            'task': self.tdir.name, 'run': 1, 'unit': self.unit[1], 'source_revision': digest,
            'recipe': contrib.DEFAULT_RECIPE, 'compiler': 'pinned',
            'recipe_sha256': hashlib.sha256((self.repo / contrib.DEFAULT_RECIPE).read_bytes()).hexdigest(),
            'image_sha256_pinned': True, 'comparator': {'version': 'x'}, 'contract_version': 2, 'practice': False,
            'functions': [{'rva': f'0x{self.RVA:x}', 'name': fn['name'], 'result': 'pass', 'reason': 'all-checks-passed',
                           'detail': self.SECRETS[0], 'hint': 'h', 'first_mismatch': self.SECRETS[1],
                           'candidate_size': 3, 'target_size': 3, 'coverage': {'code_bytes_total': 3},
                           'code_section_sha256': 'cd' * 32}],
            'bind': [self.SECRETS[2]], 'private_dir': self.SECRETS[3]}
        self.write()

    def write(self):
        (self.tdir / 'task.json').write_text(json.dumps(self.task))
        (self.tdir / 'last-compare.json').write_text(json.dumps(self.summary))

    def runner(self, cmd, **kw):
        # The repository-wide check is not under test here; everything else really runs.
        if any(str(c).endswith('tools/check.py') for c in cmd):
            return subprocess.CompletedProcess(cmd, 0, '', '')
        return subprocess.run(cmd, **kw)

    def submit(self, gh=None, *extra, env=None):
        ctx = self.ctx(repo=self.repo, github=gh or FakeGitHub(), runner=self.runner,
                       env=dict({'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)}, **(env or {})))
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'submit', '--dry-run', '--base', 'HEAD', *extra], ctx=ctx)
        return code, json.loads(out.getvalue())

    def state(self):
        return (self.git('rev-parse', 'HEAD'), self.git('status', '--porcelain'), self.git('diff', '--cached'),
                self.git('branch', '--list'))

    def test_dry_run_is_clean_and_writes_no_git_state(self):
        before = self.state()
        code, out = self.submit()
        self.assertEqual((code, out['blockers']), (0, []), out)
        self.assertEqual(self.state(), before)
        body = (self.tdir / 'pr-body.md').read_text()
        message_plan = ' '.join(out['plan'])
        for text in (body, out['title']):
            for secret in self.SECRETS:
                self.assertNotIn(secret, text)
            self.assertNotIn(str(self.tmp), text)
            self.assertNotIn(str(self.private), text)
            self.assertNotIn('packs/', text)
            self.assertNotIn(str(Path.home()), text)
        self.assertIn(f'-- {" ".join(self.unit)}', message_plan)

    def test_commit_message_is_sanitized(self):
        # The message a real submit commits with is the one the dry run reports.
        code, out = self.submit()
        self.assertEqual(code, 0)
        message = out['commit_message']
        self.assertTrue(message.startswith(out['title']))
        for secret in self.SECRETS:
            self.assertNotIn(secret, message)
        self.assertNotIn(str(self.tmp), message)

    def blockers(self, gh=None):
        code, out = self.submit(gh)
        self.assertEqual(code, contrib.FAILED)
        return '\n'.join(out['blockers'])

    def test_a_recipe_that_changed_since_the_compare_blocks(self):
        self.summary['recipe_sha256'] = 'ab' * 32
        self.write()
        self.assertIn('changed since the last compare', self.blockers())

    def test_stand_in_compiler_blocks(self):
        self.summary['compiler'] = 'override'
        self.write()
        self.assertIn('stand-in compiler', self.blockers())

    def test_changed_unit_blocks(self):
        (self.repo / self.unit[1]).write_text((self.repo / self.unit[1]).read_text() + '\n')
        self.assertIn('changed since the last compare', self.blockers())

    def test_failed_function_blocks(self):
        self.summary['functions'][0]['result'] = 'fail'
        self.write()
        self.assertIn('not every function passed', self.blockers())

    def test_practice_task_blocks(self):
        self.task['contrib']['practice'] = True
        self.write()
        self.assertIn('practice tasks', self.blockers())

    def test_undeclared_adapted_body_blocks(self):
        import check_origin
        hit = {'trivial': False, 'fork_of': None, 'declared': False}
        with unittest.mock.patch.object(check_origin, 'check_unit', return_value=[hit]), \
                unittest.mock.patch.object(check_origin, 'describe', return_value='close to a community body'):
            self.assertIn('not declared in the unit header', self.blockers())

    def test_sibling_origin_suppression_preserves_blockers_and_hides_identifiers(self):
        import check_origin
        hit = {'function': 'SiblingClass::HiddenMethod', 'repo': 'momusdigital/fnv_decomp',
               'revision': 'abcdef12', 'path': 'secret/sibling.cpp', 'upstream_line': 99,
               'similarity': 0.98, 'trivial': False, 'fork_of': None, 'declared': False}
        with unittest.mock.patch.object(check_origin, 'check_unit', return_value=[hit]):
            plain_code, plain = self.submit()
            code, out = self.submit(env={'SR_NO_SIBLING_NAMES': '1'})
        self.assertEqual((code, out['blockers']), (plain_code, plain['blockers']))
        self.assertEqual(code, contrib.FAILED)
        text = json.dumps(out) + (self.tdir / 'pr-body.md').read_text()
        self.assertIn('sibling body similarity finding', text)
        self.assertNotIn('momusdigital/fnv_decomp', json.dumps(out))
        for identifier in ('SiblingClass', 'HiddenMethod', 'secret/sibling.cpp'):
            self.assertNotIn(identifier, text)

    def test_fresh_foreign_claim_blocks_on_any_function(self):
        self.task['functions'].append({'rva': '0xf2120', 'size': 3, 'symbol': 'y', 'community_name': 'A::B'})
        self.write()
        gh = FakeGitHub({0xf2120: [item('someone', 0, 5)]})
        self.assertIn('0xf2120', self.blockers(gh))
        code, out = self.submit(gh, '--ack-collision')
        self.assertEqual(out['blockers'], [])

    def test_other_staged_files_stop_a_real_submit(self):
        (self.repo / 'notes.txt').write_text('x\n')
        self.git('add', 'notes.txt')
        ctx = self.ctx(repo=self.repo, github=FakeGitHub(), runner=self.runner,
                       env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'submit', '--base', 'HEAD'], ctx=ctx)
        self.assertEqual(code, contrib.USAGE)
        self.assertIn('notes.txt', json.loads(out.getvalue())['error'])
        self.assertEqual(self.git('log', '--oneline').count('\n'), 1)


class ClaimFollowUpTests(Base):
    def claim(self, gh, *extra, env=None):
        ctx = self.ctx(github=gh, env=env or {'PATH': ''})
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = contrib.main(['--json', 'claim', '--model', 'synthetic-agent', f'0x{MAPPED:x}', *extra], ctx=ctx)
        return code, json.loads(out.getvalue())

    def test_link_only_is_not_recorded_as_claimed(self):
        code, out = self.claim(FakeGitHub(can_create=False))
        self.assertEqual((code, out['claim']), (0, 'link-only'))
        self.assertNotIn(f'0x{MAPPED:x}', contrib.local_claims(self.ctx()))

    def test_older_rival_after_creating_withdraws_ours(self):
        rival = item('someone', 0, 98)
        mine = dict(item('me', 0, 99), url='https://github.com/x/y/issues/99')
        gh = FakeGitHub(after_create={MAPPED: [rival, mine]})
        code, out = self.claim(gh)
        self.assertEqual(code, contrib.CLAIMED)
        self.assertEqual(gh.closed, [99])
        self.assertNotIn(f'0x{MAPPED:x}', contrib.local_claims(self.ctx()))

    def test_unknown_login_with_open_items_asks_for_it(self):
        gh = FakeGitHub({MAPPED: [item('someone', 0)]}, me=None)
        code, out = self.claim(gh)
        self.assertEqual(code, contrib.USAGE)
        self.assertIn('--github-user', out['next'])

    def test_paging_goes_past_five_hundred(self):
        pages = [[{'number': i, 'title': f'claim: x 0x{0x100000 + i:x} A::B', 'html_url': f'u/{i}',
                   'user': {'login': 'a'}, 'updated_at': '2026-01-01T00:00:00Z'} for i in range(p * 100, p * 100 + 100)]
                 for p in range(6)] + [[]]
        gh = contrib.GitHub(self.ctx(env={'PATH': ''}))
        gh.api = lambda path: pages[int(path.rsplit('page=', 1)[1]) - 1]
        self.assertEqual(len(gh.open_items()), 600)


class FollowUpTests(Base):
    def test_winget_source_agreements_need_their_own_flag(self):
        ctx = self.ctx()
        plain = contrib.install_command(ctx, 'winget', [['LLVM.LLVM']])[0]
        self.assertNotIn('--accept-source-agreements', plain)
        self.assertIn('--accept-source-agreements', contrib.install_command(ctx, 'winget', [['LLVM.LLVM']], True)[0])
        args = contrib.parser().parse_args(['--yes', 'setup'])
        self.assertFalse(args.accept_winget_source_agreements)

    def test_steamcmd_depot_route_and_its_download_folder(self):
        lines = '\n'.join(contrib.steamcmd_route(self.ctx()))
        self.assertIn(f'download_depot {contrib.STEAM_APP_ID} {contrib.STEAM_EXE_DEPOT} {contrib.STEAM_EXE_MANIFEST}',
                      lines)
        home = self.tmp / 'home'
        exe = (home / 'Library/Application Support/Steam/steamapps/content' / f'app_{contrib.STEAM_APP_ID}'
               / f'depot_{contrib.STEAM_EXE_DEPOT}' / 'SkyrimSE.exe')
        ctx = self.ctx(platform='darwin', env={'HOME': str(home)})
        found = contrib.exe_candidates(ctx, exists=lambda p: p == str(exe), dir_exists=lambda p: False)
        self.assertEqual(found, [str(exe)])

    @unittest.skipIf(sys.platform == 'win32', 'simulates a Linux host with shell stubs and a colon-separated PATH')
    def test_apt_steamcmd_is_left_to_the_person(self):
        bin_dir = self.tmp / 'bin'
        bin_dir.mkdir()
        for tool in ('git', 'apt-get', 'wine', 'msiextract', 'llvm-objdump'):
            (bin_dir / tool).write_text('#!/bin/sh\nexit 0\n')
            (bin_dir / tool).chmod(0o755)
        ran = []
        ctx = self.ctx(env={'PATH': str(bin_dir), 'HOME': str(self.tmp), 'SR_MSVC': str(self.tmp / 'msvc'),
                            'SR_SKYRIM_EXE': str(self.tmp / 'none.exe')},
                       platform='linux', assume_yes=True, runner=lambda cmd, **kw: ran.append(cmd))
        with self.assertRaises(contrib.Stop) as cm:
            contrib.cmd_setup(ctx, contrib.parser().parse_args(['setup', '--steamcmd']))
        steps = {s['step']: s for s in cm.exception.data['steps']}
        self.assertEqual(steps['steamcmd']['status'], 'needs-person')
        self.assertIn('sudo apt install steamcmd', steps['steamcmd']['detail'])
        self.assertFalse(any('steamcmd' in ' '.join(map(str, c)) for c in ran))

    def test_area_must_be_a_plain_directory_name(self):
        ctx = self.ctx(env={'PATH': ''})
        for bad in ('../tools', 'Forms', 'a/b', ''):
            args = contrib.parser().parse_args(['start', f'0x{MAPPED:x}', '--area', bad])
            with self.assertRaises(contrib.Stop) as cm:
                contrib.start(ctx, args)
            self.assertEqual(cm.exception.code, contrib.USAGE, bad)
            self.assertIn('--area must be', cm.exception.message)

    def _bare_entry_start(self, *extra, name='Function2c5ce0'):
        entry = {'id': 'x-0x2c5ce0', 'build_id': TARGET['build_id'], 'rva': 0x2c5ce0, 'size': 29, 'status': 'mapped',
                 'name': name, 'name_origin': 'GUESS'}
        data = {'target_build_id': TARGET['build_id'], 'functions': [entry]}
        args = contrib.parser().parse_args(['start', '0x2c5ce0', '--no-branch', *extra])
        seen = {}

        def stop_after_naming(ctx, target):
            seen['named'] = True
            raise contrib.Stop(contrib.USAGE, 'no executable in this test')

        with unittest.mock.patch.object(contrib, 'inventory', return_value=data), \
                unittest.mock.patch.object(contrib, 'require_exe', stop_after_naming), \
                unittest.mock.patch.object(contrib, 'unit_files', wraps=contrib.unit_files) as unit_files:
            with self.assertRaises(contrib.Stop) as cm:
                contrib.start(self.ctx(env={'PATH': ''}), args)
        if unit_files.called:
            seen['class'] = unit_files.call_args.args[1]
        return cm.exception, seen

    def test_start_names_the_class_of_a_bare_placeholder_entry_only_when_given(self):
        stop, seen = self._bare_entry_start()
        self.assertIn('--class', stop.message)
        self.assertNotIn('named', seen)
        stop, seen = self._bare_entry_start('--class', 'TESObjectCELL')
        self.assertTrue(seen.get('named'), stop.message)
        stop, seen = self._bare_entry_start('--class', 'not a class')
        self.assertIn('--class must be', stop.message)
        self.assertNotIn('named', seen)

    def test_start_explicit_class_overrides_an_existing_name(self):
        stop, seen = self._bare_entry_start('--class', 'TESObjectCELL', name='TESObjectCell::GetValue')
        self.assertTrue(seen.get('named'), stop.message)
        self.assertEqual(seen['class'], 'TESObjectCELL')

    def test_redact_hides_checkout_and_home(self):
        home = str(self.tmp / 'home')
        ctx = self.ctx(repo=self.tmp / 'home/src/skyrim-research', env={'HOME': home, 'USERPROFILE': home})
        ctx.redact = True
        text = ctx.scrub(f'{self.tmp.as_posix()}/home/src/skyrim-research/.local/x and {Path(home).as_posix()}/Games/SkyrimSE.exe')
        self.assertEqual(text, '<repo>/.local/x and ~/Games/SkyrimSE.exe')

    def test_practice_tasks_have_their_own_id_and_are_not_picked_by_default(self):
        self.assertEqual(contrib.task_id_for('NiNode', practice=True), 'practice-ninode')
        for tid, practice in (('practice-ninode', True), ('contrib-ninode', False)):
            d = self.private / 'tasks' / tid
            d.mkdir(parents=True)
            (d / 'task.json').write_text(json.dumps({'compiled': 'x', 'functions': [],
                                                     'contrib': {'practice': practice}}))
        self.assertEqual(contrib.load_task(self.ctx())[0].name, 'contrib-ninode')

    def test_self_test_is_skipped_not_passed_without_its_function(self):
        repo = self.tmp / 'repo'
        (repo / 'data').mkdir(parents=True)
        (repo / 'data/progress.json').write_text(json.dumps({'functions': []}))
        code, data, _ = contrib.run_self_test(self.ctx(repo=repo))
        self.assertTrue(data['skipped'])
        self.assertEqual(data['functions'], [])

    def test_no_licence_link_means_no_acceptance(self):
        vsman = self.tmp / 'VisualStudio.vsman'
        vsman.write_text(json.dumps({'packages': []}))
        self.assertIsNone(contrib.licence_url(vsman))

    def test_case_folded_include_is_matched_only_to_closure_files(self):
        root = '/Users/A/repo'
        repo_files = []
        with unittest.mock.patch.object(contrib, 'same_file', return_value=True):
            rest = contrib.fold_case_includes(['/users/a/repo/reconstruction/forms/X.h'.lower(),
                                               'Z:/users/a/repo/reconstruction/forms/../../secret.h',
                                               '/users/a/elsewhere/X.h'], root, ['reconstruction/forms/X.h'],
                                              repo_files)
        self.assertEqual(repo_files, ['reconstruction/forms/X.h'])
        self.assertEqual(len(rest), 2)

    def test_case_folded_include_must_open_the_closure_file_itself(self):
        root = self.tmp / 'repo'
        (root / 'reconstruction/forms').mkdir(parents=True)
        (root / 'reconstruction/forms/X.h').write_text('// closure file\n')
        other = self.tmp / 'other'
        other.mkdir()
        (other / 'X.h').write_text('// another file\n')
        exact = str(root / 'reconstruction/forms/X.h')
        repo_files = []
        self.assertEqual(contrib.fold_case_includes([exact], root, ['reconstruction/forms/X.h'], repo_files), [])
        self.assertEqual(repo_files, ['reconstruction/forms/X.h'])
        # A name that folds to a closure entry but opens nothing, or another file, is still outside.
        missing = str(root / 'reconstruction/forms/Y.h')
        repo_files = []
        self.assertEqual(contrib.fold_case_includes([missing], root, ['reconstruction/forms/y.h'], repo_files),
                         [missing])
        self.assertEqual(repo_files, [])
        with unittest.mock.patch.object(contrib.os.path, 'samefile', return_value=False):
            self.assertEqual(contrib.fold_case_includes([exact], root, ['reconstruction/forms/X.h'], []), [exact])
        self.assertFalse(contrib.same_file(exact, other / 'X.h'))

    def test_manifest_hash_mismatch_stops_before_any_licence_or_download(self):
        pins = contrib.recipe_constants(ROOT)
        work = self.private / 'toolchain-work' / 'msvc-wine' / '.git'
        work.mkdir(parents=True)

        def runner(cmd, **kw):
            out = pins['MSVC_WINE_COMMIT'] if cmd[:2] == ['git', 'rev-parse'] else ''
            return subprocess.CompletedProcess(cmd, 0, out, '')

        class Resp(io.BytesIO):
            def __enter__(self):
                return self

            def __exit__(self, *a):
                return False
        ctx = self.ctx(repo=ROOT, runner=runner, env={'PATH': ''})
        with unittest.mock.patch.object(contrib.urllib.request, 'urlopen', return_value=Resp(b'{"tampered": 1}')):
            with self.assertRaises(contrib.Stop) as cm:
                contrib.install_toolchain(ctx, accept=True)
        self.assertEqual(cm.exception.code, contrib.FAILED)
        self.assertIn('pinned SHA-256', cm.exception.message)
        self.assertFalse((self.private / 'toolchain-work' / 'VisualStudio.vsman').exists())

    def test_fetch_sources_pins_each_revision_and_reports_network_failure(self):
        ran = []

        def runner(cmd, **kw):
            ran.append(cmd)
            return subprocess.CompletedProcess(cmd, 0, '', '')
        repo = self.tmp / 'repo'
        ctx = self.ctx(repo=repo, runner=runner)
        sources = {'a/b': ('.local/sources/b', 'f' * 40, 'MIT')}
        self.assertEqual(contrib.fetch_sources(ctx, sources), ['a/b'])
        self.assertIn(['git', 'fetch', '-q', '--depth', '1', 'https://github.com/a/b.git', 'f' * 40], ran)
        ctx.runner = lambda cmd, **kw: subprocess.CompletedProcess(cmd, 128, '', 'no network')
        with self.assertRaises(contrib.Stop) as cm:
            contrib.fetch_sources(ctx, sources)
        self.assertEqual(cm.exception.code, contrib.NETWORK)

    def test_go_resumes_unsubmitted_work(self):
        d = self.private / 'tasks' / 'contrib-a'
        d.mkdir(parents=True)
        (d / 'task.json').write_text(json.dumps({'task_id': 'contrib-a', 'compiled': 'reconstruction/forms/A.cpp',
                                                 'contrib': {'practice': False, 'unit': ['x']}}))
        args = contrib.parser().parse_args(['go'])
        with unittest.mock.patch.object(contrib, 'cmd_setup', return_value=(0, {}, None)), \
                unittest.mock.patch.object(contrib, 'cmd_claim') as claim:
            code, data, nxt = contrib.cmd_go(self.ctx(), args)
        self.assertTrue(data['resumed'])
        claim.assert_not_called()

    def test_release_closes_only_own_claim_issues(self):
        gh = FakeGitHub({MAPPED: [item('me', 1, 3), item('someone', 1, 4),
                                    dict(item('me', 1, 5), pull_request=True)]})
        contrib.save_local_claim(self.ctx(), MAPPED, {'status': 'published', 'url': 'u'})
        code, data, _ = contrib.cmd_release(self.ctx(github=gh), contrib.parser().parse_args(['release', f'0x{MAPPED:x}']))
        self.assertEqual(gh.closed, [3])
        self.assertNotIn(f'0x{MAPPED:x}', contrib.local_claims(self.ctx()))

    def test_planner_skips_open_claims_and_warns_offline(self):
        sys.path.insert(0, str(ROOT / 'tools' / 'ghidra'))
        import export_pack
        gh = FakeGitHub({MAPPED: [item('someone', 0)], 0x2000: [item('someone', 4)]})
        with unittest.mock.patch.object(contrib.Ctx, 'github', return_value=gh):
            self.assertEqual(export_pack.open_claim_rvas(), {MAPPED})
        err = io.StringIO()
        with unittest.mock.patch.object(contrib.Ctx, 'github', return_value=FakeGitHub(offline=True)), \
                contextlib.redirect_stderr(err):
            self.assertEqual(export_pack.open_claim_rvas(), set())
        self.assertIn('not checked', err.getvalue())


class JoinPageTests(unittest.TestCase):
    def test_numbers_come_from_the_inventory(self):
        from build_site import render_join
        data = contrib.inventory(ROOT)
        page = render_join(data, 'synthetic-revision')
        matched = sum(f['status'] == 'matched' for f in data['functions'])
        self.assertIn(f'{matched} accepted', page)
        self.assertNotIn('%', page.split('<main>')[1].split('</main>')[0].replace('100%', ''))


class SymbolMapPathTests(unittest.TestCase):
    def test_missing_map_names_the_path_and_the_sparse_fix(self):
        import tempfile
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaises(contrib.Stop) as caught:
                contrib.symbol_map_path(tmp, 'some-build')
        self.assertIn('reports/some-build/symbol-map.json', caught.exception.message)
        self.assertIn("git sparse-checkout set --no-cone '/*' '!/site/'", caught.exception.next_action)


class CommandLineTests(unittest.TestCase):
    def test_non_tty_json_never_prompts(self):
        proc = subprocess.run([sys.executable, str(ROOT / 'tools/contrib.py'), '--json', 'doctor'],
                              stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=120,
                              env={'PATH': '/usr/bin:/bin', 'HOME': tempfile.gettempdir(),
                                   'SR_SKYRIM_EXE': '/nonexistent/SkyrimSE.exe', 'SR_MSVC': '/nonexistent'})
        out = json.loads(proc.stdout)
        self.assertEqual(proc.returncode, out['exit_code'])
        self.assertIn('next', out)

    def test_rva_parsing(self):
        self.assertEqual(contrib.parse_rva('0x1DE5E0'), 0x1de5e0)
        with self.assertRaises(contrib.Stop):
            contrib.parse_rva('sub_1de5e0')
        self.assertEqual(str(PureWindowsPath(r'C:\a') / 'b'), r'C:\a\b')


if __name__ == '__main__':
    unittest.main()


class ProfileTests(Base):
    def test_default_remembered_and_refused(self):
        ctx = self.ctx()
        self.assertEqual(contrib.contrib_profile(ctx)['name'], 'cheap')
        contrib.save_config(ctx, profile='full')
        self.assertEqual(contrib.contrib_profile(ctx)['name'], 'full')
        self.assertEqual(contrib.contrib_profile(ctx, 'cheap')['contrib_max_tries'], 6)
        with self.assertRaises(contrib.Stop):
            contrib.contrib_profile(ctx, 'claude-low')

    def test_go_and_start_accept_profile(self):
        p = contrib.parser()
        self.assertEqual(p.parse_args(['go', '--profile', 'full']).profile, 'full')
        self.assertEqual(p.parse_args(['start', '0x10', '--profile', 'cheap']).profile, 'cheap')
        self.assertIsNone(p.parse_args(['start', '0x10']).profile)


class CompareProfileTests(CompareTests):
    def test_summary_names_profile_and_limit(self):
        code, data, nxt = contrib.run_compare(self.ctx_, 'contrib-synthetic')
        self.assertEqual((data['profile'], data['max_tries']), ('cheap', 6))


class OutsiderRegressionTests(Base):
    def test_claim_needs_no_label_or_assignment_permissions(self):
        commands = []
        def runner(cmd, **kw):
            commands.append(cmd)
            if cmd[1:3] == ['auth', 'status']:
                return subprocess.CompletedProcess(cmd, 0, '', '')
            if cmd[1:3] == ['issue', 'create']:
                return subprocess.CompletedProcess(cmd, 0, 'https://github.com/x/y/issues/1\n', '')
            self.fail('unexpected privileged operation: ' + repr(cmd))
        ctx = self.ctx(runner=runner)
        with unittest.mock.patch.object(ctx, 'which', return_value='gh'):
            self.assertTrue(contrib.GitHub(ctx).create_issue('claim', 'public scope'))
        self.assertFalse(any('--label' in c or '--assignee' in c for c in commands))

    def test_external_paths_are_redacted_in_json_and_subprocess_logs(self):
        exe = '/outside-home/game/SkyrimSE.exe'
        tool = '/external-toolchain/msvc'
        ctx = self.ctx(env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp / 'home'), 'SR_MSVC': tool})
        ctx.redact = True
        ctx.redact_paths[exe] = '<exe>'
        ctx.run([sys.executable, '-c', 'print(' + repr(exe + ' ' + tool) + ')'])
        text = Path(ctx.process_logs[0]).read_text()
        self.assertNotIn(exe, text)
        self.assertNotIn(tool, text)
        self.assertIn('<exe>', text)
        self.assertIn('<toolchain>', text)

    def test_json_escaped_unicode_and_quoted_external_paths_are_redacted(self):
        ctx = self.ctx(env={'HOME': str(self.tmp / 'home')})
        ctx.redact = True
        external = '/outside-home/\u00e9"quoted/SkyrimSE.exe'
        ctx.redact_paths[external] = '<exe>'
        result = json.loads(ctx.scrub(json.dumps({'path': external, 'log': 'opened ' + external})))
        self.assertEqual(result, {'path': '<exe>', 'log': 'opened <exe>'})

    def test_fresh_windows_doctor_redacts_discovered_exe_and_tools(self):
        exe = r'D:\Private Library\Café\SkyrimSE.exe'
        git = r'E:\Private Tools\Git\bin\git.exe'
        llvm = r'F:\Private Tools\LLVM\bin\llvm-objdump.exe'
        env = {'USERPROFILE': r'C:\Users\synthetic', 'SR_OBJDUMP': llvm, 'SR_CONTRIB_COMPILER': 'stand-in'}
        # LLVM is found by the filesystem fallback, while Git is found on PATH.
        def which(name, **_):
            return git if name == 'git' else None

        for json_mode in (False, True):
            for status in ('ok', 'wrong-build'):
                with self.subTest(json_mode=json_mode, status=status):
                    ctx = self.ctx(env=env, platform='win32', as_json=json_mode)
                    info = {'status': status, 'path': exe.replace('\\', '/'),
                            'version': 'private-version', 'sha256': 'a' * 64}
                    flags = ['--json'] if json_mode else []
                    with unittest.mock.patch('contrib.shutil.which', side_effect=which), \
                            unittest.mock.patch('contrib.os.path.isfile', side_effect=lambda p: p == llvm), \
                            unittest.mock.patch('contrib.exe_candidates', return_value=[exe]), \
                            unittest.mock.patch('contrib.inspect_exe', return_value=info), \
                            contextlib.redirect_stdout(io.StringIO()) as output:
                        code = contrib.main([*flags, '--redact', 'doctor'], ctx=ctx)
                    shown = output.getvalue()
                    self.assertEqual(code, contrib.OK if status == 'ok' else contrib.MISSING)
                    for private in ('Private Library', 'Private Tools', 'private-version', 'a' * 16):
                        self.assertNotIn(private, shown)
                    for marker in ('<exe>', '<git>', '<llvm-objdump>'):
                        self.assertIn(marker, shown)
                    if json_mode:
                        self.assertTrue(json.loads(shown)['checks'])
                    self.assertFalse(contrib.config_path(ctx).exists())

    def test_redacted_setup_omits_private_self_test_failure_details(self):
        for failure in ('compile', 'compare'):
            with self.subTest(failure=failure):
                ctx = self.ctx(env={'SR_CONTRIB_COMPILER': 'stand-in'}, platform='win32')
                exe = r'D:\Private Library\SkyrimSE.exe'
                exc = contrib.Stop(contrib.COMPILE, 'synthetic private diagnostic', errors=['synthetic listing'])
                result = (contrib.FAILED, {'bind': ['synthetic private diagnostic'], 'functions': []}, None)
                with unittest.mock.patch.object(ctx, 'which', return_value='git'), \
                        unittest.mock.patch('contrib.wanted_packages', return_value=[]), \
                        unittest.mock.patch('contrib.exe_candidates', return_value=[exe]), \
                        unittest.mock.patch('contrib.inspect_exe', return_value={'status': 'ok', 'path': exe}), \
                        unittest.mock.patch('contrib.run_self_test', side_effect=exc if failure == 'compile' else None,
                                            return_value=result), \
                        contextlib.redirect_stdout(io.StringIO()) as output:
                    code = contrib.main(['--json', '--redact', 'setup', '--no-sources', '--no-decompiler'], ctx=ctx)
                shown = output.getvalue()
                self.assertEqual(code, contrib.COMPILE if failure == 'compile' else contrib.FAILED)
                self.assertNotIn('Private Library', shown)
                self.assertNotIn('synthetic private diagnostic', shown)
                self.assertNotIn('synthetic listing', shown)
                self.assertEqual(json.loads(shown)['steps'][-1]['step'], 'self-test')

    def test_setup_emits_one_json_object_even_when_installer_prints(self):
        ctx = self.ctx(env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
        def setup(ctx, args):
            ctx.run([sys.executable, '-c', 'print("installer progress")'])
            return contrib.OK, {'phase': 'complete'}, None
        out = io.StringIO()
        with unittest.mock.patch.dict(contrib.COMMANDS, setup=setup), contextlib.redirect_stdout(out):
            self.assertEqual(contrib.main(['--json', 'setup'], ctx=ctx), 0)
        result = json.loads(out.getvalue())
        self.assertEqual(result['phase'], 'complete')
        self.assertIn('installer progress', Path(result['logs'][0]).read_text())

    def test_rate_limit_is_distinct_from_offline(self):
        import urllib.error
        ctx = self.ctx(env={'PATH': ''})
        gh = contrib.GitHub(ctx)
        error = urllib.error.HTTPError('https://api.github.com/', 403, 'forbidden',
                                       {'X-RateLimit-Remaining': '0'}, None)
        with unittest.mock.patch('urllib.request.urlopen', side_effect=error):
            with self.assertRaisesRegex(contrib.Offline, 'rate-limit.*gh auth login'):
                gh.api('repos/x/y/issues')
        with unittest.mock.patch('urllib.request.urlopen', side_effect=urllib.error.URLError('offline')):
            with self.assertRaisesRegex(contrib.Offline, 'offline or transport'):
                gh.api('repos/x/y/issues')


class SubmitPreflightTests(SubmitTests):
    def test_renamed_or_legacy_upstream_can_never_receive_submit_push(self):
        self.git('remote', 'remove', 'fork')
        self.git('remote', 'add', 'origin', 'https://github.com/awarebayes/skyrim_decomp.git')
        for url in ('https://github.com/Mudcrab-Team/skyrim_decomp.git',
                    'https://github.com/awarebayes/skyrim_decomp.git',
                    'git@github.com:awarebayes/skyrim-research.git',
                    'https://github.com/AWAREBAYES/SKYRIM_DECOMP.git/'):
            with self.subTest(url=url):
                self.git('remote', 'set-url', 'origin', url)
                before = self.state()
                commands = []
                def runner(cmd, **kw):
                    commands.append(cmd)
                    if cmd[:2] == ['git', 'push']:
                        self.fail('submit attempted an upstream push, including a credential probe')
                    return self.runner(cmd, **kw)
                ctx = self.ctx(repo=self.repo, github=FakeGitHub(), runner=runner,
                               env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
                for dry_run in (True, False):
                    out = io.StringIO()
                    with contextlib.redirect_stdout(out):
                        code = contrib.main(['--json', 'submit', '--base', 'HEAD'] +
                                            (['--dry-run'] if dry_run else []), ctx=ctx)
                    result = json.loads(out.getvalue())
                    self.assertEqual(code, contrib.FAILED)
                    self.assertIsNone(result['preflight']['fork_remote'])
                    self.assertIn('no fork remote', ' '.join(result['blockers']))
                    self.assertIn('<you>/skyrim_decomp.git', ' '.join(result['preflight']['actions']))
                self.assertEqual(self.state(), before)
                self.assertFalse(any(c[:2] in (['git', 'add'], ['git', 'commit']) for c in commands))

    def test_fork_with_additional_upstream_push_url_is_refused(self):
        self.git('remote', 'set-url', '--add', '--push', 'fork',
                 'https://github.com/contributor/skyrim_decomp.git')
        self.git('remote', 'set-url', '--add', '--push', 'fork',
                 'https://github.com/awarebayes/skyrim_decomp.git')
        ctx = self.ctx(repo=self.repo, runner=self.runner)
        self.assertEqual(contrib.upstream_remote(ctx), ('fork', None))
        code, out = self.submit()
        self.assertEqual(code, contrib.FAILED)
        self.assertIn('no fork remote', ' '.join(out['blockers']))

    def test_fork_push_auth_failure_precedes_staging_and_commit(self):
        before = self.state()
        def runner(cmd, **kw):
            if cmd[:3] == ['git', 'push', '--dry-run']:
                return subprocess.CompletedProcess(cmd, 128, '', 'synthetic auth refusal')
            return self.runner(cmd, **kw)
        ctx = self.ctx(repo=self.repo, github=FakeGitHub(can_create=False), runner=runner,
                       env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
        with contextlib.redirect_stdout(io.StringIO()):
            code = contrib.main(['--json', 'submit', '--base', 'HEAD'], ctx=ctx)
        self.assertEqual(code, contrib.NETWORK)
        self.assertEqual(self.state(), before)

    def test_missing_fork_and_author_are_reported_without_a_commit(self):
        self.git('remote', 'remove', 'fork')
        self.git('config', '--unset', 'user.name')
        self.git('config', '--unset', 'user.email')
        before = self.state()
        code, out = self.submit()
        self.assertEqual(code, contrib.FAILED)
        self.assertIn('no fork remote', ' '.join(out['blockers']))
        self.assertIn('git author name', ' '.join(out['blockers']))
        self.assertEqual(self.state(), before)
        ctx = self.ctx(repo=self.repo, github=FakeGitHub(), runner=self.runner,
                       env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(contrib.main(['--json', 'submit', '--base', 'HEAD'], ctx=ctx), contrib.FAILED)
        self.assertEqual(self.state(), before)

    def test_manual_browser_link_names_fork_owner_and_encoded_branch(self):
        self.git('switch', '-q', '-c', 'contrib/test')
        def runner(cmd, **kw):
            if cmd[:2] == ['git', 'push'] or cmd[:2] == ['git', 'commit']:
                return subprocess.CompletedProcess(cmd, 0, '', '')
            return self.runner(cmd, **kw)
        ctx = self.ctx(repo=self.repo, github=FakeGitHub(can_create=False), runner=runner,
                       env={'PATH': '/usr/bin:/bin', 'HOME': str(self.tmp)})
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            self.assertEqual(contrib.main(['--json', 'submit', '--base', 'HEAD'], ctx=ctx), 0)
        result = json.loads(out.getvalue())
        self.assertIn('/compare/main...contributor:contrib%2Ftest?', result['link'])
        self.assertFalse(result['preflight']['authenticated'])
        self.assertIn('no-target', result['ci_hash']['advice'])
        self.assertNotIn('fo4-private', ' '.join(result['warnings']))


class ContributorActionsTests(Base):
    def test_go_requires_person_to_file_link_only_claim_before_start(self):
        args = contrib.parser().parse_args(['go', '0x1000'])
        claim = {'claim': 'link-only', 'link': 'https://github.com/x/y/issues/new',
                 'links': ['https://github.com/x/y/issues/new']}
        with unittest.mock.patch.object(contrib, 'cmd_setup', return_value=(0, {}, None)), \
                unittest.mock.patch.object(contrib, 'cmd_claim', return_value=(0, claim, 'file claim')), \
                unittest.mock.patch.object(contrib, 'start') as start:
            code, data, nxt = contrib.cmd_go(self.ctx(), args)
        self.assertEqual(code, contrib.CONSENT)
        self.assertEqual(data['claim'], 'link-only')
        self.assertIn(claim['link'], nxt)
        self.assertIn('claim 0x1000 --github-user', nxt)
        start.assert_not_called()

    def test_unsigned_claim_body_does_not_mention_placeholder_login(self):
        import claims
        body = claims.body('synthetic', [(0x1000, 0x1001)], {'functions': []}, None)
        self.assertIn('Claimant: (issue author)', body)
        self.assertNotIn('@claimant', body)
        self.assertIn('Claimant: @tester', claims.body('synthetic', [(0x1000, 0x1001)],
                                                     {'functions': []}, 'tester'))

    def test_model_ids_are_preserved_in_attribution_and_claim(self):
        import agent_identity
        for model in ('claude-opus-5-5', 'gpt-6.1-sol', 'person, assisted by claude-opus-5-5'):
            with self.subTest(model=model):
                self.assertEqual(agent_identity.resolve(drafted_by=model), model)
                self.assertEqual(agent_identity.resolve(model=model), model)
                ctx = self.ctx(github=FakeGitHub())
                contrib.save_config(ctx, drafted_by=model, model=None)
                with contextlib.redirect_stdout(io.StringIO()):
                    contrib.cmd_claim(ctx, contrib.parser().parse_args(['claim', f'0x{MAPPED:x}']))
                self.assertEqual(contrib.load_config(ctx)['model'], model)
                self.assertEqual(contrib.local_claims(ctx)[f'0x{MAPPED:x}']['model'], model)
        self.assertEqual(agent_identity.resolve(agent='worker-12'), 'worker')

    def test_contributor_profiles_use_the_contributor_card(self):
        import profiles
        for name in ('cheap', 'full'):
            docs = profiles.get(name)['contrib_docs']
            self.assertIn('docs/contributor-card.md', docs)
            self.assertFalse(any('drafter-card' in doc for doc in docs))

class StructuredFeedbackParsingTests(unittest.TestCase):
    def test_bot_sticky_findings(self):
        import contrib_feedback
        body = ('<!-- pr-bot -->\nBot status for head 0123abcd (updated in place).\n\n'
                'Not accepted yet:\n- 0x1000: the review did not approve it\n  - Fix the binding.\n')
        parsed = contrib_feedback.parse_sticky(body)
        self.assertEqual(parsed['head'], '0123abcd')
        self.assertEqual(parsed['what_needs_changing'], ['0x1000: the review did not approve it (Fix the binding.)'])
