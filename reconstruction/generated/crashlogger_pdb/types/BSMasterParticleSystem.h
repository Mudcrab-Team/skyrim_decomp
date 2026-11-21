// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMasterParticleSystem; size 0x168
#pragma once

#include "BSTArray_RE__NiParticles_2bee0f98.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "NiNode.h"
struct BSMasterParticleSystem {
    NiNode _base;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 emitterObjs;
    BSTArray_RE__NiParticles_2bee0f98 particles;
    int index;
    unsigned int unk15C;
    unsigned short unk160;
    unsigned short maxEmitterObj;
    unsigned short maxParticlesPerFrame;
    bool destroyWhenNotInUse;
    unsigned char pad167;
};
static_assert(sizeof(BSMasterParticleSystem) == 360, "BSMasterParticleSystem layout differs from the PDB");
