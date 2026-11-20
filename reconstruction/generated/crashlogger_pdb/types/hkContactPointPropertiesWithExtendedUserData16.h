// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkContactPointPropertiesWithExtendedUserData16; size 0x40
#pragma once

#include "hkUFloat8.h"
struct hkContactPointPropertiesWithExtendedUserData16 {
    float m_impulseApplied_0;
    float m_internalSolverData_4;
    unsigned long long m_userData_8;
    hkUFloat8 m_friction_10;
    unsigned char m_restitution_11;
    hkUFloat8 m_maxImpulse_12;
    unsigned char m_flags_13;
    char _pad_14[4];
    float m_internalDataA_18;
    char _pad_1C[4];
    unsigned int m_extendedUserDatas_20[7];
    char _pad_3C[4];
};
static_assert(sizeof(hkContactPointPropertiesWithExtendedUserData16) == 64, "hkContactPointPropertiesWithExtendedUserData16 layout differs from the PDB");
