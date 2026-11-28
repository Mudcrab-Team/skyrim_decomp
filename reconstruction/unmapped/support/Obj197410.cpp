// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x197410 Obj197410::HasPositiveCount
// Adapted bodies: none.
#include "Obj197410.h"

// Returns true when a_target is non-null and its GetCount helper returns a positive value.
// guess: a member that reads no member, so the owning class and its role are unknown.
bool Obj197410::HasPositiveCount(Target197410* a_target) const
{
    if (a_target && a_target->GetCount() > 0) {
        return true;
    }
    return false;
}
