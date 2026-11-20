// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FACTION_RANK; size 0x10
#pragma once

struct TESFaction_fe5903c5;
struct FACTION_RANK {
    TESFaction_fe5903c5* faction;
    unsigned char rank;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(FACTION_RANK) == 16, "FACTION_RANK layout differs from the PDB");
