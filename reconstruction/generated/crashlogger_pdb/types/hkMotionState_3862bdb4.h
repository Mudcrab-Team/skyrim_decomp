// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMotionState; size 0xb0
// one of 2 different PDB types sharing this name
#pragma once

#include "hkHalf.h"
#include "hkSweptTransform_f4cf8d28.h"
#include "hkTransform.h"
#include "hkUFloat8.h"
#include "hkVector4_f554a678.h"
struct hkMotionState_3862bdb4 {
    hkTransform m_transform_0;
    hkSweptTransform_f4cf8d28 m_sweptTransform_40;
    hkVector4_f554a678 m_deltaAngle_90;
    float m_objectRadius_A0;
    hkHalf m_linearDamping_A4;
    hkHalf m_angularDamping_A6;
    hkHalf m_timeFactor_A8;
    hkUFloat8 m_maxLinearVelocity_AA;
    hkUFloat8 m_maxAngularVelocity_AB;
    unsigned char m_deactivationClass_AC;
    char _pad_AD[3];
};
static_assert(sizeof(hkMotionState_3862bdb4) == 176, "hkMotionState_3862bdb4 layout differs from the PDB");
