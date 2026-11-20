// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MiddleHighProcessData; size 0x338
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ActorPackage.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSSimpleList_RE__TESObjectREFR_8fb2ed7e.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1.h"
#include "BSTArray_RE__CommandedActorData_f3441327_3361422a.h"
#include "BSTArray_void_7a93e7a7.h"
#include "BSTEventSource_void_9d1a19e6.h"
#include "BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f.h"
#include "BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70.h"
#include "BSTSmartPointer_RE__bhkRagdollPenetrationUtil_c4e89d74.h"
#include "EnumSet_RE__RESET_3D_FLAGS_unsigned_char_75d6f033.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__BSCloneReserver_7b0be990.h"
#include "NiPointer_RE__BSLightingShaderProperty_f3e1b3e4.h"
#include "NiPointer_RE__QueuedFile_61648701.h"
#include "NiPointer_RE__bhkCharacterController_33126cd3.h"
#include "WardState.h"
struct AIPerkData;
struct BSAnimationGraphVariableCache;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSSimpleList_RE__ActiveEffect_f55158cb_9f0ebb33;
struct DeferredHideLimb_4a5d8aa7;
struct HitData;
struct InventoryEntryData;
struct MagicItem;
struct NiAVObject_968dc716;
struct NiNode_9cd97e9e;
struct QueuedItem_13d93b08;
struct TESIdleForm;
struct MiddleHighProcessData {
    BSTEventSource_void_9d1a19e6 fld000;
    ActorPackage runOncePackage;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1 deadDetectList;
    BSSimpleList_RE__TESObjectREFR_8fb2ed7e refListChairBed;
    NiPoint3_a7124070 rotation;
    NiPoint3_a7124070 rotationSpeed;
    NiPoint3_a7124070 actorMountPosition;
    NiPoint3_a7124070 furniturePathPoint;
    NiPoint3_a7124070 lastSeenPosition;
    unsigned int bleedoutAttacker;
    WardState wardState;
    unsigned int pad0F4;
    BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70 animResponse;
    BSTArray_RE__CommandedActorData_f3441327_3361422a commandedActors;
    NiNode_9cd97e9e* damageRootNode[6];
    NiAVObject_968dc716* unk148;
    NiNode_9cd97e9e* weaponBone;
    NiAVObject_968dc716* headNode;
    NiAVObject_968dc716* torsoNode;
    NiAVObject_968dc716* faceTargetSourceNode;
    BSFaceGenNiNode* faceNodeSkinned;
    NiPointer_RE__BSLightingShaderProperty_f3e1b3e4 lightingProperty;
    unsigned long long unk180;
    QueuedItem_13d93b08* itemstoEquipUnequip;
    HitData* lastHitData;
    DeferredHideLimb_4a5d8aa7* headDeferredHideLimb;
    BSSimpleList_RE__ActiveEffect_f55158cb_9f0ebb33* activeEffects;
    BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f animationGraphManager;
    BSAnimationGraphVariableCache* animationVariableCache;
    BSTArray_void_7a93e7a7 fld1B8;
    BSTArray_void_7a93e7a7 fld1D0;
    BSSpinLock unk1E8;
    void* unk1F0;
    unsigned short unk1F8;
    unsigned short unk1FA;
    unsigned int unk1FC;
    unsigned int unk200;
    float headHeightOffset;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 occupiedFurniture;
    unsigned int unk20C;
    TESIdleForm* unk210;
    BSPointerHandle_RE__Actor_1a35f4b9 commandingActor;
    unsigned int pad21C;
    InventoryEntryData* leftHand;
    TESIdleForm* furnitureIdle;
    void* unk230;
    BSFaceGenAnimationData* faceAnimationData;
    MagicItem* currentPackageSpell;
    unsigned long long unk248;
    NiPointer_RE__bhkCharacterController_33126cd3 charController;
    BSTSmartPointer_RE__bhkRagdollPenetrationUtil_c4e89d74 penetrationDetectUtil;
    InventoryEntryData* rightHand;
    InventoryEntryData* bothHands;
    NiPointer_RE__QueuedFile_61648701 bodyPartPreload;
    NiPointer_RE__BSCloneReserver_7b0be990 unk278;
    TESIdleForm* lastIdlePlayed;
    AIPerkData* perkData;
    unsigned int unk290;
    unsigned int currentFurnitureSubgraphID;
    float unk298;
    float unk29C;
    float unk2A0;
    float unk2A4;
    float currentMovementSpeed;
    float unk2AC;
    float unk2B0;
    float bleedoutRate;
    float unk2B8;
    float maximumWardPower;
    float unk2C0;
    float torchEvaluationTimer;
    float alphaMult;
    float scriptRefractPower;
    float unk2D0;
    float deferredKillTimer;
    float killMoveTimer;
    float unk2DC;
    unsigned int unk2E0;
    unsigned int reservationSlot;
    unsigned int currentFurnitureMarkerID;
    unsigned int unk2EC;
    unsigned long long unk2F0;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned short unk304;
    unsigned short unk306;
    unsigned long long unk308;
    unsigned char unk310;
    EnumSet_RE__RESET_3D_FLAGS_unsigned_char_75d6f033 update3DModel;
    unsigned short unk312;
    unsigned short unk314;
    bool unk316;
    bool unk317;
    bool unk318;
    bool unk319;
    bool unk31A;
    bool pickPocketed;
    bool summonedCreature;
    bool forceNextUpdate;
    bool unk31E;
    bool unk31F;
    bool unk320;
    bool unk321;
    bool beenAttacked;
    bool alwaysHit;
    bool doNoDamage;
    bool soulTrapped;
    bool unk326;
    bool unk327;
    bool unk328;
    bool preventCombat;
    bool unk32A;
    bool isFleeing;
    bool unk32C;
    bool hostileGuard;
    bool unk32E;
    bool unk32F;
    bool unk330;
    bool killQueued;
    bool inDeferredKill;
    bool pad333;
    unsigned int pad334;
};
static_assert(sizeof(MiddleHighProcessData) == 824, "MiddleHighProcessData layout differs from the PDB");
