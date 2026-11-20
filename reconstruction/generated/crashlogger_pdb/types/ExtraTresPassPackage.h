// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraTresPassPackage; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TrespassPackage;
struct ExtraTresPassPackage {
    BSExtraData_4ca6af76 _base;
    TrespassPackage* pack;
    unsigned long long unk18;
};
static_assert(sizeof(ExtraTresPassPackage) == 32, "ExtraTresPassPackage layout differs from the PDB");
