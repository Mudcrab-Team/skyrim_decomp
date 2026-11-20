// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTargetSelectorStandard__VFTable; size 0x38
#pragma once

struct CombatTargetSelector;
struct CombatTargetSelectorStandard__VFTable {
    unsigned long long*(*Func0_0)(CombatTargetSelector* , char);
    int (*Func1_8)(int (*)(unsigned long long, unsigned long long));
    int (*Func2_10)(void);
    void*(*Func3_18)(CombatTargetSelector* , long long);
    void*(*Func4_20)(CombatTargetSelector* , long long);
    void (*Func5_28)(void);
    int (*Func6_30)(void);
};
static_assert(sizeof(CombatTargetSelectorStandard__VFTable) == 56, "CombatTargetSelectorStandard__VFTable layout differs from the PDB");
