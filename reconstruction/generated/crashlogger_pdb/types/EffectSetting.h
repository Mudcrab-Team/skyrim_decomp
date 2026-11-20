// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EffectSetting; size 0x198
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSSimpleList_EffectSetting_f1435147.h"
#include "BSTArray_SoundPair_81c2f5ce.h"
#include "SOUND_LEVEL.h"
#include "TESCondition.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSArtObject;
struct BGSExplosion;
struct BGSImpactDataSet;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSMenuDisplayObject__VFTable;
struct BGSPerk;
struct BGSProjectile;
struct BGSReferenceEffect_f86c67af;
struct EffectSetting__VFTable;
struct SpellItem;
struct TESBoundObject;
struct TESEffectShader_b73bcea8;
struct TESForm_4074aa87;
struct TESFullName__VFTable;
struct TESImageSpaceModifier_d2373462;
struct TESObjectLIGH;
struct EffectSetting {
    EffectSetting__VFTable* vftable_EffectSetting_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    BGSMenuDisplayObject__VFTable* vftable_BGSMenuDisplayObject_30;
    TESBoundObject* MenuDisplayObject_38;
    BGSKeywordForm__VFTable* vftable_BGSKeywordForm_40;
    BGSKeyword_f67121b2** Keywords_48;
    int Count_50;
    char _pad_54[4];
    void* FilterValidationFunction_58;
    void* FilterValidationItem_60;
    unsigned int EffectFlags_68;
    float BaseCost_6C;
    TESForm_4074aa87* AssociatedForm_70;
    int AssociatedSkill_78;
    int ResistVariable_7C;
    short NumCounterEffects_80;
    char _pad_82[6];
    TESObjectLIGH* CastingLight_88;
    float TaperWeight_90;
    char _pad_94[4];
    TESEffectShader_b73bcea8* HitShader_98;
    TESEffectShader_b73bcea8* EnchantShader_A0;
    int MinimumSkill_A8;
    int SpellmakingArea_AC;
    float SpellmakingChargeTime_B0;
    float TaperCurve_B4;
    float TaperDuration_B8;
    float SecondaryActorValueWeight_BC;
    int Archetype_C0;
    int PrimaryActorValue_C4;
    BGSProjectile* MagicProjectile_C8;
    BGSExplosion* Explosion_D0;
    int CastingType_D8;
    int Delivery_DC;
    int SecondaryActorValue_E0;
    char _pad_E4[4];
    BGSArtObject* CastingArt_E8;
    BGSArtObject* HitEffectArt_F0;
    BGSImpactDataSet* ImpactData_F8;
    float SkillUsageMultiplier_100;
    char _pad_104[4];
    BGSArtObject* DualCastingArt_108;
    float DualCastingScale_110;
    char _pad_114[4];
    BGSArtObject* EnchantEffectArt_118;
    BGSReferenceEffect_f86c67af* HitVisuals_120;
    BGSReferenceEffect_f86c67af* EnchantVisuals_128;
    SpellItem* EquipAbility_130;
    TESImageSpaceModifier_d2373462* ImageSpaceModifier_138;
    BGSPerk* Perk_140;
    SOUND_LEVEL CastingSoundLevel_148;
    float AiScore_14C;
    float AiDelayTimer_150;
    char _pad_154[4];
    BSSimpleList_EffectSetting_f1435147 CounterEffects_158;
    BSTArray_SoundPair_81c2f5ce EffectSounds_168;
    BSFixedString MagicItemDescription_180;
    int EffectLoadedCount_188;
    int AssociatedItemLoadedCount_18C;
    TESCondition Conditions_190;
};
static_assert(sizeof(EffectSetting) == 408, "EffectSetting layout differs from the PDB");
