// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSurfaceInfo; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4_f554a678.h"
struct hkpSurfaceInfo {
    unsigned char undefined_0[4];
    unsigned int pad04;
    unsigned long long pad08;
    unsigned char undefined_10[16];
    hkVector4_f554a678 m_surfaceVelocity_20;
    float surfaceDistanceExcess;
    bool surfaceIsDynamic;
    unsigned char pad35;
    unsigned short pad36;
    unsigned long long pad38;
};
static_assert(sizeof(hkpSurfaceInfo) == 64, "hkpSurfaceInfo layout differs from the PDB");
