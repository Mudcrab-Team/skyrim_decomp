// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6c44f0 Character::sub_140620550
// Adapted bodies: none
#include "Character_6c44f0.h"

// Return whether the given actor value is damaged, using cached flags for health, magicka, and stamina.
bool Character::sub_140620550(std::int32_t a_av) const
{
    if (!currentProcess) {
        return false;
    }
    switch (a_av) {
    case 0x18:
        if (currentProcess->cachedValues) {
            return ((currentProcess->cachedValues->flags >> 21) & 1u) != 0;
        }
        return false;
    case 0x19:
        if (currentProcess->cachedValues) {
            return ((currentProcess->cachedValues->flags >> 22) & 1u) != 0;
        }
        return false;
    case 0x1a:
        if (currentProcess->cachedValues) {
            return ((currentProcess->cachedValues->flags >> 23) & 1u) != 0;
        }
        return false;
    default: {
        float current = GetActorValue(a_av);
        return GetPermanentActorValue(a_av) > current;
    }
    }
}
