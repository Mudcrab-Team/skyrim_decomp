// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x300ab0 TESObjectREFR::GetEncounterZone
// Adapted bodies: none
#include "TESObjectREFR_300ab0.h"

BGSEncounterZone* TESObjectREFR::GetEncounterZone() const
{
    BGSEncounterZone* zone = extraList.GetEncounterZone();
    if (zone) {
        return zone;
    }
    if (parentCell) {
        zone = parentCell->GetEncounterZone();
        if (zone) {
            return zone;
        }
    }
    if (GetWorldspace()) {
        return GetWorldspace()->encounterZone;
    }
    return zone;
}
