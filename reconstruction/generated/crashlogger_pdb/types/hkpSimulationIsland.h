// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimulationIsland; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkpAction_5716abb7.h"
#include "hkInplaceArray_RE__hkpEntity_1_e61f21f1.h"
#include "hkMultiThreadCheck_64f82694.h"
#include "hkpAgentNnTrack.h"
#include "hkpConstraintOwner_1e63eaed.h"
struct hkpWorld;
struct hkpSimulationIsland {
    hkpConstraintOwner_1e63eaed _base;
    hkpWorld* world;
    int numConstraints;
    unsigned short storageIndex;
    unsigned short dirtyListIndex;
    unsigned char splitCheckFrameCounter;
    unsigned char splitCheckRequested : 2;
    unsigned char isSparse : 2;
    unsigned char actionListCleanupNeeded : 2;
    unsigned char allowIslandLocking : 2;
    unsigned char isInActiveIslandsArray : 2;
    unsigned char activeMark : 2;
    unsigned char tryToIncreaseIslandSizeMark : 2;
    unsigned char inIntegrateJob : 2;
    unsigned char pad33;
    hkMultiThreadCheck_64f82694 multiThreadCheck;
    float timeSinceLastHighFrequencyCheck;
    float timeSinceLastLowFrequencyCheck;
    hkArray_RE__hkpAction_5716abb7 actions;
    float timeOfDeactivation;
    unsigned int pad5C;
    hkInplaceArray_RE__hkpEntity_1_e61f21f1 entities;
    hkpAgentNnTrack midphaseAgentTrack;
    hkpAgentNnTrack narrowphaseAgentTrack;
};
static_assert(sizeof(hkpSimulationIsland) == 184, "hkpSimulationIsland layout differs from the PDB");
