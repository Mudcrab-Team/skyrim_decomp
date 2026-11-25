import sys
import tempfile
import unittest
import zipfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import papyrus_psc as psc  # noqa: E402

SAMPLE = '''Scriptname Widget extends Form Hidden Conditional
{A doc string with Function Fake() native in it.}

; Function Commented() native
;/ block comment
Function InBlock() native
/;
Int Function GetCount(Form akThing, Int aiLimit = 5, String asLabel = "a; b, c") native
Float[] Function Samples(Widget[] akWidgets, Bool abFlag) global native
Function Notify(Form akSender, \\
    Int aiCode, \\
    Float afValue = 1.5) global native
Event OnTick(Float afDelta) native
Bool Function Plain(Int aiValue)
    return aiValue > 0
EndFunction
Function Latency(Float afSeconds) global native latent
Property Size Auto
'''


class PapyrusParserTests(unittest.TestCase):
    def test_script_header(self):
        s = psc.parse_script(SAMPLE)
        self.assertEqual((s.name, s.parent), ('Widget', 'Form'))
        self.assertEqual(s.flags, frozenset({'hidden', 'conditional'}))

    def test_comments_and_docstrings_are_not_declarations(self):
        names = [c.name for c in psc.parse_script(SAMPLE).callables]
        self.assertNotIn('Fake', names)
        self.assertNotIn('Commented', names)
        self.assertNotIn('InBlock', names)

    def test_native_selection_and_flags(self):
        s = psc.parse_script(SAMPLE)
        self.assertEqual([c.name for c in s.natives], ['GetCount', 'Samples', 'Notify', 'OnTick', 'Latency'])
        by = {c.name: c for c in s.natives}
        self.assertTrue(by['Samples'].is_global)
        self.assertFalse(by['GetCount'].is_global)
        self.assertIn('latent', by['Latency'].flags)
        self.assertEqual(by['OnTick'].kind, 'event')
        self.assertEqual(by['OnTick'].returns, '')

    def test_returns_arrays_and_params(self):
        by = {c.name: c for c in psc.parse_script(SAMPLE).natives}
        self.assertEqual((by['Samples'].returns, by['Samples'].returns_array), ('Float', True))
        self.assertEqual(by['Samples'].signature(), 'Float[] Samples(Widget[] akWidgets, Bool abFlag)')
        self.assertTrue(by['Samples'].params[0].array)
        self.assertFalse(by['Samples'].params[1].array)

    def test_defaults_with_separators_do_not_split(self):
        c = {c.name: c for c in psc.parse_script(SAMPLE).natives}['GetCount']
        self.assertEqual([p.name for p in c.params], ['akThing', 'aiLimit', 'asLabel'])
        self.assertEqual([p.has_default for p in c.params], [False, True, True])

    def test_continuation_lines_join(self):
        c = {c.name: c for c in psc.parse_script(SAMPLE).natives}['Notify']
        self.assertEqual([p.name for p in c.params], ['akSender', 'aiCode', 'afValue'])
        self.assertTrue(c.is_global)

    def test_case_is_folded_for_keywords(self):
        s = psc.parse_script('SCRIPTNAME Loud EXTENDS Quiet\nINT FUNCTION Shout() GLOBAL NATIVE\n')
        self.assertEqual(s.parent, 'Quiet')
        c = s.natives[0]
        self.assertTrue(c.is_global)
        self.assertEqual(c.returns, 'INT')

    def test_no_scriptname(self):
        self.assertIsNone(psc.parse_script('Function Stray() native\n'))

    def test_archive_summary_and_table(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'pack.zip'
            with zipfile.ZipFile(path, 'w') as z:
                z.writestr('Widget.psc', SAMPLE)
                z.writestr('Other.psc', 'Scriptname Other\nFunction Nothing()\nEndFunction\n')
                z.writestr('readme.txt', 'ignored')
            scripts, stats = psc.scan_archive(path)
            self.assertEqual((stats['members'], stats['parsed']), (2, 2))
            info = psc.summary(scripts, stats)
            self.assertEqual(info['native_callables'], 5)
            self.assertEqual(info['native_events'], 1)
            self.assertEqual(info['global'], 3)
            self.assertEqual(info['array_returns'], 1)
            table = psc.native_table(scripts)
            self.assertEqual(list(table), ['widget'])
            self.assertEqual(len(table['widget']['natives']), 5)


if __name__ == '__main__':
    unittest.main()
