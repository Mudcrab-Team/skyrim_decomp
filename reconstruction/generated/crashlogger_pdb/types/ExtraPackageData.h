// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPackageData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct ActorPackageData_d9b366d6;
struct ExtraPackageData {
    BSExtraData_4ca6af76 _base;
    ActorPackageData_d9b366d6* actorPackageData;
};
static_assert(sizeof(ExtraPackageData) == 24, "ExtraPackageData layout differs from the PDB");
