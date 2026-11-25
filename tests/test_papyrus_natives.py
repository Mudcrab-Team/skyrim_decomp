"""Registration scanner, type decoding and the declaration join on synthetic inputs.
No game data: every listing, string, class name and declaration below is invented."""
from pathlib import Path
import sys
from types import SimpleNamespace
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools' / 'ghidra'))
import harvest_handlers as hh  # noqa: E402
import papyrus_natives as pn  # noqa: E402

BASE = 0x140000000


def line(addr, mnemonic, ops=''):
    return f'{BASE + addr:x}:     \t{mnemonic}\t{ops}\n'


class FakeImage:
    """Executable at 0x1000..0x11000, strings in a read-only section at 0x20000."""

    def __init__(self, strings):
        rdata = bytearray()
        self.at = {}
        for s in strings:
            self.at[s] = 0x20000 + len(rdata)
            rdata.extend(s.encode() + b'\0')
        text = 0x10000
        self.sections = [
            SimpleNamespace(name='.text', vaddr=0x1000, vsize=text, raw_ptr=0, raw_size=text, flags=0x60000020),
            SimpleNamespace(name='.rdata', vaddr=0x20000, vsize=len(rdata), raw_ptr=text, raw_size=len(rdata),
                            flags=0x40000040),
        ]
        self.blob = b'\x90' * text + bytes(rdata)
        self.pe = SimpleNamespace(image_base=BASE, sections=self.sections)

    def section(self, rva):
        for s in self.sections:
            if s.vaddr <= rva < s.vaddr + s.vsize:
                return s
        return None


def registration(base_addr, func, name, script, handler, vtable, callee=0x3000):
    """The shape a registering function takes: strings and a table address are loaded, the base
    constructor is called, then the table and handler addresses are stored into the new object."""
    return [
        line(base_addr + 0x00, 'lea', f'r13, [rip + 0x1000]  # 0x{BASE + vtable:x}'),
        line(base_addr + 0x07, 'lea', f'r8, [rip + 0x1000]  # 0x{BASE + script:x}'),
        line(base_addr + 0x0e, 'lea', f'rdx, [rip + 0x1000]  # 0x{BASE + name:x}'),
        line(base_addr + 0x15, 'mov', 'rcx, rax'),
        line(base_addr + 0x18, 'call', f'0x{BASE + callee:x} <f>'),
        line(base_addr + 0x1d, 'mov', 'qword ptr [rbx], r13'),
        line(base_addr + 0x21, 'lea', f'rax, [rip + 0x10]  # 0x{BASE + handler:x}'),
        line(base_addr + 0x28, 'mov', 'qword ptr [rbx + 0x50], rax'),
        line(base_addr + 0x2c, 'ret'),
    ]


NATIVES = {
    'widget': {'name': 'Widget', 'natives': [
        {'name': 'Spin', 'kind': 'function', 'returns': 'Bool', 'returns_array': False, 'global': False,
         'latent': False, 'params': [['Int', False, 'aiTurns', False], ['String', False, 'asLabel', False]]},
        {'name': 'Count', 'kind': 'function', 'returns': '', 'returns_array': False, 'global': True,
         'latent': False, 'params': []}]}}


