// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6d6690 Actor::InterruptCast_140631C80
// Adapted bodies: none
#include "Actor_6d6690.h"

// Interrupt casting on each active magic caster slot of the actor.
void Actor::InterruptCast_140631C80(bool a_refund)
{
    for (std::uint32_t i = 0; i < 4; ++i) {
        if (magicCasters[i]) {
            magicCasters[i]->InterruptCast(a_refund);
        }
    }
}
