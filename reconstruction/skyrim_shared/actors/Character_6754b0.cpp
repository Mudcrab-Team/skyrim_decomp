// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6754b0 Character::sub_1405D2330
// Adapted bodies: none
#include "Character_6754b0.h"

// Return true unless both status bits at 0x180 are set and the voice timer is not positive.
bool Character::sub_1405D2330() const
{
    if ((boolBits & 0x180u) == 0x180u && voiceTimer <= 0.0f) {
        return false;
    }
    return true;
}
