// Source exposure: mixed (community declarations; pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x27ca80 TESObjectARMA::HasRace
// Adapted bodies: none
#include "TESObjectARMA_27ca80.h"

// Checks whether the armor addon applies to a race or its armor parent race.
bool TESObjectARMA::HasRace(const TESRace* a_race) const
{
    const TESRace* targetRace = (a_race && a_race->armorParentRace) ? a_race->armorParentRace : a_race;
    if (race == targetRace) {
        return true;
    }
    for (std::uint32_t i = 0; i < additionalRaces.size; ++i) {
        if (additionalRaces.data[i] == targetRace) {
            return true;
        }
    }
    return false;
}
