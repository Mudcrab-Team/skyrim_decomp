// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEffectShader; size 0x220
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EffectShaderData.h"
#include "TESForm.h"
#include "TESTexture.h"
struct TESEffectShader {
    TESForm _base;
    EffectShaderData data;
    TESTexture fillTexture;
    TESTexture particleShaderTexture;
    TESTexture holesTexture;
    TESTexture membranePaletteTexture;
    TESTexture particlePaletteTexture;
    void* unk210;
    void* unk218;
};
static_assert(sizeof(TESEffectShader) == 544, "TESEffectShader layout differs from the PDB");
