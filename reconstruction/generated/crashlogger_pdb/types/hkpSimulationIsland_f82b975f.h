// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimulationIsland; size 0xb8
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkpAction_5716abb7.h"
#include "hkInplaceArray_RE__hkpEntity_1_e61f21f1.h"
#include "hkMultiThreadCheck.h"
#include "hkpAgentNnTrack_be66e966.h"
#include "hkpConstraintOwner.h"
struct hkpWorld_938ebb10;
struct hkpSimulationIsland_f82b975f {
    hkpConstraintOwner _base;
    hkpWorld_938ebb10* world;
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
    hkMultiThreadCheck multiThreadCheck;
    float timeSinceLastHighFrequencyCheck;
    float timeSinceLastLowFrequencyCheck;
    hkArray_RE__hkpAction_5716abb7 actions;
    float timeOfDeactivation;
    unsigned int pad5C;
    hkInplaceArray_RE__hkpEntity_1_e61f21f1 entities;
    hkpAgentNnTrack_be66e966 midphaseAgentTrack;
    hkpAgentNnTrack_be66e966 narrowphaseAgentTrack;
};
static_assert(sizeof(hkpSimulationIsland_f82b975f) == 184, "hkpSimulationIsland_f82b975f layout differs from the PDB");
