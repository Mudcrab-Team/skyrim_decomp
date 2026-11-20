// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageLocation__VFTable; size 0x20
#pragma once

struct IAIWorldLocationHandle;
struct PackageLocation__VFTable {
    unsigned long long*(*dtor_0)(IAIWorldLocationHandle* , char);
    int (*AllocateLocation_8)(void);
    long long (*GetAsPackageLocation_10)(void);
    int (*IsRefAtLocation_18)(void);
};
static_assert(sizeof(PackageLocation__VFTable) == 32, "PackageLocation__VFTable layout differs from the PDB");
