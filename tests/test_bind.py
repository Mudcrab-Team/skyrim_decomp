"""tools/verifier/bind.py on the original synthetic object and image (no game data, no demangler needed)."""
import hashlib
import json
from pathlib import Path
import sys
import os
import shutil
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import bind  # noqa: E402
from compare import compare  # noqa: E402
import synthetic_pecoff as fx  # noqa: E402


class BindTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()
        (self.root / 'obj').write_bytes(fx.coff_object())
        (self.root / 'image').write_bytes(fx.pe_image())
        pack = self.root / 'packs' / 'p'
        pack.mkdir(parents=True)
        # The pack lists the targets the analysis saw; names differ from the stand-ins on purpose.
        refs = [{'target_rva': fx.LAYOUT[fx.CALLEE], 'community_names': [{'name': 'RE::Other::AddOne', 'kind': 'func'}]},
                {'target_rva': fx.LAYOUT[fx.BASE], 'community_names': []}]
        (pack / 'pack.json').write_text(json.dumps({'references': refs}))
        self.write_task('unbound:Synthetic::SyntheticSum', {})

    def tearDown(self):
        self.tmp.cleanup()

    def write_task(self, symbol, symbols, hints=None):
        task = {'symbols': 'symbols.json', 'functions': [
            {'rva': hex(fx.LAYOUT[fx.FUNCTION]), 'size': len(fx.CODE), 'symbol': symbol,
             'community_name': 'Synthetic::SyntheticSum', 'pack': 'packs/p'}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        (self.task_dir / 'symbols.json').write_text(json.dumps({'schema': 1, 'symbols': symbols}))
        if hints is not None:
            (self.task_dir / bind.HINTS).write_text(json.dumps(hints))

    def test_list_preflight_checks_references_before_publication(self):
        self.write_task('Function', {'Reference': {'rva': 8192}})
        other = self.root / 'other'
        other.mkdir()
        (other / 'task.json').write_text(json.dumps({
            'functions': [{'symbol': 'OtherSignature', 'rva': hex(fx.LAYOUT[fx.FUNCTION])}]}))
        before = (self.task_dir / 'symbols.json').read_bytes()
        with self.assertRaisesRegex(ValueError, 'conflicting symbol declarations'):
            bind.preflight([self.task_dir, other], repo=self.root)
        self.assertEqual(before, (self.task_dir / 'symbols.json').read_bytes())
        bind.preflight([self.task_dir, self.task_dir], repo=self.root)

    def test_preflight_allows_reference_aliases_but_not_two_targets(self):
        self.write_task('Function', {'Reference': {'rva': 8192}})
        other = self.root / 'other'
        other.mkdir()
        (other / 'task.json').write_text(json.dumps({
            'functions': [{'symbol': 'OtherFunction', 'rva': '0x3000'}]}))
        (other / 'symbols.json').write_text(json.dumps({
            'symbols': {'OtherReference': {'rva': 8192}}}))
        bind.preflight([self.task_dir, other], repo=self.root)
        (other / 'symbols.json').write_text(json.dumps({
            'symbols': {'OtherFunction': {'rva': 8193}}}))
        with self.assertRaisesRegex(ValueError, 'two RVAs'):
            bind.preflight([self.task_dir, other], repo=self.root)

    def test_unit_maps_publish_independent_reference_names(self):
        self.write_task(fx.FUNCTION, {fx.FUNCTION: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)},
                                     fx.CALLEE: {'rva': fx.LAYOUT[fx.CALLEE], 'size': None}})
        task = json.loads((self.task_dir / 'task.json').read_text())
        task.update(build_id='synthetic-fixture')
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        attempt = self.task_dir / 'attempts/001'
        attempt.mkdir(parents=True)
        (attempt / 'candidate.obj').write_bytes(fx.coff_object())
        bind.unit_map(self.task_dir, repo=self.root)
        first = json.loads((self.task_dir / 'task.json').read_text())['symbols']
        first_bytes = (self.root / first).read_bytes()
        private = json.loads((self.task_dir / 'symbols.json').read_text())
        private['symbols'][fx.CALLEE]['rva'] += 16
        (self.task_dir / 'symbols.json').write_text(json.dumps(private))
        bind.unit_map(self.task_dir, repo=self.root)
        second = json.loads((self.task_dir / 'task.json').read_text())['symbols']
        self.assertNotEqual(first, second)
        self.assertEqual((self.root / first).read_bytes(), first_bytes)
        bind.symbol_maps.load_state(self.root, first)
        bind.symbol_maps.load_state(self.root, second)

    def test_two_units_publish_different_names_for_one_reference(self):
        from types import SimpleNamespace
        from unittest.mock import patch
        directories = []
        for index, reference in enumerate(['ReferenceA', 'ReferenceB']):
            directory = self.root / f'unit{index}'
            attempt = directory / 'attempts/001'
            attempt.mkdir(parents=True)
            (attempt / 'candidate.obj').write_bytes(b'synthetic placeholder')
            function = f'Function{index}'
            (directory / 'task.json').write_text(json.dumps({
                'build_id': 'synthetic-fixture', 'functions': [
                    {'symbol': function, 'rva': hex(4096 + index * 16), 'size': 5}]}))
            (directory / 'symbols.json').write_text(json.dumps({
                'symbols': {reference: {'rva': 8192, 'size': None}}}))
            obj = SimpleNamespace(symbols={0: SimpleNamespace(name=reference)})
            with patch.object(bind, 'CoffObject', return_value=obj):
                bind.unit_map(directory, repo=self.root)
            task = json.loads((directory / 'task.json').read_text())
            state = bind.symbol_maps.load_state(self.root, task['symbols'])
            self.assertEqual(state.current['symbols'][reference]['rva'], 8192)
            directories.append(directory)
        with patch.object(bind, 'CoffObject', return_value=SimpleNamespace(symbols={})):
            bind.preflight(directories, repo=self.root)

    def run_bind(self):
        report = bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        return report, json.loads((self.task_dir / 'symbols.json').read_text())['symbols']

    def test_function_by_member_name_and_references_by_position(self):
        report, symbols = self.run_bind()
        self.assertEqual(report['functions'][0]['how'], 'member name')
        self.assertEqual(symbols[fx.FUNCTION], {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)})
        self.assertEqual(symbols[fx.CALLEE]['rva'], fx.LAYOUT[fx.CALLEE])
        self.assertEqual(symbols[fx.BASE]['rva'], fx.LAYOUT[fx.BASE])
        # Not listed in the pack, so position alone does not bind it.
        self.assertEqual(report['unbound_references'], [fx.COUNTER])
        text = '\n'.join(bind.describe(report, self.task_dir))
        self.assertIn(f'UNBOUND reference {fx.COUNTER}', text)
        self.assertIn(bind.HINTS, text)

    def test_permuter_binds_private_header_hints_in_its_scratch_task(self):
        import permute

        private = self.root / 'private'
        private.mkdir()
        raw = json.loads((self.task_dir / 'task.json').read_text())
        raw['compiled'] = 'unit.cpp'
        original = json.dumps(raw)
        (self.task_dir / 'task.json').write_text(original)
        address = fx.LAYOUT[fx.FUNCTION]
        (private / 'unit.cpp').write_text(f'// CI hash: {hex(address)} {fx.FUNCTION}\n')
        task = {'dir': self.task_dir, 'symbols_local': self.task_dir / 'symbols.json'}
        transport = SimpleNamespace(join=lambda *parts: Path(*parts), get=lambda _, out: shutil.copyfile(self.root / 'obj', out))
        host = SimpleNamespace(transport=transport, _remote=lambda run: run, _run=self.root)
        out = self.root / 'out'
        out.mkdir()
        _, _, bound, lines = permute.bound_scoring_maps(task, host, out, self.root / 'image', None, address, private)
        self.assertEqual(bound[address], fx.FUNCTION)
        self.assertTrue(any('hint' in line and fx.FUNCTION in line for line in lines), lines)
        self.assertEqual((self.task_dir / 'task.json').read_text(), original)

    def test_reference_stored_with_a_member_offset_binds_the_symbol_itself(self):
        # A store to a member of a global puts the member offset in the object's field; the image
        # encodes symbol plus offset, and the comparator adds the offset back to the bound RVA.
        code = bytearray(fx.CODE)
        code[0x0D:0x11] = (8).to_bytes(4, 'little')
        (self.root / 'obj').write_bytes(fx.coff_object(code=bytes(code)))
        (self.root / 'image').write_bytes(fx.pe_image(code=bytes(code), link_addresses={fx.BASE: fx.LAYOUT[fx.BASE] + 8}))
        report, symbols = self.run_bind()
        self.assertEqual(symbols[fx.BASE]['rva'], fx.LAYOUT[fx.BASE])
        self.assertEqual({r['symbol']: r['how'] for r in report['references']}[fx.BASE], 'position')

    def test_hint_binds_unlisted_reference(self):
        self.write_task('unbound:x', {}, hints={fx.COUNTER: hex(fx.LAYOUT[fx.COUNTER])})
        report, symbols = self.run_bind()
        self.assertEqual(report['unbound_references'], [])
        self.assertEqual(symbols[fx.COUNTER]['rva'], fx.LAYOUT[fx.COUNTER])

    def test_hint_replaces_a_stale_reference_entry(self):
        # A misaligned earlier attempt can leave another listed target in the map.
        self.write_task('unbound:x', {fx.COUNTER: {'rva': fx.LAYOUT[fx.BASE], 'size': None}},
                        hints={fx.COUNTER: hex(fx.LAYOUT[fx.COUNTER])})
        report, symbols = self.run_bind()
        self.assertEqual(symbols[fx.COUNTER]['rva'], fx.LAYOUT[fx.COUNTER])
        how = {r['symbol']: r['how'] for r in report['references']}[fx.COUNTER]
        self.assertEqual(how, f'hint, replaced {hex(fx.LAYOUT[fx.BASE])}')

    def test_renamed_function_is_reported_and_old_entry_dropped(self):
        old = '?SyntheticSum@Synthetic@@QEAAHXZ'
        self.write_task(old, {old: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)}})
        report, symbols = self.run_bind()
        self.assertEqual(report['renamed'], [{'rva': hex(fx.LAYOUT[fx.FUNCTION]), 'old': old, 'new': fx.FUNCTION}])
        self.assertNotIn(old, symbols)
        self.assertIn('decorated name changed', '\n'.join(bind.describe(report, self.task_dir)))

    def test_old_decoration_from_an_accepted_record_is_dropped_when_the_function_is_rebound(self):
        old = '?SyntheticSum@Synthetic@@QEAAHXZ'
        self.write_task('unbound:x', {old: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)}})
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['export'] = {'unit_already_records': [{'rva': hex(fx.LAYOUT[fx.FUNCTION]), 'symbol': old}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        report, symbols = self.run_bind()
        self.assertNotIn(old, symbols)
        self.assertEqual(symbols[fx.FUNCTION]['rva'], fx.LAYOUT[fx.FUNCTION])
        self.assertEqual(report['renamed'], [{'rva': hex(fx.LAYOUT[fx.FUNCTION]), 'old': old, 'new': fx.FUNCTION}])

    def test_a_stale_name_at_the_function_rva_is_dropped_from_a_private_map(self):
        # A private copy of the public map still holds the decoration the community gave this RVA.
        stale = '?SetupSomething@Synthetic@@QEAAHXZ'
        self.write_task('unbound:x', {stale: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': None}})
        report, symbols = self.run_bind()
        self.assertNotIn(stale, symbols)
        self.assertEqual(symbols[fx.FUNCTION]['rva'], fx.LAYOUT[fx.FUNCTION])
        self.assertIn({'rva': hex(fx.LAYOUT[fx.FUNCTION]), 'old': stale, 'new': fx.FUNCTION}, report['renamed'])

    def test_a_name_the_object_refers_to_is_kept_at_the_function_rva(self):
        # The unit calls the function through another declaration of it: the entry resolves that call.
        self.write_task('unbound:x', {fx.COUNTER: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': None}})
        _report, symbols = self.run_bind()
        self.assertIn(fx.COUNTER, symbols)

    def test_function_hint_by_rva(self):
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['functions'][0]['community_name'] = 'Unrelated::Name'
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        report, _ = self.run_bind()
        self.assertEqual(report['functions'], [])
        self.assertIn(fx.FUNCTION, report['unbound_functions'][0]['defined_in_object'])
        (self.task_dir / bind.HINTS).write_text(json.dumps({fx.FUNCTION: hex(fx.LAYOUT[fx.FUNCTION])}))
        report, _ = self.run_bind()
        self.assertEqual(report['functions'][0]['how'], 'hint')

    def test_misaligned_position_does_not_bind_an_unknown_address(self):
        (self.root / 'image').write_bytes(fx.pe_image(link_addresses={fx.CALLEE: 0x1008}))
        report, symbols = self.run_bind()
        # 0x1008 is not a listed reference, so the call falls back to the name rule and stays unbound.
        self.assertIn(fx.CALLEE, report['unbound_references'])

    def test_qualified_names(self):
        self.assertEqual(bind.qualified('public: static struct H<class A> __cdecl M<class A, struct B>::Get(class A *)'),
                         'M::Get')
        self.assertEqual(bind.qualified('public: static float BSTimer::Q'), 'BSTimer::Q')
        self.assertEqual(bind.fallback_qualified('?Visit@Base@@UEAAIPEAX@Z'), 'Base::Visit')
        self.assertEqual(bind.community_qualified('RE::BSPointerHandleManagerInterface<Actor>::GetHandle'),
                         'BSPointerHandleManagerInterface::GetHandle')


# Listings in the pack format, written by hand for these tests (no tool or game output).
SCALAR_LISTING = """Function FUN_1 at rva 0x1000
  +0x000  PUSH RBX
  +0x002  SUB RSP,0x20
  +0x006  MOV EBX,EDX                                     
  +0x008  CALL 0x140002000                                 [UNCONDITIONAL_CALL 0x2000 FUN_2]
  +0x00d  TEST BL,0x1
  +0x010  JZ 0x14000101c
  +0x012  MOV EDX,0x18
  +0x017  CALL 0x140003000                                 [UNCONDITIONAL_CALL 0x3000 FUN_3]
  +0x01c  RET
"""
VECTOR_LISTING = """  +0x000  TEST DL,0x2
  +0x003  JZ 0x140001010
  +0x005  CALL 0x140003000
  +0x00a  RET
"""
CLOBBERED_LISTING = """  +0x000  MOV EDX,0x8
  +0x005  TEST DL,0x1
  +0x008  RET
"""
CALL_CLOBBERS_LISTING = """  +0x000  CALL 0x140002000
  +0x005  TEST DL,0x1
  +0x008  JZ 0x140001010
  +0x00a  CALL 0x140003000
"""
PLAIN = '??1Synth@@UEAA@XZ'
SCALAR = '??_GSynth@@UEAAPEAXI@Z'
VECTOR = '??_ESynth@@UEAAPEAXI@Z'
THUNK = '??_ESynth@@WBA@EAAPEAXI@Z'


class DestructorTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()

    def tearDown(self):
        self.tmp.cleanup()

    def setup_task(self, defined, listing=SCALAR_LISTING, name_how='slot 0', symbol='unbound:Synth::~Synth',
                   size=29, hints=None):
        unit = fx.Unit()
        for name, length in defined.items():
            sec = unit.section('.text$mn', b'\xc3' * length, fx.SCN_CODE)
            unit.define(name, sec, storage=fx.STORAGE_EXTERNAL, function=True)
        (self.root / 'obj').write_bytes(unit.coff())
        pack = self.root / 'packs' / 'd'
        pack.mkdir(parents=True, exist_ok=True)
        (pack / 'pack.json').write_text(json.dumps({'identity': {'name_how': name_how}, 'references': []}))
        if listing is not None:
            (pack / 'listing.txt').write_text(listing)
        task = {'symbols': 'symbols.json', 'functions': [
            {'rva': '0x1000', 'size': size, 'symbol': symbol, 'community_name': 'RE::Synth::~Synth', 'pack': 'packs/d'}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        smap = {symbol: {'rva': 0x1000, 'size': size}} if not symbol.startswith('unbound:') else {}
        (self.task_dir / 'symbols.json').write_text(json.dumps({'schema': 1, 'symbols': smap}))
        if hints is not None:
            (self.task_dir / bind.HINTS).write_text(json.dumps(hints))

    def run_bind(self):
        report = bind.bind(self.task_dir, self.root / 'obj', None, repo=self.root)
        task = json.loads((self.task_dir / 'task.json').read_text())
        return report, task['functions'][0]

    def test_spec_from_listing(self):
        spec = bind.destructor_spec('Synth::~Synth', 'slot 0', SCALAR_LISTING)
        self.assertEqual((spec['symbols'], spec['decided']), (['??_G'], True))
        self.assertEqual(bind.destructor_spec('Synth::~Synth', 'slot 0', VECTOR_LISTING)['symbols'], ['??_E'])
        # The flag register overwritten, or clobbered by a call, is no flag test.
        self.assertEqual(bind.destructor_spec('Synth::~Synth', 'name', CLOBBERED_LISTING)['symbols'], ['??1'])
        self.assertEqual(bind.destructor_spec('Synth::~Synth', 'name', CALL_CLOBBERS_LISTING)['symbols'], ['??1'])
        undecided = bind.destructor_spec('Synth::~Synth', 'slot 0', None)
        self.assertEqual((sorted(undecided['symbols']), undecided['decided']), (['??1', '??_E', '??_G'], False))
        self.assertIsNone(bind.destructor_spec('Synth::Update', 'slot 3', SCALAR_LISTING))
        self.assertIsNone(bind.destructor_spec('Synth::Dtor', 'table', SCALAR_LISTING))

    def test_decoration(self):
        self.assertEqual(bind.dtor_decoration(SCALAR), ('??_G', 'Synth'))
        self.assertEqual(bind.dtor_decoration('??_GInner@Outer@@UEAAPEAXI@Z'), ('??_G', 'Outer::Inner'))
        self.assertIsNone(bind.dtor_decoration(THUNK))
        self.assertIsNone(bind.dtor_decoration('?Update@Synth@@UEAAXXZ'))

    def test_plain_destructor_rebound_to_scalar_deleting(self):
        self.setup_task({PLAIN: 12, SCALAR: 29, THUNK: 9}, symbol=PLAIN)
        report, fn = self.run_bind()
        self.assertEqual(fn['symbol'], SCALAR)
        self.assertEqual(fn['destructor']['symbols'], ['??_G'])
        self.assertEqual(report['renamed'], [{'rva': '0x1000', 'old': PLAIN, 'new': SCALAR}])
        symbols = json.loads((self.task_dir / 'symbols.json').read_text())['symbols']
        self.assertNotIn(PLAIN, symbols)

    def test_unbound_names_the_expected_kind(self):
        self.setup_task({PLAIN: 12})
        report, fn = self.run_bind()
        self.assertEqual(report['functions'], [])
        self.assertEqual(report['unbound_functions'][0]['expected']['symbols'], ['??_G'])
        text = '\n'.join(bind.describe(report, self.task_dir))
        self.assertIn('scalar deleting destructor', text)
        self.assertIn('constructor', text)

    def test_delivers_the_required_destructor_kind_for_the_declared_class(self):
        declared_plain = '??1LocalBox@@UEAA@XZ'
        declared_scalar = '??_GLocalBox@@UEAAPEAXI@Z'
        self.setup_task({declared_plain: 29, declared_scalar: 29})
        path = self.task_dir / 'task.json'
        task = json.loads(path.read_text())
        task['compiled'] = 'Test.cpp'
        path.write_text(json.dumps(task))
        (self.root / 'Test.cpp').write_text('// 0x1000 LocalBox::~LocalBox\n')

        report, fn = self.run_bind()
        self.assertEqual(fn['symbol'], declared_scalar)
        self.assertEqual(report['unbound_functions'], [])

    def test_undecided_binds_by_size_and_reports_choice(self):
        self.setup_task({PLAIN: 12, SCALAR: 29, VECTOR: 40}, listing=None)
        report, fn = self.run_bind()
        self.assertEqual(fn['symbol'], SCALAR)
        self.assertEqual(report['functions'][0]['how'], 'destructor kind, size match')
        choice = report['destructor_choices'][0]
        self.assertEqual([c['symbol'] for c in choice['candidates']], [SCALAR, VECTOR, PLAIN])
        self.assertIn(f'bound to {SCALAR}', '\n'.join(bind.describe(report, self.task_dir)))

    def test_unused_hint_is_reported(self):
        self.setup_task({PLAIN: 12}, listing=CLOBBERED_LISTING, name_how='name', hints={SCALAR: '0x1000'})
        report, fn = self.run_bind()
        self.assertEqual(fn['symbol'], PLAIN)
        self.assertEqual(report['ignored_hints'][0]['hint'], SCALAR)
        self.assertIn('not defined in the compiled object', report['ignored_hints'][0]['reason'])
        self.assertIn(f'WARNING bind hint {SCALAR}', '\n'.join(bind.describe(report, self.task_dir)))

    def test_hint_overriding_evidence_is_used_and_warned(self):
        self.setup_task({PLAIN: 12, SCALAR: 29}, hints={PLAIN: '0x1000'})
        report, fn = self.run_bind()
        self.assertEqual(fn['symbol'], PLAIN)
        self.assertEqual(report['ignored_hints'], [])
        self.assertIn('overrides the pack evidence', report['warnings'][0])


DTOR = 'SyntheticDtor'
DTOR_RVA = fx.LAYOUT[fx.OTHER_CALLEE]


class ClassSpecialNameTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()

    def tearDown(self):
        self.tmp.cleanup()

    def run_ctor(self, defined, community='RE::BSLightingShaderMaterialEye::Ctor', size=3):
        unit = fx.Unit()
        for name, length in defined.items():
            sec = unit.section('.text$mn', b'\xc3' * length, fx.SCN_CODE)
            unit.define(name, sec, storage=fx.STORAGE_EXTERNAL, function=True)
        (self.root / 'obj').write_bytes(unit.coff())
        task = {'symbols': 'symbols.json', 'functions': [
            {'rva': '0x1000', 'size': size, 'symbol': 'unbound:Eye', 'community_name': community}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        (self.task_dir / 'symbols.json').write_text(json.dumps({'schema': 1, 'symbols': {}}))
        report = bind.bind(self.task_dir, self.root / 'obj', None, repo=self.root)
        return report, json.loads((self.task_dir / 'task.json').read_text())['functions'][0]

    def test_other_classes_constructor_does_not_make_it_ambiguous(self):
        report, fn = self.run_ctor({'??0BSLightingShaderMaterialEye@@QEAA@XZ': 3, '??0NiColor@@QEAA@XZ': 3})
        self.assertEqual(fn['symbol'], '??0BSLightingShaderMaterialEye@@QEAA@XZ')
        self.assertEqual(report['unbound_functions'], [])

    def test_single_constructor(self):
        report, fn = self.run_ctor({'??0BSLightingShaderMaterialEye@@QEAA@XZ': 3})
        self.assertEqual(fn['symbol'], '??0BSLightingShaderMaterialEye@@QEAA@XZ')

    def test_overloaded_constructors_stay_unbound_with_hint_advice(self):
        report, fn = self.run_ctor({'??0BSLightingShaderMaterialEye@@QEAA@XZ': 3,
                                    '??0BSLightingShaderMaterialEye@@QEAA@H@Z': 3, '??0NiColor@@QEAA@XZ': 3})
        self.assertEqual(fn['symbol'], 'unbound:Eye')
        self.assertEqual(len(report['unbound_functions'][0]['overloads']), 2)
        self.assertIn('CI hash:', '\n'.join(bind.describe(report, self.task_dir)))



COLL = '?GetCollisionObject@NiAVObject@@QEAAPEAVbhkCollisionObject@@XZ'
COLL_CONST = '?GetCollisionObject@NiAVObject@@QEBAPEAVbhkCollisionObject@@XZ'


class NormalizeParamsTests(unittest.TestCase):
    def test_source_style_equals_demangled_style(self):
        pairs = [
            ('NiBSplineData*, std::uint32_t, NiBSplineBasisData*',
             'class NiBSplineData *, unsigned int, class NiBSplineBasisData *'),
            ('const NiColorA&', 'class NiColorA const &'),
            ('const char*, std::int64_t', 'char const *, __int64'),
            ('volatile const T*, uint8_t', 'T const volatile *, unsigned char'),
            ('const std::pair<int, char const*>&', 'std::pair<int, char const *> const &'),
            ('void', ''),
        ]
        for source, demangled in pairs:
            with self.subTest(source=source):
                self.assertEqual(bind.normalize_params(source), bind.normalize_params(demangled))

    def test_distinct_signatures_stay_distinct(self):
        self.assertNotEqual(bind.normalize_params('const NiColorA&'), bind.normalize_params('NiColorA&'))
        self.assertNotEqual(bind.normalize_params('std::uint32_t'), bind.normalize_params('std::uint64_t'))


class OverloadAndOrderTests(unittest.TestCase):
    """Name-to-definition rules for C++ forms that share or rename a community name (no demangler)."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()

    def tearDown(self):
        self.tmp.cleanup()

    def run_bind(self, defined, functions, header=None, hints=None, matcher=None, symbols=None, source_root=None):
        """`defined` is {decorated name: section bytes}; `functions` [(rva, size, community name)]."""
        unit = fx.Unit()
        for name, code in defined.items():
            sec = unit.section('.text$mn', code if isinstance(code, bytes) else b'\xc3' * code, fx.SCN_CODE)
            unit.define(name, sec, storage=fx.STORAGE_EXTERNAL, function=True)
        (self.root / 'obj').write_bytes(unit.coff())
        task = {'symbols': 'symbols.json', 'compiled': 'unit.cpp', 'functions': [
            {'rva': rva, 'size': size, 'symbol': f'unbound:{rva}', 'community_name': name}
            for rva, size, name in functions]}
        if header is not None:
            (self.root / 'unit.cpp').write_text(''.join(f'// {line}\n' for line in header) + '#include "unit.h"\n')
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        (self.task_dir / 'symbols.json').write_text(json.dumps({'schema': 1, 'symbols': symbols or {}}))
        if hints is not None:
            (self.task_dir / bind.HINTS).write_text(json.dumps(hints))
        with mock.patch.object(bind, 'target_matcher', return_value=matcher):
            report = bind.bind(self.task_dir, self.root / 'obj', None, repo=self.root, source_root=source_root)
        bound = {f['rva']: f['symbol'] for f in json.loads((self.task_dir / 'task.json').read_text())['functions']}
        return report, bound

    def test_const_and_non_const_overloads_split_by_size(self):
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 20}, [
            ('0x1900a0', 9, 'RE::NiAVObject::GetCollisionObject'),
            ('0x405a50', 20, 'RE::NiAVObject::GetCollisionObject')])
        self.assertEqual(bound, {'0x1900a0': COLL, '0x405a50': COLL_CONST})
        self.assertEqual(report['unbound_functions'], [])
        self.assertIn('narrowed by size', report['functions'][0]['how'])

    def test_same_size_overloads_split_by_target_hash(self):
        def matcher(rva, symbol):
            return (rva, symbol) in {(0x1900a0, COLL), (0x405a50, COLL_CONST)}
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [
            ('0x1900a0', 9, 'NiAVObject::GetCollisionObject'),
            ('0x405a50', 9, 'NiAVObject::GetCollisionObject')], matcher=matcher)
        self.assertEqual(bound, {'0x1900a0': COLL, '0x405a50': COLL_CONST})
        self.assertIn('target hash', report['functions'][0]['how'])

    def test_declared_signature_on_the_header_line_picks_the_overload(self):
        static = '?GetContainer@TESObjectREFR@@SAPEAVTESContainer@@PEAVTESBoundObject@@@Z'
        member_fn = '?GetContainer@TESObjectREFR@@QEBAPEAVTESContainer@@XZ'
        report, bound = self.run_bind({static: 9, member_fn: 9}, [('0x2e8660', 9, 'TESObjectREFR::GetContainer')],
                                      header=['0x2e8660 TESObjectREFR::GetContainer() const'])
        self.assertEqual(bound['0x2e8660'], member_fn)
        self.assertIn('declared signature', report['functions'][0]['how'])

    def test_the_definition_the_map_already_names_is_the_one_bound(self):
        # Same size, nothing else tells the overloads apart; the map holds one of them at the RVA.
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [('0x1900a0', 9, 'NiAVObject::GetCollisionObject')],
                                      symbols={COLL_CONST: {'rva': 0x1900a0, 'size': None}})
        self.assertEqual(bound['0x1900a0'], COLL_CONST)
        self.assertEqual(report['functions'][0]['how'], 'map entry')

    def test_a_mapped_name_the_object_does_not_define_changes_nothing(self):
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [('0x1900a0', 9, 'NiAVObject::GetCollisionObject')],
                                      symbols={'?Elsewhere@@YAXXZ': {'rva': 0x1900a0, 'size': None}})
        self.assertEqual(bound['0x1900a0'], 'unbound:0x1900a0')

    def test_indistinguishable_overloads_list_the_hint_lines(self):
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [('0x1900a0', 9, 'NiAVObject::GetCollisionObject')])
        self.assertEqual(bound['0x1900a0'], 'unbound:0x1900a0')
        self.assertEqual(report['unbound_functions'][0]['overloads'], sorted([COLL, COLL_CONST]))
        text = '\n'.join(bind.describe(report, self.task_dir))
        self.assertIn(f'// CI hash: 0x1900a0 {COLL}', text)
        self.assertIn(f'// CI hash: 0x1900a0 {COLL_CONST}', text)

    def test_hint_still_decides_between_overloads(self):
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [('0x1900a0', 9, 'NiAVObject::GetCollisionObject')],
                                      hints={COLL_CONST: '0x1900a0'})
        self.assertEqual(bound['0x1900a0'], COLL_CONST)

    def test_member_name_never_takes_another_functions_exact_name(self):
        # The unit defines TESObjectCELL::GetOwner and calls ExtraDataList::GetOwner, and the task lists
        # the callee first: the callee must not take the definition by member name.
        owner = '?GetOwner@TESObjectCELL@@QEAAPEAVTESForm@@XZ'
        report, bound = self.run_bind({owner: 33}, [('0x164570', 33, 'ExtraDataList::GetOwner'),
                                                    ('0x2be530', 33, 'TESObjectCELL::GetOwner')])
        self.assertEqual(bound['0x2be530'], owner)
        self.assertEqual(bound['0x164570'], 'unbound:0x164570')

    def test_member_name_still_binds_an_override_named_for_its_base(self):
        derived = '?Update@Derived@@UEAAXXZ'
        report, bound = self.run_bind({derived: 9}, [('0x1000', 9, 'Base::Update')])
        self.assertEqual(bound['0x1000'], derived)
        self.assertEqual(report['functions'][0]['how'], 'member name')

    def test_header_line_names_a_stand_in_without_a_community_name(self):
        slot = '?Slot8@PlayerCharacter@@UEBAEXZ'
        report, bound = self.run_bind({slot: 9, '?Other@PlayerCharacter@@QEAAXXZ': 9}, [('0x75c2b0', 9, None)],
                                      header=['0x75c2b0 PlayerCharacter::Slot8'])
        self.assertEqual(bound['0x75c2b0'], slot)
        self.assertEqual(report['functions'][0]['how'], 'header name')

    def test_literal_ctor_member_beats_the_class_constructor(self):
        literal = '?Ctor@BSLightingShaderMaterialSnow@@QEAAPEAV1@XZ'
        report, bound = self.run_bind({literal: 9, '??0BSLightingShaderMaterialSnow@@QEAA@XZ': 9},
                                      [('0x1527fc0', 9, 'BSLightingShaderMaterialSnow::Ctor')])
        self.assertEqual(bound['0x1527fc0'], literal)

    def test_deleting_destructor_adjustor_thunk_binds_by_size(self):
        thunk = '??_EBGSMovableStatic@@WBA@EAAPEAXI@Z'
        report, bound = self.run_bind({'??1BGSMovableStatic@@UEAA@XZ': 40, '??_GBGSMovableStatic@@UEAAPEAXI@Z': 60,
                                       thunk: 9}, [('0x264444', 9, 'BGSMovableStatic::dtor')])
        self.assertEqual(bound['0x264444'], thunk)

    def test_ci_hash_line_in_the_unit_is_a_hint(self):
        report, bound = self.run_bind({COLL: 9, COLL_CONST: 9}, [('0x1900a0', 9, 'NiAVObject::GetCollisionObject')],
                                      header=['0x1900a0 NiAVObject::GetCollisionObject', f'CI hash: 0x1900a0 {COLL}'])
        self.assertEqual(bound['0x1900a0'], COLL)
        self.assertEqual(report['functions'][0]['how'], 'hint')

    def test_ci_hash_line_comes_from_the_private_source_root(self):
        cache_name = '?Use@Toy@@QEAAXXZ'
        private_name = '?Use@Toy@@QEBAXXZ'
        private = self.root / 'private'
        private.mkdir()
        (private / 'unit.cpp').write_text(f'// CI hash: 0x1000 {private_name}\n')
        report, bound = self.run_bind({cache_name: 9, private_name: 9}, [('0x1000', 9, 'Toy::Use')],
                                      header=[f'CI hash: 0x1000 {cache_name}'], source_root=private)
        self.assertEqual(bound['0x1000'], private_name)
        self.assertEqual(report['functions'][0]['how'], 'hint')

    def test_decoration_traits(self):
        self.assertEqual(bind.decoration_traits(COLL_CONST), {'static': False, 'cv': 'const', 'params': None})
        self.assertEqual(bind.decoration_traits(COLL)['cv'], '')
        self.assertTrue(bind.decoration_traits('?GetContainer@TESObjectREFR@@SAPEAVTESContainer@@XZ')['static'])
        self.assertEqual(bind.decoration_traits('??0Eye@@QEAA@XZ')['cv'], '')
        text = 'public: static class TESContainer * __cdecl TESObjectREFR::GetContainer(class TESBoundObject *)'
        self.assertEqual(bind.decoration_traits('?x', text)['params'], 'TESBoundObject*')

    def test_header_declarations(self):
        (self.root / 'u.cpp').write_text('// Source exposure: original.\n// 0x10 A::F\n'
                                         '// 0x20 RE::A::G(int, char const *) const\n// CI hash: 0x10 ?F@A@@QEAAXXZ\n#include "u.h"\n')
        decls = bind.header_declarations(self.root, 'u.cpp')
        self.assertEqual(decls[0x10], {'name': 'A::F', 'params': None, 'cv': None})
        self.assertEqual(decls[0x20], {'name': 'A::G', 'params': 'int,charconst*', 'cv': 'const'})


class FuncletTests(unittest.TestCase):
    """References made only from funclets, on the synthetic catch unit (catch$0 and dtor$0)."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()
        unit = fx.catch_unit()
        # The unwind funclet calls a destructor nothing else in the unit references.
        x = next(i for i, sec in enumerate(unit.sections, 1) if sec[0] == '.text$x')
        unit.sections[x - 1][2] = [(o, DTOR if o == 0x29 else sym, k) for o, sym, k in unit.sections[x - 1][2]]
        unit.external(DTOR)
        self.unit = unit
        self.externals = fx.image_externals(**{DTOR: DTOR_RVA})
        self.image = unit.link(self.externals)
        (self.root / 'obj').write_bytes(unit.coff())
        (self.root / 'image').write_bytes(self.image)
        self.dtor_rva = fx.section_rva(unit, '?dtor$0@?0??SyntheticCatch@@4HA')

    def tearDown(self):
        self.tmp.cleanup()

    def setup_task(self, calls, hints=None, funclet=True):
        pack = self.root / 'packs' / 'c'
        pack.mkdir(parents=True, exist_ok=True)
        states = [{'state': 0, 'to_state': -1, 'funclet': self.dtor_rva if funclet else None, 'calls': calls}]
        (pack / 'pack.json').write_text(json.dumps({
            'references': [{'target_rva': fx.LAYOUT[fx.CALLEE], 'community_names': []}],
            'object_lifetimes': {'states': states, 'try_blocks': []}}))
        rva = fx.section_rva(self.unit, fx.CATCH_FUNCTION)
        task = {'symbols': 'symbols.json', 'functions': [
            {'rva': hex(rva), 'size': len(fx.CATCH_CODE), 'symbol': fx.CATCH_FUNCTION,
             'community_name': 'SyntheticCatch', 'pack': 'packs/c'}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        (self.task_dir / 'symbols.json').write_text(json.dumps({'schema': 1, 'symbols': {}}))
        if hints is not None:
            (self.task_dir / bind.HINTS).write_text(json.dumps(hints))

    def run_bind(self, image=True):
        report = bind.bind(self.task_dir, self.root / 'obj', self.root / 'image' if image else None, repo=self.root)
        return report, json.loads((self.task_dir / 'symbols.json').read_text())['symbols']

    def test_funclets_found_with_unwind_state(self):
        obj = bind.CoffObject(self.unit.coff())
        defined = bind.defined_functions(obj)
        found = bind.funclets(obj, defined[fx.CATCH_FUNCTION], set(defined.values()))
        x = next(i for i, sec in enumerate(self.unit.sections, 1) if sec[0] == '.text$x')
        self.assertEqual(found, {x: (0, 0x21)})

    def test_lifetime_callee_bound_by_funclet_position(self):
        self.setup_task([hex(DTOR_RVA)], hints={fx.BASE: hex(self.externals[fx.BASE])})
        report, symbols = self.run_bind()
        self.assertEqual(report['unbound_references'], [])
        got = {r['symbol']: r for r in report['references']}
        self.assertEqual((got[DTOR]['how'], got[DTOR]['from']), ('object lifetime position', 'funclet'))
        self.assertEqual(symbols[DTOR]['rva'], DTOR_RVA)
        # The catch funclet's global is bound only because funclets are scanned at all.
        self.assertEqual((got[fx.BASE]['how'], got[fx.BASE]['from']), ('hint', 'funclet'))
        self.assertEqual(got[fx.CALLEE]['how'], 'position')
        # The comparator, which compares funclets too, passes with exactly this map.
        smap = dict(symbols, **{n: {'rva': r, 'size': None} for n, r in fx.HANDLER_THUNKS.items()},
                    **fx.catch_map(self.unit))
        args = fx.unit_inputs(self.unit, fx.CATCH_FUNCTION, self.externals, image=self.image)
        args['symbol_map']['symbols'] = smap
        result = compare(**args)
        self.assertEqual(result['result'], 'pass', result.get('detail'))
        self.assertGreater(result['coverage']['funclet_sections'], 0)

    def test_without_position_single_lifetime_call_binds(self):
        self.setup_task([hex(DTOR_RVA) + ' Synthetic::~Synthetic'], hints={fx.BASE: '0x3100'}, funclet=False)
        report, symbols = self.run_bind(image=False)
        self.assertEqual(symbols[DTOR]['rva'], DTOR_RVA)
        self.assertEqual({r['symbol']: r['how'] for r in report['references']}[DTOR], 'object lifetime')

    def test_position_contradicting_the_lifetime_call_does_not_bind(self):
        self.setup_task(['0x1004'], hints={fx.BASE: '0x3100'})
        report, symbols = self.run_bind()
        self.assertNotIn(DTOR, symbols)
        self.assertEqual(report['unbound_references'], [DTOR])

    def test_funclet_only_reference_without_hint_is_listed(self):
        self.setup_task([hex(DTOR_RVA)])
        report, symbols = self.run_bind()
        self.assertIn(fx.BASE, report['unbound_references'])
        self.assertIn(f'UNBOUND reference {fx.BASE}', '\n'.join(bind.describe(report, self.task_dir)))

    def test_lifetime_name_binds_by_community_name(self):
        # Two calls in the state, so only the community name can pick one.
        self.setup_task(['0x1000 RE::Other', hex(DTOR_RVA) + ' RE::SyntheticDtor'], hints={fx.BASE: '0x3100'},
                        funclet=False)
        report, symbols = self.run_bind(image=False)
        self.assertEqual(symbols[DTOR]['rva'], DTOR_RVA)
        self.assertEqual({r['symbol']: r['how'] for r in report['references']}[DTOR], 'community name')

    def table(self, *rvas):
        path = self.root / 'functions.jsonl'
        path.write_text(''.join(json.dumps({'rva': r}) + '\n' for r in rvas))
        return mock.patch.dict(os.environ, {'SR_FUNCTION_TABLE': str(path)})

    def test_unlisted_destructor_binds_when_the_target_is_a_function_start(self):
        # The pack lists no destructor call at all, as for a compiler-generated local destructor.
        self.setup_task([], hints={fx.BASE: hex(self.externals[fx.BASE])})
        with self.table(DTOR_RVA, 0x1000):
            report, symbols = self.run_bind()
        self.assertEqual(report['unbound_references'], [])
        got = {r['symbol']: r for r in report['references']}
        self.assertEqual((got[DTOR]['how'], got[DTOR]['from']), ('unwind funclet position', 'funclet'))
        self.assertEqual(symbols[DTOR]['rva'], DTOR_RVA)

    def test_unlisted_destructor_stays_unbound_when_the_target_is_not_in_the_table(self):
        self.setup_task([], hints={fx.BASE: hex(self.externals[fx.BASE])})
        with self.table(0x1000):
            report, symbols = self.run_bind()
        self.assertEqual(report['unbound_references'], [DTOR])
        self.assertNotIn(DTOR, symbols)

    def test_unlisted_destructor_stays_unbound_without_a_table(self):
        self.setup_task([], hints={fx.BASE: hex(self.externals[fx.BASE])})
        with mock.patch.dict(os.environ, {'SR_FUNCTION_TABLE': str(self.root / 'absent.jsonl')}), \
                mock.patch.object(bind, 'function_starts', return_value=None):
            report, symbols = self.run_bind()
        self.assertEqual(report['unbound_references'], [DTOR])

    def test_function_table_does_not_bind_a_reference_of_the_function_itself(self):
        # Only unwind funclets get the rule; the parent's own references still need the pack.
        self.setup_task([hex(DTOR_RVA)], hints={fx.BASE: hex(self.externals[fx.BASE])})
        with self.table(DTOR_RVA, fx.LAYOUT[fx.CALLEE]):
            report, symbols = self.run_bind()
        got = {r['symbol']: r['how'] for r in report['references']}
        self.assertEqual(got[fx.CALLEE], 'position')
        self.assertEqual(got[DTOR], 'object lifetime position')


class PublicMapBindTests(BindTests):
    """A task naming the repository map: bind adds through tools/symbol_map.py, never by hand."""
    MAP = 'reports/synthetic-fixture/symbol-map.json'

    def write_task(self, symbol, symbols, hints=None):
        super().write_task(symbol, symbols, hints)
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['symbols'] = self.MAP
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        path = self.root / self.MAP
        path.parent.mkdir(parents=True, exist_ok=True)
        # Bytes: the tool's canonical form ends in a bare LF, which text mode would turn into CRLF on Windows.
        path.write_bytes((json.dumps({'schema': 1, 'build_id': 'synthetic-fixture', 'symbols': symbols,
                                      'folds': []}, indent=2) + '\n').encode())

    def run_bind(self):
        report = bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        return report, json.loads((self.root / self.MAP).read_text())['symbols']

    def test_a_stale_name_at_the_function_rva_is_dropped_from_a_private_map(self):
        self.skipTest('private maps only: a public map changes through tools/symbol_map.py')

    def test_a_name_the_object_refers_to_is_kept_at_the_function_rva(self):
        self.skipTest('private maps only: a public map changes through tools/symbol_map.py')

    def test_additions_go_through_the_history(self):
        self.run_bind()
        history = json.loads((self.root / 'reports/synthetic-fixture/symbol-map.history.json').read_text())
        self.assertEqual(len(history['versions']), 2)
        self.assertIn(fx.FUNCTION, history['versions'][1]['added'])

    def test_rename_that_would_stale_a_record_is_refused(self):
        old = '?SyntheticSum@Synthetic@@QEAAHXZ'
        self.write_task(old, {old: {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)}})
        blob = (self.root / self.MAP).read_bytes()
        record = {'symbol_map': {'path': self.MAP, 'sha256': hashlib.sha256(blob).hexdigest()},
                  'runs': [{'report': {'function': {'rva': fx.LAYOUT[fx.FUNCTION], 'size': len(fx.CODE)},
                                       'coverage': {}}}]}
        (self.root / 'reports/synthetic-fixture/0x1010.json').write_text(json.dumps(record))
        with self.assertRaisesRegex(ValueError, 'stale'):
            self.run_bind()
        self.assertEqual((self.root / self.MAP).read_bytes(), blob)


class ThreadLocalBindTests(unittest.TestCase):
    """A SECREL reference binds only through a `tls:` hint, as a thread-local entry; _tls_index never."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()
        unit = fx.tls_unit()
        (self.root / 'obj').write_bytes(unit.coff())
        image = unit.link({fx.TLS_INDEX: fx.TLS_INDEX_RVA}, tls=fx.tls_layout())
        (self.root / 'image').write_bytes(image)
        rva = unit.default_placement()[1]
        pack = self.root / 'packs' / 't'
        pack.mkdir(parents=True)
        # Even a pack listing the very value the target's SECREL field holds must not bind it as an RVA.
        refs = [{'target_rva': fx.TLS_OFFSET, 'community_names': [{'name': 'tSyntheticGuard', 'kind': 'data'}]},
                {'target_rva': fx.TLS_INDEX_RVA, 'community_names': []}]
        (pack / 'pack.json').write_text(json.dumps({'references': refs}))
        task = {'symbols': 'symbols.json', 'functions': [
            {'rva': hex(rva), 'size': len(fx.TLS_CODE), 'symbol': fx.TLS_FUNCTION,
             'community_name': 'SyntheticTlsRead', 'pack': 'packs/t'}]}
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        (self.task_dir / 'symbols.json').write_text(json.dumps(
            {'schema': 1, 'symbols': {fx.TLS_FUNCTION: {'rva': rva, 'size': len(fx.TLS_CODE)}}}))

    def tearDown(self):
        self.tmp.cleanup()

    def run_bind(self, hints=None):
        if hints is not None:
            (self.task_dir / bind.HINTS).write_text(json.dumps(hints))
        report = bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        return report, json.loads((self.task_dir / 'symbols.json').read_text())['symbols']

    def test_unhinted_thread_local_stays_unbound(self):
        report, symbols = self.run_bind()
        self.assertEqual(report['unbound_thread_locals'], [fx.TLS_VAR])
        self.assertEqual(report['unbound_references'], [])
        self.assertNotIn(fx.TLS_VAR, symbols)
        self.assertNotIn(fx.TLS_INDEX, symbols)
        self.assertIn('tls:0x<offset>', '\n'.join(bind.describe(report, self.task_dir)))

    def test_tls_hint_writes_thread_local_entry(self):
        report, symbols = self.run_bind({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
        self.assertEqual(report['unbound_thread_locals'], [])
        self.assertEqual(symbols[fx.TLS_VAR], {'kind': 'thread-local', 'tls_offset': fx.TLS_OFFSET, 'size': None})
        self.assertNotIn(fx.TLS_INDEX, symbols)
        self.assertIn('thread-local hint', '\n'.join(bind.describe(report, self.task_dir)))

    def test_underscore_prefixed_hint_keys_are_hints(self):
        (self.task_dir / bind.HINTS).write_text(json.dumps({
            '_Init_thread_epoch': 'tls:0x2a08', '_Init_thread_abort': '0x15a7c7c', '_note': 'free text',
            '_empty': ''}))
        self.assertEqual(bind.load_tls_hints(self.task_dir), {'_Init_thread_epoch': 0x2a08})
        self.assertEqual(bind.load_hints(self.task_dir), {'_Init_thread_abort': 0x15a7c7c})

    def test_non_underscore_key_with_bad_value_still_rejected(self):
        (self.task_dir / bind.HINTS).write_text(json.dumps({'Class::Method': 'note'}))
        with self.assertRaises(ValueError):
            bind.load_hints(self.task_dir)

    def crt_defaults(self, table, build='synthetic-fixture'):
        path = self.root / bind.CRT_DEFAULTS
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps({build: table}))
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['build_id'] = build
        (self.task_dir / 'task.json').write_text(json.dumps(task))

    def test_crt_default_binds_thread_local_without_a_hint(self):
        self.crt_defaults({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
        report, symbols = self.run_bind()
        self.assertEqual(report['unbound_thread_locals'], [])
        self.assertEqual(symbols[fx.TLS_VAR], {'kind': 'thread-local', 'tls_offset': fx.TLS_OFFSET, 'size': None})
        self.assertEqual(report['ignored_hints'], [])

    def test_crt_default_for_an_unreferenced_name_is_not_listed_as_ignored(self):
        self.crt_defaults({'_Init_thread_epoch': 'tls:0x2a08', '_Init_thread_abort': '0x15a7c7c'})
        report, symbols = self.run_bind()
        self.assertEqual(report['ignored_hints'], [])
        self.assertNotIn('_Init_thread_epoch', symbols)
        self.assertEqual(report['unbound_thread_locals'], [fx.TLS_VAR])

    def test_private_hint_overrides_crt_default(self):
        self.crt_defaults({fx.TLS_VAR: 'tls:0x40'})
        _, symbols = self.run_bind({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
        self.assertEqual(symbols[fx.TLS_VAR]['tls_offset'], fx.TLS_OFFSET)

    def test_crt_defaults_of_another_build_are_not_used(self):
        self.crt_defaults({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')}, build='other-build')
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['build_id'] = 'synthetic-fixture'
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        report, _ = self.run_bind()
        self.assertEqual(report['unbound_thread_locals'], [fx.TLS_VAR])

    def test_malformed_tls_hint_rejected(self):
        with self.assertRaises(ValueError):
            self.run_bind({fx.TLS_VAR: 'tls:seven'})

    def test_unused_tls_hint_is_listed_as_ignored(self):
        hint = '?tUnused@@3HA'
        report, symbols = self.run_bind({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x'), hint: 'tls:0x40'})
        self.assertEqual([h['hint'] for h in report['ignored_hints']], [hint])
        self.assertNotIn(hint, symbols)
        self.assertIn(f'bind hint {hint} -> tls:0x40 ignored', '\n'.join(bind.describe(report, self.task_dir)))

    def test_undecorated_name_binds_a_thread_local(self):
        report, symbols = self.run_bind({'tSyntheticGuard': hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
        self.assertEqual(report['unbound_thread_locals'], [])
        self.assertEqual(report['ignored_hints'], [])
        self.assertEqual(symbols[fx.TLS_VAR]['tls_offset'], fx.TLS_OFFSET)

    def test_member_name_of_a_scoped_variable_binds_when_unique(self):
        old = fx.TLS_VAR
        fx.TLS_VAR = '?tSyntheticGuard@Scope@@2HA'
        try:
            self.tearDown()
            self.setUp()
            report, symbols = self.run_bind({'tSyntheticGuard': hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
            self.assertEqual(report['unbound_thread_locals'], [])
            self.assertEqual(symbols[fx.TLS_VAR]['tls_offset'], fx.TLS_OFFSET)
            # The qualified spelling binds the same symbol.
            self.run_bind({'Scope::tSyntheticGuard': hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')})
        finally:
            fx.TLS_VAR = old

    def test_unused_hint_is_listed_by_name(self):
        report, _ = self.run_bind({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x'), 'MissingThing': '0x1234'})
        self.assertEqual(report['unused_hints'], ['MissingThing'])
        self.assertIn('MissingThing', '\n'.join(bind.describe(report, self.task_dir)))

    def test_describe_names_every_unbound_reference_and_pastes_a_hint_object(self):
        report = {'functions': [], 'references': [], 'renamed': [], 'unbound_functions': [],
                  'unbound_references': ['?a@@3HA', '?b@@3HA', '??_C@_01ABCDEFGH@x@'],
                  'unbound_thread_locals': ['?t@@3HA']}
        lines = bind.describe(report, self.task_dir)
        text = '\n'.join(lines)
        for name in report['unbound_references'] + report['unbound_thread_locals']:
            self.assertIn(f'UNBOUND', text)
            self.assertIn(name, text)
        paste = [line for line in lines if 'paste into' in line]
        self.assertEqual(len(paste), 1)
        self.assertEqual(json.loads(paste[0].split(': ', 1)[1]),
                         {'?a@@3HA': '0x<rva>', '?b@@3HA': '0x<rva>', '??_C@_01ABCDEFGH@x@': '0x<rva>',
                          '?t@@3HA': 'tls:0x<offset>'})

    def test_used_tls_hint_stays_used_once_bound(self):
        hints = {fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')}
        self.run_bind(hints)
        report, _ = self.run_bind(hints)
        self.assertEqual(report['ignored_hints'], [])

    PUBLIC = 'reports/synthetic-fixture/symbol-map.json'

    def public_map(self, provenance=False):
        task = json.loads((self.task_dir / 'task.json').read_text())
        task['symbols'] = self.PUBLIC
        (self.task_dir / 'task.json').write_text(json.dumps(task))
        smap = json.loads((self.task_dir / 'symbols.json').read_text())
        smap.update(build_id='synthetic-fixture', folds=[])
        if provenance:
            smap['_provenance'] = {'database': 'synthetic', 'entries': [{'name': n, 'note': 'synthetic'}
                                                                       for n in smap['symbols']]}
        path = self.root / self.PUBLIC
        path.parent.mkdir(parents=True)
        path.write_bytes((json.dumps(smap, indent=2) + '\n').encode())
        (self.task_dir / bind.HINTS).write_text(json.dumps({fx.TLS_VAR: hex(fx.TLS_OFFSET).replace('0x', 'tls:0x')}))
        return path

    def test_thread_local_is_published_to_the_repository_map(self):
        path = self.public_map(provenance=True)
        bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        smap = json.loads(path.read_text())
        self.assertEqual(list(smap['symbols'][fx.TLS_VAR].items()),
                         [('kind', 'thread-local'), ('tls_offset', fx.TLS_OFFSET), ('size', None)])
        prov = {e['name']: e for e in smap['_provenance']['entries']}[fx.TLS_VAR]
        self.assertEqual(prov['tls_offset'], hex(fx.TLS_OFFSET))
        self.assertNotIn('rva', prov)
        self.assertTrue((self.root / 'reports/synthetic-fixture/symbol-map.history.json').is_file())

    def test_thread_local_publication_refused_while_it_would_stale_a_record(self):
        path = self.public_map()
        blob = path.read_bytes()
        # Only what the stale check reads: a record pinned to the current map, its function elsewhere.
        record = {'symbol_map': {'path': self.PUBLIC, 'sha256': hashlib.sha256(blob).hexdigest()},
                  'runs': [{'report': {'function': {'rva': 0x9000, 'size': 16, 'symbol': 'Other'}, 'coverage': {}}}]}
        (self.root / 'reports/synthetic-fixture/0x9000.json').write_text(json.dumps(record))
        with self.assertRaisesRegex(ValueError, 'stale.*thread-local entry'):
            bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        self.assertEqual(path.read_bytes(), blob)


class PoolConstantTests(unittest.TestCase):
    """Compiler-made float and vector literals bind by the value the symbol name spells."""

    def test_bytes_follow_the_name(self):
        self.assertEqual(bind.pool_constant_bytes('__real@3f800000'), bytes.fromhex('0000803f'))
        self.assertEqual(bind.pool_constant_bytes('__real@3ff0000000000000'), bytes.fromhex('000000000000f03f'))
        self.assertEqual(len(bind.pool_constant_bytes('__xmm@' + '0' * 24 + '80000000')), 16)
        self.assertIsNone(bind.pool_constant_bytes('__real@3f80'))
        self.assertIsNone(bind.pool_constant_bytes('?g@@3HA'))

    def test_string_literal_names_spell_their_text(self):
        self.assertEqual(bind.string_literal_bytes('??_C@_0BA@KBMLLPJE@Scroll?5Sequence@'), (b'Scroll Sequence\0', True))
        self.assertEqual(bind.string_literal_bytes('??_C@_05BHEJOJJF@Shout@'), (b'Shout\0', True))
        self.assertEqual(bind.string_literal_bytes('??_C@_0BL@EIDEOLFC@?$CIUninitialized?5event?5node?$CJ@'),
                         (b'(Uninitialized event node)\0', True))
        self.assertEqual(bind.string_literal_bytes('??_C@_04ABCDEFGH@ab?$AAc@')[0], b'ab\0c\0')
        self.assertIsNone(bind.string_literal_bytes('??_C@_1BA@ABCDEFGH@x@'))
        self.assertIsNone(bind.string_literal_bytes('??_C@_05BHEJOJJF@Sho@'))  # length disagrees with the text

    def test_image_must_hold_those_bytes(self):
        class Image:
            def read(self, rva, size, what):
                return rva, (b'\x00\x00\x80?' + b'\x00' * 12)[:size]
        want = bind.pool_constant_bytes('__real@3f800000')
        self.assertTrue(bind.constant_at(Image(), 0x100, want))
        self.assertFalse(bind.constant_at(Image(), 0x100, bind.pool_constant_bytes('__real@40000000')))


class DeclaredTlsNameTests(unittest.TestCase):
    """With no hint, a variable named `tls_0x<offset>` binds when the target's own field agrees."""

    VAR = '?tGuard_tls_0x768@@3HA'

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.task_dir = self.root / 'task'
        self.task_dir.mkdir()
        self.old = fx.TLS_VAR
        fx.TLS_VAR = self.VAR  # the fixture's unit and link layout read this module name at call time

    def tearDown(self):
        fx.TLS_VAR = self.old
        self.tmp.cleanup()

    def prepare(self, var=None, target_offset=fx.TLS_OFFSET, addend=0):
        if var is not None:
            fx.TLS_VAR = var
        unit = fx.tls_unit(addend=addend)
        (self.root / 'obj').write_bytes(unit.coff())
        image = unit.link({fx.TLS_INDEX: fx.TLS_INDEX_RVA}, tls=fx.tls_layout(offset=target_offset))
        (self.root / 'image').write_bytes(image)
        rva = unit.default_placement()[1]
        pack = self.root / 'packs' / 't'
        pack.mkdir(parents=True)
        (pack / 'pack.json').write_text(json.dumps({'references': []}))
        (self.task_dir / 'task.json').write_text(json.dumps({'symbols': 'symbols.json', 'functions': [
            {'rva': hex(rva), 'size': len(fx.TLS_CODE), 'symbol': fx.TLS_FUNCTION,
             'community_name': 'SyntheticTlsRead', 'pack': 'packs/t'}]}))
        (self.task_dir / 'symbols.json').write_text(json.dumps(
            {'schema': 1, 'symbols': {fx.TLS_FUNCTION: {'rva': rva, 'size': len(fx.TLS_CODE)}}}))
        report = bind.bind(self.task_dir, self.root / 'obj', self.root / 'image', repo=self.root)
        return report, json.loads((self.task_dir / 'symbols.json').read_text())['symbols']

    def test_declared_offset_binds_without_a_hint(self):
        report, symbols = self.prepare()
        self.assertEqual(report['unbound_thread_locals'], [])
        self.assertEqual(symbols[self.VAR], {'kind': 'thread-local', 'tls_offset': fx.TLS_OFFSET, 'size': None})
        self.assertEqual([r['how'] for r in report['references']], ['thread-local name'])
        self.assertNotIn(fx.TLS_INDEX, symbols)

    def test_declared_offset_that_the_target_does_not_use_binds_nothing(self):
        report, symbols = self.prepare(target_offset=0x770)
        self.assertEqual(report['unbound_thread_locals'], [self.VAR])
        self.assertNotIn(self.VAR, symbols)

    def test_name_without_a_declared_offset_binds_nothing(self):
        report, symbols = self.prepare(var='?tGuard@@3HA')
        self.assertEqual(report['unbound_thread_locals'], ['?tGuard@@3HA'])

    def test_declared_offset_outside_the_template_binds_nothing(self):
        report, symbols = self.prepare(var='?tFar_tls_0x7f768@@3HA', target_offset=0x7f768)
        self.assertEqual(report['unbound_thread_locals'], ['?tFar_tls_0x7f768@@3HA'])

    def test_declared_offset_is_the_variable_start_not_the_field(self):
        report, symbols = self.prepare(addend=4)
        self.assertEqual(symbols[self.VAR]['tls_offset'], fx.TLS_OFFSET)

    def test_hint_still_wins_over_the_name(self):
        (self.task_dir / bind.HINTS).write_text(json.dumps({self.VAR: 'tls:0x768'}))
        report, symbols = self.prepare()
        self.assertEqual([r['how'] for r in report['references']], ['thread-local hint'])


if __name__ == '__main__':
    unittest.main()
