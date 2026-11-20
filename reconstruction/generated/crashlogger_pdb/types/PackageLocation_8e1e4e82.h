// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageLocation; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "PackageLocation__Data.h"
struct PackageLocation__VFTable;
struct PackageLocation_8e1e4e82 {
    PackageLocation__VFTable* vftable_PackageLocation_0;
    char LocationType_8;
    char _pad_9[3];
    unsigned int Rad_C;
    PackageLocation__Data LocationData_10;
};
static_assert(sizeof(PackageLocation_8e1e4e82) == 24, "PackageLocation_8e1e4e82 layout differs from the PDB");
