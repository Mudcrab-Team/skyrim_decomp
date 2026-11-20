// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSWaterCollisionManager::bhkWaterfall; size 0x68
#pragma once

#include "BGSWaterCollisionManager__BGSWaterUpdateI.h"
#include "hkpPhantomCallbackShape.h"
struct BGSWaterCollisionManager__bhkWaterfall {
    hkpPhantomCallbackShape base;
    BGSWaterCollisionManager__BGSWaterUpdateI updateI;
};
static_assert(sizeof(BGSWaterCollisionManager__bhkWaterfall) == 104, "BGSWaterCollisionManager__bhkWaterfall layout differs from the PDB");
