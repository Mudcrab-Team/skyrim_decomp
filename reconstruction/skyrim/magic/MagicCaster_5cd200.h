// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicCaster, MagicCaster::SetCurrentSpell, MagicCaster::~MagicCaster, MagicCaster::CastSpellImmediate, MagicCaster::FindTouchTarget, MagicCaster::RequestCastImpl, MagicCaster::StartChargeImpl, MagicCaster::StartReadyImpl, MagicCaster::StartCastImpl, MagicCaster::FinishCastImpl, MagicCaster::InterruptCastImpl, MagicCaster::SpellCast, MagicCaster::CheckCast, MagicCaster::GetCasterStatsObject, MagicCaster::GetCasterAsActor, MagicCaster::GetCasterObjectReference, MagicCaster::GetMagicNode, MagicCaster::ClearMagicNode, MagicCaster::SetCurrentSpellImpl, MagicCaster::SelectSpellImpl, MagicCaster::DeselectSpellImpl, MagicCaster::SetSkipCheckCast, MagicCaster::SetCastingTimerForCharge, MagicCaster::GetCastingSource, MagicCaster::GetIsDualCasting, MagicCaster::SetDualCasting, MagicCaster::SaveGame, MagicCaster::LoadGame, MagicCaster::FinishLoadGame, MagicCaster::PrepareSound, MagicCaster::AdjustActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItem, TESObjectREFR, Actor, NiNode, BGSSaveGameBuffer, BGSLoadGameBuffer, ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicCaster::SetCurrentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SIBLING(fo4-private@1b765c70, author-permission)
// currentSpell, state, castingTimer, currentSpellCost, magnitudeOverride, nextTargetUpdate, projectileTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicSystem, CannotCastReason, CastingSource, SoundID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque enums, only the names the slots mention
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItem;
class TESObjectREFR;
class Actor;
class NiNode;
class BGSSaveGameBuffer;
class BGSLoadGameBuffer;
class ActiveEffect;

namespace MagicSystem
{
    enum class CannotCastReason : std::uint32_t;
    enum class CastingSource : std::uint32_t;
    enum class SoundID : std::uint32_t;
}

class MagicCaster
{
public:
    virtual ~MagicCaster();  // 00
    virtual void CastSpellImmediate(MagicItem* a_spell, bool a_noHitEffectArt, TESObjectREFR* a_target, float a_effectiveness, bool a_hostileEffectivenessOnly, float a_magnitudeOverride, Actor* a_blameActor);  // 01
    virtual void FindTouchTarget();  // 02
    virtual void RequestCastImpl();  // 03
    virtual bool StartChargeImpl();  // 04
    virtual void StartReadyImpl();  // 05
    virtual void StartCastImpl();  // 06
    virtual void FinishCastImpl();  // 07
    virtual void InterruptCastImpl(bool a_depleteEnergy);  // 08
    virtual void SpellCast(bool a_doCast, std::uint32_t a_arg2, MagicItem* a_spell);  // 09
    virtual bool CheckCast(MagicItem* a_spell, bool a_dualCast, float* a_effectStrength, MagicSystem::CannotCastReason* a_reason, bool a_useBaseValueForCost);  // 0A
    virtual TESObjectREFR* GetCasterStatsObject() const;  // 0B
    virtual Actor* GetCasterAsActor() const;  // 0C
    virtual TESObjectREFR* GetCasterObjectReference(Actor** a_outCaster) const;  // 0D
    virtual NiNode* GetMagicNode();  // 0E
    virtual void ClearMagicNode();  // 0F
    virtual void SetCurrentSpellImpl(MagicItem* a_spell);  // 10
    virtual void SelectSpellImpl();  // 11
    virtual void DeselectSpellImpl();  // 12
    virtual void SetSkipCheckCast();  // 13
    virtual void SetCastingTimerForCharge();  // 14
    virtual MagicSystem::CastingSource GetCastingSource() const;  // 15
    virtual bool GetIsDualCasting() const;  // 16
    virtual void SetDualCasting(bool a_set);  // 17
    virtual void SaveGame(BGSSaveGameBuffer* a_buf);  // 18
    virtual void LoadGame(BGSLoadGameBuffer* a_buf);  // 19
    virtual void FinishLoadGame(BGSLoadGameBuffer* a_buf);  // 1A
    virtual void PrepareSound(MagicSystem::SoundID a_sound, MagicItem* a_spell);  // 1B
    virtual void AdjustActiveEffect(ActiveEffect* a_activeEffect, float a_power, bool a_arg3);  // 1C
    void SetCurrentSpell(MagicItem* a_spell);  // compared: 0x5cd200

    std::uint8_t unknown08[0x20];  // 08
    MagicItem* currentSpell;  // 28
    std::uint32_t state;  // 30
    float castingTimer;  // 34
    float currentSpellCost;  // 38
    float magnitudeOverride;  // 3C
    float nextTargetUpdate;  // 40
    float projectileTimer;  // 44
};
static_assert(sizeof(MagicCaster) == 0x48, "MagicCaster size");
