// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LaunchData; size 0xa8
#pragma once

#include "CastingSource.h"
#include "NiPoint3.h"
struct AlchemyItem_e992fb73;
struct BGSProjectile_dfe2d43e;
struct CombatController;
struct EnchantmentItem_57a0edce;
struct LaunchData_vtbl;
struct MagicItem_34516af4;
struct TESAmmo;
struct TESObjectCELL_f81013b3;
struct TESObjectREFR_b225f218;
struct TESObjectWEAP_335e104b;
struct LaunchData {
    LaunchData_vtbl* __vftable;
    NiPoint3 origin;
    NiPoint3 contactNormal;
    BGSProjectile_dfe2d43e* projectileBase;
    TESObjectREFR_b225f218* shooter;
    CombatController* combatController;
    TESObjectWEAP_335e104b* weaponSource;
    TESAmmo* ammoSource;
    float angleZ;
    float angleX;
    void* unk50;
    TESObjectREFR_b225f218* desiredTarget;
    float unk60;
    float unk64;
    TESObjectCELL_f81013b3* parentCell;
    MagicItem_34516af4* spell;
    CastingSource castingSource;
    unsigned int pad7C;
    EnchantmentItem_57a0edce* enchantItem;
    AlchemyItem_e992fb73* poison;
    int area;
    float power;
    float scale;
    bool alwaysHit;
    bool noDamageOutsideCombat;
    bool autoAim;
    bool chainShatter;
    bool useOrigin;
    bool deferInitialization;
    bool forceConeOfFire;
    unsigned char undefined_a3[5];
};
static_assert(sizeof(LaunchData) == 168, "LaunchData layout differs from the PDB");
