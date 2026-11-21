// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IAIWorldLocationHandle__VFTable; size 0x20
#pragma once

struct IAIWorldLocationHandle;
struct IAIWorldLocationHandle__VFTable {
    unsigned long long*(*dtor_0)(IAIWorldLocationHandle* , char);
    int (*AllocateLocation_8)(void);
    long long (*GetAsPackageLocation_10)(void);
    int (*IsRefAtLocation_18)(void);
};
static_assert(sizeof(IAIWorldLocationHandle__VFTable) == 32, "IAIWorldLocationHandle__VFTable layout differs from the PDB");
