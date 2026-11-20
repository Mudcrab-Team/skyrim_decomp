// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementMessage__VFTable; size 0x30
#pragma once

struct MovementMessage;
struct MovementMessage__VFTable {
    long long (*Func0_0)(MovementMessage* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    int (*Func3_18)(void);
    void (*Func4_20)(void);
    long long (*Func5_28)(void);
};
static_assert(sizeof(MovementMessage__VFTable) == 48, "MovementMessage__VFTable layout differs from the PDB");
