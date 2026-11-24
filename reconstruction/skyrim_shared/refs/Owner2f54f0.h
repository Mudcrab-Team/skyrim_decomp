// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Code origin: Stamped as a twin of matched 0x2f10d0 (skyrim_shared/refs/TESObjectREFR_2ef670): source copied, names replaced by placeholders.
// Origin: reconstructed from target and sibling hints.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2436
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3193
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function2f54f0, Owner2f54f0: GUESS(low) STANDIN
#pragma once
#include "TESObjectREFR_2ef670.h"

class Owner2f54f0 : public TESForm {
public:
    virtual void Predestroy();
    virtual BGSLocation* GetEditorLocation1() const;
    virtual bool GetEditorLocation2(NiPoint3&, NiPoint3&, TESForm*&, TESObjectCELL*);
    virtual void ForceEditorLocation(BGSLocation*);
    virtual void Update3DPosition(bool);
    virtual void UpdateSoundCallBack(bool);
    virtual bool SetDialogueWithPlayer(bool, bool, TESTopicInfo*);
    virtual void DamageObject(float, bool);
    virtual bool GetFullLODRef() const;
    virtual void SetFullLODRef(bool);
    virtual BGSAnimationSequencer* GetSequencer() const;
    virtual bool QCanUpdateSync() const;
    virtual bool GetAllowPromoteToPersistent() const;
    virtual bool HasKeywordHelper(const BGSKeyword*) const;
    virtual TESPackage* CheckForCurrentAliasPackage();
    virtual BGSScene* GetCurrentScene() const;
    virtual void SetCurrentScene(BGSScene*);
    virtual bool UpdateInDialogue(DialogueResponse*, bool);
    virtual BGSDialogueBranch* GetExclusiveBranch() const;
    virtual void SetExclusiveBranch(BGSDialogueBranch*);
    virtual void PauseCurrentDialogue();
    virtual void SetActorCause(ActorCause*);
    virtual ActorCause* GetActorCause() const;
    virtual NiPoint3 GetStartingAngle() const;
    virtual NiPoint3 GetStartingLocation() const;
    virtual void SetStartingPosition(const NiPoint3&);
    virtual void UpdateRefLight();
    virtual ObjectRefHandle RemoveItem(TESBoundObject*, std::int32_t, ITEM_REMOVE_REASON, ExtraDataList*, Owner2f54f0*, const NiPoint3*, const NiPoint3*);
    virtual bool AddWornItem(TESBoundObject*, std::int32_t, bool, std::uint32_t, std::uint32_t);
    virtual void DoTrap1(TrapData&);
    virtual void DoTrap2(TrapEntry*, TargetEntry*);
    virtual void AddObjectToContainer(TESBoundObject*, ExtraDataList*, std::int32_t, Owner2f54f0*);
    virtual NiPoint3 GetLookingAtLocation() const;
    virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource);
    virtual MagicTarget* GetMagicTarget();
    virtual bool IsChild() const;
    virtual TESActorBase* GetTemplateActorBase();
    virtual void SetTemplateActorBase(TESActorBase*);
    virtual BSFaceGenNiNode* GetFaceNodeSkinned();
    virtual BSFaceGenNiNode* GetFaceNode();
    virtual BSFaceGenAnimationData* GetFaceGenAnimationData();
    virtual bool ClampToGround();
    virtual bool DetachHavok(NiAVObject*);
    virtual void InitHavok();
    virtual void Unk_67(); virtual void Unk_68(); virtual void Unk_69();
    virtual NiAVObject* Load3D(bool);
    virtual void Release3DRelatedData();
    virtual void Set3D(NiAVObject*, bool);
    virtual bool ShouldBackgroundClone() const;
    virtual void Unk_6E();
    virtual NiAVObject* Get3D1(bool) const;
    virtual NiAVObject* Get3D2() const;
    virtual bool Is3rdPersonVisible() const;
    virtual bool PopulateGraphProjectsToLoad() const;
    virtual NiPoint3 GetBoundMin() const;
    virtual NiPoint3 GetBoundMax() const;
    virtual void Unk_75();
    virtual bool InitNonNPCAnimation(NiNode&);
    virtual bool CheckAndFixSkinAndBoneOrder(NiNode&);
    virtual void Unk_78();
    virtual void ModifyAnimationUpdateData(BSAnimationUpdateData&);
    virtual bool ShouldSaveAnimationOnUnloading() const;
    virtual bool ShouldSaveAnimationOnSaving() const;
    virtual bool ShouldPerformRevert() const;
    virtual void UpdateAnimation(float);
    virtual const BSTSmartPointer<BipedAnim>& GetBiped1(bool) const;
    virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;
    virtual const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const;
    NiAVObject* Get3D() const;
    void Function2f54f0(bool force);
};

