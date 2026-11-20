// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMotion; size 0x140
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__hkpMotion__MotionType_unsigned_char_17336e65.h"
#include "hkMotionState_3862bdb4.h"
#include "hkReferencedObject_2e7f2489.h"
#include "hkVector4_f554a678.h"
struct hkpMaxSizeMotion_6c02c998;
struct hkpMotion {
    hkReferencedObject_2e7f2489 _base;
    EnumSet_RE__hkpMotion__MotionType_unsigned_char_17336e65 type;
    unsigned char deactivationIntegrateCounter;
    unsigned short deactivationNumInactiveFrames[2];
    unsigned short pad016;
    unsigned long long pad018;
    hkMotionState_3862bdb4 motionState;
    unsigned char undefined_d0[12];
    float field19_0xdc;
    hkVector4_f554a678 linearVelocity;
    hkVector4_f554a678 angularVelocity;
    unsigned char deactivationRefPosition_raw[32];
    unsigned int deactivationRefOrientation[2];
    hkpMaxSizeMotion_6c02c998* savedMotion;
    unsigned short savedQualityTypeIndex;
    unsigned short pad132;
    unsigned char gravityFactor_raw[4];
    unsigned long long pad138;
};
static_assert(sizeof(hkpMotion) == 320, "hkpMotion layout differs from the PDB");
