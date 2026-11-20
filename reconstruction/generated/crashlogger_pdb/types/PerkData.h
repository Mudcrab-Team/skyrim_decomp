// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PerkData; size 0x5
#pragma once
struct PerkData {
    bool trait;
    unsigned char level;
    unsigned char numRanks;
    bool playable;
    bool hidden;
};
static_assert(sizeof(PerkData) == 5, "PerkData layout differs from the PDB");
