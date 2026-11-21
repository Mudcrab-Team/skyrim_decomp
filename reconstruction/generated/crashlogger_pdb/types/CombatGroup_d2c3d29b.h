// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatGroup; size 0x168
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "AITimer.h"
#include "BGSWorldLocation.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSReadWriteLock.h"
#include "BSTArray_RE__CombatMember_a3db0469.h"
#include "BSTArray_RE__CombatSearchDoor_20d0ae33_d93b506e.h"
#include "BSTArray_RE__CombatSearchLocation_9f02d3eb.h"
#include "BSTArray_RE__CombatTarget_8724e0cd_bd0fe47f.h"
struct BSPathingLOSGridMap;
struct CombatGroupDetectionListener;
struct CombatGroup_d2c3d29b {
    unsigned int groupID;
    unsigned int groupIndex;
    BSTArray_RE__CombatTarget_8724e0cd_bd0fe47f targets;
    BSTArray_RE__CombatMember_a3db0469 members;
    CombatGroupDetectionListener* detectionListener;
    AITimer allyKilledTimer;
    AITimer avoidThreathTimer;
    AITimer unk50;
    unsigned char detectionDialogueTimers_raw[88];
    AITimer updateTimer;
    AITimer musicThreatRatioTimer;
    AITimer fldC0;
    float unkC8;
    float unkCC;
    float unkD0;
    float unkD4;
    unsigned int searchState;
    unsigned int padDC;
    BSPathingLOSGridMap* gridMap;
    AITimer searchUpdateTimer;
    AITimer searchAreaUpdateTimer;
    AITimeStamp searchStartedTimeStamp;
    BSPointerHandle_RE__Actor_1a35f4b9 targetToSearchFor;
    BGSWorldLocation searchTargetLoc;
    float searchRadius;
    unsigned int pad11C;
    BSTArray_RE__CombatSearchLocation_9f02d3eb searchLocations;
    BSTArray_RE__CombatSearchDoor_20d0ae33_d93b506e searchDoors;
    unsigned int initializedMemberCount;
    unsigned int fleeCount;
    unsigned int fightCount;
    unsigned char musicState;
    unsigned char unk15D;
    unsigned char unk15E;
    unsigned char unk15F;
    BSReadWriteLock lock;
};
static_assert(sizeof(CombatGroup_d2c3d29b) == 360, "CombatGroup_d2c3d29b layout differs from the PDB");
