import json
import posixpath
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import digest_v2  # noqa: E402
import migrate_layout as ml  # noqa: E402
import source_digest  # noqa: E402
import source_moves  # noqa: E402
import unit_paths as up  # noqa: E402

HEAD = '// Source exposure: black-box\n// Labels: v2\n'


def unit(cls, includes=()):
    inc = ''.join(f'#include "{i}"\n' for i in includes)
    header = f'{HEAD}#pragma once\n{inc}class {cls} {{ public: int x; }};\n'
    cpp = f'{HEAD}// 0x1000 {cls}::F\n#include "{cls}.h"\nint {cls}_f() {{ return 1; }}\n'
    return header, cpp


class UnitPathTests(unittest.TestCase):
    def test_classes_land_in_subsystem_areas(self):
        for cls, area in (('NiNode', 'gamebryo/nimain'), ('NiBlendFloatInterpolator', 'gamebryo/nianimation'),
                          ('BSFixedString', 'bscore'), ('TESObjectREFR', 'skyrim_shared/refs'),
                          ('ExtraDataList', 'skyrim_shared/extradata'), ('CombatTargetSelector', 'skyrim/ai/combat'),
                          ('PlayerCharacterTyped', 'skyrim_shared/actors'), ('BSImagespaceShaderBlur3', 'bsshader'),
                          ('ComplexPass', 'skyrim_shared/forms')):
            self.assertEqual(up.unit_dir(cls), area, cls)
        self.assertEqual(up.unit_dir('ZzUnknownThing'), None)

    def test_layout_suffixes_and_families(self):
        self.assertEqual(up.owner_of('ActivateHandlerStorageLayout'), 'ActivateHandler')
        self.assertEqual(up.owner_of('Layout'), 'Layout')
        self.assertEqual(up.family_dir('Static17b64c0'), 'unmapped/static')
        self.assertEqual(up.family_dir('DeletingLeaf1069aa0'), 'unmapped/leaves')
        self.assertIsNone(up.family_dir('TESForm'))

    def test_every_rule_names_a_listed_area(self):
        self.assertLessEqual({area for _p, area in up.RULES}, set(up.AREAS))
        self.assertLessEqual(set(up.BULK_DIRS.values()) | {d for _p, d in up.FAMILY_DIRS}, set(up.AREAS))

    def test_area_accepted(self):
        for area in ('skyrim/ai/combat', 'declarations', 'netimmerse', 'contrib_magicitem', 'fo4p198c_bound'):
            self.assertTrue(up.area_accepted(area), area)
        for area in ('misc', 'skyrim/anything', 'brand_new_area'):
            self.assertFalse(up.area_accepted(area), area)


