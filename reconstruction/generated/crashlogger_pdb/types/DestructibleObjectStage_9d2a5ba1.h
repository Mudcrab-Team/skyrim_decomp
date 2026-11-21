// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DestructibleObjectStage; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__DestructibleObjectStage__DESTRUCTIBLE_OBJECT_STAGE_FLAGS_unsigned_char_40a22bee.h"
struct BGSDebris_f2fddb01;
struct BGSExplosion;
struct TESModelTextureSwap;
struct DestructibleObjectStage_9d2a5ba1 {
    unsigned char modelDamageStage;
    unsigned char healthPercentage;
    EnumSet_RE__DestructibleObjectStage__DESTRUCTIBLE_OBJECT_STAGE_FLAGS_unsigned_char_40a22bee flags;
    unsigned char pad03;
    unsigned int selfDamagePerSecond;
    BGSExplosion* explosion;
    BGSDebris_f2fddb01* debris;
    unsigned int debrisCount;
    unsigned int pad1C;
    TESModelTextureSwap* replacementModel;
};
static_assert(sizeof(DestructibleObjectStage_9d2a5ba1) == 40, "DestructibleObjectStage_9d2a5ba1 layout differs from the PDB");
