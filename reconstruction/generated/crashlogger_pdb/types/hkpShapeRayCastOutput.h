// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeRayCastOutput; size 0x50
#pragma once

#include "hkpShapeRayCastCollectorOutput.h"
struct hkpShapeRayCastOutput {
    hkpShapeRayCastCollectorOutput _base;
    unsigned int shapeKeys[8];
    int shapeKeyIndex;
    unsigned int pad44;
    unsigned long long pad48;
};
static_assert(sizeof(hkpShapeRayCastOutput) == 80, "hkpShapeRayCastOutput layout differs from the PDB");
