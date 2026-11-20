// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatGroup; size 0x168
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "AITimer.h"
#include "BGSWorldLocation.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSReadWriteLock.h"
#include "BSTArray_RE__CombatMember_a3db0469_ba69948f.h"
#include "BSTArray_RE__CombatSearchDoor_20d0ae33.h"
#include "BSTArray_RE__CombatSearchLocation_9f02d3eb_89298640.h"
#include "BSTArray_RE__CombatTarget_8724e0cd.h"
struct BSPathingLOSGridMap_7edc83a1;
struct CombatGroupDetectionListener_2d17a06e;
struct CombatGroup {
    unsigned int groupID;
    unsigned int groupIndex;
    BSTArray_RE__CombatTarget_8724e0cd targets;
    BSTArray_RE__CombatMember_a3db0469_ba69948f members;
    CombatGroupDetectionListener_2d17a06e* detectionListener;
    AITimer allyKilledTimer;
    AITimer avoidThreathTimer;
    AITimer unk50;
    unsigned char detectionDialogueTimers_raw[88];
    AITimer updateTimer;
    AITimer musicThreatRatioTimer;
    AITimer unkC0;
    float unkC8;
    float unkCC;
    float unkD0;
    float unkD4;
    unsigned int searchState;
    unsigned int padDC;
    BSPathingLOSGridMap_7edc83a1* gridMap;
    AITimer searchUpdateTimer;
    AITimer searchAreaUpdateTimer;
    AITimeStamp searchStartedTimeStamp;
    BSPointerHandle_RE__Actor_1a35f4b9 targetToSearchFor;
    BGSWorldLocation searchTargetLoc;
    float searchRadius;
    unsigned int pad11C;
    BSTArray_RE__CombatSearchLocation_9f02d3eb_89298640 searchLocations;
    BSTArray_RE__CombatSearchDoor_20d0ae33 searchDoors;
    unsigned int initializedMemberCount;
    unsigned int fleeCount;
    unsigned int fightCount;
    unsigned char musicState;
    unsigned char unk15D;
    unsigned char unk15E;
    unsigned char unk15F;
    BSReadWriteLock lock;
};
static_assert(sizeof(CombatGroup) == 360, "CombatGroup layout differs from the PDB");
