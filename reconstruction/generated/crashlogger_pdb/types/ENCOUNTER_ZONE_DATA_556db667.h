// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ENCOUNTER_ZONE_DATA; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BGSLocation;
struct TESFaction_fe5903c5;
struct ENCOUNTER_ZONE_DATA_556db667 {
    TESFaction_fe5903c5* zoneOwner;
    BGSLocation* location;
    unsigned char ownerRank;
    unsigned char minLevel;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char maxLevel;
    unsigned int pad14;
};
static_assert(sizeof(ENCOUNTER_ZONE_DATA_556db667) == 24, "ENCOUNTER_ZONE_DATA_556db667 layout differs from the PDB");
