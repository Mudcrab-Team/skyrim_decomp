// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EffectSettingData; size 0xf0
#pragma once

#include "ActorValue_a2156ae9.h"
#include "ArchetypeID.h"
#include "CastingType.h"
#include "Delivery.h"
#include "Flag_a4a94b8a.h"
#include "SOUND_LEVEL.h"
struct BGSArtObject_14762d66;
struct BGSDualCastData;
struct BGSExplosion_c355258c;
struct BGSImpactDataSet_e1a4fffc;
struct BGSPerk_dfc65d7f;
struct BGSProjectile_dfe2d43e;
struct BGSReferenceEffect;
struct SpellItem_847bf892;
struct TESEffectShader;
struct TESForm;
struct TESImageSpaceModifier;
struct TESObjectLIGH_a35fc737;
struct EffectSettingData {
    Flag_a4a94b8a flags;
    float baseCost;
    TESForm* associatedForm;
    ActorValue_a2156ae9 associatedSkill;
    ActorValue_a2156ae9 resistVariable;
    short numCounterEffects;
    unsigned short pad1A;
    unsigned int pad1C;
    TESObjectLIGH_a35fc737* light;
    float taperWeight;
    unsigned int pad2C;
    TESEffectShader* effectShader;
    TESEffectShader* enchantShader;
    int minimumSkill;
    int spellmakingArea;
    float spellmakingChargeTime;
    float taperCurve;
    float taperDuration;
    float secondAVWeight;
    ArchetypeID archetype;
    ActorValue_a2156ae9 primaryAV;
    BGSProjectile_dfe2d43e* projectileBase;
    BGSExplosion_c355258c* explosion;
    CastingType castingType;
    Delivery delivery;
    unsigned char secondaryAV_raw[8];
    BGSArtObject_14762d66* castingArt;
    BGSArtObject_14762d66* hitEffectArt;
    BGSImpactDataSet_e1a4fffc* impactDataSet;
    float skillUsageMult;
    unsigned int pad9C;
    BGSDualCastData* dualCastData;
    float dualCastScale;
    unsigned int padAC;
    BGSArtObject_14762d66* enchantEffectArt;
    BGSReferenceEffect* hitVisuals;
    BGSReferenceEffect* enchantVisuals;
    SpellItem_847bf892* equipAbility;
    TESImageSpaceModifier* imageSpaceMod;
    BGSPerk_dfc65d7f* perk;
    SOUND_LEVEL castingSoundLevel;
    float aiScore;
    float aiDelayTimer;
    unsigned int padEC;
};
static_assert(sizeof(EffectSettingData) == 240, "EffectSettingData layout differs from the PDB");
