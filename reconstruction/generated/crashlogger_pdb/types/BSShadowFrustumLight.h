// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShadowFrustumLight; size 0x578
#pragma once

#include "BSShadowLight.h"
struct BSShadowFrustumLight {
    BSShadowLight _base;
    float semiWidth;
    float semiHeight;
    float falloff;
    float nearDistance;
    float farDistance;
    unsigned char undefined_574[4];
};
static_assert(sizeof(BSShadowFrustumLight) == 1400, "BSShadowFrustumLight layout differs from the PDB");
