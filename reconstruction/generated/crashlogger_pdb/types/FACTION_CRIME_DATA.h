// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FACTION_CRIME_DATA; size 0x48
#pragma once

#include "FACTION_CRIME_DATA_VALUES.h"
struct BGSListForm;
struct BGSOutfit;
struct TESObjectREFR_b225f218;
struct FACTION_CRIME_DATA {
    TESObjectREFR_b225f218* factionJailMarker;
    TESObjectREFR_b225f218* factionWaitMarker;
    TESObjectREFR_b225f218* factionStolenContainer;
    TESObjectREFR_b225f218* factionPlayerInventoryContainer;
    BGSListForm* crimeGroup;
    BGSOutfit* jailOutfit;
    FACTION_CRIME_DATA_VALUES crimevalues;
    unsigned int pad44;
};
static_assert(sizeof(FACTION_CRIME_DATA) == 72, "FACTION_CRIME_DATA layout differs from the PDB");
