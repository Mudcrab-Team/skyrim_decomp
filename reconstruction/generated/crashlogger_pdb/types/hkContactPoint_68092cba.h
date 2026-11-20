// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkContactPoint; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "hkVector4_f554a678.h"
struct hkContactPoint_68092cba {
    hkVector4_f554a678 m_position_0;
    hkVector4_f554a678 m_separatingNormal_10;
};
static_assert(sizeof(hkContactPoint_68092cba) == 32, "hkContactPoint_68092cba layout differs from the PDB");
