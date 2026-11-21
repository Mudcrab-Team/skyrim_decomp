// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEffectShader; size 0x220
// one of 2 different PDB types sharing this name
#pragma once

#include "EffectShaderData_e91d6286.h"
#include "TESForm_4074aa87.h"
#include "TESTexture_fe82fffc.h"
struct BSParticleShaderGeometry;
struct BSParticleShaderProperty_d994b2f7;
struct TESEffectShader_b73bcea8 {
    TESForm_4074aa87 _base;
    EffectShaderData_e91d6286 data;
    TESTexture_fe82fffc fillTexture;
    TESTexture_fe82fffc particleShaderTexture;
    TESTexture_fe82fffc holesTexture;
    TESTexture_fe82fffc membranePaletteTexture;
    TESTexture_fe82fffc particlePaletteTexture;
    BSParticleShaderProperty_d994b2f7* fld210;
    BSParticleShaderGeometry* fld218;
};
static_assert(sizeof(TESEffectShader_b73bcea8) == 544, "TESEffectShader_b73bcea8 layout differs from the PDB");
