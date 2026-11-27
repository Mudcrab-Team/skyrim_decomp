// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6b5cb0 Actor::IsFlagSet6b5cb0
// Adapted bodies: none
#include "Actor_6b5cb0.h"

bool gFeatureEnabled;

bool Actor::IsFlagSet6b5cb0() const
{
    bool result = gFeatureEnabled;
    if (result && subObject) {
        result = subObject->flags164 & 1;
    }
    return result;
}
