// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Actor; size 0x2b8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "ActorState.h"
#include "ActorValueOwner_a5cb15e5.h"
#include "ActorValueStorage_7a14662e.h"
#include "ActorValueStorage__Modifiers.h"
#include "Actor__ACTOR_CRITICAL_STAGE.h"
#include "Actor__BOOL_BITS.h"
#include "Actor__BOOL_FLAGS.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_SpellItem__BSTSmallArrayHeapAllocator_8.h"
#include "BSTEventSink_RE__BSTransformDeltaEvent_c065a1f9.h"
#include "BSTEventSink_RE__bhkCharacterMoveFinishEvent_248c3d00.h"
#include "BSTSmartPointer_BipedAnim_7055920d.h"
#include "BSTSmartPointer_MovementControllerNPC_9c241e9f.h"
#include "CRITICAL_SECTION_9c93bfc5.h"
#include "EmotionType.h"
#include "IPostAnimationChannelUpdateFunctor.h"
#include "NiPoint3_a7124070.h"
#include "TESObjectREFR.h"
struct ActorMagicCaster;
struct ActorMover;
struct ActorProcess;
struct BGSDialogueBranch;
struct BGSLocation_075ae773;
struct CombatController_f906bf3b;
struct TESFaction;
struct TESForm_4074aa87;
struct TESPackage;
struct TESRace_e57679c0;
struct Actor {
    TESObjectREFR _base;
    unsigned char undefined_a0[16];
    ActorValueOwner_a5cb15e5 _base_ActorValueOwner;
    ActorState _base_ActorState;
    BSTEventSink_RE__BSTransformDeltaEvent_c065a1f9 _base_BSTEventSink_RE_BSTransformDeltaEvent_;
    BSTEventSink_RE__bhkCharacterMoveFinishEvent_248c3d00 _base_BSTEventSink_RE_bhkCharacterMoveFinishEvent_;
    IPostAnimationChannelUpdateFunctor _base_IPostAnimationChannelUpdateFunctor;
    Actor__BOOL_BITS boolBits;
    float updateTargetTimer;
    Actor__ACTOR_CRITICAL_STAGE criticalStage;
    unsigned int pad0EC;
    ActorProcess* currentProcess;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 dialogueItemTarget;
    BSPointerHandle_RE__Actor_1a35f4b9 currentCombatTarget;
    BSPointerHandle_RE__Actor_1a35f4b9 myKiller;
    float checkMyDeadBodyTimer;
    float voiceTimer;
    float underWaterTimer;
    int thiefCrimeStamp;
    int actionValue;
    float timerOnAction;
    unsigned int unk11C;
    NiPoint3_a7124070 editorLocCoord;
    float editorLocRot;
    TESForm_4074aa87* editorLocForm;
    BGSLocation_075ae773* editorLocation;
    ActorMover* actorMover;
    BSTSmartPointer_MovementControllerNPC_9c241e9f movementController;
    TESPackage* unk150;
    CombatController_f906bf3b* combatController;
    TESFaction* vendorFaction;
    AITimeStamp calculateVendorFactionTimer;
    EmotionType emotionType;
    unsigned int emotionValue;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int intimidateBribeDayStamp;
    unsigned long long unk180;
    BSTArray_SpellItem__BSTSmallArrayHeapAllocator_8 addedSpells;
    ActorMagicCaster* magicCasters[4];
    TESForm_4074aa87* selectedSpells[4];
    TESForm_4074aa87* selectedPower;
    unsigned int unk1E8;
    unsigned int pad1EC;
    TESRace_e57679c0* race;
    float equippedWeight;
    Actor__BOOL_FLAGS boolFlags;
    ActorValueStorage_7a14662e avStorage;
    BGSDialogueBranch* exclusiveBranch;
    ActorValueStorage__Modifiers healthModifiers;
    ActorValueStorage__Modifiers magickaModifiers;
    ActorValueStorage__Modifiers staminaModifiers;
    ActorValueStorage__Modifiers voicePointsModifiers;
    float lastUpdate;
    unsigned int lastSeenTime;
    BSTSmartPointer_BipedAnim_7055920d biped;
    float armorRating;
    float armorBaseFactorSum;
    char soundCallBackSet;
    unsigned char unk271;
    unsigned char unk272;
    unsigned char unk273;
    unsigned int unk274;
    unsigned long long unk278;
    unsigned long long unk280;
    CRITICAL_SECTION_9c93bfc5 unk288;
    unsigned char undefined_2b0[8];
};
static_assert(sizeof(Actor) == 696, "Actor layout differs from the PDB");
