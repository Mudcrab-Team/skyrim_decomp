// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSShaderParticleGeometryData; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSShaderParticleGeometryData__SETTINGS_VALUE_VR_e7b445f2.h"
#include "TESForm_4074aa87.h"
#include "TESTexture_fe82fffc.h"
struct BGSShaderParticleGeometryData {
    TESForm_4074aa87 _base;
    BSTArray_RE__BGSShaderParticleGeometryData__SETTINGS_VALUE_VR_e7b445f2 data;
    TESTexture_fe82fffc particleTexture;
};
static_assert(sizeof(BGSShaderParticleGeometryData) == 72, "BGSShaderParticleGeometryData layout differs from the PDB");
