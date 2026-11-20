// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Actor; size 0x2b8
// one of 2 different PDB types sharing this name
#pragma once

#include "ACTOR_CRITICAL_STAGE.h"
#include "AITimeStamp.h"
#include "ActorState_877c2eb1.h"
#include "ActorValueOwner.h"
#include "ActorValueStorage.h"
#include "BOOL_BITS.h"
#include "BOOL_FLAGS.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__SpellItem_RE__BSTSmallArrayHeapAllocator_8_60423499.h"
#include "BSTEventSink_RE__BSTransformDeltaEvent_c065a1f9.h"
#include "BSTEventSink_RE__bhkCharacterMoveFinishEvent_248c3d00.h"
#include "BSTSmartPointer_RE__BipedAnim_9198d0c2.h"
#include "BSTSmartPointer_RE__MovementControllerNPC_645fad2e.h"
#include "CRITICAL_SECTION_9c93bfc5.h"
#include "EmotionType.h"
#include "IPostAnimationChannelUpdateFunctor_d63ea43c.h"
#include "MagicTarget.h"
#include "Modifiers.h"
#include "NiPoint3.h"
#include "TESObjectREFR_b225f218.h"
struct AIProcess;
struct ActorMagicCaster_e125139c;
struct ActorMover;
struct BGSDialogueBranch_10ee3dbc;
struct BGSLocation;
struct CombatController;
struct MagicItem_34516af4;
struct TESFaction_fe5903c5;
struct TESForm;
struct TESPackage_986d2eaa;
struct TESRace;
struct Actor_b2630b95 {
    TESObjectREFR_b225f218 _base;
    MagicTarget _base_MagicTarget;
    ActorValueOwner _base_ActorValueOwner;
    ActorState_877c2eb1 _base_ActorState;
    BSTEventSink_RE__BSTransformDeltaEvent_c065a1f9 _base_BSTEventSink_RE_BSTransformDeltaEvent_;
    BSTEventSink_RE__bhkCharacterMoveFinishEvent_248c3d00 _base_BSTEventSink_RE_bhkCharacterMoveFinishEvent_;
    IPostAnimationChannelUpdateFunctor_d63ea43c _base_IPostAnimationChannelUpdateFunctor;
    BOOL_BITS boolBits;
    float updateTargetTimer;
    ACTOR_CRITICAL_STAGE criticalStage;
    unsigned int pad0EC;
    AIProcess* currentProcess;
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
    NiPoint3 editorLocCoord;
    float editorLocRot;
    TESForm* editorLocForm;
    BGSLocation* editorLocation;
    ActorMover* actorMover;
    BSTSmartPointer_RE__MovementControllerNPC_645fad2e movementController;
    TESPackage_986d2eaa* unk150;
    CombatController* combatController;
    TESFaction_fe5903c5* vendorFaction;
    AITimeStamp calculateVendorFactionTimer;
    EmotionType emotionType;
    unsigned int emotionValue;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int intimidateBribeDayStamp;
    unsigned long long unk180;
    BSTArray_RE__SpellItem_RE__BSTSmallArrayHeapAllocator_8_60423499 addedSpells;
    ActorMagicCaster_e125139c* magicCasters[4];
    MagicItem_34516af4* selectedSpells[4];
    TESForm* selectedPower;
    unsigned int unk1E8;
    unsigned int pad1EC;
    TESRace* race;
    float equippedWeight;
    BOOL_FLAGS boolFlags;
    ActorValueStorage avStorage;
    BGSDialogueBranch_10ee3dbc* exclusiveBranch;
    Modifiers healthModifiers;
    Modifiers magickaModifiers;
    Modifiers staminaModifiers;
    Modifiers voicePointsModifiers;
    float lastUpdate;
    unsigned int lastSeenTime;
    BSTSmartPointer_RE__BipedAnim_9198d0c2 biped;
    float armorRating;
    float armorBaseFactorSum;
    unsigned char soundCallBackSet;
    unsigned char unk271;
    unsigned char unk272;
    unsigned char unk273;
    unsigned int unk274;
    unsigned long long unk278;
    unsigned long long unk280;
    CRITICAL_SECTION_9c93bfc5 unk288;
};
static_assert(sizeof(Actor_b2630b95) == 696, "Actor_b2630b95 layout differs from the PDB");
