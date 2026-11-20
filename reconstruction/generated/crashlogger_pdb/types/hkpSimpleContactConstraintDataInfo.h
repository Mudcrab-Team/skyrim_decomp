// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleContactConstraintDataInfo; size 0x20
#pragma once

#include "hkHalf.h"
struct hkpSimpleContactConstraintDataInfo {
    unsigned short m_flags_0;
    unsigned short m_index_2;
    float m_internalData0_4;
    hkHalf m_rollingFrictionMultiplier_8;
    hkHalf m_internalData1_A;
    unsigned int m_data_C[5];
};
static_assert(sizeof(hkpSimpleContactConstraintDataInfo) == 32, "hkpSimpleContactConstraintDataInfo layout differs from the PDB");
