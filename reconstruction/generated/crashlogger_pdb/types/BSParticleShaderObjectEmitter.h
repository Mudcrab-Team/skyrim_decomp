// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderObjectEmitter; size 0xee0
#pragma once

#include "BSParticleShaderEmitter_8e4e6f31.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct NiAVObject;
struct BSParticleShaderObjectEmitter {
    BSParticleShaderEmitter_8e4e6f31 _base;
    NiPointer_RE__NiAVObject_9e3aa701 targetRoot;
    NiAVObject* boundsObject;
};
static_assert(sizeof(BSParticleShaderObjectEmitter) == 3808, "BSParticleShaderObjectEmitter layout differs from the PDB");
