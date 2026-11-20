// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEncounterZone; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ENCOUNTER_ZONE_DATA_556db667.h"
#include "ENCOUNTER_ZONE_GAME_DATA.h"
#include "TESForm.h"
struct BGSEncounterZone {
    TESForm _base;
    ENCOUNTER_ZONE_DATA_556db667 data;
    ENCOUNTER_ZONE_GAME_DATA gameData;
};
static_assert(sizeof(BGSEncounterZone) == 72, "BGSEncounterZone layout differs from the PDB");
