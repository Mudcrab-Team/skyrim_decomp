// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorProcess; size 0x140
#pragma once

#include "ActorPackage.h"
#include "BSSimpleList_ActorProcess__ObjectsToAcquire.h"
#include "BSSimpleList_TESObjectREFR_43d231b9.h"
#include "BSTArray_TESForm__BSTArrayHeapAllocator.h"
struct ActorProcess__ObjectsToAcquire;
struct CachedValues_ebedb0c3;
struct HighProcessData;
struct MiddleHighProcessData;
struct MiddleLowProcessData;
struct TESForm_4074aa87;
struct ActorProcess {
    MiddleLowProcessData* MiddleLow_0;
    MiddleHighProcessData* MiddleHigh_8;
    HighProcessData* High_10;
    ActorPackage CurrentPackage_18;
    char _pad_48[8];
    CachedValues_ebedb0c3* CachedValueData_50;
    int NumberItemsActivate_58;
    char _pad_5C[4];
    BSSimpleList_ActorProcess__ObjectsToAcquire Objects_60;
    BSSimpleList_TESObjectREFR_43d231b9 GenericLocations_70;
    ActorProcess__ObjectsToAcquire* AcquireObject_80;
    ActorProcess__ObjectsToAcquire* SavedAcquireObject_88;
    float EssentialDownTimer_90;
    float DeathTime_94;
    float TrackedDamage_98;
    char _pad_9C[4];
    BSTArray_TESForm__BSTArrayHeapAllocator Forms_A0;
    char _pad_B8[56];
    TESForm_4074aa87* EquippedLeftHand_F0;
    TESForm_4074aa87* EquippedRightHand_F8;
    char _pad_100[54];
    unsigned char LowProcessFlags_136;
    unsigned char ProcessLevel_137;
    bool SkippedTimeStampForPathing_138;
    bool IgnoringCombat_139;
    bool EndAlarmOnActor_13A;
    bool EscortingPlayer_13B;
    char _pad_13C[4];
};
static_assert(sizeof(ActorProcess) == 320, "ActorProcess layout differs from the PDB");
