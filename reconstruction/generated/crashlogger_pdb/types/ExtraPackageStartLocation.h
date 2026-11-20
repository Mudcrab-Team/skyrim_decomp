// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPackageStartLocation; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "WORLD_LOCATION.h"
struct ExtraPackageStartLocation {
    BSExtraData_4ca6af76 _base;
    WORLD_LOCATION worldLoc;
};
static_assert(sizeof(ExtraPackageStartLocation) == 40, "ExtraPackageStartLocation layout differs from the PDB");
