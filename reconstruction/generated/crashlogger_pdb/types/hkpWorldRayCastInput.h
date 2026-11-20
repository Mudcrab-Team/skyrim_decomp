// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldRayCastInput; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4.h"
struct hkpWorldRayCastInput {
    hkVector4 from;
    hkVector4 to;
    bool enableShapeCollectionFilter;
    unsigned char undefined_21[3];
    unsigned char filterInfo_raw[12];
};
static_assert(sizeof(hkpWorldRayCastInput) == 48, "hkpWorldRayCastInput layout differs from the PDB");
