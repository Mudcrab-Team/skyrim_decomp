"""Repair of stand-in twins whose body hands `this` to a parameter of the real class."""
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/twins'))
import twin_this

POINTER = ("    reconstruction/area/Owner1.cpp(4): error C2664: 'bool TESFile::Load(TESForm *)': "
           "cannot convert argument 1 from 'Owner1 *' to 'TESForm *'\n")
REFERENCE = ("reconstruction/area/Owner1.cpp(4): error C2664: 'int Visitor::Visit(Node &)': "
             "cannot convert argument 1 from 'Owner1' to 'Node &'\n")


class TwinThisTests(unittest.TestCase):
    def test_diagnostics_are_read_as_pointer_and_reference_conversions(self):
        self.assertEqual(twin_this.conversions(POINTER), [('reconstruction/area/Owner1.cpp', 4, 1, 'TESForm', 'pointer')])
        self.assertEqual(twin_this.conversions(REFERENCE), [('reconstruction/area/Owner1.cpp', 4, 1, 'Node', 'reference')])

    def test_other_conversions_are_left_alone(self):
        text = ("reconstruction/a/Owner1.cpp(4): error C2664: 'void F(int)': "
                "cannot convert argument 1 from 'Owner1 *' to 'int'\n")
        self.assertEqual(twin_this.conversions(text), [])

    def test_only_the_rejected_argument_is_cast(self):
        self.assertEqual(twin_this.patch('    return file.Load(this);', 1, 1, 'TESForm', 'pointer'),
                         '    return file.Load(reinterpret_cast<TESForm*>(this));')
        self.assertEqual(twin_this.patch('    return v.Visit(*this);', 1, 1, 'Node', 'reference'),
                         '    return v.Visit(*reinterpret_cast<Node*>(this));')
        self.assertEqual(twin_this.patch('    F(this, other);', 1, 2, 'X', 'pointer'), None)
        self.assertEqual(twin_this.patch('    F(a, this);', 1, 2, 'X', 'pointer'), '    F(a, reinterpret_cast<X*>(this));')
        self.assertIsNone(twin_this.patch('    F(this, this);', 1, 1, 'X', 'pointer'))

    def test_repair_edits_the_unit_text_once(self):
        files = {'area/Owner1.cpp': '#include "Owner1.h"\nbool Owner1::Load(TESFile& file)\n{\n    return file.Load(this);\n}\n'}
        self.assertEqual(twin_this.repair(files, POINTER), 1)
        self.assertIn('reinterpret_cast<TESForm*>(this)', files['area/Owner1.cpp'])
        self.assertEqual(twin_this.repair(files, POINTER), 0)

    def test_latest_log_reads_the_newest_attempt(self):
        with tempfile.TemporaryDirectory() as tmp:
            task = Path(tmp)
            for number, text in (('001', 'old'), ('002', 'new')):
                (task / 'attempts' / number).mkdir(parents=True)
                (task / 'attempts' / number / 'compile.log').write_text(text)
            self.assertEqual(twin_this.latest_log(task), 'new')
            self.assertEqual(twin_this.latest_log(task / 'missing'), '')


if __name__ == '__main__':
    unittest.main()
