// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatThreat; size 0x68
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct CombatThreat__VFTable;
struct NiRefObject__VFTable;
struct CombatThreat {
    CombatThreat__VFTable* vftable_CombatThreat_0;
    NiRefObject__VFTable* vftable_NiRefObject_8;
    unsigned int formid;
    unsigned int handle;
    unsigned char undefined_18[80];
};
static_assert(sizeof(CombatThreat) == 104, "CombatThreat layout differs from the PDB");