class ScannerTests(unittest.TestCase):
    def setUp(self):
        self.img = FakeImage(['Spin', 'Widget', 'Count', 'Unrelated'])
        s = self.img.at
        lines = (registration(0x5000, 0x5000, s['Spin'], s['Widget'], 0x6000, 0x20010)
                 + registration(0x5100, 0x5100, s['Count'], s['Widget'], 0x6100, 0x20010))
        self.scanner = hh.RegistrationSiteScanner(BASE, entries={0x5000, 0x5100, 0x3000})
        self.sites = self.scanner.feed(lines)

    def test_sites_carry_argument_addresses_and_stores(self):
        self.assertEqual(len(self.sites), 2)
        site = self.sites[0]
        self.assertEqual(site['callee'], 0x3000)
        self.assertEqual(sorted(site['args']), [1, 2])
        self.assertIn((0, 0x20010), site['stores'])
        self.assertIn((0x50, 0x6000), site['stores'])

    def test_join_pairs_strings_with_declarations(self):
        rows, stats = hh.harvest_native_registrations(self.img, self.sites, NATIVES, {0x20010: 'NativeThing'})
        by = {r['function']: r for r in rows}
        self.assertEqual(set(by), {'Spin', 'Count'})
        self.assertEqual(by['Spin']['handler'], 0x6000)
        self.assertEqual(by['Spin']['native_class'], 'NativeThing')
        self.assertEqual(stats['resolved'], 2)

    def test_undeclared_pair_is_not_a_registration(self):
        rows, _ = hh.harvest_native_registrations(self.img, self.sites, {'other': NATIVES['widget']})
        self.assertEqual(rows, [])

    def test_a_handler_claimed_by_two_pairs_is_dropped(self):
        shared = registration(0x7000, 0x7000, self.img.at['Count'], self.img.at['Widget'], 0x6000, 0x20010)
        sites = self.sites + hh.RegistrationSiteScanner(BASE, {0x7000, 0x3000}).feed(shared)
        rows, stats = hh.harvest_native_registrations(self.img, sites, NATIVES)
        self.assertEqual([r['function'] for r in rows], ['Count'])
        self.assertEqual(stats['shared_handlers'], 2)

    def test_handler_passed_as_argument_and_vtable_from_constructor(self):
        s = self.img.at
        lines = [line(0x5400, 'lea', f'r9, [rip + 0x1]  # 0x{BASE + 0x6400:x}'),
                 line(0x5407, 'lea', f'r8, [rip + 0x1]  # 0x{BASE + s["Widget"]:x}'),
                 line(0x540e, 'lea', f'rdx, [rip + 0x1]  # 0x{BASE + s["Spin"]:x}'),
                 line(0x5415, 'call', f'0x{BASE + 0x3100:x} <ctor>'),
                 line(0x541a, 'ret'),
                 line(0x3100, 'lea', f'rax, [rip + 0x1]  # 0x{BASE + 0x20018:x}'),
                 line(0x3107, 'mov', 'qword ptr [rcx], rax'),
                 line(0x310a, 'ret')]
        scanner = hh.RegistrationSiteScanner(BASE, {0x5400, 0x3100})
        sites = scanner.feed(lines)
        self.assertEqual(dict(scanner.ctor_vtables), {0x3100: {0x20018}})
        rows, _ = hh.harvest_native_registrations(self.img, sites, NATIVES, {0x20018: 'Cls'}, scanner.ctor_vtables)
        self.assertEqual((rows[0]['handler'], rows[0]['native_class']), (0x6400, 'Cls'))

    def test_calls_clear_volatile_registers_only(self):
        s = self.img.at
        lines = [line(0x5500, 'lea', f'r13, [rip + 0x1]  # 0x{BASE + 0x20010:x}'),
                 line(0x5507, 'lea', f'rdx, [rip + 0x1]  # 0x{BASE + s["Spin"]:x}'),
                 line(0x550e, 'call', f'0x{BASE + 0x3000:x} <helper>'),
                 line(0x5513, 'lea', f'r8, [rip + 0x1]  # 0x{BASE + s["Widget"]:x}'),
                 line(0x551a, 'call', f'0x{BASE + 0x3000:x} <ctor>'),
                 line(0x551f, 'mov', 'qword ptr [rbx], r13'),
                 line(0x5522, 'ret')]
        sites = hh.RegistrationSiteScanner(BASE, {0x5500, 0x3000}).feed(lines)
        self.assertEqual(len(sites), 0)  # rdx was lost across the first call, so only one argument is known


class TypeDecodingTests(unittest.TestCase):
    def test_primitives_pointers_and_back_references(self):
        # Self = Widget, R = bool, args = Item*, const Label&, Item* (back reference to entry 3), int
        t = pn.decode_template_types('VWidget@@_NPEAVItem@@AEBVLabel@@PEAV2@H', 4)
        self.assertEqual(t, ['Widget', 'bool', 'Item*', 'Label const&', 'Item*', 'std::int32_t'])

    def test_namespaced_static_tag(self):
        t = pn.decode_template_types('UStaticFunctionTag@Ns@@X', 0)
        self.assertEqual(t, ['Ns::StaticFunctionTag', 'void'])

    def test_unknown_forms_return_none(self):
        self.assertIsNone(pn.decode_template_types('V?$Box@H@@X', 0))
        self.assertIsNone(pn.decode_template_types('VWidget@@X', 3))

    def test_class_name(self):
        info = pn.native_class_types('NativeFunction2<VWidget@@_NHM@BSScript>')
        self.assertEqual(info, {'self': 'Widget', 'ret': 'bool', 'args': ['std::int32_t', 'float']})
        self.assertIsNone(pn.native_class_types('SomethingElse<VWidget@@X@Ns>'))


