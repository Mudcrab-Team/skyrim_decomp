// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ENCOUNTER_ZONE_GAME_DATA; size 0x10
#pragma once
struct ENCOUNTER_ZONE_GAME_DATA {
    unsigned int detachTime;
    unsigned int attachTime;
    unsigned int resetTime;
    unsigned short zoneLevel;
    unsigned short pad0D;
};
static_assert(sizeof(ENCOUNTER_ZONE_GAME_DATA) == 16, "ENCOUNTER_ZONE_GAME_DATA layout differs from the PDB");
