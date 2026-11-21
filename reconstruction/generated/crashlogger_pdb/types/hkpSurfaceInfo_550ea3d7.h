// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSurfaceInfo; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "SupportedState.h"
#include "hkVector4.h"
struct hkpSurfaceInfo_550ea3d7 {
    SupportedState supportedState;
    unsigned int pad04;
    unsigned long long pad08;
    hkVector4 surfaceNormal;
    hkVector4 surfaceVelocity;
    float surfaceDistanceExcess;
    bool surfaceIsDynamic;
    unsigned char pad35;
    unsigned short pad36;
    unsigned long long pad38;
};
static_assert(sizeof(hkpSurfaceInfo_550ea3d7) == 64, "hkpSurfaceInfo_550ea3d7 layout differs from the PDB");
