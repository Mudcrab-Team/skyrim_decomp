// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6be290 Actor::IsPassable6be290
// Adapted bodies: none
#include "Actor_6be290.h"

bool Actor::IsPassable6be290() const
{
    OwnerObject* object = owner;
    if (object && ((object->flags10 & 0x820) || object->unk99(true))) {
        return false;
    }
    return true;
}
