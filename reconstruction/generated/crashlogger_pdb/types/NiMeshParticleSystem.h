// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiMeshParticleSystem; size 0x1a0
#pragma once

#include "NiParticleSystem.h"
struct NiMeshParticleSystem {
    NiParticleSystem _base;
    float time;
    bool updateControllers;
    unsigned char pad19D;
    unsigned short pad19E;
};
static_assert(sizeof(NiMeshParticleSystem) == 416, "NiMeshParticleSystem layout differs from the PDB");
