// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x41dc50 ActorValueOwner::sub_1403BD3C0
// Adapted bodies: none
#include "ActorValueOwner_41dc50.h"

// Return the override threshold from data if flagged, otherwise scale permanent health.
float ActorValueOwner::sub_1403BD3C0(const Data41dc50* a_data, const Mult41dc50* a_mult) const
{
    if (a_data && TestBit(a_data->flags, 18)) {
        return static_cast<float>(a_data->unk4e);
    }
    float mult = a_mult ? a_mult->unk68 : g_defaultMult41dc50;
    return GetPermanentActorValue(0x18) * mult;
}
