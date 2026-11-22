// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x14b4f0 EffectSetting::Function14b4f0
// 0x14b510 EffectSetting::HasKeyword
// 0x14b6a0 EffectSetting::Function14b6a0
// 0x14b6d0 EffectSetting::Function14b6d0
// 0x14b740 EffectSetting::Function14b740
// 0x14b780 EffectSetting::Function14b780
// 0x14b7b0 EffectSetting::Function14b7b0
// 0x14b7e0 EffectSetting::Function14b7e0
// 0x14b810 EffectSetting::Function14b810
// 0x14b840 EffectSetting::Function14b840
// 0x14b890 EffectSetting::Function14b890
#include "EffectSetting_14b4f0.h"

// ArchetypeEntry, archetypes, keywordFormType: GUESS(low)
struct ArchetypeEntry
{
    std::uint32_t flags;
    std::uint32_t padding04;
    std::uint32_t associatedType;
    std::uint8_t padding0C[0xC];
};
static_assert(sizeof(ArchetypeEntry) == 0x18, "archetype table entry size");

extern const ArchetypeEntry archetypes[];
constexpr auto keywordFormType = static_cast<FormType>(4);

// TestBit: GUESS(low)
inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1u) != 0;
}

TESForm* EffectSetting::Function14b4f0() const
{
    auto* associated = data.associatedForm;
    return associated && associated->formType == keywordFormType ? associated : nullptr;
}

bool EffectSetting::HasKeyword(const BGSKeyword* keyword) const
{
    bool hasKeyword = BGSKeywordForm::HasKeyword(keyword);
    if (!hasKeyword && archetypes[data.archetype].associatedType == static_cast<std::uint32_t>(keywordFormType)) {
        hasKeyword = keyword == reinterpret_cast<const BGSKeyword*>(Function14b4f0());
    }
    return hasKeyword;
}

BGSProjectile* EffectSetting::Function14b6a0(bool dualCast) const
{
    auto* result = data.projectileBase;
    if (dualCast && data.dualCastData) {
        auto* overrideValue = data.dualCastData->data.pProjectile;
        if (overrideValue) {
            result = overrideValue;
        }
    }
    return result;
}

BGSExplosion* EffectSetting::Function14b6d0(bool dualCast) const
{
    auto* result = data.explosion;
    if (dualCast && data.dualCastData) {
        auto* overrideValue = data.dualCastData->data.pExplosion;
        if (overrideValue) {
            result = overrideValue;
        }
    }
    return result;
}

BGSArtObject* EffectSetting::Function14b740(bool dualCast) const
{
    auto* result = data.hitVisuals ? data.hitVisuals->artObject : data.hitEffectArt;
    if (dualCast && data.dualCastData) {
        auto* overrideValue = data.dualCastData->data.pHitEffectArt;
        if (overrideValue) {
            result = overrideValue;
        }
    }
    return result;
}

BGSImpactDataSet* EffectSetting::Function14b780(bool dualCast) const
{
    auto* result = data.impactDataSet;
    if (dualCast && data.dualCastData) {
        auto* overrideValue = data.dualCastData->data.pImpactDataSet;
        if (overrideValue) {
            result = overrideValue;
        }
    }
    return result;
}

bool EffectSetting::Function14b7b0() const
{
    if (data.explosion && TestBit(data.explosion->flags, 7)) {
        return true;
    }
    return false;
}

bool EffectSetting::Function14b7e0() const
{
    const auto* dual = data.dualCastData;
    return dual && dual->data.pHitEffectArt && (dual->data.flags & 1u) == 0;
}

bool EffectSetting::Function14b810() const
{
    const auto* dual = data.dualCastData;
    return dual && dual->data.pProjectile && !TestBit(dual->data.flags, 1);
}

bool EffectSetting::Function14b840() const
{
    const auto* dual = data.dualCastData;
    return dual && dual->data.pExplosion && !TestBit(dual->data.flags, 2);
}

bool EffectSetting::Function14b890(TESObjectREFR* subject, TESObjectREFR* target) const
{
    return conditions.IsTrue(subject, target);
}
