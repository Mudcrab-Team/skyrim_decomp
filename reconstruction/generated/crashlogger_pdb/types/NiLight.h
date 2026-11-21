// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiLight; size 0x140
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiAVObject.h"
#include "NiColor_e5e1ad7d.h"
#include "NiPoint3.h"
struct NiLight {
    NiAVObject _base;
    NiColor_e5e1ad7d ambient;
    NiColor_e5e1ad7d diffuse;
    NiPoint3 radius;
    float fade;
    unsigned int unk138;
    unsigned char undefined_13c[4];
};
static_assert(sizeof(NiLight) == 320, "NiLight layout differs from the PDB");
