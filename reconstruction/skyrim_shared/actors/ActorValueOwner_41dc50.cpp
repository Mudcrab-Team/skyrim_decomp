// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: it resembles the sibling bit-test helper cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// 0x41dc50 ActorValueOwner::sub_1403BD3C0
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
