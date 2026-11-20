// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the partial magic effect and dual-cast layouts follow the cited declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// EffectSetting, EffectSettingData, TESFullName, BGSMenuDisplayObject, BGSKeywordForm, HasKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSDualCastData, BGSDualCastDataDEF, pProjectile, pExplosion, pHitEffectArt, pImpactDataSet, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSReferenceEffect, artObject, BGSExplosion, BGSProjectile, BGSArtObject, BGSImpactDataSet, BGSKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectSettingData::associatedForm, archetype, projectileBase, explosion, hitEffectArt, impactDataSet, dualCastData, hitVisuals: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// conditions, TESCondition, TESCondition::IsTrue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, FunctionSlot declarations, padding, nameStorage, menuStorage, ArchetypeEntry: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BGSArtObject;
class BGSImpactDataSet;
class BGSProjectile;
class BGSKeyword;
class TESEffectShader;

struct BGSExplosion
{
    std::uint8_t padding000[0xDC];
    std::uint32_t flags;
};

struct BGSDualCastDataDEF
{
    BGSProjectile* pProjectile;
    BGSExplosion* pExplosion;
    TESEffectShader* pEffectShader;
    BGSArtObject* pHitEffectArt;
    BGSImpactDataSet* pImpactDataSet;
    std::uint32_t flags;
};

struct BGSDualCastData
{
    std::uint8_t padding00[0x30];
    BGSDualCastDataDEF data;
};

struct BGSReferenceEffect
{
    std::uint8_t padding00[0x20];
    BGSArtObject* artObject;
};

class TESFullName
{
public:
    virtual ~TESFullName();

private:
    void* nameStorage;
};

class BGSMenuDisplayObject
{
public:
    virtual ~BGSMenuDisplayObject();

private:
    void* menuStorage;
};

class BGSKeywordForm
{
public:
    virtual ~BGSKeywordForm();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual bool HasKeyword(const BGSKeyword* keyword) const;

private:
    std::uint8_t padding08[0x10];
};

class TESCondition
{
public:
    bool IsTrue(TESObjectREFR* subject, TESObjectREFR* target) const;

private:
    void* head;
};

class EffectSetting : public TESForm, public TESFullName, public BGSMenuDisplayObject, public BGSKeywordForm
{
public:
    TESForm* Function14b4f0() const;
    bool HasKeyword(const BGSKeyword* keyword) const override;
    BGSProjectile* Function14b6a0(bool dualCast) const;
    BGSExplosion* Function14b6d0(bool dualCast) const;
    BGSArtObject* Function14b740(bool dualCast) const;
    BGSImpactDataSet* Function14b780(bool dualCast) const;
    bool Function14b7b0() const;
    bool Function14b7e0() const;
    bool Function14b810() const;
    bool Function14b840() const;
    bool Function14b870() const;
    bool Function14b890(TESObjectREFR* subject, TESObjectREFR* target) const;

private:
    struct EffectSettingData
    {
        std::uint8_t padding00[8];
        TESForm* associatedForm;
        std::uint8_t padding10[0x48];
        std::int32_t archetype;
        std::uint8_t padding5C[4];
        BGSProjectile* projectileBase;
        BGSExplosion* explosion;
        std::uint8_t padding70[0x18];
        BGSArtObject* hitEffectArt;
        BGSImpactDataSet* impactDataSet;
        std::uint8_t padding98[8];
        BGSDualCastData* dualCastData;
        std::uint8_t paddingA8[0x10];
        BGSReferenceEffect* hitVisuals;
        std::uint8_t paddingC0[0x30];
    };
    static_assert(sizeof(EffectSettingData) == 0xF0, "effect data size");

    std::uint8_t padding058[0x10];
    EffectSettingData data;
    std::uint8_t padding158[0x38];
    TESCondition conditions;
};
static_assert(sizeof(EffectSetting) == 0x198, "magic effect form size");
