// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ProcessLists; size 0x1f0
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSemaphore.h"
#include "BSSimpleList_RE__BSPointerHandle_RE__Actor_582a0960.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8.h"
#include "BSTArray_RE__BSTSmartPointer_RE__SyncQueueObj_d894efce.h"
#include "BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d.h"
#include "BSTSingletonSDM_RE__ProcessLists_d5d08c72.h"
struct RE__BSSimpleList_RE__Crime_d5767256;
struct ProcessLists {
    BSTSingletonSDM_RE__ProcessLists_d5d08c72 _base;
    bool runDetection;
    bool showDetectionStats;
    unsigned char pad003;
    BSPointerHandle_RE__Actor_1a35f4b9 statdetect;
    bool processHigh;
    bool processLow;
    bool processMHigh;
    bool processMLow;
    bool runEditorSchedules;
    bool showDialogueSubtitles;
    unsigned char unk00E;
    unsigned char pad00F;
    int numberHighActors;
    float unk014;
    unsigned int unk018;
    float removeExcessDeadTimer;
    BSSemaphore movementSyncSema;
    unsigned int unk028;
    unsigned int pad02C;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 highActorHandles;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 lowActorHandles;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 middleHighActorHandles;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 middleLowActorHandles;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5* allProcesses[4];
    RE__BSSimpleList_RE__Crime_d5767256* globalCrimes[7];
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d globalTempEffects;
    BSSpinLock globalEffectsLock;
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d magicEffects;
    BSSpinLock magicEffectsLock;
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d interfaceEffects;
    BSSpinLock interfaceEffectsLock;
    unsigned long long unk148;
    unsigned long long unk150;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 tempShouldMoves;
    BSSimpleList_RE__BSPointerHandle_RE__Actor_582a0960 aliveActorList;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 initPackageLocationsQueue;
    BSSpinLock packageLocationsQueueLock;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 initAnimPositionQueue;
    BSTArray_RE__BSTSmartPointer_RE__SyncQueueObj_d894efce syncPositionQueue;
    float playerActionCommentTimer;
    float playerKnockObjectCommentTimer;
    unsigned int currentLowActor;
    unsigned int currentMiddleHighActor;
    unsigned int currentMiddleLowActor;
    bool runSchedules;
    bool runMovement;
    bool runAnimations;
    bool updateActorsInPlayerCell;
    unsigned long long unk1E8;
};
static_assert(sizeof(ProcessLists) == 496, "ProcessLists layout differs from the PDB");
