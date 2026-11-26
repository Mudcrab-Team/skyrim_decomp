"""A unit is built, compared and confirmed with the compiler its recipe names (tools/verifier/toolsets.py).

Toy trees and a fake compiler only: no game bytes and no real toolchain.
"""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tools/verifier')]
import check
import ci_hash_check
import contrib
import ci_target_hash_check as cth
import host_agent
import pipeline
import runners
import toolsets

HAVOK_PIN = 'tools/verifier/pinned/19.00.23918.sha256'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def tree(default_cl='a' * 64, second_cl='b' * 64):
    """A minimal checkout: the default pin file, one second pin file and one recipe for each."""
    root = Path(tempfile.mkdtemp())
    (root / 'tools/verifier/pinned').mkdir(parents=True)
    (root / 'reconstruction/recipes').mkdir(parents=True)
    names = ('cl.exe', 'c1xx.dll', 'c2.dll', 'link.exe')
    (root / toolsets.PIN_DEFAULT).write_text(''.join(f'{default_cl if n == "cl.exe" else sha(n.encode())}  {n}\n' for n in names))
    (root / HAVOK_PIN).write_text(''.join(f'{second_cl if n == "cl.exe" else sha(b"u2" + n.encode())}  {n}\n' for n in names))
    for name, digest in (('default', default_cl), ('second', second_cl)):
        (root / f'reconstruction/recipes/{name}.json').write_text(json.dumps(
            {'compiler': {'binary_sha256': digest, 'version': '19'}, 'flags': ['/O2'], 'sdk': '10.0.19041.0'}))
    return root


class RecipeToolset(unittest.TestCase):
    def test_the_recipe_names_the_compiler_by_its_cl_hash(self):
        root = tree()
        self.assertEqual(toolsets.toolset_of_recipe(root, 'reconstruction/recipes/default.json'), toolsets.DEFAULT)
        self.assertEqual(toolsets.toolset_of_recipe(root, 'reconstruction/recipes/second.json'), '19.00.23918')
        self.assertEqual(toolsets.pins_for_recipe(root, 'reconstruction/recipes/second.json')[1], HAVOK_PIN)

    def test_an_unknown_compiler_is_refused_only_when_strict(self):
        root = tree()
        (root / 'reconstruction/recipes/odd.json').write_text(json.dumps({'compiler': {'binary_sha256': 'c' * 64}}))
        self.assertEqual(toolsets.toolset_of_recipe(root, 'reconstruction/recipes/odd.json'), toolsets.DEFAULT)
        with self.assertRaisesRegex(toolsets.ToolsetError, 'no toolchain pins'):
            toolsets.toolset_of_recipe(root, 'reconstruction/recipes/odd.json', strict=True)

    def test_every_committed_recipe_names_a_pinned_compiler(self):
        for path in sorted((ROOT / 'reconstruction/recipes').glob('*.json')):
            with self.subTest(path.name):
                toolsets.toolset_of_recipe(ROOT, path.relative_to(ROOT).as_posix(), strict=True)

    def test_the_havok_recipes_use_the_second_compiler_and_default_ones_do_not(self):
        for suffix in ('', '-reconstruction', '-root-includes'):
            for shape in ('noeh', 'fpfast', 'fpfast-noeh'):
                self.assertEqual(toolsets.toolset_of_recipe(
                    ROOT, f'reconstruction/recipes/msvc-19.00.23918-o2-{shape}{suffix}.json', strict=True), toolsets.HAVOK)
            self.assertEqual(toolsets.toolset_of_recipe(ROOT, f'reconstruction/recipes/msvc-19.00.23918-o2{suffix}.json',
                                                        strict=True), toolsets.HAVOK)
            self.assertEqual(toolsets.toolset_of_recipe(ROOT, f'reconstruction/recipes/msvc-19.16.27054-o2{suffix}.json',
                                                        strict=True), toolsets.DEFAULT)

    def test_each_second_recipe_is_its_default_twin_with_only_the_compiler_changed(self):
        for suffix in ('', '-reconstruction', '-root-includes'):
            old = json.loads((ROOT / f'reconstruction/recipes/msvc-19.16.27054-o2{suffix}.json').read_text())
            new = json.loads((ROOT / f'reconstruction/recipes/msvc-19.00.23918-o2{suffix}.json').read_text())
            self.assertEqual(old['flags'], new['flags'])
            self.assertEqual(old['sdk'], new['sdk'])

    def test_the_gate_accepts_exactly_the_registered_second_pin(self):
        self.assertEqual(check.SECOND_TOOLCHAIN_PINS, (toolsets.pin_path(toolsets.HAVOK),))
        cl = toolsets.known(ROOT)[toolsets.HAVOK]['cl.exe']
        self.assertEqual(check.toolchain_pin_for(ROOT, cl), HAVOK_PIN)
        self.assertEqual(check.recipe_toolchain_pin(ROOT, 'reconstruction/recipes/msvc-19.00.23918-o2.json'), HAVOK_PIN)
        self.assertEqual(check.recipe_toolchain_pin(ROOT, 'reconstruction/recipes/msvc-19.16.27054-o2.json'),
                         check.TOOLCHAIN_PIN)
        # The sweep's stand-in compilers have pin files but the gate does not accept them.
        stand_in = toolsets.known(ROOT)['19.00.24247']['cl.exe']
        self.assertIsNone(check.toolchain_pin_for(ROOT, stand_in))

    def test_the_agent_and_the_module_agree_on_the_default(self):
        self.assertEqual(host_agent.DEFAULT_TOOLSET, toolsets.DEFAULT)

    def test_toolchain_arguments_and_selection(self):
        self.assertEqual(toolsets.toolchain_args(['19.00.23918=/x/y']), {'19.00.23918': '/x/y'})
        with self.assertRaises(toolsets.ToolsetError):
            toolsets.toolchain_args(['nonsense'])
        self.assertEqual(toolsets.select_msvc('/d', {'19.00.23918': '/u'}, toolsets.DEFAULT), '/d')
        self.assertEqual(toolsets.select_msvc('/d', {'19.00.23918': '/u'}, '19.00.23918'), '/u')
        self.assertIsNone(toolsets.select_msvc('/d', {}, '19.00.23918'))


