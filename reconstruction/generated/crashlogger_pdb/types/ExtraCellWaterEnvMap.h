// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraCellWaterEnvMap; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "TESTexture.h"
struct ExtraCellWaterEnvMap {
    BSExtraData_4ca6af76 _base;
    TESTexture waterEnvMap;
};
static_assert(sizeof(ExtraCellWaterEnvMap) == 32, "ExtraCellWaterEnvMap layout differs from the PDB");
