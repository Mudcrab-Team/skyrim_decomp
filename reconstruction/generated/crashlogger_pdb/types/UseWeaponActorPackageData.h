// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UseWeaponActorPackageData; size 0x10
#pragma once

#include "ActorPackageData_d9b366d6.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
struct UseWeaponActorPackageData {
    ActorPackageData_d9b366d6 _base;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    unsigned int pad0C;
};
static_assert(sizeof(UseWeaponActorPackageData) == 16, "UseWeaponActorPackageData layout differs from the PDB");
