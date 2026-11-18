// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, RE/T/TESObjectREFR.h, TESForm.h, RE/E/ExtraDataList.h, RE/M/MagicTarget.h, RE/B/BSHandleRefObject.h, BSAtomic.h, BSTEvent.h and RE/I/IAnimationGraphManagerHolder.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
class TESFileArray; class TESBoundObject {}; class TESNPC : public TESBoundObject {}; class PerkEntryVisitor; class Actor; class TESFaction { public: unsigned GetCrimeGoldValue(TESNPC*) const; void SetCrimeGoldValue(TESNPC*, unsigned); void ModCrimeGoldValue(TESNPC*, int); }; class TESObjectCELL; class LOADED_REF_DATA; class BSExtraData; class SpellDispelData; class AIProcess { public: float QMaxAlpha(); bool HasBeenAttacked() const; void ForEachPerkEntry(unsigned char, PerkEntryVisitor&) const; void ApplyPerksFromBase(Actor*); void EndDeferredKill(bool, Actor&); bool HasPerkEntries(unsigned char) const; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: TESFileArray* sourceFiles; unsigned formFlags, formID; unsigned short inGameFormFlags; unsigned char formType; unsigned char pad1B; unsigned pad1C; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class BSHandleRefObject : public NiRefObject {};
template<class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
struct NiPoint3 { float x,y,z; }; struct OBJ_REFR { TESBoundObject* objectReference; NiPoint3 angle, location; };
class BaseExtraList { public: virtual ~BaseExtraList(); BSExtraData* data; void* presence; };
struct BSReadWriteLock { unsigned writerThread, lock; }; struct ExtraDataList { BaseExtraList extraData; BSReadWriteLock rwlock; };
class BSAnimationGraphEvent; class TESObjectREFR : public TESForm, public BSHandleRefObject, public BSTEventSink<BSAnimationGraphEvent>, public IAnimationGraphManagerHolder { public: OBJ_REFR data; TESObjectCELL* parentCell; LOADED_REF_DATA* loadedData; ExtraDataList extraList; unsigned long long unknownRuntime; unsigned short refScale; signed char modelState; bool preDestroyed; };
class MagicTarget { public: virtual ~MagicTarget(); SpellDispelData* postUpdateDispelList; unsigned char flags; };
class ActorValueOwner { public: virtual ~ActorValueOwner(); };
class IMovementState { public: virtual ~IMovementState(); }; class ActorState : public IMovementState { public: unsigned actorState1, actorState2; };
class BSTransformDeltaEvent; class bhkCharacterMoveFinishEvent; class IPostAnimationChannelUpdateFunctor { public: virtual ~IPostAnimationChannelUpdateFunctor(); };
class Actor : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState, public BSTEventSink<BSTransformDeltaEvent>, public BSTEventSink<bhkCharacterMoveFinishEvent>, public IPostAnimationChannelUpdateFunctor { public: unsigned boolBits; float updateTargetTimer; unsigned criticalStage; AIProcess* currentProcess; bool HasBeenAttacked() const; int GetProcessLevel(); float GetAlpha(); };
static_assert(sizeof(TESObjectREFR)==0xA0, "reference layout");
