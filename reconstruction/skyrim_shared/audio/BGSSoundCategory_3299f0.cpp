// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3299f0 BGSSoundCategory::Function3299f0
// Adapted bodies: TestBit, the same one-line bit-index helper as the sibling's (also the project cookbook rule 16 spelling)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "BGSSoundCategory_3299f0.h"

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
    inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 1) != 0;
    }
}

bool BGSSoundCategory::Function3299f0()
{
    if (TestBit(unk18, 1)) {
        return true;
    }
    if (parent && parent->category.Unk_08()) {
        return true;
    }
    return false;
}
