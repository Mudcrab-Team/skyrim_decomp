// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HighProcessData; size 0x478
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "BGSAnimationSequencer.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSReadWriteLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1.h"
#include "BSTArray_RE__BSTTuple_unsigned_int_RE__NiPointer_RE__ActorKnowledge_98b5b87c_dc4d57bb.h"
#include "BSTArray_RE__QueuedDialogueType_2a40d15e.h"
#include "BSTArray_unsigned_long_long_RE__BSTSmallArrayHeapAllocator_8_d4df0649.h"
#include "BSTSmartPointer_RE__DialogueItem_6093c8e0.h"
#include "BSTSmartPointer_RE__HighProcessData__Data190_280db0e6.h"
#include "BSTSmartPointer_RE__IAnimationSetCallbackFunctor_72f51ba7.h"
#include "BUMP_TYPE.h"
#include "FADE_STATE.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__BGSAttackData_03e8c1e0.h"
#include "NiPointer_RE__NiBillboardNode_acd9a360.h"
#include "NiPointer_RE__NiRefObject_b6c51fb2.h"
#include "NiPointer_RE__StandardDetectionListener_0ddfbe83.h"
#include "PLAYER_ACTION_17d90833.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
#include "TypeData.h"
#include "VOICE_STATE_b918a6f4.h"
#include "VariationID.h"
struct Crime;
struct Data208;
struct DetectionEvent;
struct MagicItem;
struct MuzzleFlash;
struct RE__BSSimpleList_RE__SpellItem_8953e8bd;
struct TESIdleForm;
struct TESObjectREFR;
struct TESShout;
struct TESTopicInfo;
struct HighProcessData {
    VOICE_STATE_b918a6f4 voiceState;
    unsigned int pad004;
    TESShout* currentShout;
    VariationID currentShoutVariation;
    float voiceTimeElapsed;
    float voiceRecoveryTime;
    float healthRegenDelay;
    float staminaRegenDelay;
    float magickaRegenDelay;
    float unk028;
    unsigned int unk02C;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1 lastSpokenToArray;
    unsigned long long unk048;
    BGSAnimationSequencer animSequencer;
    NiPoint3_a7124070 pathingCurrentMovementSpeed;
    NiPoint3_a7124070 pathingCurrentRotationSpeed;
    NiPoint3_a7124070 pathingDesiredPosition;
    NiPoint3_a7124070 pathingDesiredOrientation;
    NiPoint3_a7124070 pathingDesiredMovementSpeed;
    NiPoint3_a7124070 pathingDesiredRotationSpeed;
    unsigned int unk0D0;
    float lastBumpDirection;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 lastExtDoorActivated;
    float activationHeight;
    BSPointerHandle_RE__Actor_1a35f4b9 reanimateCaster;
    unsigned int pad0E4;
    MagicItem* reanimateSpell;
    TypeData currentMovementType;
    FADE_STATE fadeState;
    float fadeAlpha;
    TESObjectREFR* fadeTrigger;
    unsigned char headTrackTarget_raw[24];
    bool headTracked;
    unsigned char undefined_159[5];
    unsigned short unk15E;
    float headTrackTargetTimer;
    NiPoint3_a7124070 headTrackTargetOffset;
    float headTrackHoldOffsetHoldTimer;
    float headTrackTargetOffsetTimer;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 lastTarget;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 pathLookAtTarget;
    void* unk180;
    void* unk188;
    BSTSmartPointer_RE__HighProcessData__Data190_280db0e6 unk190;
    BSTSmartPointer_RE__HighProcessData__Data190_280db0e6 unk198;
    NiPoint3_a7124070 unk1A0;
    unsigned int unk1AC;
    unsigned long long unk1B0;
    unsigned long long unk1B8;
    unsigned long long unk1C0;
    unsigned long long unk1C8;
    unsigned long long unk1D0;
    unsigned long long unk1D8;
    float unk1E0;
    float cachedActorHeight;
    NiPointer_RE__NiRefObject_b6c51fb2 unk1E8;
    unsigned int unk1F0;
    AITimeStamp bumpTimer;
    AITimeStamp unk1F8;
    BUMP_TYPE bumpedState;
    float takeBackTimer;
    unsigned int pad204;
    Data208* unk208;
    float avoidWaitTimer;
    PLAYER_ACTION_17d90833 playerActionReaction;
    BSFixedString_char_83b572b4 voiceSubtitle;
    BSTArray_RE__BSTTuple_unsigned_int_RE__NiPointer_RE__ActorKnowledge_98b5b87c_dc4d57bb knowledgeArray;
    BSReadWriteLock knowledgeLock;
    BSTArray_RE__QueuedDialogueType_2a40d15e queueofGreetings;
    NiPointer_RE__BGSAttackData_03e8c1e0 attackData;
    NiPoint3_a7124070 locationOffsetByWaterPoint;
    unsigned int unk26C;
    unsigned long long unk270;
    float unk278;
    NiPoint3_a7124070 deathForceDirection;
    float deathForce;
    float unk28C;
    float unk290;
    float unk294;
    float unk298;
    float clearTalkToListTimer;
    float maxAlpha;
    float unk2A4;
    unsigned long long unk2A8;
    float checkToTalkTimer;
    unsigned int unk2B4;
    unsigned long long unk2B8;
    unsigned long long unk2C0;
    unsigned long long unk2C8;
    unsigned long long unk2D0;
    unsigned int animAction;
    NiPoint3_a7124070 leftWeaponLastPos;
    NiPoint3_a7124070 rightWeaponLastPos;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 greetActor;
    float soundDelay;
    unsigned char soundHandles_raw[24];
    float greetingTimer;
    float exclusiveTimer;
    float idleTimer;
    float detectGreetTimer;
    float breathTimer;
    float voiceTimer;
    float dyingTimer;
    TESTopicInfo* lastGreeting;
    unsigned long long unk338;
    float awarePlayerTimer;
    unsigned int unk344;
    TESIdleForm* currentProcessIdle;
    unsigned int unk350;
    unsigned int unk354;
    unsigned long long unk358;
    BSTSmartPointer_RE__DialogueItem_6093c8e0 greetTopic;
    unsigned int unk368;
    unsigned int unk36C;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 faceGenGeomHandle;
    unsigned long long unk378;
    NiPointer_RE__NiBillboardNode_acd9a360 healthBarNode;
    float unk388;
    unsigned int unk38C;
    unsigned int numberGuardsPursuing;
    float reEquipArmorTimer;
    RE__BSSimpleList_RE__SpellItem_8953e8bd* leveledSpellList;
    float detectionModifier;
    float detectionModifierTimer;
    float lightLevel;
    float sceneHeadTrackTimer;
    float pCapVoiceFailsafeTimer;
    unsigned int pad3B4;
    void* unk3B8;
    unsigned long long unk3C0;
    MuzzleFlash* muzzleFlash;
    unsigned int unk3D0;
    unsigned int pad3D4;
    DetectionEvent* actorsGeneratedDetectionEvent;
    NiPointer_RE__StandardDetectionListener_0ddfbe83 detectionListener;
    unsigned long long unk3E8;
    void* unk3F0;
    unsigned long long unk3F8;
    BSTArray_unsigned_long_long_RE__BSTSmallArrayHeapAllocator_8_d4df0649 unk400;
    NiPoint3_a7124070 animationDelta;
    NiPoint3_a7124070 animationAngleMod;
    BSTSmartPointer_RE__IAnimationSetCallbackFunctor_72f51ba7 unk430;
    float absorbTimer;
    float unk43C;
    Crime* crimeToReactTo;
    unsigned long long unk448;
    bool unk450;
    unsigned char unk451;
    unsigned char unk452;
    unsigned char unk453;
    bool greetingPlayer;
    unsigned char unk455;
    unsigned char unk456;
    bool detectAlert;
    bool talkingToPC;
    bool inCommandState;
    unsigned char unk45A;
    unsigned char unk45B;
    unsigned char unk45C;
    unsigned char unk45D;
    unsigned char unk45E;
    bool isDualCasting;
    bool getPlantedExplosive;
    bool approachingAutoTeleportDoor;
    bool arrested;
    bool unk463;
    bool unk464;
    bool unk465;
    bool unk466;
    bool unk467;
    bool farGeometry;
    bool unk469;
    bool unk46A;
    bool deathDialogue;
    bool fistsDrawn;
    bool unk46D;
    bool unk46E;
    bool allowRotation;
    bool doorActivated;
    bool unk471;
    bool aggroRadiusStarted;
    unsigned char pad473;
    unsigned int pad474;
};
static_assert(sizeof(HighProcessData) == 1144, "HighProcessData layout differs from the PDB");
