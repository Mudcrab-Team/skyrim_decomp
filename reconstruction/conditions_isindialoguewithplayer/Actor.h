// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, RE/T/TESObjectREFR.h, TESForm.h, RE/E/ExtraDataList.h, RE/M/MagicTarget.h, RE/B/BSHandleRefObject.h, BSAtomic.h, BSTEvent.h, RE/T/TESNPC.h, TESActorBase.h, TESActorBaseData.h, TESContainer.h, TESSpellList.h, TESAIForm.h, TESFullName.h, TESRaceForm.h, RE/B/BGSKeywordForm.h, BGSAttackDataForm.h, BGSPerkRankArray.h, BGSSkinForm.h, BGSDestructibleObjectForm.h and RE/I/IAnimationGraphManagerHolder.h.
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// names: GUESS(low); representation follows pinned community AE declarations and target this adjustment.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once
#include <cstddef>
class TESFileArray; class TESBoundObject; class TESRace; class TESObjectCELL; class LOADED_REF_DATA; class BSExtraData; class SpellDispelData; class AIProcess;
#include "TESForm.h"
struct Point3Short { short x,y,z; };
class TESBoundObject : public TESForm { public: Point3Short boundMin, boundMax; }; class TESBoundAnimObject : public TESBoundObject {};
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class BSHandleRefObject : public NiRefObject {};
template<class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
struct NiPoint3 { float x,y,z; }; struct OBJ_REFR { TESBoundObject* objectReference; NiPoint3 angle, location; };
class BaseExtraList { public: virtual ~BaseExtraList(); BSExtraData* data; void* presence; };
struct BSReadWriteLock { unsigned writerThread, lock; }; class ExtraDataList { public: BaseExtraList extraData; BSReadWriteLock rwlock; };
class BSAnimationGraphEvent; class TESObjectREFR : public TESForm, public BSHandleRefObject, public BSTEventSink<BSAnimationGraphEvent>, public IAnimationGraphManagerHolder { public: void SetObjectReference(TESBoundObject*); OBJ_REFR data; TESObjectCELL* parentCell; LOADED_REF_DATA* loadedData; ExtraDataList extraList; unsigned long long unknownRuntime; unsigned short refScale; signed char modelState; bool preDestroyed; };
class MagicTarget { public: virtual ~MagicTarget(); SpellDispelData* postUpdateDispelList; unsigned char flags; };
class ActorValueOwner { public: virtual ~ActorValueOwner(); };
class IMovementState { public: virtual ~IMovementState(); }; class ActorState : public IMovementState { public: unsigned actorState1, actorState2; };
class BSTransformDeltaEvent; class bhkCharacterMoveFinishEvent; class IPostAnimationChannelUpdateFunctor { public: virtual ~IPostAnimationChannelUpdateFunctor(); };

template<class T> struct ArrayAllocator { T* data; unsigned capacity; }; struct ArrayBase { unsigned size; }; template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
struct ActorBaseData { unsigned actorBaseFlags; short magickaOffset, staminaOffset; unsigned short level, calcLevelMin, calcLevelMax, speedMult, baseDisposition, templateUseFlags; short healthOffset, bleedoutOverride; };
class TESLevItem; class BGSVoiceType; struct FactionRank;
class TESActorBaseData : public BaseFormComponent { public: ActorBaseData actorData; TESLevItem* deathItem; BGSVoiceType* voiceType; TESForm* baseTemplateForm; TESForm** templateForms; Array<FactionRank> factions; };
class ContainerObject; class TESContainer : public BaseFormComponent { public: ContainerObject** containerObjects; unsigned numContainerObjects; bool allowStolenItems; };
class SpellData; class TESSpellList : public BaseFormComponent { public: SpellData* actorEffects; };
class TESPackage; template<class T> struct SimpleList { T* item; SimpleList* next; };
struct AIData { unsigned char aggressionConfidenceEnergy, energyMoralityMood, moodAssistance, unused; unsigned short aggroRadius[3]; unsigned char noSlowApproach, unusedEnd; };
class TESAIForm : public BaseFormComponent { public: AIData aiData; SimpleList<TESPackage> aiPackages; };
class TESFullName : public BaseFormComponent { public: virtual unsigned int GetFullNameLength() const; virtual const char* GetFullName() const; const char* fullName; };
class DestructibleObjectData; class BGSDestructibleObjectForm : public BaseFormComponent { public: DestructibleObjectData* data; };
class TESObjectARMO; class BGSSkinForm : public BaseFormComponent { public: TESObjectARMO* skin; };
class BGSKeyword; class BGSKeywordForm : public BaseFormComponent { public: BGSKeyword** keywords; unsigned numKeywords; };
class BGSAttackDataMap; class BGSAttackDataForm : public BaseFormComponent { public: BGSAttackDataMap* attackDataMap; };
class PerkRankData; class BGSPerkRankArray : public BaseFormComponent { public: PerkRankData* perks; unsigned perkCount; };
class TESActorBase : public TESBoundAnimObject, public TESActorBaseData, public TESContainer, public TESSpellList, public TESAIForm, public TESFullName, public ActorValueOwner, public BGSDestructibleObjectForm, public BGSSkinForm, public BGSKeywordForm, public BGSAttackDataForm, public BGSPerkRankArray {};
class TESRaceForm : public BaseFormComponent { public: TESRace* race; }; class TESNPC : public TESActorBase, public TESRaceForm {};
class BGSLocation; class ActorMover; class MovementControllerNPC; class CombatController; class TESFaction; class ActorMagicCaster; class MagicItem; class SpellItem;
struct SmallSpellAllocator { unsigned capacity:31; unsigned local:1; union { SpellItem* localSpell; SpellItem** heap; }; }; struct SmallSpellArray : SmallSpellAllocator, ArrayBase {};
class Actor : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState, public BSTEventSink<BSTransformDeltaEvent>, public BSTEventSink<bhkCharacterMoveFinishEvent>, public IPostAnimationChannelUpdateFunctor { public: unsigned boolBits; float updateTargetTimer; unsigned criticalStage; AIProcess* currentProcess; unsigned dialogueItemTarget, currentCombatTarget, myKiller; float checkMyDeadBodyTimer, voiceTimer, underWaterTimer; int thiefCrimeStamp, actionValue; float timerOnAction; unsigned unk11C; NiPoint3 editorLocCoord; float editorLocRot; TESForm* editorLocForm; BGSLocation* editorLocation; ActorMover* actorMover; MovementControllerNPC* movementController; TESPackage* unk150; CombatController* combatController; TESFaction* vendorFaction; unsigned calculateVendorFactionTimer, emotionType, emotionValue, unk174, unk178, intimidateBribeDayStamp; unsigned long long unk180; SmallSpellArray addedSpells; ActorMagicCaster* magicCasters[4]; MagicItem* selectedSpells[4]; TESForm* selectedPower; unsigned unk1E8, pad1EC; TESRace* race; void SetObjectReference(TESBoundObject*); };
static_assert(sizeof(TESObjectREFR)==0xA0, "reference layout");
static_assert(sizeof(TESActorBase)==0x150, "actor base layout");
static_assert(offsetof(Actor, race)==0x1F8, "actor race");
static_assert(offsetof(TESNPC, race)==0x158, "npc race");