class AgreementTests(unittest.TestCase):
    DECL = NATIVES['widget']['natives'][0]

    def test_agree_and_typed_prototype(self):
        native = {'self': 'Widget', 'ret': 'bool', 'args': ['std::int32_t', 'BSFixedString const&']}
        self.assertEqual(pn.agreement(self.DECL, native), 'agree')
        self.assertEqual(pn.typed_prototype(native, self.DECL),
                         'bool (Widget* self, std::int32_t aiTurns, BSFixedString const& asLabel)')

    def test_each_kind_of_disagreement(self):
        base = {'self': 'Widget', 'ret': 'bool', 'args': ['std::int32_t', 'BSFixedString const&']}
        self.assertEqual(pn.agreement(self.DECL, dict(base, args=['std::int32_t'])), 'arity')
        self.assertEqual(pn.agreement(self.DECL, dict(base, ret='float')), 'return')
        self.assertEqual(pn.agreement(self.DECL, dict(base, args=['float', 'BSFixedString const&'])), 'argument 0')
        self.assertEqual(pn.agreement(self.DECL, None), 'no-class')


class FamilyTests(unittest.TestCase):
    CLASSES = [
        {'class': 'BSScript::NF_util::NativeFunctionBase', 'slots': [1, 2, 3, 4]},
        {'class': 'NativeFunction0<VWidget@@X@BSScript>', 'slots': [10, 2, 3, 40]},
        {'class': 'NativeFunction0<VGadget@@X@BSScript>', 'slots': [11, 2, 3, 41]},
        {'class': 'Unrelated', 'slots': [99, 98]},
    ]

    def test_own_slots_are_counted_against_the_base(self):
        info = pn.family_counts(self.CLASSES, matched={10, 11})
        self.assertEqual(info['native_function_classes'], 2)
        self.assertEqual(info['native_function_classes_decoded'], 2)
        self.assertEqual(info['native_function_own_slots']['0'], {'instances': 2, 'distinct_functions': 2, 'matched': 2})
        self.assertEqual(info['native_function_own_slots']['3'], {'instances': 2, 'distinct_functions': 2, 'matched': 0})
        self.assertNotIn('1', info['native_function_own_slots'])

    def test_shape_groups_cluster_by_masked_key(self):
        import json
        import tempfile
        rows = [{'rva': 40, 'l1': 'a', 'size': 100}, {'rva': 41, 'l1': 'a', 'size': 100},
                {'rva': 7, 'l1': 'z', 'size': 5}]
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'functions.jsonl'
            path.write_text('\n'.join(json.dumps(r) for r in rows) + '\n')
            info = pn.shape_groups(self.CLASSES, path, slot=3)
        self.assertEqual(info, {'slot': 3, 'functions': 2, 'shape_groups': 1, 'in_groups_of_two_or_more': 2,
                                'largest_group': 2, 'size_min': 100, 'size_max': 100})


class LeadTests(unittest.TestCase):
    def test_crashlogger_lead_forms(self):
        names = {1: 'papyrus::Widget::Spin', 2: 'papyrus__Widget::Count_1409B1A80', 3: 'Other::Spin',
                 4: 'papyrus::Widget::Spin_HBA60'}
        self.assertEqual(pn.cl_script_leads(names),
                         {1: ('Widget', 'Spin'), 2: ('Widget', 'Count'), 4: ('Widget', 'Spin')})

    def test_join_counts_and_lead_agreement(self):
        img = FakeImage(['Spin', 'Widget'])
        s = img.at
        sites = hh.RegistrationSiteScanner(BASE, {0x5000, 0x3000}).feed(
            registration(0x5000, 0x5000, s['Spin'], s['Widget'], 0x6000, 0x20010))
        rows, stats, leads = pn.join(sites, NATIVES, img, {0x20010: 'NativeFunction2<VWidget@@_NHPEAV1@@BSScript>'},
                                     {0x6000}, {0x6000: 'papyrus::Widget::Spin'})
        self.assertEqual(len(rows), 1)
        r = rows[0]
        self.assertTrue(r['matched'])
        self.assertTrue(r['cl_lead_agrees'])
        counts = pn.count(rows, leads, NATIVES, {0x6000})
        self.assertEqual(counts['crashlogger_leads_confirmed'], 1)
        self.assertEqual(counts['handlers_already_matched'], 1)


if __name__ == '__main__':
    unittest.main()
