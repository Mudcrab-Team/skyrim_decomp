// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatObject; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiRefObject__VFTable;
struct CombatObject {
    NiRefObject__VFTable* vftable_NiRefObject_0;
    char _pad_8[8];
};
static_assert(sizeof(CombatObject) == 16, "CombatObject layout differs from the PDB");
