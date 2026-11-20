// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatArea; size 0x30
#pragma once

struct CombatArea__VFTable;
struct NiRefObject__VFTable;
struct CombatArea {
    CombatArea__VFTable* vftable_CombatArea_0;
    NiRefObject__VFTable* vftable_NiRefObject_8;
    char _pad_10[32];
};
static_assert(sizeof(CombatArea) == 48, "CombatArea layout differs from the PDB");
