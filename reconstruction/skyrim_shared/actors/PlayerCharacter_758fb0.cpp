// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x758fb0 PlayerCharacter::ModCrimeGoldValue_1406B1980
// Adapted bodies: none
#include "PlayerCharacter_758fb0.h"

// Adjust the player's violent or non-violent crime gold for a faction, clamping at zero.
std::int32_t PlayerCharacter::ModCrimeGoldValue_1406B1980(TESFaction* a_faction, bool a_violent, std::int32_t a_amount)
{
    std::int32_t result = 0;
    if (a_faction) {
        std::int32_t current = a_violent ? GetViolentCrimeGoldValue(a_faction) : GetNonViolentCrimeGoldValue(a_faction);
        std::int32_t total = current + a_amount;
        result = total > 0 ? total : 0;
        SetCrimeGoldValue(a_faction, a_violent, result);
    }
    return result;
}
