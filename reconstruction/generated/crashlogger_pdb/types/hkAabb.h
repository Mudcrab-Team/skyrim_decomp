// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkAabb; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4_f554a678.h"
struct hkAabb {
    hkVector4_f554a678 m_min_0;
    hkVector4_f554a678 m_max_10;
};
static_assert(sizeof(hkAabb) == 32, "hkAabb layout differs from the PDB");
