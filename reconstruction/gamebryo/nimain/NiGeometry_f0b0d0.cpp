// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf0b0d0 NiGeometry::ForwardToAttachedObjects
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Adapted bodies: TestBit (a one-line bit-test helper, from momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0)
#include "NiGeometry_f0b0d0.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

void NiGeometry::ForwardToAttachedObjects(void* a_arg)
{
    if (TestBit(flags, 18)) {
        if (skin && skin->field18) {
            skin->unk26(a_arg);
        }
        if (attached && attached->field18) {
            attached->unk26(a_arg);
        }
    }
}
