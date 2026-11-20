// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDChargeMeter; size 0x30
#pragma once

#include "HUDObject.h"
struct HUDChargeMeter {
    HUDObject _base;
    float unk28;
    float unk2C;
};
static_assert(sizeof(HUDChargeMeter) == 48, "HUDChargeMeter layout differs from the PDB");
