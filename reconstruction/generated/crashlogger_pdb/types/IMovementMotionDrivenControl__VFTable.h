// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMovementMotionDrivenControl__VFTable; size 0x48
#pragma once

struct IMovementInterface;
struct IMovementMotionDrivenControl__VFTable {
    long long (*dtor_0)(IMovementInterface* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    int (*Func3_18)(void);
    int (*Func4_20)(void);
    int (*Func5_28)(void);
    int (*Func6_30)(void);
    int (*Func7_38)(void);
    int (*Func8_40)(void);
};
static_assert(sizeof(IMovementMotionDrivenControl__VFTable) == 72, "IMovementMotionDrivenControl__VFTable layout differs from the PDB");
