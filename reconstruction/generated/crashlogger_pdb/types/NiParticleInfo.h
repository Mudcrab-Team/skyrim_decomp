// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiParticleInfo; size 0x20
#pragma once

#include "NiPoint3.h"
struct NiParticleInfo {
    NiPoint3 velocity;
    float age;
    float lifespan;
    float lastUpdate;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned int pad1C;
};
static_assert(sizeof(NiParticleInfo) == 32, "NiParticleInfo layout differs from the PDB");
