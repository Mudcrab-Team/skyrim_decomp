// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSShaderParticleGeometryData; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSShaderParticleGeometryData__SETTING_VALUE_ea026cc6.h"
#include "TESForm.h"
#include "TESTexture.h"
struct BGSShaderParticleGeometryData_cc38b210 {
    TESForm _base;
    BSTArray_RE__BGSShaderParticleGeometryData__SETTING_VALUE_ea026cc6 data;
    TESTexture particleTexture;
};
static_assert(sizeof(BGSShaderParticleGeometryData_cc38b210) == 72, "BGSShaderParticleGeometryData_cc38b210 layout differs from the PDB");
