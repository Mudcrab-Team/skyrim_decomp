// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSExplosionData; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_d5bcd2af.h"
#include "SOUND_LEVEL_ea79a10f.h"
struct BGSImpactDataSet;
struct BGSProjectile;
struct BGSSoundDescriptorForm_de361764;
struct TESObjectLIGH;
struct TESObjectREFR;
struct BGSExplosionData_b4630b42 {
    TESObjectLIGH* light;
    BGSSoundDescriptorForm_de361764* sound1;
    BGSSoundDescriptorForm_de361764* sound2;
    BGSImpactDataSet* impactDataSet;
    TESObjectREFR* impactPlacedObject;
    BGSProjectile* spawnProjectile;
    float force;
    float damage;
    float radius;
    float imageSpaceRadius;
    float verticalOffsetMult;
    Flag_d5bcd2af flags;
    SOUND_LEVEL_ea79a10f eSoundLevel;
    unsigned int pad4C;
};
static_assert(sizeof(BGSExplosionData_b4630b42) == 80, "BGSExplosionData_b4630b42 layout differs from the PDB");
