// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDualCastDataDEF; size 0x30
#pragma once

#include "Flags_fa7f7281.h"
struct BGSArtObject_14762d66;
struct BGSExplosion_c355258c;
struct BGSImpactDataSet_e1a4fffc;
struct BGSProjectile_dfe2d43e;
struct TESEffectShader;
struct BGSDualCastDataDEF {
    BGSProjectile_dfe2d43e* pProjectile;
    BGSExplosion_c355258c* pExplosion;
    TESEffectShader* pEffectShader;
    BGSArtObject_14762d66* pHitEffectArt;
    BGSImpactDataSet_e1a4fffc* pImpactDataSet;
    Flags_fa7f7281 flags;
    unsigned int pad30;
};
static_assert(sizeof(BGSDualCastDataDEF) == 48, "BGSDualCastDataDEF layout differs from the PDB");
