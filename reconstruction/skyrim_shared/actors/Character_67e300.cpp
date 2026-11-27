// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x67e300 Character::Function67e300
// Adapted bodies: none
#include "Character_67e300.h"

bool Character::Function67e300()
{
    if (unkE8 & 1) {
        Function6afef0();
        unkE8 &= ~1u;
        return true;
    }
    return false;
}
