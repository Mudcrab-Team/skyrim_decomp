"""The compact `// 0x<rva> <Name>` header line is a claim; the same text further down is not."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import rva_headers  # noqa: E402


class ClaimTests(unittest.TestCase):
    def test_compact_lines_in_the_leading_block(self):
        text = ('// Source exposure: mixed\n// 0x1de5e0 TESActorBaseData::Unk_07\n//  0x1de5f0 Other\n'
                '#include "A.h"\n// 0x2000 not a claim\nint x;\n')
        self.assertEqual(rva_headers.claimed_rvas([text]), {0x1de5e0, 0x1de5f0})

    def test_older_phrase_is_still_read_anywhere(self):
        text = '// Build: b; RVA 0x1000; 8 bytes\n#include "A.h"\n// RVAs 0x20, 0x30 and 0x40\n'
        self.assertEqual(rva_headers.claimed_rvas([text]), {0x1000, 0x20, 0x30, 0x40})

    def test_a_bare_address_without_a_name_is_not_a_claim(self):
        self.assertEqual(rva_headers.claimed_rvas(['// 0x1000\n#pragma once\n']), set())


if __name__ == '__main__':
    unittest.main()
