// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ParticleShader; size 0x10
#pragma once

#include "NiPointer_RE__BSParticleShaderObjectEmitter_c9964fde.h"
#include "NiPointer_RE__BSParticleShaderProperty_3f6a5bbf.h"
struct ParticleShader {
    NiPointer_RE__BSParticleShaderProperty_3f6a5bbf particleShaderProp;
    NiPointer_RE__BSParticleShaderObjectEmitter_c9964fde particleEmitter;
};
static_assert(sizeof(ParticleShader) == 16, "ParticleShader layout differs from the PDB");
