// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkQsTransform; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "hkQuaternion.h"
#include "hkVector4_f554a678.h"
struct hkQsTransform_f8a86d4b {
    hkVector4_f554a678 m_translation_0;
    hkVector4_f554a678 m_scale_20;
    hkQuaternion m_rotation_10;
};
static_assert(sizeof(hkQsTransform_f8a86d4b) == 48, "hkQsTransform_f8a86d4b layout differs from the PDB");
