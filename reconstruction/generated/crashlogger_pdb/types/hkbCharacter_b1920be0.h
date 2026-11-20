// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacter; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkbCharacter_603a2548.h"
#include "hkRefPtr_RE__hkbBehaviorGraph_d760ee5d.h"
#include "hkRefPtr_RE__hkbCharacterSetup_9a37d407.h"
#include "hkRefPtr_RE__hkbProjectData_59f60ea6.h"
#include "hkRefPtr_RE__hkbRagdollDriver_7df05669.h"
#include "hkRefVariant.h"
#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
struct hkbCharacter_b1920be0 {
    hkReferencedObject _base;
    hkArray_RE__hkbCharacter_603a2548 nearbyCharacters;
    short currentLOD;
    short numTracksInLOD;
    unsigned int pad24;
    hkStringPtr_33d8e88b name;
    hkRefPtr_RE__hkbRagdollDriver_7df05669 ragdollDriver;
    hkRefVariant characterControllerDriver;
    hkRefVariant footIkDriver;
    hkRefVariant handIkDriver;
    hkRefPtr_RE__hkbCharacterSetup_9a37d407 setup;
    hkRefPtr_RE__hkbBehaviorGraph_d760ee5d behaviorGraph;
    hkRefPtr_RE__hkbProjectData_59f60ea6 projectData;
    hkRefVariant animationBindingSet;
    hkRefVariant raycastInterface;
    hkRefVariant world;
    hkRefVariant eventQueue;
    hkRefVariant worldFromModel;
    void** poseLocal;
    int numPoseLocal;
    bool deleteWorldFromModel;
    bool deletePoseLocal;
    unsigned short pad9E;
};
static_assert(sizeof(hkbCharacter_b1920be0) == 160, "hkbCharacter_b1920be0 layout differs from the PDB");
