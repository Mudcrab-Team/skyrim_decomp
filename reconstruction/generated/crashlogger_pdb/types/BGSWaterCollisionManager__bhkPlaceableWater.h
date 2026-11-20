// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSWaterCollisionManager::bhkPlaceableWater; size 0x70
#pragma once

#include "BGSWaterCollisionManager__BGSWaterUpdateI.h"
#include "hkpPhantomCallbackShape.h"
struct BGSWaterCollisionManager__bhkPlaceableWater {
    hkpPhantomCallbackShape base;
    BGSWaterCollisionManager__BGSWaterUpdateI updateI;
    unsigned int usageCount;
    unsigned int pad6C;
};
static_assert(sizeof(BGSWaterCollisionManager__bhkPlaceableWater) == 112, "BGSWaterCollisionManager__bhkPlaceableWater layout differs from the PDB");
