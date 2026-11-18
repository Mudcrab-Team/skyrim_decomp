// Source exposure: mixed
// Origin: authorized sibling and community declarations
// ValueModifierEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:138
// ActiveEffect, ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/ActiveEffect.h and include/RE/V/ValueModifierEffect.h
// names: GUESS(low); signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class Actor; class MagicTarget; class TESObjectREFR; class NiPoint3; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class BSFixedString; class NiNode;
class ActiveEffect {
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
    virtual std::int32_t Compare(ActiveEffect*);
    virtual void HandleEvent(const BSFixedString&);
    virtual void SwitchAttachedRoot(NiNode*,NiNode*);
    virtual void HandleQueuedStart();
    virtual bool ShouldDispelOnDeath() const;
    virtual bool GetAllowMultipleCastingSourceStacking();
    virtual void ClearTargetImpl();
    virtual ~ActiveEffect();
    virtual void Start();
    virtual void Finish();
    virtual bool CanFinish();
    virtual bool CheckCustomSkillUseConditions() const;
    virtual float GetCustomSkillUseMagnitudeMultiplier(float) const;
};
class ValueModifierEffect : public ActiveEffect {
public:
    void Start() override;
    virtual void SetActorValue(std::uint32_t);
    virtual bool ShouldModifyOnStart();
    virtual void ModifyOnStart();
};
