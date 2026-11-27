// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x6ca4c0 Actor::UpdateFlag6ca4c0
// Adapted bodies: TestBit (header), a one-line bit test close to the Fallout 3 sibling body, CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "Actor_6ca4c0.h"

void Actor::UpdateFlag6ca4c0()
{
    StateObject* state = GetStateObject675310();
    if (state && !TestBit(state->flags218, 28)) {
        bool zero = GetValue679d00() == 0.0f;
        unsigned int flags = state->flags218;
        if (zero) {
            state->flags218 = flags | 0x4000;
        } else {
            state->flags218 = flags & ~0x4000u;
        }
    }
}
