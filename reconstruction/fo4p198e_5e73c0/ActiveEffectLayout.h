// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActiveEffect.h; MIT.
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ActiveEffectReferenceEffectControllerLayout.h"
#include "BSSoundHandleLayout.h"
#include "LayoutValueTypes.h"

class Actor; class TESObjectREFR; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class BSFixedString;
namespace ResearchLayouts {
class Effect;
class MagicItem;
class MagicTarget;
class NiNode;
class ReferenceEffectLayout;
class TESBoundObject;
class ActiveEffectLayout {
public:
    virtual void AdjustForPerks(Actor*, MagicTarget*);
    virtual void OnAdd(MagicTarget*);
    virtual void OnRemove();
    virtual TESObjectREFR* GetVisualsTarget();
    virtual void Update(float);
    virtual void EvaluateConditions(float, bool);
    virtual bool IsCausingHealthDamage();
    virtual void SetLocation(const NiPoint3&);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void FinishLoadGame(BGSLoadFormBuffer*);
    virtual void Revert(BGSLoadFormBuffer*);
    virtual int Compare(ActiveEffectLayout*);
    virtual void HandleEvent(const BSFixedString&);
    virtual void SwitchAttachedRoot(NiNode*, NiNode*);
    virtual void HandleQueuedStart();
    virtual bool ShouldDispelOnDeath() const;
    virtual bool GetAllowMultipleCastingSourceStacking();
    virtual void ClearTargetImpl();
    virtual ~ActiveEffectLayout();
    virtual void Start();
    virtual void Finish();
    virtual bool CanFinish();
    virtual bool CheckCustomSkillUseConditions() const;
    virtual float GetCustomSkillUseMagnitudeMultiplier(float) const;
    void DoStandardCustomSkillUsage(float);

    ActiveEffectReferenceEffectControllerLayout hitEffectController;
    BSSoundHandleLayout persistentSound;
    ActorHandle caster;
    NiPointer<NiNode> sourceNode;
    MagicItem* spell;
    Effect* effect;
    MagicTarget* target;
    TESBoundObject* source;
    BSSimpleList<ReferenceEffectLayout*>* hitEffects;
    MagicItem* displacementSpell;
    float elapsedSeconds;
    float duration;
    float magnitude;
    std::uint32_t flags;
    std::uint32_t conditionStatus;
    std::uint16_t usUniqueID;
    MagicSystem::CastingSource castingSource;
};
static_assert(sizeof(ActiveEffectLayout) == 144, "community represented size");
static_assert(offsetof(ActiveEffectLayout, hitEffectController) == 8, "hitEffectController offset");
static_assert(offsetof(ActiveEffectLayout, persistentSound) == 40, "persistentSound offset");
static_assert(offsetof(ActiveEffectLayout, caster) == 52, "caster offset");
static_assert(offsetof(ActiveEffectLayout, sourceNode) == 56, "sourceNode offset");
static_assert(offsetof(ActiveEffectLayout, spell) == 64, "spell offset");
static_assert(offsetof(ActiveEffectLayout, effect) == 72, "effect offset");
static_assert(offsetof(ActiveEffectLayout, target) == 80, "target offset");
static_assert(offsetof(ActiveEffectLayout, source) == 88, "source offset");
static_assert(offsetof(ActiveEffectLayout, hitEffects) == 96, "hitEffects offset");
static_assert(offsetof(ActiveEffectLayout, displacementSpell) == 104, "displacementSpell offset");
static_assert(offsetof(ActiveEffectLayout, elapsedSeconds) == 112, "elapsedSeconds offset");
static_assert(offsetof(ActiveEffectLayout, duration) == 116, "duration offset");
static_assert(offsetof(ActiveEffectLayout, magnitude) == 120, "magnitude offset");
static_assert(offsetof(ActiveEffectLayout, flags) == 124, "flags offset");
static_assert(offsetof(ActiveEffectLayout, conditionStatus) == 128, "conditionStatus offset");
static_assert(offsetof(ActiveEffectLayout, usUniqueID) == 132, "usUniqueID offset");
static_assert(offsetof(ActiveEffectLayout, castingSource) == 136, "castingSource offset");
}
