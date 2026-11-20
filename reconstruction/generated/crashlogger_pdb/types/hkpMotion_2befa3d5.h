// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMotion; size 0x140
// one of 2 different PDB types sharing this name
#pragma once

#include "hkMotionState.h"
#include "hkReferencedObject.h"
#include "hkVector4.h"
struct hkpMaxSizeMotion;
struct hkpMotion_2befa3d5 {
    hkReferencedObject _base;
    unsigned char type;  // MotionType in the PDB is wider than this slot
    unsigned char deactivationIntegrateCounter;
    unsigned short deactivationNumInactiveFrames[2];
    unsigned short pad016;
    unsigned long long pad018;
    hkMotionState motionState;
    hkVector4 inertiaAndMassInv;
    hkVector4 linearVelocity;
    hkVector4 angularVelocity;
    unsigned char deactivationRefPosition_raw[32];
    unsigned int deactivationRefOrientation[2];
    hkpMaxSizeMotion* savedMotion;
    unsigned short savedQualityTypeIndex;
    unsigned short pad132;
    unsigned char gravityFactor_raw[4];
    unsigned long long pad138;
};
static_assert(sizeof(hkpMotion_2befa3d5) == 320, "hkpMotion_2befa3d5 layout differs from the PDB");
