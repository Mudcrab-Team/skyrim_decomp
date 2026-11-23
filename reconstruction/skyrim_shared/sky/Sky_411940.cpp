// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x411940 Sky::Function411940
// Adapted bodies: none
#include "Sky_411940.h"

void Sky::Function411940(bool a_set)
{
    if (a_set) {
        flags1DC |= 0x10;
    } else {
        flags1DC &= ~0x10u;
    }
}
