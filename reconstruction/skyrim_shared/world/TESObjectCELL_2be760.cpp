// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction; no external implementation body copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2be760 TESObjectCELL::Function2be760
// Adapted bodies: none.
#include "TESObjectCELL_2be760.h"

BGSEncounterZone* TESObjectCELL::Function2be760() const
{
    BGSEncounterZone* zone = extraList.GetEncounterZone();
    if (!zone && !(cellFlags & 1) && worldSpace) {
        zone = worldSpace->encounterZone;
    }
    return zone;
}
