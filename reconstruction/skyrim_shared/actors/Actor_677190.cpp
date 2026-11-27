// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x677190 Actor::GetLinearVelocity_1405D3EB0
// Adapted bodies: none
#include "Actor_677190.h"

// Copy the actor's linear velocity from its character controller, or zero if unavailable.
void Actor::GetLinearVelocity_1405D3EB0(NiPoint3& a_out) const
{
    const VelocityController* controller = currentProcess ? currentProcess->GetVelocityController() : nullptr;
    const NiPoint3&           velocity   = controller ? controller->linearVelocity : kNiPointZero;
    a_out.x = velocity.x;
    a_out.y = velocity.y;
    a_out.z = velocity.z;
}
