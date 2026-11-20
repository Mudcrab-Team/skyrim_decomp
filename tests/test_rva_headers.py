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

    def test_size_record_is_a_claim_anywhere(self):
        text = ('// Build: b; RVA 0x1000; 8 bytes\n#include "A.h"\n// RVA 0x20, 4 bytes: an empty body\n'
                '/* Compared: RVA 0x30 12 bytes; RVA 0x40 16 bytes. */\n')
        self.assertEqual(rva_headers.claimed_rvas([text]), {0x1000, 0x20, 0x30, 0x40})

    def test_compared_at_label_is_a_claim(self):
        text = '// A::f, A::g: COMMUNITY(x/y@z, MIT); compared at RVA 0x20, 0x30 and 0x40; same shape\n'
        self.assertEqual(rva_headers.claimed_rvas([text]), {0x20, 0x30, 0x40})

    def test_prose_that_mentions_addresses_is_not_a_claim(self):
        text = ('// 0x1cf0f0 TESFile::ReadFormHeader\n'
                '// TESFile::OpenInternal, ::ReadFormHeader: GUESS; callees at RVAs 0x1ca490, 0x1cf0f0, 0x1cf2e0 and '
                '0x1cfcf0 with no community name\n'
                '// IsReservedFormID: GUESS(low); the callee at RVA 0x1e6600 and a global at 0x2078a30\n'
                '// BSFile::Read: GUESS; bound by hint to RVA 0xebea00, a read that returns the byte count\n'
                '// Evidence: findings/x.md, RVAs 0x20 and 0x30 are the vtable slots\n'
                '#include "A.h"\nvoid f();   // RVA 0x1e01d0\n')
        self.assertEqual(rva_headers.claimed_rvas([text]), {0x1cf0f0})

    def test_prose_only_unit_claims_nothing(self):
        self.assertEqual(rva_headers.claimed_rvas(['// the callee at RVA 0x1000, called by f\n']), set())

    def test_a_bare_address_without_a_name_is_not_a_claim(self):
        self.assertEqual(rva_headers.claimed_rvas(['// 0x1000\n#pragma once\n']), set())


if __name__ == '__main__':
    unittest.main()
