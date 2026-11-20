// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatAreaStandard; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct CombatAreaStandard__VFTable;
struct NiRefObject__VFTable;
struct CombatAreaStandard {
    CombatAreaStandard__VFTable* vftable_CombatAreaStandard_0;
    NiRefObject__VFTable* vftable_NiRefObject_8;
    char _pad_10[64];
};
static_assert(sizeof(CombatAreaStandard) == 80, "CombatAreaStandard layout differs from the PDB");
