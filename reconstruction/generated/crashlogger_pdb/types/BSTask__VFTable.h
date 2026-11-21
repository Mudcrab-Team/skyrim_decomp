// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTask__VFTable; size 0x28
#pragma once

struct BSTask_b2e18bcd;
struct BSTask__VFTable {
    long long (*Func0_0)(BSTask_b2e18bcd* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    void (*Func3_18)(void);
    char (*Func4_20)(long long, char* , unsigned int);
};
static_assert(sizeof(BSTask__VFTable) == 40, "BSTask__VFTable layout differs from the PDB");
