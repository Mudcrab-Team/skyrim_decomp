// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraLight; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct REFR_LIGHT;
struct ExtraLight {
    BSExtraData_4ca6af76 _base;
    REFR_LIGHT* lightData;
};
static_assert(sizeof(ExtraLight) == 24, "ExtraLight layout differs from the PDB");
