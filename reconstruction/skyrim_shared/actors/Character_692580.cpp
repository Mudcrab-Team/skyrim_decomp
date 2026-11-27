// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x692580 Character::UpdateCachedValueData_1405ED420
// Adapted bodies: none
#include "Character_692580.h"

// Clear the four cached-value validity flags on the character's process.
void Character::UpdateCachedValueData_1405ED420()
{
    if (currentProcess) {
        ClearCachedFlag(0x2000u);
        ClearCachedFlag(0x1000u);
        ClearCachedFlag(0x0800u);
        ClearCachedFlag(0x0400u);
    }
}
