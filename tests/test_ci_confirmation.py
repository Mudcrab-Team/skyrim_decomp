"""Original synthetic fixtures exercise the CI exception without game inputs or network."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import subprocess
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tools/verifier'), str(ROOT/'tests')]
import check
import ci_confirmation as c
import ci_confirm_batch as batch
import runners
import ci_confirm as client
import synthetic_pecoff as fx
from test_match_gate import GateFixture, RECORD, PIN


class Content(unittest.TestCase):
    def test_eh_and_unwind_data_are_bound(self):
        blob=fx.coff_object()
        from pecoff import CoffObject
        obj=CoffObject(blob)
        for sec in obj.sections:
            if sec.name in ('.xdata','.pdata'):
                changed=bytearray(blob);changed[sec.raw_ptr] ^= 1
                self.assertNotEqual(c.content_digest(blob),c.content_digest(changed))

    def test_timestamp_is_excluded_but_code_and_reference_identity_are_bound(self):
        blob=fx.coff_object(); stamped=bytearray(blob);struct.pack_into('<I',stamped,4,123)
        self.assertEqual(c.content_digest(blob),c.content_digest(stamped))
        changed=fx.coff_object(code=fx.CODE[:-1]+bytes([0x90]))
        self.assertNotEqual(c.content_digest(blob),c.content_digest(changed))
        changed=fx.coff_object(relocs=((fx.RELOCS[0][0],fx.FUNCTION,fx.REL32),*fx.RELOCS[1:]))
        self.assertNotEqual(c.content_digest(blob),c.content_digest(changed))


class Evidence(GateFixture,unittest.TestCase):
    def setUp(self):
        super().setUp()
        self.record['runs']=self.record['runs'][:1]
        self.record['runs'][0].update(compiled_on='mac-wine',compared_on='mac-wine')
        self.record['build']['hosts']={'mac-wine':next(iter(self.record['build']['hosts'].values()))}
        self.write('tools/toolchain/v141-manifest.json','{}')
        self.row=dict(rva=self.fn['rva'],size=self.fn['size'],extraction='linked-reference-inference',
                      normalized_sha256='1'*64,layout_sha256='2'*64)
        pins={n:d for d,n in (s.split() for s in (self.root/PIN).read_text().splitlines())}
        obj=self.record['runs'][0]['report']['candidate']['object_sha256']
        self.record['ci_confirmation']=dict(schema=1,kind='ci-hash',host_id='github-windows-native',
            machine='github-hosted-windows',loader='native',os='windows',workflow=c.WORKFLOW,
            conclusion='success',run_id=123,run_attempt=1,base_sha='a'*40,candidate_sha='b'*40,
            tools_sha256='3'*64,toolchain_manifest_sha256=c.sha(b'{}'),cache_verified=True,toolset='MATCH',
            compiler_sha256=pins,target=self.row,build_id=self.target['build_id'],
            source_sha256=self.record['source']['digest'],unit=self.record['source']['compiled'],
            recipe_sha256=self.record['recipe']['sha256'],result='hash-match',deterministic=True,
            mac_content_sha256='4'*64,content_sha256='4'*64,object_sha256='5'*64,request_sha256='6'*64,
            normalized_sha256='1'*64,layout_sha256='2'*64,mac_object_sha256=obj)
        def git(*args):
            return subprocess.run(['git', *args], cwd=self.root, check=True, capture_output=True).stdout.decode().strip()
        self.git = git
        git('init', '-q'); git('config', 'user.email', 'test@example.invalid'); git('config', 'user.name', 'Test')
        for name in c.TOOLS:
            self.write(name, 'synthetic tool')
        git('add', '.'); git('commit', '-qm', 'fixture')
        self.record['ci_confirmation']['base_sha'] = git('rev-parse', 'HEAD')
        self.record['ci_confirmation']['tools_sha256'] = c.tools_digest(self.root)
        self.p2=patch.object(c.target_hashes,'load_manifest',return_value={'functions':[self.row]});self.p2.start();self.addCleanup(self.p2.stop)
        self.save_record()

    def test_local_full_pass_and_bound_ci_evidence_are_accepted(self):
        check.validate_match(self.fn,self.target,root=self.root)

    def test_revision_bound_tools(self):
        base = self.record['ci_confirmation']['base_sha']
        self.write(c.TOOLS[0], 'changed tool')
        self.git('add', c.TOOLS[0]); self.git('commit', '-qm', 'change tool')
        c.validate(self.root, self.record, self.fn, self.target)
        self.record['ci_confirmation']['tools_sha256'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'stale CI tools'):
            c.validate(self.root, self.record, self.fn, self.target)
        self.record['ci_confirmation']['base_sha'] = 'f' * 40
        with self.assertRaisesRegex(ValueError, 'CI tools revision unavailable'):
            c.validate(self.root, self.record, self.fn, self.target)
        self.git('checkout', '-q', '--detach', base)
        self.write(c.TOOLS[0], 'other tool')
        self.git('add', c.TOOLS[0]); self.git('commit', '-qm', 'other branch')
        other = self.git('rev-parse', 'HEAD')
        self.git('checkout', '-q', '--detach', base)
        self.record['ci_confirmation']['base_sha'] = other
        with self.assertRaisesRegex(ValueError, 'not an ancestor'):
            c.validate(self.root, self.record, self.fn, self.target)

    def native_first(self):
        host = 'winpc-native'
        self.record['runs'][0].update(compiled_on=host, compared_on=host)
        self.record['build']['hosts'] = {host: next(iter(self.record['build']['hosts'].values()))}
        ci = self.record['ci_confirmation']
        ci['first_host'] = dict(host_id=host, machine='synthetic-pc', loader='native', os='windows')
        for field in ('object_sha256', 'content_sha256'):
            ci['first_' + field] = ci.pop('mac_' + field)
        self.save_record()

    def test_native_first_host_and_ci_on_distinct_machines_pass(self):
        self.native_first()
        check.validate_match(self.fn, self.target, root=self.root)

    def test_native_first_host_identity_reuse_and_content_tampering_fail(self):
        self.native_first()
        original = copy.deepcopy(self.record)
        for field, value in [('host_id', 'github-windows-native'), ('machine', 'github-hosted-windows'),
                             ('host_id', 'unbound-host'), ('os', 'linux')]:
            with self.subTest(field=field, value=value):
                self.record = copy.deepcopy(original)
                self.record['ci_confirmation']['first_host'][field] = value
                self.save_record()
                with self.assertRaises(ValueError):
                    check.validate_match(self.fn, self.target, root=self.root)
        self.record = original
        self.record['ci_confirmation']['first_content_sha256'] = '0' * 64
        self.save_record()
        with self.assertRaisesRegex(ValueError, 'content differs'):
            check.validate_match(self.fn, self.target, root=self.root)

    def test_every_binding_fails_closed(self):
        original=copy.deepcopy(self.record)
        for key,value in list(original['ci_confirmation'].items()):
            with self.subTest(key=key):
                self.record=copy.deepcopy(original)
                self.record['ci_confirmation'][key]=None
                self.save_record()
                with self.assertRaises((ValueError,TypeError,KeyError)):
                    check.validate_match(self.fn,self.target,root=self.root)
        self.record=copy.deepcopy(original)
        del self.record['ci_confirmation'];self.save_record()
        with self.assertRaises(ValueError):check.validate_match(self.fn,self.target,root=self.root)

    def test_full_local_comparison_remains_mandatory(self):
        self.record['runs'][0]['report']['result']='fail';self.save_record()
        with self.assertRaisesRegex(ValueError,'not pass'):check.validate_match(self.fn,self.target,root=self.root)

    def test_no_target_and_object_reuse_are_refused(self):
        with patch.object(c.target_hashes,'load_manifest',return_value={'functions':[]}):
            with self.assertRaisesRegex(ValueError,'no supported'):check.validate_match(self.fn,self.target,root=self.root)
        self.record['ci_confirmation']['object_sha256']=self.record['ci_confirmation']['mac_object_sha256'];self.save_record()
        with self.assertRaisesRegex(ValueError,'object reused'):check.validate_match(self.fn,self.target,root=self.root)


class Prepare(unittest.TestCase):
    def test_real_source_intake_has_trusted_recipe_and_evidence_before_lint(self):
        from test_lint_reconstruction import HEADER, SOURCE, BUILD
        from source_digest import include_closure
        from digest_v2 import tu_digest
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp)/'repo';root.mkdir()
            def git(*args):
                return subprocess.run(['git',*args],cwd=root,check=True,capture_output=True).stdout.decode().strip()
            git('init','-q');git('config','user.email','test@example.invalid');git('config','user.name','Test')
            for name,data in {'builds/target.json':json.dumps(dict(build_id=BUILD)),
                'findings/TEMPLATE.md':'Original synthetic evidence.\n',
                'reconstruction/recipes/r.json':'{}',
                'reconstruction/misc/Widget.cpp':SOURCE.replace('#include','// Evidence: findings/TEMPLATE.md\n#include',1),'reconstruction/misc/Widget.h':HEADER}.items():
                p=root/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_text(data, newline="\n")
            git('add','.');git('commit','-qm','original synthetic fixture');base=git('rev-parse','HEAD')
            closure=include_closure(root,'reconstruction/misc/Widget.cpp')
            unit=dict(task_id='test-unit',unit='reconstruction/misc/Widget.cpp',closure=closure,
                recipe='reconstruction/recipes/r.json',recipe_sha256=c.sha(b'{}'),
                source_sha256=tu_digest(root,closure),functions=[dict(rva=4096,size=8,symbol='test')])
            request=dict(schema=1,base_sha=base,files={n:c.sha((root/n).read_bytes()) for n in closure},units=[unit])
            raw=json.dumps(request).encode();name='data/ci-confirm/test.json';p=root/name;p.parent.mkdir(parents=True);p.write_bytes(raw)
            git('add',name);git('commit','-qm','source-only batch');head=git('rev-parse','HEAD');git('checkout','-q',base)
            with patch.object(batch,'ROOT',root),patch.object(batch.target_hashes,'load_manifest',return_value={'recipe_sha256':{'reconstruction/recipes/r.json':c.sha(b'{}')}}):
                got,tree=batch.prepare(head,name,c.sha(raw),Path(tmp)/'work')
                self.assertEqual(got,request)
                self.assertTrue((tree/'findings/TEMPLATE.md').is_file())
                self.assertTrue((tree/unit['recipe']).is_file())
                with self.assertRaisesRegex(ValueError,'request digest'):
                    batch.prepare(head,name,'0'*64,Path(tmp)/'other')


class BatchBuild(unittest.TestCase):
    def test_two_clean_compiles_and_full_content_target_checks(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);blob=fx.coff_object()
            from pecoff import CoffObject
            import compare,target_hashes
            _,section=compare.find_function(CoffObject(blob),fx.FUNCTION)
            target=dict(rva=0x1010,size=len(fx.CODE),extraction='linked-reference-inference',**target_hashes.section_hash(section))
            unit=dict(task_id='test',unit='reconstruction/test/Test.cpp',recipe='reconstruction/recipes/test.json',
                source_sha256='a'*64,recipe_sha256='b'*64,mac_content_sha256=c.content_digest(blob),mac_object_sha256='c'*64,
                functions=[dict(rva=0x1010,size=len(fx.CODE),symbol=fx.FUNCTION)])
            request=dict(units=[unit])
            def compile_(ctx,tree,compiled,recipe,out,tool):
                out.mkdir(parents=True);p=out/'candidate.obj';p.write_bytes(blob);return dict(object=p)
            bindir=root/'a/b/c/d/e/f/g'
            with patch.object(batch.target_hashes,'load_manifest',return_value={'functions':[target]}),patch.object(batch.contrib,'compile_unit',side_effect=compile_) as build:
                rows=batch.compile_batch(request,root,bindir,root/'objects')
                self.assertTrue(rows[0]['deterministic']);self.assertEqual(build.call_count,2)
                wrong=copy.deepcopy(request);wrong['units'][0]['mac_content_sha256']='0'*64
                with self.assertRaisesRegex(ValueError,'content mismatch'):
                    batch.compile_batch(wrong,root,bindir,root/'wrong')
                bad=dict(target,layout_sha256='0'*64)
                with patch.object(batch.target_hashes,'load_manifest',return_value={'functions':[bad]}):
                    with self.assertRaisesRegex(ValueError,'layout mismatch'):
                        batch.compile_batch(request,root,bindir,root/'layout')

    def test_private_identity_is_rejected_before_any_git_or_push(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);name='reconstruction/test/Test.cpp'
            p=root/name;p.parent.mkdir(parents=True);p.write_text('// forbidden-private-identity\n')
            request=dict(base_sha='a'*40,files={name:c.sha(p.read_bytes())},units=[])
            with patch.object(client.check,'anonymity_terms',return_value=('forbidden-private-identity',)),patch.object(client,'command') as command:
                with self.assertRaisesRegex(ValueError,'forbidden private identity'):
                    client.submit(root,request,root,lambda m:None)
                command.assert_not_called()

    def test_artifact_candidate_binding_is_checked_before_use(self):
        submission=dict(request_sha256='a'*64,base_sha='b'*40,candidate_sha='c'*40)
        run=dict(display_title='confirm-'+submission['request_sha256'],head_sha=submission['base_sha'],
                 run_attempt=1,id=123,status='completed',conclusion='success')
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);(root/'artifact').mkdir()
            (root/'artifact/result.json').write_text(json.dumps(dict(run_id=123,conclusion='success',
                request_sha256=submission['request_sha256'],base_sha=submission['base_sha'],candidate_sha='d'*40)))
            with patch.object(client,'gh',return_value={'workflow_runs':[run]}),patch.object(client,'command'):
                with self.assertRaisesRegex(ValueError,'artifact/run binding'):
                    client.collect(root,submission,root,lambda m:None)


class Config(unittest.TestCase):
    def test_ci_host_is_confirm_only_and_does_not_need_game_image(self):
        mac=dict(backend='local',host_id='mac-wine',machine='maintainer-mac',loader='wine',
                 msvc='msvc',work='work',wine_bin='wine',image='private-image')
        ci=dict(backend='ci-hash',host_id='github-windows-native',machine='github-hosted-windows',
                loader='native',repository='awarebayes/skyrim_decomp')
        raw=dict(runners_schema=1,hosts=dict(mac=mac,ci=ci),attempt='mac',confirm=['mac','ci'])
        hosts=runners.for_confirm(runners.validate(raw))
        self.assertEqual([h['backend'] for h in hosts],['local','ci-hash'])
        pc = dict(mac, backend='ssh', host_id='winpc-native', machine='synthetic-pc',
                  loader='native', ssh_host='synthetic', ssh_config='synthetic', python=['python'])
        raw['hosts']['pc'] = pc
        raw['attempt'] = 'pc'; raw['confirm'] = ['pc', 'ci']
        self.assertEqual([h['host_id'] for h in runners.for_confirm(runners.validate(raw))],
                         ['winpc-native', 'github-windows-native'])
        raw['hosts']['pc']['machine'] = 'github-hosted-windows'
        with self.assertRaisesRegex(runners.RunnerError, 'one machine'):
            runners.for_confirm(runners.validate(raw))
        raw['attempt']='ci'
        with self.assertRaisesRegex(runners.RunnerError,'confirmation host only'):runners.validate(raw)


if __name__=='__main__':unittest.main()
