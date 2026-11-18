// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, RE/T/TESObjectREFR.h, TESForm.h, RE/E/ExtraDataList.h, RE/M/MagicTarget.h, RE/B/BSHandleRefObject.h, BSAtomic.h, BSTEvent.h, RE/A/AIProcess.h, ActorPackage.h, RE/P/ProcessLists.h and RE/I/IAnimationGraphManagerHolder.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); helper and globals inferred from target; unknown AIProcess fields follow community declarations.
#pragma once
class TESFileArray; class TESBoundObject; class TESObjectCELL; class LOADED_REF_DATA; class BSExtraData; class SpellDispelData; class AIProcess;
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

class Actor; class TESPackage; class ActorPackageData; class CachedValues; class ObjectsToAcquire; class MiddleLowProcessData; class MiddleHighProcessData; class HighProcessData;
struct ActorPackage { unsigned owningThread, lockCount; TESPackage* package; ActorPackageData* data; unsigned target; int currentProcedureIndex; float packageStartTime; unsigned modifiedPackageFlag; unsigned short modifiedInterruptFlag; signed char actorPackageFlags, preferredSpeed; };
template<class T> struct SimpleList { T* item; SimpleList* next; }; template<class T> struct ArrayAllocator { T* data; unsigned capacity; }; struct ArrayBase { unsigned size; }; template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
struct EquippedObject; struct ProcessData { void* unk00; ProcessData* unk08; void* unk10; void* unk18; unsigned long long unk20; void* unk28; unsigned unk30; };
class AIProcess { public: MiddleLowProcessData* middleLow; MiddleHighProcessData* middleHigh; HighProcessData* high; ActorPackage currentPackage; float unk048; unsigned unk04C; CachedValues* cachedValues; int numberItemsActivate; SimpleList<ObjectsToAcquire> objects; SimpleList<TESObjectREFR> genericLocations; ObjectsToAcquire* acquireObject; ObjectsToAcquire* savedAcquireObject; float essentialDownTimer, deathTime, trackedDamage; Array<EquippedObject> equippedForms; ProcessData unk0B8; TESForm* equippedObjects[2]; unsigned long long unk100, unk108; unsigned followTarget, target; unsigned long long unk118, unk120, unk128; unsigned unk130; unsigned short unk134; unsigned char lowProcessFlags, processLevel; };
class ProcessLists { public: void AddActorToTempChangeList(Actor*); }; extern ProcessLists* processLists;
class TaskQueueInterface { public: void QueueDisableReference(Actor*); }; extern TaskQueueInterface* taskQueue; extern Actor* player;

class Actor : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState, public BSTEventSink<BSTransformDeltaEvent>, public BSTEventSink<bhkCharacterMoveFinishEvent>, public IPostAnimationChannelUpdateFunctor { public: unsigned boolBits; float updateTargetTimer; unsigned criticalStage; AIProcess* currentProcess; void Disable(); void UpdateCriticalStage(); void UpdateLastSeenTime(); };
static_assert(sizeof(TESObjectREFR)==0xA0, "reference layout");
