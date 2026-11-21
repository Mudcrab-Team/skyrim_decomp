// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatNavmeshSearch; size 0x1e8
#pragma once

struct BSFastNavmeshTriLocation;
struct CombatNavmeshSearch {
    unsigned char _base[8];  // BSNavmeshSearch is 432 bytes in the PDB, more than this slot
    void* pad08[57];
    BSFastNavmeshTriLocation* bestGoal;
    unsigned char undefined_1d8[16];
};
static_assert(sizeof(CombatNavmeshSearch) == 488, "CombatNavmeshSearch layout differs from the PDB");
