// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectWEAP; size 0x270
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSBlockBashData.h"
#include "BGSDestructibleObjectForm_2db5e126.h"
#include "BGSKeywordForm.h"
#include "BGSLocalizedStringDL_8410e68a.h"
#include "BGSMessageIcon.h"
#include "BSFixedString.h"
#include "CriticalData_98be3296.h"
#include "SOUND_LEVEL.h"
#include "TESBoundObject.h"
#include "TESBoundObject__Data.h"
#include "TESDescription_99869432.h"
#include "TESEnchantableForm.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESIcon.h"
struct BGSImpactDataSet;
struct BGSSoundDescriptorForm_de361764;
struct ScopeArt_9ff67487;
struct SpellItem;
struct TESForm_4074aa87;
struct TESModel;
struct TESObjectSTAT_9b49bb32;
struct TESObjectWEAP {
    TESBoundObject _base;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESObjectWEAP* weapon;
    BSFixedString Text_38;
    SpellItem* attackDataSpell;
    BSFixedString ModelName_48;
    TESIcon _base_TESIcon;
    TESEnchantableForm _base_TESEnchantableForm;
    unsigned short NumTextures_60;
    unsigned short NumAddons_62;
    char _pad_64[4];
    void* AlternateTextures_68;
    int NumAlternateTextures_70;
    char _pad_74[4];
    void* vftable_TESIcon_78;
    BSFixedString TextureName_80;
    void* vftable_TESEnchantableForm_88;
    BGSDestructibleObjectForm_2db5e126 _base_BGSDestructibleObjectForm;
    unsigned short CastingType_98;
    unsigned short AmountOfEnchantment_9A;
    char _pad_9C[4];
    void* vftable_TESValueForm_A0;
    unsigned int ValueAmount_A8;
    char _pad_AC[4];
    BGSMessageIcon _base_BGSMessageIcon;
    float WeightValue_B8;
    char _pad_BC[4];
    void* vftable_TESAttackDamageForm_C0;
    unsigned short AttackDamage_C8;
    char _pad_CA[6];
    BGSBlockBashData _base_BGSBlockBashData;
    BGSKeywordForm _base_BGSKeywordForm;
    TESDescription_99869432 _base_TESDescription;
    TESForm_4074aa87* EquipSlot_E8;
    void* vftable_BGSPreloadable_F0;
    void* vftable_BGSMessageIcon_F8;
    TESIcon Icon_100;
    void* vftable_BGSPickupPutdownSounds_110;
    void* PickupSound_118;
    CriticalData_98be3296 criticalData;
    ScopeArt_9ff67487* scopeArt;
    BGSSoundDescriptorForm_de361764* attackSound;
    BGSSoundDescriptorForm_de361764* attackSound2D;
    BGSSoundDescriptorForm_de361764* attackLoopSound;
    BGSSoundDescriptorForm_de361764* attackFailSound;
    int Count_150;
    char _pad_154[4];
    BGSSoundDescriptorForm_de361764* equipSound;
    unsigned int FileOffset_160;
    BGSLocalizedStringDL_8410e68a DescriptionText_164;
    TESObjectSTAT_9b49bb32* firstPersonModelObject;
    TESObjectWEAP* templateWeapon;
    TESModel* field59_0x208;
    BGSSoundDescriptorForm_de361764* attackSound_2;
    unsigned int pad21C;
    unsigned char _pad_0[4];
    BGSSoundDescriptorForm_de361764* attackLoopSound_2;
    BGSSoundDescriptorForm_de361764* attackFailSound_2;
    BGSSoundDescriptorForm_de361764* idleSound;
    BGSSoundDescriptorForm_de361764* equipSound_2;
    BGSSoundDescriptorForm_de361764* unequipSound;
    BGSImpactDataSet* impactDataSet;
    TESObjectSTAT_9b49bb32* firstPersonModelObject_2;
    TESObjectWEAP* templateWeapon_2;
    BSFixedString EmbeddedNode_210;
    SOUND_LEVEL SoundLevel_218;
    char _pad_21C[4];
};
static_assert(sizeof(TESObjectWEAP) == 624, "TESObjectWEAP layout differs from the PDB");
