// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidable; size 0x70
// one of 2 different PDB types sharing this name
#pragma once

#include "BoundingVolumeData.h"
#include "hkpCdBody.h"
#include "hkpTypedBroadPhaseHandle_7f59e799.h"
struct hkpCollidable_9bd4f602 {
    hkpCdBody _base;
    unsigned char ownerOffset;
    unsigned char forceCollideOntoPpu;
    unsigned short shapeSizeOnSpu;
    hkpTypedBroadPhaseHandle_7f59e799 broadPhaseHandle;
    BoundingVolumeData boundingVolumeData;
    float allowedPenetrationDepth;
    unsigned int pad6C;
};
static_assert(sizeof(hkpCollidable_9bd4f602) == 112, "hkpCollidable_9bd4f602 layout differs from the PDB");
