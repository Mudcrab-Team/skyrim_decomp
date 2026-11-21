// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HitData; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ActorValue.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "Enum_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_a9e1cf5e.h"
#include "Flag_d5bcd2af.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__BGSAttackData_03e8c1e0.h"
struct MagicItem;
struct SpellItem;
struct TESObjectWEAP;
struct VATSCommand_c72ce330;
struct HitData {
    NiPoint3_a7124070 hitPosition;
    NiPoint3_a7124070 hitDirection;
    BSPointerHandle_RE__Actor_1a35f4b9 aggressor;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 sourceRef;
    unsigned int pad24;
    NiPointer_RE__BGSAttackData_03e8c1e0 attackData;
    TESObjectWEAP* weapon;
    MagicItem* criticalEffect;
    SpellItem* attackDataSpell;
    VATSCommand_c72ce330* VATSCommand;
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
    Flag_d5bcd2af flags;
    unsigned int equipIndex;
    ActorValue skill;
    Enum_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_a9e1cf5e damageLimb;
};
static_assert(sizeof(HitData) == 144, "HitData layout differs from the PDB");
