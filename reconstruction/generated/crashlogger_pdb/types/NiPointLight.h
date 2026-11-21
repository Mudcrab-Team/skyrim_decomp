// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPointLight; size 0x150
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiLight.h"
struct NiPointLight {
    NiLight _base;
    float constAttenuation;
    float linearAttenuation;
    float quadraticAttenuation;
    unsigned char undefined_14c[4];
};
static_assert(sizeof(NiPointLight) == 336, "NiPointLight layout differs from the PDB");
