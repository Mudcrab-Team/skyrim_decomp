// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatArea__VFTable; size 0x60
#pragma once

struct CombatArea;
struct CombatArea__VFTable {
    unsigned long long*(*Func0_0)(CombatArea* , char);
    int (*Func1_8)(int (*)(unsigned long long, unsigned long long));
    int (*Func2_10)(void);
    void*(*Func3_18)(CombatArea* , long long);
    void*(*Func4_20)(CombatArea* , long long);
    int (*Func5_28)(void);
    int (*Func6_30)(void);
    int (*Func7_38)(void);
    int (*Func8_40)(void);
    int (*Func9_48)(void);
    int (*Func10_50)(void);
    void (*Func11_58)(void);
};
static_assert(sizeof(CombatArea__VFTable) == 96, "CombatArea__VFTable layout differs from the PDB");
