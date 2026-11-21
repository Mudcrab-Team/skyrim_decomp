// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleSystemManager; size 0x148
#pragma once

#include "NiNode.h"
struct BSMasterParticleSystem;
struct BSParticleSystemManager {
    NiNode _base;
    BSMasterParticleSystem** masterParticleSystems;
    unsigned int masterParticleSystemsCapacity;
    unsigned int unk134;
    unsigned int masterParticleSystemsCount;
    unsigned int unk13C;
    void* unk140;
};
static_assert(sizeof(BSParticleSystemManager) == 328, "BSParticleSystemManager layout differs from the PDB");