class Spec(unittest.TestCase):
    task = {'task_id': 'x', 'build_id': 'b', 'compiled': 'reconstruction/a/B.cpp', 'recipe': 'r',
            'symbols_repo': None, 'functions': [{'rva': 1, 'size': 1, 'symbol': 's'}]}

    def test_a_default_unit_spec_is_unchanged(self):
        spec = pipeline.unit_spec(self.task, {}, 'h')
        self.assertNotIn('toolset', spec)
        self.assertNotIn('pins', spec)

    def test_a_second_compiler_unit_spec_names_it_and_ships_its_pin_file(self):
        task = dict(self.task, toolset='19.00.23918')
        spec = pipeline.unit_spec(task, {}, 'h')
        self.assertEqual((spec['toolset'], spec['pins']), ('19.00.23918', HAVOK_PIN))

    def test_load_task_derives_the_toolset_from_the_unit_recipe_line(self):
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            (repo / 'builds').mkdir()
            (repo / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
            real = ROOT / 'tools/verifier'
            (repo / 'tools/verifier/pinned').mkdir(parents=True)
            for name in ('pinned.sha256', 'pinned/19.00.23918.sha256'):
                (repo / 'tools/verifier' / name).write_text((real / name).read_text())
            for name in ('o2', 'o2-reconstruction'):
                (repo / f'reconstruction/recipes').mkdir(parents=True, exist_ok=True)
                (repo / f'reconstruction/recipes/msvc-19.00.23918-{name}.json').write_text(
                    (ROOT / f'reconstruction/recipes/msvc-19.00.23918-{name}.json').read_text())
                (repo / f'reconstruction/recipes/msvc-19.16.27054-{name}.json').write_text(
                    (ROOT / f'reconstruction/recipes/msvc-19.16.27054-{name}.json').read_text())
            (repo / 'reconstruction/a').mkdir()
            (repo / 'reconstruction/a/B.cpp').write_text(
                '// Recipe: reconstruction/recipes/msvc-19.00.23918-o2-reconstruction.json\n')
            (repo / 'reconstruction/a/C.cpp').write_text('int c;\n')
            private = repo / '.local/tasks'
            for unit, expected in (('B', '19.00.23918'), ('C', toolsets.DEFAULT)):
                task_dir = private / unit.lower()
                task_dir.mkdir(parents=True)
                (task_dir / 'symbols.json').write_text('{}')
                (task_dir / 'task.json').write_text(json.dumps({
                    'build_id': 'b', 'compiled': f'reconstruction/a/{unit}.cpp',
                    'recipe': 'reconstruction/recipes/msvc-19.16.27054-o2.json',
                    'functions': [{'rva': 1, 'size': 1, 'symbol': 's'}]}))
                self.assertEqual(pipeline.load_task(task_dir, repo)['toolset'], expected)


class AgentRouting(unittest.TestCase):
    def make_run(self, root, toolset):
        """A one-unit batch archive whose spec asks for `toolset` (no unit_build is ever reached)."""
        run = root / 'u-0123456789ab'
        (root / 'stage/unit-one/repo/.unit').mkdir(parents=True)
        spec = {'toolset': toolset} if toolset else {}
        (root / 'stage/unit-one/repo/.unit/spec.json').write_text(json.dumps(spec))
        (root / 'stage/units.json').write_text('["unit-one"]')
        bundle = root / 'u-0123456789ab.tar'
        with tarfile.open(bundle, 'w') as tar:
            for path in sorted((root / 'stage').rglob('*')):
                tar.add(path, arcname=path.relative_to(root / 'stage').as_posix(), recursive=False)
        return run, bundle

    def test_a_host_without_the_compiler_refuses_the_unit_without_a_verdict(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            run, bundle = self.make_run(root, '19.00.23918')
            agent = ROOT / 'tools/verifier/host_agent.py'
            out = subprocess.run([sys.executable, '-I', str(agent), 'batch', '--run', str(run), '--bundle', str(bundle),
                                  '--msvc', str(root / 'msvc'), '--image', str(root / 'image'), '--loader', 'native',
                                  '--label', 'host-x', '--jobs', '1'], capture_output=True, text=True)
            self.assertEqual(out.returncode, 0, out.stderr)
            with tarfile.open(root / 'u-0123456789ab.out.tar') as tar:
                result = json.loads(tar.extractfile('unit-one.agent.json').read())
            self.assertEqual(result['exit'], host_agent.EXIT_TOOLCHAIN)
            self.assertIn('toolchain-missing', result['stdout'])

    def test_unit_msvc_picks_the_toolchain_the_spec_names(self):
        with tempfile.TemporaryDirectory() as tmp:
            spec = Path(tmp) / 'spec.json'
            args = mock.Mock(msvc='/default', toolchain=['19.00.23918=/second'])
            spec.write_text('{}')
            self.assertEqual(host_agent.unit_msvc(spec, args), '/default')
            spec.write_text('{"toolset": "19.16.27054"}')
            self.assertEqual(host_agent.unit_msvc(spec, args), '/default')
            spec.write_text('{"toolset": "19.00.23918"}')
            self.assertEqual(host_agent.unit_msvc(spec, args), '/second')
            self.assertIsNone(host_agent.unit_msvc(spec, mock.Mock(msvc='/default', toolchain=[])))


class RunnerConfig(unittest.TestCase):
    def config(self, **extra):
        return {'runners_schema': 1, 'attempt': 'mac', 'confirm': [], 'hosts': {'mac': dict(
            {'backend': 'local', 'host_id': 'mac-wine', 'machine': 'm-one', 'loader': 'native',
             'msvc': '/m/default', 'work': '/m/work'}, **extra)}}

    def test_toolchains_are_validated_and_resolved_like_the_other_paths(self):
        host = runners.validate(self.config(toolchains={'19.00.23918': '/m/second'}), root='/m')['hosts']['mac']
        self.assertEqual(host['toolchains'], {'19.00.23918': '/m/second'})
        self.assertEqual(runners.toolchain_args(host), ['--toolchain', '19.00.23918=/m/second'])
        self.assertTrue(runners.supports(host, '19.00.23918'))
        self.assertTrue(runners.supports(host, toolsets.DEFAULT))
        self.assertFalse(runners.supports(host, '19.00.24247'))

    def test_a_bad_toolchains_entry_is_refused(self):
        for bad in ({'not-an-id': '/x'}, {toolsets.DEFAULT: '/x'}, {'19.00.23918': ''}, ['19.00.23918']):
            with self.subTest(bad), self.assertRaises(runners.RunnerError):
                runners.validate(self.config(toolchains=bad), root='/m')

    def test_a_unit_goes_to_a_host_that_has_its_compiler_or_fails_early(self):
        cfg = runners.validate({'runners_schema': 1, 'attempt': 'one', 'confirm': [], 'hosts': {
            'one': {'backend': 'local', 'host_id': 'host-one', 'machine': 'm-one', 'loader': 'native',
                    'msvc': '/m/a', 'work': '/m/w1'},
            'two': {'backend': 'local', 'host_id': 'host-two', 'machine': 'm-two', 'loader': 'native',
                    'msvc': '/m/b', 'work': '/m/w2', 'toolchains': {'19.00.23918': '/m/second'}}}}, root='/m')
        one, two = cfg['hosts']['one'], cfg['hosts']['two']
        self.assertIs(runners.for_toolset(cfg, one, toolsets.DEFAULT), one)
        self.assertIs(runners.for_toolset(cfg, one, '19.00.23918'), two)
        with self.assertRaisesRegex(runners.RunnerError, 'no configured runner host has a toolchain for compiler 19.00.24247'):
            runners.for_toolset(cfg, one, '19.00.24247')

    def test_the_ci_host_decides_for_itself(self):
        self.assertTrue(runners.supports({'backend': 'ci-hash'}, '19.00.23918'))


class CiRouting(unittest.TestCase):
    def test_needed_toolsets_lists_only_what_the_recipes_call_for(self):
        root = tree()
        refs = [{'recipe': 'reconstruction/recipes/default.json'}, {'recipe': 'reconstruction/recipes/second.json'}]
        self.assertEqual(cth.needed_toolsets(root, refs), [toolsets.DEFAULT, '19.00.23918'])
        self.assertEqual(cth.needed_toolsets(root, refs[:1]), [toolsets.DEFAULT])
        self.assertEqual(cth.needed_toolsets(root, refs[:1], ['reconstruction/recipes/second.json']),
                         [toolsets.DEFAULT, '19.00.23918'])

    def test_a_lone_bin_directory_is_the_default_toolset(self):
        self.assertEqual(cth.as_bindirs(Path('/x')), {toolsets.DEFAULT: Path('/x')})
        self.assertEqual(cth.as_bindirs({'a': 1}), {'a': 1})

    def test_a_missing_second_compiler_is_an_error_not_a_verdict(self):
        manifest = {'functions': [], 'recipe_sha256': {'reconstruction/recipes/msvc-19.00.23918-o2.json': 'x'}}
        ref = dict(rva=None, unit='reconstruction/a/B.cpp', symbol=None,
                   recipe='reconstruction/recipes/msvc-19.00.23918-o2.json')
        with tempfile.TemporaryDirectory() as tmp, self.assertRaisesRegex(ValueError, 'toolchain unavailable'):
            cth.compile_requests(ROOT, Path(tmp), [ref], {toolsets.DEFAULT: Path('/nowhere')}, Path(tmp), manifest)

    def test_the_probe_measures_the_pins_of_the_toolset_it_is_given(self):
        with tempfile.TemporaryDirectory() as tmp:
            report = ci_hash_check.probe(ROOT, Path(tmp), '19.00.23918')
        self.assertEqual({f['name']: f['expected_sha256'] for f in report['files']},
                         toolsets.known(ROOT)['19.00.23918'])
        self.assertEqual(report['toolset'], 'MISMATCH')


class ContribRouting(unittest.TestCase):
    FILES = ('cl.exe', 'c1xx.dll', 'c2.dll', 'link.exe')

    def toolchain(self, root, content):
        bin_dir = root / 'VC/Tools/MSVC/toy/bin/Hostx64/x64'
        bin_dir.mkdir(parents=True)
        for name in self.FILES:
            (bin_dir / name).write_bytes(content)
        return root

    def test_a_recipe_naming_the_second_compiler_finds_it_beside_an_explicit_default_toolchain(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            default = self.toolchain(tmp / 'msvc-default', b'default')
            second = self.toolchain(tmp / 'msvc-second', b'second')
            repo = tmp / 'repo'
            (repo / 'tools/verifier/pinned').mkdir(parents=True)
            (repo / 'reconstruction/recipes').mkdir(parents=True)
            for path, content in ((repo / 'tools/verifier/pinned.sha256', b'default'),
                                  (repo / 'tools/verifier/pinned/19.00.23918.sha256', b'second')):
                path.write_text(''.join(f'{sha(content)}  {n}\n' for n in self.FILES))
            for name, content in (('a', b'default'), ('b', b'second')):
                (repo / f'reconstruction/recipes/{name}.json').write_text(json.dumps(
                    {'compiler': {'binary_sha256': sha(content), 'version': '19.00.23918 for x64' if name == 'b' else '19.16.27054'}}))
            ctx = contrib.Ctx(repo=repo, platform='win32', env={'SR_MSVC': str(default)})
            with mock.patch.object(contrib, 'toolchain_dirs', return_value=[default, second]):
                self.assertEqual(contrib.check_toolchain(ctx, repo, 'reconstruction/recipes/a.json')['root'], str(default))
                self.assertEqual(contrib.check_toolchain(ctx, repo, 'reconstruction/recipes/b.json')['root'], str(second))
                # No recipe: the explicit toolchain only, as before.
                self.assertEqual(contrib.check_toolchain(ctx, repo)['root'], str(default))

    def test_the_second_compiler_has_an_alias_and_a_licence_that_a_person_accepts(self):
        self.assertEqual(contrib.second_toolchain_id('havok'), '19.00.23918')
        self.assertEqual(contrib.second_toolchain_id('19.00.23918'), '19.00.23918')
        self.assertIsNone(contrib.second_toolchain_id('other'))
        info = contrib.SECOND_TOOLCHAINS['19.00.23918']
        self.assertTrue(info['licence'].startswith('https://visualstudio.microsoft.com/license-terms/'))
        ctx = contrib.Ctx(repo=ROOT, platform='linux', interactive=False, env={})
        with mock.patch.object(contrib, 'check_toolchain', return_value={'status': 'ok', 'root': '/x'}), \
                self.assertRaises(contrib.Stop) as caught:
            contrib.install_second_toolchain(ctx, '19.00.23918', accept=False)
        self.assertEqual(caught.exception.code, contrib.CONSENT)
        self.assertIn('--accept-vs2015-license', caught.exception.next_action)


class InstallerPins(unittest.TestCase):
    def test_the_package_table_covers_the_compiler_packages_and_nothing_else(self):
        import vs2015_u2
        table = json.loads((ROOT / 'tools/verifier/vs2015-u2-packages.json').read_text())
        self.assertEqual(table['toolset'], toolsets.HAVOK)
        self.assertTrue(table['image_url'].startswith('https://download.microsoft.com/'))
        paths = [row['path'] for row in table['packages']]
        self.assertEqual(len(paths), len(set(paths)))
        for row in table['packages']:
            self.assertRegex(row['sha256'], r'^[0-9a-f]{64}$')
            self.assertTrue(any(row['path'].startswith(d + '/') for d in vs2015_u2.PACKAGE_DIRS), row['path'])
        self.assertEqual(vs2015_u2.ISO_URL, table['image_url'])
        self.assertEqual(vs2015_u2.TOOLSET, toolsets.HAVOK)

    def test_the_four_binaries_are_pinned(self):
        self.assertEqual(sorted(toolsets.known(ROOT)[toolsets.HAVOK]), ['c1xx.dll', 'c2.dll', 'cl.exe', 'link.exe'])

    def test_an_empty_pin_file_would_not_pass_verification(self):
        import vs2015_u2
        with tempfile.TemporaryDirectory() as tmp, mock.patch.object(vs2015_u2, 'PINS', Path(tmp) / 'p.sha256'):
            (Path(tmp) / 'p.sha256').write_text('')
            with self.assertRaises(vs2015_u2.SetupError):
                vs2015_u2.verify_pins(Path(tmp))

    def test_a_package_that_differs_from_its_pin_is_refused(self):
        import vs2015_u2
        with tempfile.TemporaryDirectory() as tmp:
            iso = Path(tmp) / 'not-an-image.iso'
            iso.write_bytes(b'\0' * (40 * vs2015_u2.SECTOR))
            with self.assertRaisesRegex(vs2015_u2.SetupError, 'not an ISO 9660 image'):
                vs2015_u2.package_files(vs2015_u2.Source(str(iso)))

    def test_installing_requires_the_licence_flag(self):
        import vs2015_u2
        with tempfile.TemporaryDirectory() as tmp:
            self.assertEqual(vs2015_u2.main(['install', '--root', tmp, '--iso', str(Path(tmp) / 'x')]), 7)


if __name__ == '__main__':
    unittest.main()
