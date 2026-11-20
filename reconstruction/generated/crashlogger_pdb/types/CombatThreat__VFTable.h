// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatThreat__VFTable; size 0x28
#pragma once

struct CombatThreat;
struct CombatThreat__VFTable {
    unsigned long long*(*Func0_0)(CombatThreat* , char);
    int (*Func1_8)(int (*)(unsigned long long, unsigned long long));
    long long (*Func2_10)(void);
    int (*Func3_18)(CombatThreat* , long long);
    long long (*Func4_20)(CombatThreat* , long long);
};
static_assert(sizeof(CombatThreat__VFTable) == 40, "CombatThreat__VFTable layout differs from the PDB");
