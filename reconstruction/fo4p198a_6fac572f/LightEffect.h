// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/A/ActiveEffect.h and include/RE/L/LightEffect.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
class Actor; class MagicTarget; class TESObjectREFR; class NiPoint3; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class BSFixedString; class NiNode;
class ActiveEffect { public:
 virtual void AdjustForPerks(Actor*, MagicTarget*); virtual void OnAdd(MagicTarget*); virtual void OnRemove(); virtual TESObjectREFR* GetVisualsTarget(); virtual void Update(float); virtual void EvaluateConditions(float, bool); virtual bool IsCausingHealthDamage(); virtual void SetLocation(const NiPoint3&); virtual void SaveGame(BGSSaveFormBuffer*); virtual void LoadGame(BGSLoadFormBuffer*); virtual void FinishLoadGame(BGSLoadFormBuffer*); virtual void Revert(BGSLoadFormBuffer*); virtual int Compare(ActiveEffect*); virtual void HandleEvent(const BSFixedString&); virtual void SwitchAttachedRoot(NiNode*, NiNode*); virtual void HandleQueuedStart(); virtual bool ShouldDispelOnDeath() const; virtual bool GetAllowMultipleCastingSourceStacking(); virtual void ClearTargetImpl(); virtual ~ActiveEffect(); virtual void Start(); virtual void Finish(); virtual bool CanFinish(); virtual bool CheckCustomSkillUseConditions() const; virtual float GetCustomSkillUseMagnitudeMultiplier(float) const;
};
class LightEffect : public ActiveEffect { public: void FinishLoadGame(BGSLoadFormBuffer*) override; };
