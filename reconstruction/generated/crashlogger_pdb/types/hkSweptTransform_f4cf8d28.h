// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSweptTransform; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "hkQuaternion.h"
#include "hkVector4_f554a678.h"
struct hkSweptTransform_f4cf8d28 {
    hkVector4_f554a678 m_centerOfMass0_0;
    hkVector4_f554a678 m_centerOfMass1_10;
    hkQuaternion m_rotation0_20;
    hkQuaternion m_rotation1_30;
    hkVector4_f554a678 m_centerOfMassLocal_40;
};
static_assert(sizeof(hkSweptTransform_f4cf8d28) == 80, "hkSweptTransform_f4cf8d28 layout differs from the PDB");
