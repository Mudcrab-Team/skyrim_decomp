// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeRayCastCollectorOutput; size 0x20
#pragma once

#include "hkVector4.h"
struct hkpShapeRayCastCollectorOutput {
    hkVector4 normal;
    float hitFraction;
    int extraInfo;
    unsigned int shapeKey;
    int pad1C;
};
static_assert(sizeof(hkpShapeRayCastCollectorOutput) == 32, "hkpShapeRayCastCollectorOutput layout differs from the PDB");
