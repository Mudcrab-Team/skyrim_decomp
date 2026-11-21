// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMovementMessageInterface__VFTable; size 0x20
#pragma once

struct IMovementInterface;
struct IMovementMessageInterface__VFTable {
    long long (*dtor_0)(IMovementInterface* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    int (*Func3_18)(void);
};
static_assert(sizeof(IMovementMessageInterface__VFTable) == 32, "IMovementMessageInterface__VFTable layout differs from the PDB");
