// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSOcclusionBox; size 0x1e8
#pragma once

#include "BSOcclusionShape.h"
#include "NiFrustumPlanes.h"
#include "NiPoint3.h"
struct BSMultiBoundShape;
struct BSOcclusionBox {
    BSOcclusionShape _base;
    NiPoint3 size;
    NiFrustumPlanes frustumPlanes[2];
    NiPoint3 corners[8];
    float unused194;
    BSMultiBoundShape* boundShape;
    unsigned long long unused1A0;
    unsigned int unused1A8;
    int facePlaneSlots[6];
    unsigned int silhouetteIndices[8];
    unsigned int silhouetteCount;
};
static_assert(sizeof(BSOcclusionBox) == 488, "BSOcclusionBox layout differs from the PDB");
