// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkRotation; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4_f554a678.h"
struct hkRotation {
    hkVector4_f554a678 m_col0_0;
    hkVector4_f554a678 m_col1_10;
    hkVector4_f554a678 m_col2_20;
};
static_assert(sizeof(hkRotation) == 48, "hkRotation layout differs from the PDB");
