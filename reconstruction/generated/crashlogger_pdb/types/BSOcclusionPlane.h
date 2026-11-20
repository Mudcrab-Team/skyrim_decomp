// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSOcclusionPlane; size 0x118
#pragma once

#include "BSOcclusionShape.h"
#include "NiFrustumPlanes.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPoint3.h"
struct BSOcclusionPlane {
    BSOcclusionShape _base;
    NiPoint2_6bdffc9f size;
    NiFrustumPlanes frustumPlanes;
    NiPoint3 corners[4];
    unsigned char edgeFlags[4];
    unsigned char twoSided;
    unsigned char undefined_f5[3];
    unsigned long long unkF8[4];
};
static_assert(sizeof(BSOcclusionPlane) == 280, "BSOcclusionPlane layout differs from the PDB");
