// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiLight; size 0x140
// one of 2 different PDB types sharing this name
#pragma once

#include "NiAVObject_968dc716.h"
#include "NiColor.h"
#include "NiPoint3_a7124070.h"
struct NiLight_ca3e8036 {
    NiAVObject_968dc716 _base;
    NiColor ambient;
    NiColor diffuse;
    NiPoint3_a7124070 radius;
    float fade;
    unsigned int unk;
    unsigned int pad13C;
};
static_assert(sizeof(NiLight_ca3e8036) == 320, "NiLight_ca3e8036 layout differs from the PDB");
