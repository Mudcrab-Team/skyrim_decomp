// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x86aa30 Actor::Function86aa30
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Actor_86aa30.h"

bool Actor::Function86aa30()
{
    bool result = false;
    const std::uint32_t state = *reinterpret_cast<const std::uint32_t*>(&actorState2);
    if (TestBit(state, 13)) {
        result = true;
    } else if ((state & 0xC00) == 0x800) {
        result = true;
    }
    return result;
}
