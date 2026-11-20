// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPointLight; size 0x150
// one of 2 different PDB types sharing this name
#pragma once

#include "NiLight_ca3e8036.h"
struct NiPointLight_7130942c {
    NiLight_ca3e8036 _base;
    float linearAttenuation;
    float quadraticAttenuation;
    unsigned char _tail[8];
};
static_assert(sizeof(NiPointLight_7130942c) == 336, "NiPointLight_7130942c layout differs from the PDB");
