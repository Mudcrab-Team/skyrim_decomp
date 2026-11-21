// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkQsTransform; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkQuaternion_eff9c81f.h"
#include "hkVector4.h"
struct hkQsTransform {
    hkVector4 translation;
    hkQuaternion_eff9c81f rotation;
    hkVector4 scale;
};
static_assert(sizeof(hkQsTransform) == 48, "hkQsTransform layout differs from the PDB");
