// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ENCOUNTER_ZONE_DATA; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__ENCOUNTER_ZONE_DATA__Flag_unsigned_char_3d1e15ec.h"
struct BGSLocation_075ae773;
struct TESFaction;
struct ENCOUNTER_ZONE_DATA {
    TESFaction* zoneOwner;
    BGSLocation_075ae773* location;
    unsigned char ownerRank;
    unsigned char minLevel;
    EnumSet_RE__ENCOUNTER_ZONE_DATA__Flag_unsigned_char_3d1e15ec flags;
    unsigned char maxLevel;
    unsigned int pad14;
};
static_assert(sizeof(ENCOUNTER_ZONE_DATA) == 24, "ENCOUNTER_ZONE_DATA layout differs from the PDB");
