// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldCinfo; size 0x100
#pragma once

#include "hkAabb_e8754794.h"
#include "hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7.h"
#include "hkRefPtr_RE__hkpCollisionFilter_8eac39a8.h"
#include "hkRefPtr_RE__hkpConvexListFilter_9f3e6e81.h"
#include "hkReferencedObject.h"
#include "hkVector4.h"
struct hkpWorldCinfo {
    hkReferencedObject _base;
    hkVector4 gravity;
    int broadPhaseQuerySize;
    float contactRestingVelocity;
    unsigned char broadPhaseBorderBehaviour;  // BroadPhaseBorderBehaviour in the PDB is wider than this slot
    bool mtPostponeAndSortBroadPhaseBorderCallbacks;
    unsigned short pad02A;
    unsigned int pad02C;
    hkAabb_e8754794 broadPhaseWorldAabb;
    bool useKdTree;
    bool useMultipleTree;
    unsigned char treeUpdateType;  // TreeUpdateType in the PDB is wider than this slot
    bool autoUpdateKdTree;
    float collisionTolerance;
    hkRefPtr_RE__hkpCollisionFilter_8eac39a8 collisionFilter;
    hkRefPtr_RE__hkpConvexListFilter_9f3e6e81 convexListFilter;
    float expectedMaxLinearVelocity;
    int sizeOfToiEventQueue;
    float expectedMinPsiDeltaTime;
    unsigned char undefined_74[4];
    hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7 memoryWatchDog;
    int broadPhaseNumMarkers;
    unsigned char contactPointGeneration;  // ContactPointGeneration in the PDB is wider than this slot
    bool allowToSkipConfirmedCallbacks;
    bool useHybridBroadphase;
    unsigned char pad087;
    float solverTau;
    float solverDamp;
    int solverIterations;
    int solverMicrosteps;
    float maxConstraintViolation;
    bool forceCoherentConstraintOrderingInSolver;
    unsigned char pad09D;
    unsigned short pad09E;
    float snapCollisionToConvexEdgeThreshold;
    float snapCollisionToConcaveEdgeThreshold;
    bool enableToiWeldRejection;
    bool enableDeprecatedWelding;
    unsigned short pad0AA;
    float iterativeLinearCastEarlyOutDistance;
    int iterativeLinearCastMaxIterations;
    unsigned char deactivationNumInactiveFramesSelectFlag0;
    unsigned char deactivationNumInactiveFramesSelectFlag1;
    unsigned char deactivationIntegrateCounter;
    bool shouldActivateOnRigidBodyTransformChange;
    float deactivationReferenceDistance;
    float toiCollisionResponseRotateNormal;
    int maxSectorsPerMidphaseCollideTask;
    int maxSectorsPerNarrowphaseCollideTask;
    bool processToisMultithreaded;
    unsigned char pad0C9;
    unsigned short pad0CA;
    int maxEntriesPerToiMidphaseCollideTask;
    int maxEntriesPerToiNarrowphaseCollideTask;
    int maxNumToiCollisionPairsSinglethreaded;
    float numToisTillAllowedPenetrationSimplifiedToi;
    float numToisTillAllowedPenetrationToi;
    float numToisTillAllowedPenetrationToiHigher;
    float numToisTillAllowedPenetrationToiForced;
    bool enableDeactivation;
    unsigned char simulationType;  // SimulationType in the PDB is wider than this slot
    bool enableSimulationIslands;
    unsigned char pad0EB;
    unsigned int minDesiredIslandSize;
    bool processActionsInSingleThread;
    bool allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
    unsigned short pad0F2;
    float frameMarkerPsiSnap;
    bool fireCollisionCallbacks;
    unsigned char pad0F9;
    unsigned short pad0FA;
    unsigned int pad0FC;
};
static_assert(sizeof(hkpWorldCinfo) == 256, "hkpWorldCinfo layout differs from the PDB");
