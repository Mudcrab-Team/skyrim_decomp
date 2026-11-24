"""Offline tests: synthetic archives and projects only, never a game or a network."""
import hashlib
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch, Mock
import zipfile

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import contrib
import contrib_decompiler as d
import contrib_screen
import check


class DecompilerTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.ctx = contrib.Ctx(repo=ROOT, private=self.root / '.local/contrib',
                               as_json=True, assume_yes=True,
                               env={'PATH': '', 'ProgramFiles': str(self.root), 'ProgramFiles(x86)': str(self.root)})
        if sys.platform == 'cygwin':
            self.ctx.platform = 'linux'
        self.project = self.ctx.private / 'decompiler/projects/synthetic'
        self.project.mkdir(parents=True)

    def archive(self, root, *, java=False):
        stream = io.BytesIO()
        with zipfile.ZipFile(stream, 'w') as z:
            z.writestr(root + ('/bin/java' if java else '/support/analyzeHeadless'), 'synthetic')
            if not java:
                z.writestr(root + '/Ghidra/Features/Decompiler/os/linux_x86_64/decompile', 'synthetic')
        blob = stream.getvalue()
        return {'root': root, 'url': 'https://example.invalid/' + root + '.zip',
                'sha256': hashlib.sha256(blob).hexdigest(), 'size': len(blob)}, blob

    def test_official_release_pins_and_platforms(self):
        pins = d.pins(self.ctx)
        self.assertEqual(pins['ghidra']['version'], '12.2')
        self.assertEqual(pins['ghidra']['sha256'],
                         '2c2cd776db3c1f6a097ba418922378ac3649cadd5e844a6f5f088ae628a7be67')
        for platform, machine, key in [('darwin', 'arm64', 'mac-aarch64'),
                                      ('darwin', 'x86_64', 'mac-x64'),
                                      ('linux', 'x86_64', 'linux-x64'),
                                      ('linux', 'aarch64', 'linux-aarch64'),
                                      ('win32', 'AMD64', 'windows-x64')]:
            self.ctx.platform = platform
            with patch.object(d.platform, 'machine', return_value=machine):
                self.assertEqual(d.platform_key(self.ctx), key)
                self.assertRegex(pins['jdk'][key]['sha256'], r'^[0-9a-f]{64}$')
                self.assertTrue(pins['jdk'][key]['url'].startswith('https://github.com/adoptium/'))
        self.assertTrue(pins['ghidra']['url'].startswith('https://github.com/NationalSecurityAgency/ghidra/'))

    def test_download_hash_check_and_cache(self):
        pin, blob = self.archive('synthetic')
        with patch.object(d.urllib.request, 'urlopen', return_value=io.BytesIO(blob)) as fetch:
            output = d.download(self.ctx, pin)
            self.assertEqual(output.read_bytes(), blob)
            d.download(self.ctx, pin)
            self.assertEqual(fetch.call_count, 1)
        output.write_bytes(b'corrupt cache')
        with patch.object(d.urllib.request, 'urlopen', return_value=io.BytesIO(b'corrupt network')):
            with self.assertRaises(contrib.Stop) as raised:
                d.download(self.ctx, pin)
            self.assertEqual(raised.exception.code, contrib.FAILED)
        self.assertFalse(output.exists())
        self.assertFalse(output.with_name(output.name + '.part').exists())

    def test_transient_download_errors_retry_at_most_three_times(self):
        pin, blob = self.archive('synthetic')
        failure = d.urllib.error.URLError('synthetic offline')
        with patch.object(d.urllib.request, 'urlopen', side_effect=[failure, io.BytesIO(blob)]) as network, \
                patch.object(d.time, 'sleep'):
            self.assertTrue(d.download(self.ctx, pin).is_file())
            self.assertEqual(network.call_count, 2)
        pin['url'] += '-missing'
        with patch.object(d.urllib.request, 'urlopen', side_effect=failure) as network, \
                patch.object(d.time, 'sleep'):
            with self.assertRaises(contrib.Stop) as raised:
                d.download(self.ctx, pin)
            self.assertEqual(raised.exception.code, contrib.NETWORK)
            self.assertEqual(network.call_count, 3)

    def test_mock_install_is_private_and_idempotent(self):
        ghidra, gblob = self.archive('synthetic-ghidra')
        jdk, jblob = self.archive('synthetic-jdk', java=True)
        pins = {'ghidra': ghidra, 'jdk': {'linux-x64': jdk}}
        self.ctx.platform = 'linux'
        def fetch(url, **kw):
            return io.BytesIO(gblob if url == ghidra['url'] else jblob)
        with patch.object(d, 'pins', return_value=pins), \
                patch.object(d.platform, 'machine', return_value='x86_64'), \
                patch.object(d.urllib.request, 'urlopen', side_effect=fetch) as network:
            d.install(self.ctx)
            d.install(self.ctx)
            self.assertEqual(network.call_count, 2)
            headless, java = d.runtime(self.ctx)
            self.assertTrue(headless.is_relative_to(self.ctx.private))
            self.assertTrue(headless.is_file())
            self.assertTrue((java / 'bin/java').is_file())
        self.assertIn('MB download', self.ctx.log[0])

    def test_mac_native_build_uses_pinned_source_and_is_idempotent(self):
        self.ctx.platform = 'darwin'
        calls = []
        def run(cmd, **kw):
            calls.append(cmd)
            if cmd[0].endswith('make'):
                (kw['cwd'] / 'ghidra_opt').write_text('synthetic native executable')
            return subprocess.CompletedProcess(cmd, 0)
        self.ctx.runner = run
        self.ctx.which = lambda name: '/usr/bin/' + name
        with patch.object(d.platform, 'machine', return_value='arm64'):
            source = d.runtime(self.ctx)[0].parents[1] / 'Ghidra/Features/Decompiler/src/decompile/cpp'
            source.mkdir(parents=True)
            d.ensure_native(self.ctx)
            d.ensure_native(self.ctx)
            self.assertTrue(d.native_binary(self.ctx).is_file())
            self.assertEqual(sum(cmd[0].endswith('make') for cmd in calls), 1)
            self.assertIn('ARCH_TYPE=-arch arm64', calls[-1])
            self.assertTrue((d.directory(self.ctx) / 'native-build.json').is_file())

    def test_missing_native_build_tools_are_reported(self):
        self.ctx.platform = 'darwin'
        self.ctx.which = lambda name: None
        with patch.object(d.platform, 'machine', return_value='x86_64'):
            with self.assertRaises(contrib.Stop) as raised:
                d.ensure_native(self.ctx)
        self.assertEqual(raised.exception.code, contrib.MISSING)
        self.assertIn('Command Line Tools', raised.exception.next_action)

    def test_missing_executable_prevents_download(self):
        with patch.object(d, 'install') as install:
            with self.assertRaises(contrib.Stop) as raised:
                d.setup(self.ctx)
            self.assertEqual(raised.exception.code, contrib.MISSING)
            install.assert_not_called()

    def test_launch_is_bounded_and_all_runtime_state_is_private(self):
        self.ctx.env.update(_JAVA_OPTIONS='-Xmx64G', JDK_JAVA_OPTIONS='-Xmx64G',
                            GHIDRA_HEADLESS_JAVA_OPTIONS='-Xmx64G')
        command, env = d.launch_command(self.ctx, self.project, '-noanalysis')
        self.assertEqual(env['GHIDRA_HEADLESS_MAXMEM'], '16G')
        self.assertIn('-XX:+ExitOnOutOfMemoryError', env['JAVA_TOOL_OPTIONS'])
        self.assertNotIn('_JAVA_OPTIONS', env)
        self.assertNotIn('JDK_JAVA_OPTIONS', env)
        self.assertNotIn('GHIDRA_HEADLESS_JAVA_OPTIONS', env)
        for key in ['user.home', 'java.io.tmpdir', 'application.tempdir',
                    'application.cachedir', 'application.settingsdir']:
            self.assertIn('-D' + key + '="' + str(d.directory(self.ctx)), env['JAVA_TOOL_OPTIONS'])
        if isinstance(command, list):
            self.assertEqual(command[command.index('-max-cpu') + 1], '4')
        else:
            self.assertIn('"-max-cpu" "4"', command)
        self.assertTrue(env['PATH'].startswith(str(d.runtime(self.ctx)[1] / 'bin')))

    def test_windows_memory_sampling_counts_only_the_target_process_tree(self):
        rows = [(10, 1, 100), (20, 10, 200), (30, 20, 300), (40, 1, None)]
        with patch.object(d.sys, 'platform', 'win32'), \
                patch.object(d, 'windows_process_rows', return_value=rows):
            self.assertEqual(d.process_tree_rss(10), 600)
        rows[1] = (20, 10, None)
        with patch.object(d.sys, 'platform', 'win32'), \
                patch.object(d, 'windows_process_rows', return_value=rows):
            self.assertIsNone(d.process_tree_rss(10))

    def test_setup_and_go_accept_opt_in(self):
        for command in ('setup', 'go'):
            self.assertTrue(contrib.parser().parse_args([command]).decompiler)
            self.assertTrue(contrib.parser().parse_args([command, '--decompiler']).decompiler)
            self.assertFalse(contrib.parser().parse_args([command, '--no-decompiler']).decompiler)
        self.assertEqual(contrib.parser().parse_args(['decomp', '0x1234']).rva, '0x1234')

    def ordinary_setup(self, *extra):
        self.ctx.platform = 'linux'
        args = contrib.parser().parse_args(['setup', '--no-sources', '--no-sibling', '--no-self-test', *extra])
        with patch.object(self.ctx, 'which', return_value='/synthetic/git'), \
                patch.object(contrib, 'check_toolchain', return_value={'status': 'override', 'bin': 'synthetic'}), \
                patch.object(contrib, 'wanted_packages', return_value=[]), \
                patch.object(contrib, 'package_manager', return_value=None), \
                patch.object(contrib, 'resolve_exe', return_value=({'status': 'ok', 'path': 'synthetic.exe'}, 'synthetic')):
            return contrib.cmd_setup(self.ctx, args)

    def test_ordinary_setup_installs_decompiler_by_default_and_opt_out_skips_it(self):
        with patch.object(d, 'recommended_setup', return_value={'state': 'starting'}) as setup:
            code, data, _ = self.ordinary_setup()
            self.assertEqual(code, contrib.OK)
            self.assertEqual(data['decompiler']['state'], 'starting')
            setup.assert_called_once_with(self.ctx, False)
            setup.reset_mock()
            code, data, _ = self.ordinary_setup('--no-decompiler')
            self.assertEqual(code, contrib.OK)
            self.assertNotIn('decompiler', data)
            setup.assert_not_called()

    def test_low_available_ram_skips_without_download_or_setup_failure(self):
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'available_ram', return_value=17 * 1024**3), \
                patch.object(d, 'install') as install:
            code, data, _ = self.ordinary_setup()
        self.assertEqual(code, contrib.OK)
        self.assertEqual(data['decompiler']['state'], 'skipped')
        self.assertIn('17.0 GiB available RAM', data['decompiler']['reason'])
        install.assert_not_called()
        lines = [line for line in self.ctx.log if 'decompiler:' in line]
        self.assertEqual(len(lines), 1)
        self.assertIn('setup later', lines[0])

    def test_low_disk_unknown_ram_and_launch_failure_are_nonblocking(self):
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'available_ram', return_value=20 * 1024**3), \
                patch.object(d.shutil, 'disk_usage', return_value=Mock(free=2 * 1024**3)), \
                patch.object(d, 'setup') as setup:
            result = d.recommended_setup(self.ctx)
            self.assertEqual(result['state'], 'skipped')
            self.assertIn('free disk', result['reason'])
            setup.assert_not_called()
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'available_ram', return_value=None):
            self.assertIn('could not be measured', d.recommended_setup(self.ctx)['reason'])
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'resource_problem', return_value=None), \
                patch.object(d, 'setup', side_effect=contrib.Stop(contrib.NETWORK, 'synthetic failure')):
            self.assertEqual(d.recommended_setup(self.ctx)['state'], 'skipped')

    def test_ready_analysis_stays_available_without_new_resource_reservation(self):
        d.write_json(self.project / 'state.json', dict(state='ready'))
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'resource_problem') as resources, patch.object(d, 'setup') as setup:
            self.assertEqual(d.recommended_setup(self.ctx)['state'], 'ready')
            self.assertTrue(contrib.load_config(self.ctx)['decompiler'])
            resources.assert_not_called()
            setup.assert_not_called()

    def test_go_forwards_default_and_opt_out_to_setup(self):
        for extra in ([], ['--no-decompiler']):
            args = contrib.parser().parse_args(['go', *extra])
            with patch.object(contrib, 'cmd_setup', side_effect=contrib.Stop(contrib.USAGE, 'synthetic stop')) as setup:
                with self.assertRaises(contrib.Stop):
                    contrib.cmd_go(self.ctx, args)
                self.assertEqual(setup.call_args.args[1].decompiler, not extra)

    def test_available_ram_uses_available_values_on_mac_linux_and_windows(self):
        self.ctx.platform = 'darwin'
        self.ctx.runner = lambda *a, **kw: subprocess.CompletedProcess(a, 0, stdout=(
            'Mach Virtual Memory Statistics: (page size of 16384 bytes)\n'
            'Pages free: 100.\nPages inactive: 200.\nPages speculative: 300.\nPages wired down: 900.\n'))
        self.assertEqual(d.available_ram(self.ctx), 300 * 16384)
        self.ctx.platform = 'linux'
        with patch.object(Path, 'read_text', return_value='MemTotal: 99999 kB\nMemAvailable: 12345 kB\n'):
            self.assertEqual(d.available_ram(self.ctx), 12345 * 1024)
        self.ctx.platform = 'win32'
        import ctypes
        def memory(pointer):
            self.assertEqual(pointer._obj.length, 64)
            pointer._obj.avail_phys = 123456
            return 1
        with patch.object(ctypes, 'windll', Mock(), create=True) as dll:
            dll.kernel32.GlobalMemoryStatusEx.side_effect = memory
            self.assertEqual(d.available_ram(self.ctx), 123456)

    def test_go_does_not_swallow_optional_decompiler_setup_failure(self):
        args = contrib.parser().parse_args(['go', '--decompiler'])
        failure = contrib.Stop(contrib.MISSING, 'no pinned decompiler runtime', component='decompiler')
        with patch.object(contrib, 'cmd_setup', side_effect=failure), \
                patch.object(contrib, 'cmd_claim') as claim:
            with self.assertRaises(contrib.Stop):
                contrib.cmd_go(self.ctx, args)
            claim.assert_not_called()

    def test_background_setup_is_idempotent(self):
        worker = Mock(pid=1234)
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'install'), patch.object(contrib, 'public_names', return_value={}), \
                patch.object(d.subprocess, 'Popen', return_value=worker) as start, \
                patch.object(d, 'process_alive', return_value=True):
            self.assertEqual(d.setup(self.ctx)['state'], 'starting')
            self.assertEqual(d.setup(self.ctx)['state'], 'starting')
            self.assertEqual(start.call_count, 1)
            self.assertTrue(contrib.load_config(self.ctx)['decompiler'])

    def test_interrupted_worker_and_completed_project(self):
        d.write_json(self.project / 'state.json', dict(state='running', pid=1234, started=0))
        with patch.object(d, 'process_alive', return_value=False):
            self.assertEqual(d.status(self.project)['state'], 'interrupted')
        d.write_json(self.project / 'state.json', dict(state='ready'))
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'install'), patch.object(d.subprocess, 'Popen') as start:
            self.assertEqual(d.setup(self.ctx)['state'], 'ready')
            start.assert_not_called()

    @unittest.skipIf(sys.platform == 'win32', 'the analysis runs through a junction made with mklink, which this test counts among the launched commands')
    def test_analysis_resumes_saved_import_and_requires_fresh_completion(self):
        imported = []
        def run(cmd, **kw):
            imported.append(cmd)
            (self.project / 'skyrim.gpr').write_text('synthetic project')
            return subprocess.CompletedProcess(cmd, 0)
        def analyze(cmd, **kw):
            (self.project / 'analyzed').write_text('synthetic checkpoint')
            return Mock(pid=1234, returncode=0, poll=Mock(side_effect=[None, None, 0]))
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'launch_command', side_effect=lambda ctx, alias, *args: (list(args), {})), \
                patch.object(d.subprocess, 'run', side_effect=run), \
                patch.object(d.subprocess, 'Popen', side_effect=analyze), \
                patch.object(d, 'process_tree_rss', side_effect=[1024, None, 1024, None]), \
                patch.object(d.time, 'sleep'):
            d.run_analysis(self.ctx, self.project)
            self.assertEqual(d.status(self.project)['state'], 'ready')
            self.assertEqual(d.status(self.project)['peak_rss_bytes'], 1024)
            self.assertEqual(len(imported), 1)
            self.assertIn('-noanalysis', imported[0])
            d.run_analysis(self.ctx, self.project)
            self.assertEqual(len(imported), 1)
        # A stale success marker cannot turn a later failed script into a ready project.
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'launch_command', return_value=(['synthetic'], {})), \
                patch.object(d.subprocess, 'Popen', return_value=Mock(pid=1234, returncode=0, poll=lambda: 0)):
            with self.assertRaisesRegex(ValueError, 'headless analysis failed'):
                d.run_analysis(self.ctx, self.project)
        self.assertEqual(d.status(self.project)['state'], 'failed')

    @unittest.skipIf(sys.platform == 'win32', 'the analysis runs through a junction made with mklink, and this test patches the process launcher that makes it')
    def test_oom_cannot_publish_ready_even_with_zero_exit_and_checkpoint(self):
        (self.project / 'imported').write_text('synthetic import')
        (self.project / 'skyrim.gpr').write_text('synthetic project')
        exhaust = [True, False]
        def analyze(cmd, **kw):
            (self.project / 'analyzed').write_text('synthetic checkpoint')
            kw['stdout'].write(b'Picked up JAVA_TOOL_OPTIONS: -XX:+ExitOnOutOfMemoryError\n')
            if exhaust.pop(0):
                kw['stdout'].write(b'java.lang.OutOfMemoryError: synthetic failure\n')
            return Mock(pid=1234, returncode=0, poll=lambda: 0)
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)), \
                patch.object(d, 'launch_command', return_value=(['synthetic'], {})), \
                patch.object(d.subprocess, 'Popen', side_effect=analyze):
            with self.assertRaisesRegex(ValueError, 'headless analysis failed'):
                d.run_analysis(self.ctx, self.project)
            self.assertEqual(d.status(self.project)['state'], 'failed')
            # A later successful pass must not inherit the earlier appended OOM diagnostic.
            d.run_analysis(self.ctx, self.project)
            self.assertEqual(d.status(self.project)['state'], 'ready')

    def test_private_pack_layout_and_per_function_export(self):
        d.write_json(self.project / 'state.json', dict(state='ready'))
        dest = self.ctx.private / 'packs/synthetic-build/0x1234'
        def run(cmd, **kw):
            folder = self.project / 'exports/1234/1234'
            folder.mkdir(parents=True)
            (folder / 'decomp.c').write_text('// ' + d.WARNING + '\nvoid Synthetic();\n// END PRIVATE DECOMPILER HINT\n')
            self.assertIn('-noanalysis', cmd)
            self.assertIn('-readOnly', cmd)
            self.assertEqual(kw['env']['GHIDRA_HEADLESS_MAXMEM'], '16G')
            return subprocess.CompletedProcess(cmd, 0)
        self.ctx.runner = run
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)):
            output = d.decompile(self.ctx, 0x1234, dest)
        self.assertEqual(output, dest / 'decomp.c')
        self.assertIn(d.WARNING, output.read_text())
        self.assertTrue(output.is_relative_to(self.ctx.private))

    def test_pending_analysis_does_not_block_ordinary_pack(self):
        with patch.object(d, 'identity', return_value=('synthetic.exe', self.project)):
            self.assertIsNone(d.decompile(self.ctx, 0x1234, self.root, required=False))
            with self.assertRaises(contrib.Stop):
                d.decompile(self.ctx, 0x1234, self.root)

    def test_write_pack_adds_optional_hint_beside_existing_listing(self):
        exe = self.root / 'synthetic.exe'
        exe.write_bytes(b'synthetic')
        contrib.save_config(self.ctx, decompiler=True)
        fn = dict(rva=0x1234, size=1, build_id='synthetic-build', name='Synthetic::Function')
        def export(ctx, rva, dest, **kw):
            (dest / 'decomp.c').write_text('// ' + d.WARNING)
        with patch.object(contrib, 'build_pack', return_value={}), \
                patch.object(contrib, 'pack_listing', return_value='synthetic listing'), \
                patch.object(contrib, 'find_objdump', return_value=None), \
                patch.object(d, 'decompile', side_effect=export) as decompile:
            dest, _ = contrib.write_pack(self.ctx, exe, fn, {})
        self.assertEqual(dest, self.ctx.private / 'packs/synthetic-build/0x1234')
        self.assertEqual({p.name for p in dest.iterdir()}, {'bytes.txt', 'pack.json', 'decomp.c'})
        decompile.assert_called_once_with(self.ctx, 0x1234, dest, required=False)

    def test_windows_batch_arguments_are_quoted_and_expansion_refused(self):
        command = d.windows_command(self.ctx, [r'C:\private & tools\analyzeHeadless.bat', 'project'])
        self.assertIn('private & tools', command)
        self.assertIn(' /d /s /c ""', command)
        for path in ['%TEMP%', 'a!b', 'a"b', 'a\n']:
            with self.assertRaises(contrib.Stop):
                d.windows_command(self.ctx, [path])

    def test_archive_traversal_is_rejected(self):
        archive = self.root / 'bad.zip'
        with zipfile.ZipFile(archive, 'w') as z:
            z.writestr('../escape', 'synthetic')
        with self.assertRaisesRegex(ValueError, 'unsafe archive path'):
            d.unpack(archive, self.root / 'unpack')
        self.assertFalse((self.root / 'escape').exists())

    def test_staged_commit_and_real_pr_diff_reject_private_paths(self):
        repo = self.root / 'repo'
        repo.mkdir()
        def git(*args):
            return subprocess.run(['git', '-c', 'user.name=Synthetic', '-c', 'user.email=test@example.invalid',
                                   *args], cwd=repo, check=True, capture_output=True)
        git('init', '-q')
        (repo / 'builds').mkdir()
        (repo / 'builds/target.json').write_bytes((ROOT / 'builds/target.json').read_bytes())
        git('add', 'builds/target.json')
        git('commit', '-qm', 'synthetic base')
        for name in ['decomp.c', 'project.rep/idata/0']:
            path = repo / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('synthetic fixture')
        git('add', 'decomp.c', 'project.rep/idata/0')
        with self.assertRaisesRegex(ValueError, 'private decompiler'):
            check.check_git(repo, staged=True)
        git('commit', '-qm', 'synthetic rejected input')
        ctx = contrib.Ctx(repo=repo, private=self.ctx.private, as_json=True)
        problems = contrib.intake_problems(ctx, 'HEAD~1', 'HEAD')
        self.assertTrue(any('decomp.c:1: outside contributor scope' in p for p in problems))
        self.assertTrue(any('project.rep' in p for p in problems))

    def test_commit_and_pr_reject_private_outputs(self):
        for name in ['decomp.c', 'exports/decompiled.c', 'project.gpr', 'project.rep/idata/0',
                     'renamed/PROJECT.REP/data', r'project.rep\data']:
            with self.subTest(name=name):
                with self.assertRaisesRegex(ValueError, 'private decompiler'):
                    check.inspect_payload(name, b'synthetic text')
                self.assertIn('private-decompiler-output', contrib_screen.screen(b'void f();', name))
                problems = contrib.intake_problems(self.ctx, 'HEAD', None, files=[('A', name)])
                self.assertTrue(problems)
        with self.assertRaisesRegex(ValueError, 'private decompiler'):
            check.inspect_payload('renamed.cpp', ('// ' + d.WARNING).encode())
        for body in [('// ' + d.WARNING).encode(), b'// private-project.gpr', b'// private-project.rep/data']:
            self.assertIn('private-decompiler-output',
                          contrib_screen.screen(body, 'reconstruction/synthetic/Synthetic.cpp'))


if __name__ == '__main__':
    unittest.main()
