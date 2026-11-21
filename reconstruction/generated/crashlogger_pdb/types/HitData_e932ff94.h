// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HitData; size 0x90
// one of 2 different PDB types sharing this name
#pragma once

#include "ActorValue_a2156ae9.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "Enum_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_a9e1cf5e.h"
#include "Flag_a4a94b8a.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BGSAttackData_03e8c1e0.h"
struct MagicItem_34516af4;
struct SpellItem_847bf892;
struct TESObjectWEAP_335e104b;
struct VATSCommand;
struct HitData_e932ff94 {
    NiPoint3 hitPosition;
    NiPoint3 hitDirection;
    BSPointerHandle_RE__Actor_1a35f4b9 aggressor;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 sourceRef;
    unsigned int pad24;
    NiPointer_RE__BGSAttackData_03e8c1e0 attackData;
    TESObjectWEAP_335e104b* weapon;
    MagicItem_34516af4* criticalEffect;
    SpellItem_847bf892* attackDataSpell;
    struct VATSCommand* VATSCommand;
    float totalDamage;
    float physicalDamage;
    float targetedLimbDamage;
    float percentBlocked;
    float resistedPhysicalDamage;
    float resistedTypedDamage;
    float stagger;
    float sneakAttackBonus;
    float bonusHealthDamageMult;
    float pushBack;
    float reflectedDamage;
    float criticalDamageMult;
    Flag_a4a94b8a flags;
    unsigned int equipIndex;
    ActorValue_a2156ae9 skill;
    Enum_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_a9e1cf5e damageLimb;
};
static_assert(sizeof(HitData_e932ff94) == 144, "HitData_e932ff94 layout differs from the PDB");
