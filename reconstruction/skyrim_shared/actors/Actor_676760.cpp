// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x676760 Actor::GetRaceFullName
// Adapted bodies: none
#include "Actor_676760.h"

// Return the actor's race full name, or an empty string if absent.
const char* Actor::GetRaceFullName() const
{
    const TESRace* currentRace = race;
    if (currentRace && currentRace->GetFullNameLength() != 0) {
        return currentRace->GetFullName();
    }
    return "";
}
