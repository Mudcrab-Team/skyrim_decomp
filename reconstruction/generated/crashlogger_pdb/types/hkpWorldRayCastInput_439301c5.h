// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldRayCastInput; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "hkVector4_f554a678.h"
struct hkpWorldRayCastInput_439301c5 {
    hkVector4_f554a678 from;
    hkVector4_f554a678 to;
    bool enableShapeCollectionFilter;
    unsigned char undefined_21[3];
    unsigned char filterInfo_raw[12];
};
static_assert(sizeof(hkpWorldRayCastInput_439301c5) == 48, "hkpWorldRayCastInput_439301c5 layout differs from the PDB");
