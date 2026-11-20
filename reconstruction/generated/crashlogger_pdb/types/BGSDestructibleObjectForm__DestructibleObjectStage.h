// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDestructibleObjectForm__DestructibleObjectStage; size 0x28
#pragma once

struct BGSDebris_f2fddb01;
struct BGSExplosion;
struct TESModelTextureSwap;
struct BGSDestructibleObjectForm__DestructibleObjectStage {
    char ModelDamageStage_0;
    char HealthPercentage_1;
    unsigned char Flags_2;
    char _pad_3;
    int SelfDamagePerSecond_4;
    BGSExplosion* Explosion_8;
    BGSDebris_f2fddb01* Debris_10;
    int DebrisCount_18;
    char _pad_1C[4];
    TESModelTextureSwap* ReplacementModel_20;
};
static_assert(sizeof(BGSDestructibleObjectForm__DestructibleObjectStage) == 40, "BGSDestructibleObjectForm__DestructibleObjectStage layout differs from the PDB");
