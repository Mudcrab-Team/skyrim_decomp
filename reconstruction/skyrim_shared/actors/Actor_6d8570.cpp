// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d8570 Actor::CanAddActiveEffect
// Adapted bodies: none
#include "Actor_6d8570.h"

bool Actor::CanAddActiveEffect()
{
    Character* owner = reinterpret_cast<Character*>(reinterpret_cast<char*>(this) - 0xA0);
    int state = owner->Function6af250();
    return state == 0 || owner->Function6af250() == 1;
}
