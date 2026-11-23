// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d4620 Actor::HasSubObject6d4620
// Adapted bodies: none
#include "Actor_6d4620.h"

bool Actor::HasSubObject6d4620()
{
    SubObject* subObject = &embedded;
    if (subObject && Function164140(subObject)) {
        return true;
    }
    return false;
}
