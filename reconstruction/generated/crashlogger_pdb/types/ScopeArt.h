// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScopeArt; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESModel_c52655e4.h"
struct TESEffectShader;
struct ScopeArt {
    TESModel_c52655e4 unk00;
    TESEffectShader* unk28;
};
static_assert(sizeof(ScopeArt) == 48, "ScopeArt layout differs from the PDB");
