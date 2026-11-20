// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMotionState; size 0xb0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkHalf_603d3829.h"
#include "hkSweptTransform.h"
#include "hkTransform_d380b604.h"
#include "hkUFloat8.h"
#include "hkVector4.h"
struct hkMotionState {
    hkTransform_d380b604 transform;
    hkSweptTransform sweptTransform;
    hkVector4 deltaAngle;
    float objectRadius;
    hkHalf_603d3829 linearDamping;
    hkHalf_603d3829 angularDamping;
    hkHalf_603d3829 timeFactor;
    hkUFloat8 maxLinearVelocity;
    hkUFloat8 maxAngularVelocity;
    unsigned char deactivationClass;
    unsigned char padAD;
    unsigned short padAE;
};
static_assert(sizeof(hkMotionState) == 176, "hkMotionState layout differs from the PDB");
