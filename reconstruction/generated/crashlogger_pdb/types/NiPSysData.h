// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPSysData; size 0xa8
#pragma once

#include "NiParticlesData.h"
struct NiParticleInfo;
struct NiPSysData {
    NiParticlesData _base;
    NiParticleInfo* particleInfo;
    float* rotationSpeeds;
    unsigned short addedParticleCount;
    unsigned short addedParticlesBase;
    unsigned int padA4;
};
static_assert(sizeof(NiPSysData) == 168, "NiPSysData layout differs from the PDB");
