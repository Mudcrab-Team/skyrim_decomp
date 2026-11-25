// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1e5f50 (skyrim_shared/refs/TESObjectREFR_1e5f50): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// 0x1e6520 Owner1e6520::Function1e6520
#include "Owner1e6520.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// guess: same compiled code as matched 0x1e5f50 apart from relocated fields; its role here is not established.
void Owner1e6520::Function1e6520(bool a_set)
{
    if (TestBit(formFlags, 23) != a_set) {
        formFlags = a_set ? (formFlags | (1u << 23)) : (formFlags & ~(1u << 23));
        AddChange(1);
    }
}
