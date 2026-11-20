// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DestructibleObjectStage; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BGSDebris;
struct BGSExplosion_c355258c;
struct TESModelTextureSwap_014aa4ed;
struct DestructibleObjectStage {
    unsigned char modelDamageStage;
    unsigned char healthPercentage;
    unsigned char flags;  // DESTRUCTIBLE_OBJECT_STAGE_FLAGS in the PDB is wider than this slot
    unsigned char pad03;
    unsigned int selfDamagePerSecond;
    BGSExplosion_c355258c* explosion;
    BGSDebris* debris;
    unsigned int debrisCount;
    unsigned int pad1C;
    TESModelTextureSwap_014aa4ed* replacementModel;
};
static_assert(sizeof(DestructibleObjectStage) == 40, "DestructibleObjectStage layout differs from the PDB");
