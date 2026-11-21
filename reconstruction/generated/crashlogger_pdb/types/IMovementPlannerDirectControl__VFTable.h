// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMovementPlannerDirectControl__VFTable; size 0x30
#pragma once

struct IMovementInterface;
struct IMovementPlannerDirectControl__VFTable {
    long long (*dtor_0)(IMovementInterface* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    int (*Func3_18)(void);
    int (*Func4_20)(void);
    int (*Func5_28)(void);
};
static_assert(sizeof(IMovementPlannerDirectControl__VFTable) == 48, "IMovementPlannerDirectControl__VFTable layout differs from the PDB");
