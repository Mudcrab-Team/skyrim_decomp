// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeRayCastInput; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CFilter.h"
#include "hkVector4.h"
struct hkpRayShapeCollectionFilter;
struct hkpShapeRayCastInput {
    hkVector4 from;
    hkVector4 to;
    CFilter collisionFilterInfo;
    unsigned char pad24[4];
    hkpRayShapeCollectionFilter* rayShapeCollectionFilter;
};
static_assert(sizeof(hkpShapeRayCastInput) == 48, "hkpShapeRayCastInput layout differs from the PDB");
