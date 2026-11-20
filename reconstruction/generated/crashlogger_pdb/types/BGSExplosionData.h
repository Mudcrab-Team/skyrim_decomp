// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSExplosionData; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_a4a94b8a.h"
#include "SOUND_LEVEL.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSProjectile_dfe2d43e;
struct BGSSoundDescriptorForm;
struct TESObjectLIGH_a35fc737;
struct TESObjectREFR_b225f218;
struct BGSExplosionData {
    TESObjectLIGH_a35fc737* light;
    BGSSoundDescriptorForm* sound1;
    BGSSoundDescriptorForm* sound2;
    BGSImpactDataSet_e1a4fffc* impactDataSet;
    TESObjectREFR_b225f218* impactPlacedObject;
    BGSProjectile_dfe2d43e* spawnProjectile;
    float force;
    float damage;
    float radius;
    float imageSpaceRadius;
    float verticalOffsetMult;
    Flag_a4a94b8a flags;
    SOUND_LEVEL eSoundLevel;
    unsigned int pad4C;
};
static_assert(sizeof(BGSExplosionData) == 80, "BGSExplosionData layout differs from the PDB");
