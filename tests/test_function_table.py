"""Whole-image table logic on synthetic inputs: cluster keys, call-site census, community slot
parsing, the per-class checks, class skeletons, the fan-in planner and the scope breakdown.
No game data: every listing, header and table row below is invented for the test."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools' / 'ghidra'))
import build_function_table as bft  # noqa: E402
import class_skeleton  # noqa: E402
import export_pack as ep  # noqa: E402
import harvest_handlers as hh  # noqa: E402
import lint_reconstruction as lint  # noqa: E402
import struct
from types import SimpleNamespace

BASE = 0x140000000


def line(addr, mnemonic, ops=''):
    return f'{BASE + addr:x}:     \t{mnemonic}\t{ops}\n'


class DisasmTests(unittest.TestCase):
    def run_pass(self, lines, functions):
        return bft.DisasmPass(functions, BASE).feed(lines)

    def test_l1_masks_relocated_fields_l2_masks_numbers(self):
        a = [line(0x1000, 'mov', 'rax, qword ptr [rip + 0x100]  # 0x140001107'),
             line(0x1007, 'mov', 'ecx, 0x5'), line(0x100c, 'call', '0x140003000 <x>'), line(0x1011, 'ret')]
        b = [line(0x2000, 'mov', 'rax, qword ptr [rip + 0x900]  # 0x140002907'),
             line(0x2007, 'mov', 'ecx, 0x5'), line(0x200c, 'call', '0x140003010 <y>'), line(0x2011, 'ret')]
        c = [line(0x2100, 'mov', 'rax, qword ptr [rip + 0x900]  # 0x140002a07'),
             line(0x2107, 'mov', 'ecx, 0x6'), line(0x210c, 'call', '0x140003010 <y>'), line(0x2111, 'ret')]
        tail = [line(0x3000, 'ret'), line(0x3010, 'ret')]
        fns = {0x1000: [(0x1000, 0x1012)], 0x2000: [(0x2000, 0x2012)], 0x2100: [(0x2100, 0x2112)],
               0x3000: [(0x3000, 0x3001)], 0x3010: [(0x3010, 0x3011)]}
        d = self.run_pass(a + b + c + tail, fns)
        self.assertEqual(d['keys'][0x1000][0], d['keys'][0x2000][0])
        self.assertNotEqual(d['keys'][0x2000][0], d['keys'][0x2100][0])
        self.assertEqual(d['keys'][0x2000][1], d['keys'][0x2100][1])
        self.assertEqual(d['callees'][0x1000], [0x3000])

    def test_census_counts_argument_setup_and_result_use(self):
        lines = [line(0x1000, 'lea', 'rcx, [rsp + 0x30]'), line(0x1005, 'mov', 'edx, 0x18'),
                 line(0x100a, 'movss', 'xmm2, dword ptr [rip + 0x10]  # 0x140001022'),
                 line(0x1012, 'mov', 'qword ptr [rsp + 0x20], rax'), line(0x1017, 'mov', 'qword ptr [rsp + 0x48], rbx'),
                 line(0x101c, 'call', '0x140002000 <f>'), line(0x1021, 'test', 'al, al'), line(0x1023, 'ret'),
                 line(0x2000, 'ret')]
        d = self.run_pass(lines, {0x1000: [(0x1000, 0x1024)], 0x2000: [(0x2000, 0x2001)]})
        c = d['census'][0x2000]
        self.assertEqual(c['sites'], 1)
        self.assertEqual(c['arity'], {5: 1})  # slots 0, 1, 2 and stack slot 4; the far store is a local
        self.assertEqual(c['slots'][0], {'p8': 1})
        self.assertEqual(c['slots'][1], {'i4': 1})
        self.assertEqual(c['slots'][2], {'f4': 1})
        self.assertEqual(c['slots'][4], {'i8': 1})
        self.assertEqual(c['result'], {'i1': 1})
        self.assertEqual(d['edx_calls'][0x1000], [(0x2000, 0x18, 'call')])

    def test_result_overwritten(self):
        self.assertEqual(bft.result_use([('xor', ['eax', 'eax'])]), 'overwritten')
        self.assertEqual(bft.result_use([('mov', ['rcx', 'rax'])]), 'i8')
        self.assertEqual(bft.result_use([('mov', ['dword ptr [rax + 0x8]', 'ecx'])]), 'i8')


HEADER = '''
namespace RE
{
	class Base
	{
	public:
		inline static constexpr auto VTABLE = VTABLE_Base;
		virtual ~Base();  // 00
		virtual void Alpha();  // 01
		virtual void Beta();  // 02
	};
	static_assert(sizeof(Base) == 0x10);

	class Derived :
		public Base,  // 00
		public Sink   // 10
	{
	public:
		inline static constexpr auto VTABLE = VTABLE_Derived;
		struct Inner
		{
			virtual void Hidden();  // 07
		};
		~Derived() override;  // 00

		// override (Base)
		void Beta() override;  // 02

		// override (Sink)
		void Process() override;  // 01

		// add
		virtual void Gamma();  // 03
	};
	static_assert(sizeof(Derived) == 0x20);
}
'''


class CommunityTests(unittest.TestCase):
    def setUp(self):
        self.bodies = {e['vtable'] or e['name']: e for e in bft.parse_class_bodies(HEADER)}

    def test_bodies_bases_and_nested(self):
        d = self.bodies['Derived']
        self.assertEqual(d['bases'], ['Base', 'Sink'])
        self.assertNotIn(7, [s[0] for s in d['slots']])  # the nested struct's slot stays out
        self.assertIn('Inner', self.bodies)

    def test_secondary_override_section_is_skipped(self):
        slots = bft.primary_slots(self.bodies['Derived'], {'Derived', 'Base'})
        self.assertEqual(sorted(slots), [0, 2, 3])
        self.assertEqual(slots[2][:2], ('Beta', True))
        self.assertEqual(slots[3][:2], ('Gamma', False))

    def test_implicit_destructor_override_needs_checked_ancestor_slot(self):
        entry = {'slots': [(0, '~Derived', False, None, 'virtual ~Derived();')]}
        unchecked = bft.primary_slots(entry, {'Derived', 'Base'})
        checked = bft.primary_slots(entry, {'Derived', 'Base'}, {0})
        self.assertFalse(bft.class_checks(unchecked, [20], [10], [8], 8, True,
                                         'Base', 'Base')['passes'])
        self.assertTrue(bft.class_checks(checked, [20], [10], [8], 8, True,
                                        'Base', 'Base')['passes'])
        self.assertFalse(bft.class_checks(checked, [20], [10], [16], 8, True,
                                         'Base', 'Base')['passes'])
        self.assertFalse(bft.class_checks(checked, [20], [10], [8], 8, True,
                                         'WrongBase', 'Base')['passes'])
        entry['slots'] = [(0, 'Other', False, None, 'virtual void Other();')]
        self.assertFalse(bft.primary_slots(entry, {'Derived', 'Base'}, {0})[0][1])

    def test_checks(self):
        decl = bft.primary_slots(self.bodies['Derived'], {'Derived', 'Base'})
        parent = [10, 11, 12]
        own = [20, 11, 22, 23]
        ok = bft.class_checks(decl, own, parent, [0x20], 0x20, True, 'Base', 'Base')
        self.assertTrue(ok['passes'])
        self.assertEqual(ok['C3_pattern'], 'pass')
        self.assertEqual(ok['usable_slots'], [0, 2, 3])
        short = bft.class_checks(decl, own[:3], parent, [0x20], 0x20, True, 'Base', 'Base')
        self.assertFalse(short['C1_length'])
        self.assertFalse(short['passes'])
        grown = bft.class_checks(decl, own, parent + [13], [0x20], 0x20, True, 'Base', 'Base')
        self.assertFalse(grown['C2_range'])  # a new virtual inside the parent's table: shifted numbering
        size = bft.class_checks(decl, own, parent, [0x28], 0x20, True, 'Base', 'Base')
        self.assertFalse(size['C4_size'])
        self.assertFalse(size['passes'])
        base = bft.class_checks(decl, own, parent, [0x20], 0x20, True, 'Other', 'Base')
        self.assertFalse(base['base_chain'])
        same = bft.class_checks(decl, [20, 11, 12, 23], parent, [], None, True, 'Base', 'Base')
        self.assertEqual(same['C3_deviations'], 1)  # declared override still holds the parent's pointer
        self.assertNotIn(2, same['usable_slots'])

    def test_names(self):
        self.assertEqual(bft.demangle_type('.?AVInner@Outer@@'), 'Outer::Inner')
        self.assertEqual(bft.ng_style('.?AVInner@Outer@@'), 'Outer__Inner')
        self.assertTrue(bft.demangle_type('.?AV?$Foo@H@@').startswith('Foo<'))
        self.assertIsNone(bft.ng_style('.?AV?$Foo@H@@'))
        self.assertEqual(bft.area_of('NiCullingProcess'), 'netimmerse')
        self.assertEqual(bft.area_of('Character', ['Actor']), 'actors')
        self.assertEqual(bft.area_of('FireEffect', ['ActiveEffect']), 'magic')
        self.assertEqual(bft.area_of('hkpWorld'), 'havok')
        self.assertEqual(bft.area_of('Native', [], '.?AV?$Native@H@BSScript@@'), 'bsengine')
        self.assertTrue(bft.meh321_placeholder('Foo::Func12'))
        self.assertTrue(bft.meh321_placeholder('Foo::sub'))
        self.assertFalse(bft.meh321_placeholder('Foo::GetName'))


def synthetic_classes():
    base = {'class': 'Base', 'ng_key': 'Base', 'slots': [0x100, 0x110, 0x120], 'chain': ['.?AVBase@@'],
            'bases': [], 'parent': None, 'size': 0x10, 'community': {'po3': {'passes': True}},
            'slot_names': {'0': {'name': '~Base', 'source': 'po3-slot'}, '1': {'name': 'Alpha', 'source': 'ng-slot',
                                                                             'declaration': 'virtual bool Alpha() const;'}}}
    derived = {'class': 'Derived', 'ng_key': 'Derived', 'slots': [0x200, 0x110, 0x220, 0x230],
               'chain': ['.?AVDerived@@', '.?AVBase@@'], 'bases': ['.?AVBase@@'], 'parent': 'Base', 'size': 0x28,
               'community': {}, 'slot_names': {'3': {'name': 'Gamma', 'source': 'meh321'}}}
    return {'Base': base, 'Derived': derived}


class SkeletonTests(unittest.TestCase):
    def test_render(self):
        text = class_skeleton.render(synthetic_classes(), 'Derived',
                                     {'ng_revision': 'a' * 40, 'po3_revision': 'b' * 40, 'meh321_revision': 'c' * 12})
        self.assertIn('class Derived : public ::Base', text)
        self.assertIn('virtual ~Base();', text)
        self.assertIn('~Derived() override;', text)
        self.assertIn('void Unk_02() override;', text)  # override keeps the base's placeholder name
        self.assertIn('virtual void Gamma();', text)
        self.assertIn('static_assert(sizeof(Derived) == 0x28);', text)
        self.assertIn('std::uint8_t unk10[0x18];', text)
        self.assertIn('GPL-3.0', text)
        self.assertIn('permission as reported by the maintainer', text)
        self.assertIn('COMMUNITY(meh321/AddressLibrary@cccccccccccc, permission)', text)
        problems = lint.construct_problems('Derived.h', text) + \
            lint.label_problems('Derived.h', text, lint.leading_comment(text), '.h')
        self.assertEqual(problems, [])

    def test_unknown_class(self):
        with self.assertRaises(SystemExit):
            class_skeleton.render(synthetic_classes(), 'Missing')


def row(rva, cls, size=40, callers=3, eh=None, l1=None, verdict='supported', source='ng-slot', area_ok=True):
    return {'rva': rva, 'kind': 'ordinary', 'size': size, 'callers': callers, 'l1': l1 or f'k{rva}',
            'v2': {'verdict': verdict, 'reasons': [], 'cautions': []},
            'eh': {'handler_kind': 'c++' if eh else None, 'states': eh, 'try_blocks': 0},
            'owner': {'class': cls, 'how': 'vtable', 'slot': 1},
            'names': [{'name': f'{cls}::F{rva:x}', 'source': source, 'how': 'slot 1'}]}


class PlanTests(unittest.TestCase):
    def test_plan_prefers_passing_classes_fanin_and_eh_quota(self):
        classes = {'TESAlpha': {'passes': ['ng'], 'area': 'forms', 'slots': [1]},
                   'NiBeta': {'passes': ['po3'], 'area': 'netimmerse', 'slots': [1]},
                   'BSFail': {'passes': [], 'area': 'bsengine', 'slots': [1]}}
        rows = [row(0x100 + i, 'TESAlpha', callers=i) for i in range(6)]
        rows += [row(0x200 + i, 'NiBeta', callers=1) for i in range(5)]
        rows += [row(0x300 + i, 'BSFail', callers=40) for i in range(5)]
        rows += [row(0x400, 'NiBeta', eh=2), row(0x401, 'NiBeta', eh=9), row(0x402, 'TESAlpha', l1='k261', callers=50)]
        rows += [row(0x500, 'TESAlpha', verdict='unsupported')]
        opts = {'classes': 2, 'total': 8, 'eh': 1, 'max_eh_states': 3, 'min_functions': 2,
                'max_function_bytes': 500, 'max_classes_per_area': 2}
        order, picked, stats = ep.plan_from_table(rows, classes, set(), opts)
        self.assertEqual(set(order), {'TESAlpha', 'NiBeta'})
        rvas = [r['rva'] for fs in picked.values() for r in fs]
        self.assertEqual(len(rvas), 8)
        self.assertIn(0x400, rvas)  # the EH function with few states
        self.assertNotIn(0x401, rvas)
        self.assertFalse(set(rvas) & {0x300, 0x301, 0x500})
        self.assertIn(0x402, rvas)  # highest fan-in first ...
        self.assertNotIn(0x105, rvas)  # ... and one function per L1 cluster
        self.assertEqual(picked['TESAlpha'][0]['rva'], 0x402)
        self.assertEqual(stats['rejections']['class fails the per-class checks'], 5)

    def test_inventory_row(self):
        r = row(0x1234, 'TESAlpha', source='po3-slot')
        inv = ep.inventory_row(r, {'build_id': 'b', 'ng_revision': 'n', 'po3_revision': 'p'}, 'findings/x.md')
        self.assertEqual(inv['id'], 'b-0x1234')
        self.assertEqual(inv['status'], 'mapped')
        self.assertIn('GPL-3.0', inv['name_source'])


class ScopeTests(unittest.TestCase):
    def test_areas_partition_ordinary_functions(self):
        classes = {'TESAlpha': {'area': 'forms'}, 'hkpGamma': {'area': 'havok'}}
        rows = [row(1, 'TESAlpha', size=10), row(2, 'TESAlpha', size=20), row(3, 'hkpGamma', size=5),
                dict(row(4, 'X', size=7), owner=None), dict(row(5, 'TESAlpha', size=9), owner={'class': 'TESAlpha',
                                                                                              'how': 'rtti-adjacent'}),
                dict(row(6, 'TESAlpha', size=100), kind='eh-funclet')]
        blocks = {b['id']: b for b in bft.scope_areas(rows, classes)}
        self.assertEqual(sum(b['functions'] for b in blocks.values()), 5)
        self.assertEqual(sum(b['bytes'] for b in blocks.values()), 51)
        self.assertEqual(blocks['forms']['classes'][0], {'name': 'TESAlpha', 'functions': 2, 'bytes': 30,
                                                         'basis': 'measured'})
        self.assertEqual(blocks['havok']['treatment'], 'out_of_scope')
        self.assertEqual(blocks['unattributed']['adjacent_estimate']['functions'], 1)


class _FakeImg:
    """Minimal synthetic PE64 image for harvest_handlers unit tests (no game data)."""

    def __init__(self, rdata, data, text_size=0x10000):
        self._secs = [
            SimpleNamespace(name='.text', vaddr=0x1000, vsize=text_size, raw_ptr=0, raw_size=text_size,
                            flags=0x60000020),
            SimpleNamespace(name='.rdata', vaddr=0x20000, vsize=len(rdata), raw_ptr=text_size, raw_size=len(rdata),
                            flags=0x40000040),
            SimpleNamespace(name='.data', vaddr=0x40000, vsize=len(data), raw_ptr=text_size + len(rdata),
                            raw_size=len(data), flags=0xC0000040),
        ]
        self.blob = b'\x90' * text_size + bytes(rdata) + bytes(data)
        self.pe = SimpleNamespace(image_base=BASE, sections=self._secs)

    def section(self, rva):
        for s in self._secs:
            if s.vaddr <= rva < s.vaddr + s.vsize:
                return s
        return None


class HarvestHandlersTests(unittest.TestCase):
    def _build_table_image(self, n_good=22, include_gap=True, include_leading_space=True, include_shared=True):
        rdata = bytearray()
        strings = {}

        def add_str(s):
            if s not in strings:
                strings[s] = BASE + 0x20000 + len(rdata)
                rdata.extend(s.encode('ascii') + b'\0')
            return strings[s]

        records = []
        for i in range(n_good):
            nm = add_str(f'CmdAlpha{i}')
            ex = BASE + 0x2000 + i * 0x20
            cd = (BASE + 0x6000 + i * 0x20) if i < 3 else 0
            records.append((nm, ex, cd))
        if include_gap:
            records.append((add_str('UnusedSlot'), 0, 0))
        if include_leading_space:
            records.append((add_str(' TrimmedCmd'), BASE + 0x3000, 0))
        if include_shared:
            records.append((add_str('SharedA'), BASE + 0x3800, 0))
            records.append((add_str('SharedB'), BASE + 0x3800, 0))

        data = bytearray(0x40)  # leading padding
        for nm, ex, cd in records:
            rec = bytearray(0x50)
            struct.pack_into('<Q', rec, 0x00, nm)
            struct.pack_into('<Q', rec, 0x30, ex)
            struct.pack_into('<Q', rec, 0x40, cd)
            data.extend(rec)
        return _FakeImg(rdata, data)

    def test_harvest_script_functions_expands_gaps_and_skips_shared(self):
        img = self._build_table_image(n_good=22)
        out, stats = hh.harvest_script_functions(img, min_entries=20)
        self.assertEqual(stats['tables'], 1)
        self.assertEqual(out[0x2000]['name'], 'Cmd_CmdAlpha0')
        self.assertEqual(out[0x2000]['source'], 'exe-table')
        self.assertEqual(out[0x2000]['how'], 'script-exec')
        # Leading-space entry past the null gap is recovered
        self.assertEqual(out[0x3000]['name'], 'Cmd_TrimmedCmd')
        # Condition function at +0x40 is recovered
        self.assertEqual(out[0x6000]['name'], 'Cond_CmdAlpha0')
        self.assertEqual(out[0x6000]['how'], 'script-cond')
        # Shared handler is excluded
        self.assertNotIn(0x3800, out)
        self.assertEqual(bft.community_label('exe-table', {}), 'OBSERVED')

    def test_harvest_script_functions_rejects_below_threshold(self):
        img = self._build_table_image(n_good=10, include_gap=False, include_leading_space=False, include_shared=False)
        out, stats = hh.harvest_script_functions(img, min_entries=20)
        self.assertEqual(out, {})
        self.assertEqual(stats['tables'], 0)

    def test_disasm_records_reg_calls_and_respects_clobbers(self):
        lines = [
            line(0x1000, 'lea', 'rcx, [rip + 0x1ef00]  # 0x140020000'),
            line(0x1007, 'lea', 'rdx, [rip + 0x1f00]  # 0x140003000'),
            line(0x100e, 'call', '0x140002000 <reg>'),
            line(0x1013, 'lea', 'rcx, [rip + 0x1ef00]  # 0x140020000'),
            line(0x101a, 'mov', 'rcx, rax'),  # clobbers rcx
            line(0x101d, 'lea', 'rdx, [rip + 0x1f00]  # 0x140003000'),
            line(0x1024, 'call', '0x140002000 <reg>'),
            line(0x1029, 'ret'),
            line(0x2000, 'ret'),
            line(0x3000, 'ret'),
        ]
        fns = {0x1000: [(0x1000, 0x102a)], 0x2000: [(0x2000, 0x2001)], 0x3000: [(0x3000, 0x3001)]}
        d = bft.DisasmPass(fns, BASE).feed(lines)
        self.assertEqual(len(d['reg_calls']), 1)
        callsite, caller, callee, targets = d['reg_calls'][0]
        self.assertEqual((callsite, caller, callee), (0x100e, 0x1000, 0x2000))
        self.assertEqual(targets, {0: 0x20000, 1: 0x3000})

    def test_harvest_registrations_enforces_threshold_and_1to1(self):
        rdata = bytearray()
        str_rvas = []
        for i in range(24):
            str_rvas.append(0x20000 + len(rdata))
            rdata.extend(f'FactoryType{i}'.encode('ascii') + b'\0')
        img = _FakeImg(rdata, b'\0' * 0x40)
        entries = {0x2000} | {0x3000 + i * 0x20 for i in range(24)}
        reg_calls = []
        for i in range(22):
            reg_calls.append((0x1000 + i * 0x10, 0x1000, 0x2000, {0: str_rvas[i], 1: 0x3000 + i * 0x20}))
        # Two names sharing one handler (0x3400) must be excluded
        entries.add(0x3400)
        reg_calls.append((0x1500, 0x1000, 0x2000, {0: str_rvas[22], 1: 0x3400}))
        reg_calls.append((0x1510, 0x1000, 0x2000, {0: str_rvas[23], 1: 0x3400}))
        # A second callee with fewer than 20 sites must be rejected
        entries.add(0x2100)
        for i in range(5):
            reg_calls.append((0x1800 + i * 0x10, 0x1800, 0x2100, {0: str_rvas[i], 1: 0x3000 + i * 0x20}))
        out, stats = hh.harvest_registrations(img, reg_calls, entries, min_sites=20)
        self.assertEqual(stats['callees'], 1)
        self.assertNotIn(0x3400, out)
        # Entries 0..4 also appear in callee 0x2100 with the same name<->handler pair, so still globally 1-to-1
        self.assertEqual(len(out), 22)
        self.assertEqual(out[0x3000]['name'], 'FactoryType0')
        self.assertEqual(out[0x3000]['source'], 'exe-reg')
        self.assertEqual(bft.community_label('exe-reg', {}), 'OBSERVED')


if __name__ == '__main__':
    unittest.main()
