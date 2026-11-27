// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6b1580 Actor::Func282_14060AA70
// Adapted bodies: none
#include "Actor_6b1580.h"

// Zero the output vector when the actor's controller satisfies the active state check.
void Actor::Func282_14060AA70(std::uint64_t, NiPoint3& a_out) const
{
    if (currentProcess) {
        const CharController282* controller = currentProcess->GetController();
        if (controller && controller->unk31d != 0 && controller->unk314 > 0) {
            a_out.x = kNiPointZero.x;
            a_out.y = kNiPointZero.y;
            a_out.z = kNiPointZero.z;
        }
    }
}
