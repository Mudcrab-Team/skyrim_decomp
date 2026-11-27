// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x868da0 Character::sub_1407BCAF0
// Adapted bodies: none
#include "Character_868da0.h"

// Return whether the character has a process with neither right nor left hand item equipped.
bool Character::sub_1407BCAF0() const
{
    return currentProcess &&
           currentProcess->GetEquippedRightHand() == nullptr &&
           currentProcess->GetEquippedLeftHand() == nullptr;
}
