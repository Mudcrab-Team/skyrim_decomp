// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderEmitter; size 0xed0
// one of 2 different PDB types sharing this name
#pragma once

#include "NiRefObject_f24a9221.h"
struct BSParticleShaderProperty;
struct TextureAnimInfo;
struct BSParticleShaderEmitter_8e4e6f31 {
    NiRefObject_f24a9221 _base;
    BSParticleShaderProperty* property;
    unsigned short emitterType;  // EMITTER_TYPE in the PDB is wider than this slot
    unsigned short particleCount;
    float alpha;
    float generateReminder;
    float maxParticleRatio;
    TextureAnimInfo* textureAnims;
    unsigned char instanceData_raw[3744];
};
static_assert(sizeof(BSParticleShaderEmitter_8e4e6f31) == 3792, "BSParticleShaderEmitter_8e4e6f31 layout differs from the PDB");
