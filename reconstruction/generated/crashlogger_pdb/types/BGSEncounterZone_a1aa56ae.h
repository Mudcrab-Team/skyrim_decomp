// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEncounterZone; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "ENCOUNTER_ZONE_DATA.h"
#include "ENCOUNTER_ZONE_GAME_DATA.h"
#include "TESForm_4074aa87.h"
struct BGSEncounterZone_a1aa56ae {
    TESForm_4074aa87 _base;
    ENCOUNTER_ZONE_DATA data;
    ENCOUNTER_ZONE_GAME_DATA gameData;
};
static_assert(sizeof(BGSEncounterZone_a1aa56ae) == 72, "BGSEncounterZone_a1aa56ae layout differs from the PDB");
