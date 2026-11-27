// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x3b0350 ActorValueOwner::ModifyActorValue_140351740
// Adapted bodies: none
#include "ActorValueOwner_3b0350.h"

// Add a delta to the owner's base actor value via virtual get and set.
void ActorValueOwner::ModifyActorValue_140351740(std::int32_t a_av, float a_delta)
{
    SetBaseActorValue(a_av, GetBaseActorValue(a_av) + a_delta);
}
