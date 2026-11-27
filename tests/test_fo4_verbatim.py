"""Synthetic fixtures for the local-only verbatim-run guard."""
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import fo4_verbatim as guard

REFERENCE = '\n'.join(f'    value{i} = compute(value{i - 1}, {i});' for i in range(1, 14)) + '\n'


def toy_clone(tmp):
    clone = Path(tmp) / 'clone'
    (clone / 'src/Gamebryo/Core').mkdir(parents=True)
    (clone / 'src/Game/AI').mkdir(parents=True)
    (clone / 'src/Gamebryo/Core/Toy.cpp').write_text('void Toy()\n{\n' + REFERENCE + '}\n')
    (clone / 'src/Game/AI/Plain.cpp').write_text('void Plain()\n{\n' + REFERENCE.replace('compute', 'other') + '}\n')
    (clone / 'src/Game/AI/Sdk.cpp').write_text('#include "Havok/Source/Toy.h"\nvoid Sdk()\n{\n' + REFERENCE.replace('compute', 'third') + '}\n')
    subprocess.run(['git', '-C', str(clone), 'init', '-q'], check=True)
    subprocess.run(['git', '-C', str(clone), 'add', '.'], check=True)
    return clone


class Verbatim(unittest.TestCase):
    def test_reference_files_are_gamebryo_and_sdk_includers_only(self):
        with tempfile.TemporaryDirectory() as tmp:
            files = sorted(guard.reference_files(toy_clone(tmp)))
        self.assertEqual(files, ['src/Game/AI/Sdk.cpp', 'src/Gamebryo/Core/Toy.cpp'])

    def test_long_run_is_flagged_and_short_run_is_not(self):
        with tempfile.TemporaryDirectory() as tmp:
            index = guard.reference_index(toy_clone(tmp))
        copied = 'int Ours()\n{\n' + REFERENCE + '}\n'
        self.assertEqual(len(guard.check_text(copied, index)), 1)
        short = 'int Ours()\n{\n' + '\n'.join(REFERENCE.splitlines()[:7]) + '\n}\n'
        self.assertEqual(guard.check_text(short, index), [])
        reworded = REFERENCE.replace('compute', 'combine').replace('value', 'item')
        self.assertEqual(guard.check_text('int Ours()\n{\n' + reworded + '}\n', index), [])

    def test_whitespace_changes_do_not_hide_a_copy(self):
        with tempfile.TemporaryDirectory() as tmp:
            index = guard.reference_index(toy_clone(tmp))
        spaced = '\n'.join('\t' + l.strip().replace(' = ', '  =  ') for l in REFERENCE.splitlines())
        self.assertEqual(len(guard.check_text(spaced, index)), 1)

    def test_skipped_in_ci_and_without_clone(self):
        with tempfile.TemporaryDirectory() as tmp:
            self.assertIsNone(guard.clone_dir(tmp, {}))
            self.assertIsNone(guard.clone_dir(tmp, {'CI': 'true'}))
            self.assertEqual(guard.check_files([Path(tmp) / 'x.cpp'], tmp, {}), [])


if __name__ == '__main__':
    unittest.main()
