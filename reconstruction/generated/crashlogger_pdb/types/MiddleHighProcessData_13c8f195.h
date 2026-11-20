// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MiddleHighProcessData; size 0x338
// one of 2 different PDB types sharing this name
#pragma once

#include "ActorPackage.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSSimpleList_RE__TESObjectREFR_8fb2ed7e_fa203e2b.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5.h"
#include "BSTArray_RE__CommandedActorData_f3441327.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTEventSource_void_5fe0fef5.h"
#include "BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f.h"
#include "BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70.h"
#include "BSTSmartPointer_RE__bhkRagdollPenetrationUtil_c4e89d74.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSCloneReserver_7b0be990.h"
#include "NiPointer_RE__BSLightingShaderProperty_f3e1b3e4.h"
#include "NiPointer_RE__QueuedFile_61648701.h"
#include "NiPointer_RE__bhkCharacterController_33126cd3.h"
#include "WardState.h"
struct AIPerkData;
struct BSAnimationGraphVariableCache_b779e321;
struct BSFaceGenAnimationData_fcdc6879;
struct BSFaceGenNiNode_28632e02;
struct BSSimpleList_RE__ActiveEffect_f55158cb;
struct DeferredHideLimb;
struct HitData_e932ff94;
struct InventoryEntryData_beab07a8;
struct MagicItem_34516af4;
struct NiAVObject;
struct NiNode;
struct QueuedItem;
struct TESIdleForm_2b3518b0;
struct MiddleHighProcessData_13c8f195 {
    BSTEventSource_void_5fe0fef5 unk000;
    ActorPackage runOncePackage;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 deadDetectList;
    BSSimpleList_RE__TESObjectREFR_8fb2ed7e_fa203e2b refListChairBed;
    NiPoint3 rotation;
    NiPoint3 rotationSpeed;
    NiPoint3 actorMountPosition;
    NiPoint3 furniturePathPoint;
    NiPoint3 lastSeenPosition;
    unsigned int bleedoutAttacker;
    WardState wardState;
    unsigned int pad0F4;
    BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70 animResponse;
    BSTArray_RE__CommandedActorData_f3441327 commandedActors;
    NiNode* damageRootNode[6];
    NiAVObject* unk148;
    NiNode* weaponBone;
    NiAVObject* headNode;
    NiAVObject* torsoNode;
    NiAVObject* faceTargetSourceNode;
    BSFaceGenNiNode_28632e02* faceNodeSkinned;
    NiPointer_RE__BSLightingShaderProperty_f3e1b3e4 lightingProperty;
    unsigned long long unk180;
    QueuedItem* itemstoEquipUnequip;
    HitData_e932ff94* lastHitData;
    DeferredHideLimb* headDeferredHideLimb;
    BSSimpleList_RE__ActiveEffect_f55158cb* activeEffects;
    BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f animationGraphManager;
    BSAnimationGraphVariableCache_b779e321* animationVariableCache;
    BSTArray_void_9eb8914c unk1B8;
    BSTArray_void_9eb8914c unk1D0;
    BSSpinLock unk1E8;
    void* unk1F0;
    unsigned short unk1F8;
    unsigned short unk1FA;
    unsigned int unk1FC;
    unsigned int unk200;
    float headHeightOffset;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 occupiedFurniture;
    unsigned int unk20C;
    TESIdleForm_2b3518b0* unk210;
    BSPointerHandle_RE__Actor_1a35f4b9 commandingActor;
    unsigned int pad21C;
    InventoryEntryData_beab07a8* leftHand;
    TESIdleForm_2b3518b0* furnitureIdle;
    void* unk230;
    BSFaceGenAnimationData_fcdc6879* faceAnimationData;
    MagicItem_34516af4* currentPackageSpell;
    unsigned long long unk248;
    NiPointer_RE__bhkCharacterController_33126cd3 charController;
    BSTSmartPointer_RE__bhkRagdollPenetrationUtil_c4e89d74 penetrationDetectUtil;
    InventoryEntryData_beab07a8* rightHand;
    InventoryEntryData_beab07a8* bothHands;
    NiPointer_RE__QueuedFile_61648701 bodyPartPreload;
    NiPointer_RE__BSCloneReserver_7b0be990 unk278;
    TESIdleForm_2b3518b0* lastIdlePlayed;
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
    unsigned char update3DModel;  // RESET_3D_FLAGS in the PDB is wider than this slot
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
static_assert(sizeof(MiddleHighProcessData_13c8f195) == 824, "MiddleHighProcessData_13c8f195 layout differs from the PDB");
