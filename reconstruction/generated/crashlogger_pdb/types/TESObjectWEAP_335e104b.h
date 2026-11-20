// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectWEAP; size 0x220
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSBlockBashData_e0d1e6c1.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSMessageIcon_87c00b71.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "BGSPreloadable_c2823740.h"
#include "BSFixedString_char_83b572b4.h"
#include "CriticalData.h"
#include "SOUND_LEVEL.h"
#include "TESAttackDamageForm.h"
#include "TESBoundObject_fc790793.h"
#include "TESDescription.h"
#include "TESEnchantableForm_beee0919.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSSoundDescriptorForm;
struct ScopeArt;
struct TESObjectSTAT;
struct TESObjectWEAP_335e104b {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    TESEnchantableForm_beee0919 _base_TESEnchantableForm;
    TESValueForm _base_TESValueForm;
    TESWeightForm _base_TESWeightForm;
    TESAttackDamageForm _base_TESAttackDamageForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSEquipType _base_BGSEquipType;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    BGSBlockBashData_e0d1e6c1 _base_BGSBlockBashData;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    TESDescription _base_TESDescription;
    unsigned char weaponData_raw[56];
    CriticalData criticalData;
    ScopeArt* scopeArt;
    BGSSoundDescriptorForm* attackSound;
    BGSSoundDescriptorForm* attackSound2D;
    BGSSoundDescriptorForm* attackLoopSound;
    BGSSoundDescriptorForm* attackFailSound;
    BGSSoundDescriptorForm* idleSound;
    BGSSoundDescriptorForm* equipSound;
    BGSSoundDescriptorForm* unequipSound;
    BGSImpactDataSet_e1a4fffc* impactDataSet;
    TESObjectSTAT* firstPersonModelObject;
    TESObjectWEAP_335e104b* templateWeapon;
    BSFixedString_char_83b572b4 embeddedNode;
    SOUND_LEVEL soundLevel;
    unsigned int pad21C;
};
static_assert(sizeof(TESObjectWEAP_335e104b) == 544, "TESObjectWEAP_335e104b layout differs from the PDB");
