// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; target virtual-call and optional-output observations
// SPDX-License-Identifier: CC0-1.0
// 0x5cd110 MagicCaster::GetCasterObjectReference
// Adapted bodies: none
#include "MagicCaster_5cd110.h"

TESObjectREFR* MagicCaster::GetCasterObjectReference(Actor** outActor) const
{
    TESObjectREFR* result = GetCasterStatsObject();
    if (outActor)
        *outActor = GetCasterAsActor();
    if (!result)
        return GetCasterAsActor();
    return result;
}
