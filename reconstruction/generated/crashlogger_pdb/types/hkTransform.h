// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkTransform; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkRotation.h"
#include "hkVector4_f554a678.h"
struct hkTransform {
    hkRotation m_rotation_0;
    hkVector4_f554a678 m_translation_30;
};
static_assert(sizeof(hkTransform) == 64, "hkTransform layout differs from the PDB");