class MigrationTests(unittest.TestCase):
    def setUp(self):
        self.root = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.root)
        self.files = {}

    def put(self, area, cls, includes=(), only_header=False):
        header, cpp = unit(cls, includes)
        (self.root / 'reconstruction' / area).mkdir(parents=True, exist_ok=True)
        (self.root / f'reconstruction/{area}/{cls}.h').write_text(header)
        if not only_header:
            (self.root / f'reconstruction/{area}/{cls}.cpp').write_text(cpp)

    def digests(self, mapping=None):
        out = {}
        for cpp in sorted((self.root / 'reconstruction').rglob('*.cpp')):
            rel = cpp.relative_to(self.root).as_posix()
            closure = source_digest.include_closure(self.root, rel)
            out[rel] = digest_v2.tu_digest(self.root, closure)
        return out

    def test_move_keeps_digests_and_resolves_every_include(self):
        self.put('forms', 'TESForm')
        self.put('forms', 'TESObjectREFR', includes=['TESForm.h'])
        self.put('actors', 'Actor', includes=['../forms/TESObjectREFR.h'])
        self.put('netimmerse', 'NiNode')
        self.put('small1_abc', 'TESForm')
        before = self.digests()
        plan = ml.make_plan(self.root, [])
        ml.apply_plan(self.root, plan)
        after = self.digests()
        self.assertEqual(sorted(before.values()), sorted(after.values()))
        for old, new in plan['new_of'].items():
            if old.endswith('.cpp'):
                self.assertEqual(before[old], after[new], old)
        new = plan['new_of']
        self.assertEqual(new['reconstruction/forms/TESForm.cpp'], 'reconstruction/skyrim_shared/forms/TESForm.cpp')
        # The second unit of a split class is named for its lowest rva, or a hash of its folder.
        self.assertRegex(new['reconstruction/small1_abc/TESForm.cpp'],
                         r'reconstruction/skyrim_shared/forms/TESForm_[0-9a-f]{3,8}\.cpp')
        text = (self.root / new['reconstruction/actors/Actor.h']).read_text()
        self.assertIn('#include "../refs/TESObjectREFR.h"', text)
        self.assertFalse((self.root / 'reconstruction/forms').exists())

    def test_a_second_run_moves_nothing_that_already_moved(self):
        self.put('forms', 'TESForm')
        self.put('bsengine', 'BSTimer')
        ml.apply_plan(self.root, ml.make_plan(self.root, []))
        self.assertEqual(ml.make_plan(self.root, [])['new_of'], {})
        self.put('bsengine', 'BSFixedString')
        again = ml.make_plan(self.root, [])
        self.assertEqual(list(again['new_of'].values()),
                         ['reconstruction/bscore/BSFixedString.cpp', 'reconstruction/bscore/BSFixedString.h'])

    def test_include_closure_survives_a_split_unit(self):
        self.put('forms', 'TESForm')
        self.put('small1_abc', 'TESForm')
        plan = ml.make_plan(self.root, [])
        ml.apply_plan(self.root, plan)
        tagged = plan['new_of']['reconstruction/small1_abc/TESForm.cpp']
        stem = posixpath.basename(tagged)[:-4]
        self.assertEqual(source_digest.include_closure(self.root, tagged), [tagged, tagged[:-4] + '.h'])
        self.assertIn(f'#include "{stem}.h"', (self.root / tagged).read_text())

    def test_pinned_files_and_what_they_include_stay(self):
        self.put('contrib_x', 'TESForm', includes=['TESBase.h'])
        self.put('contrib_x', 'TESBase', only_header=True)
        self.put('forms', 'TESOther')
        plan = ml.make_plan(self.root, ['reconstruction/contrib_x/TESForm.h'])
        self.assertEqual(sorted(plan['pinned']), ['reconstruction/contrib_x/TESBase.h',
                                                  'reconstruction/contrib_x/TESForm.cpp',
                                                  'reconstruction/contrib_x/TESForm.h'])
        ml.apply_plan(self.root, plan)
        self.assertTrue((self.root / 'reconstruction/contrib_x/TESForm.h').is_file())
        self.assertTrue((self.root / 'reconstruction/skyrim_shared/forms/TESOther.cpp').is_file())

    def test_unmapped_folders_move_whole_and_the_map_reads_back(self):
        self.put('static', 'Static17b64c0')
        self.put('leaves', 'DeletingLeaf1069aa0')
        self.put('forms', 'TESForm')
        plan = ml.make_plan(self.root, [])
        ml.apply_plan(self.root, plan)
        (self.root / 'data').mkdir()
        ml.update_moves(self.root, plan)
        moves = json.loads((self.root / source_moves.MOVES).read_text())
        self.assertEqual(moves['dirs'], {'reconstruction/leaves': 'reconstruction/unmapped/leaves',
                                         'reconstruction/static': 'reconstruction/unmapped/static'})
        source_moves._load.cache_clear()
        self.assertEqual(source_moves.old_path('reconstruction/unmapped/static/Static17b64c0.cpp', self.root),
                         'reconstruction/static/Static17b64c0.cpp')
        self.assertEqual(source_moves.old_path('reconstruction/skyrim_shared/forms/TESForm.cpp', self.root),
                         'reconstruction/forms/TESForm.cpp')
        self.assertEqual(source_moves.accepted_paths('reconstruction/gamebryo/nimain/NiNode.cpp', self.root),
                         {'reconstruction/gamebryo/nimain/NiNode.cpp'})

    def test_a_file_that_puts_its_path_into_the_code_is_refused(self):
        self.put('forms', 'TESForm')
        cpp = self.root / 'reconstruction/forms/TESForm.cpp'
        cpp.write_text(cpp.read_text() + 'const char* f() { return __FILE__; }\n')
        plan = ml.make_plan(self.root, [])
        with self.assertRaises(ml.Refusal):
            ml.apply_plan(self.root, plan, dry=True)

    def test_record_paths_are_edited_in_place(self):
        record = ('{\n  "build": {\n    "hosts": {\n      "h": {\n        "repository_files_opened": [\n'
                  '          "reconstruction/forms/B.cpp",\n          "reconstruction/forms/B.h"\n        ]\n'
                  '      }\n    }\n  },\n  "family_parameters": {\n    "compiled": "reconstruction/forms/B.cpp"\n  },\n'
                  '  "source": {\n    "compiled": "reconstruction/forms/B.cpp",\n    "digest": "x",\n'
                  '    "translation_unit": [\n      "reconstruction/forms/B.cpp",\n      "reconstruction/forms/B.h"\n'
                  '    ]\n  }\n}\n')
        moved = {'reconstruction/forms/B.cpp': 'reconstruction/skyrim/ai/B.cpp',
                 'reconstruction/forms/B.h': 'reconstruction/skyrim/ai/B.h'}
        out = json.loads(ml.rewrite_record(record, moved))
        self.assertEqual(out['source']['compiled'], 'reconstruction/skyrim/ai/B.cpp')
        self.assertEqual(out['source']['translation_unit'],
                         ['reconstruction/skyrim/ai/B.cpp', 'reconstruction/skyrim/ai/B.h'])
        self.assertEqual(out['build']['hosts']['h']['repository_files_opened'],
                         ['reconstruction/skyrim/ai/B.cpp', 'reconstruction/skyrim/ai/B.h'])
        # A family's own parameters are bound into its member digest and stay as recorded.
        self.assertEqual(out['family_parameters']['compiled'], 'reconstruction/forms/B.cpp')


if __name__ == '__main__':
    unittest.main()
