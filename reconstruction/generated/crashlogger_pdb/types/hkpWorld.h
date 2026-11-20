// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorld; size 0x430
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkpActionListener_f7c648a8.h"
#include "hkArray_RE__hkpConstraintListener_88bf3c0e.h"
#include "hkArray_RE__hkpContactImpulseLimitBreachedListener_80cea655.h"
#include "hkArray_RE__hkpContactListener_5bc7bc9f.h"
#include "hkArray_RE__hkpEntityListener_e73758e9.h"
#include "hkArray_RE__hkpIslandActivationListener_89bb72b5.h"
#include "hkArray_RE__hkpIslandPostCollideListener_7dd216a9.h"
#include "hkArray_RE__hkpIslandPostIntegrateListener_03a3e4a0.h"
#include "hkArray_RE__hkpPhantomListener_3d5082c5.h"
#include "hkArray_RE__hkpPhantom_f69d7a63.h"
#include "hkArray_RE__hkpSimulationIsland_4a2061d4.h"
#include "hkArray_RE__hkpWorldDeletionListener_7deaa4f8.h"
#include "hkArray_RE__hkpWorldExtension_f3b97616.h"
#include "hkArray_RE__hkpWorldPostCollideListener_a278f904.h"
#include "hkArray_RE__hkpWorldPostIntegrateListener_a93f74a0.h"
#include "hkArray_RE__hkpWorldPostSimulationListener_36a98abc.h"
#include "hkMultiThreadCheck_64f82694.h"
#include "hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7.h"
#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkpWorldDynamicsStepInfo.h"
struct hkCriticalSection_342cc62e;
struct hkdWorld;
struct hknpWorld_00ead89c;
struct hkpBroadPhaseBorderListener_1b4a882d;
struct hkpBroadPhaseBorder_8abc8c87;
struct hkpBroadPhase_ceb45477;
struct hkpCollisionDispatcher_f542eee0;
struct hkpCollisionFilter;
struct hkpConvexListFilter_8ec0d7aa;
struct hkpDebugInfoOnPendingOperationQueues_c520c3bc;
struct hkpEntityEntityBroadPhaseListener_09be3500;
struct hkpMtThreadStructure;
struct hkpPhantomBroadPhaseListener_e9e993cb;
struct hkpProcessCollisionInput_c2f94de3;
struct hkpRigidBody_ce35757a;
struct hkpSimulationIsland;
struct hkpSimulation_6510d48a;
struct hkpTreeWorldManager_1468e6a5;
struct hkpTypedBroadPhaseDispatcher_d891f99d;
struct hkpViolatedConstraintArray_53135bbf;
struct hkpWorldMaintenanceMgr_068e62ed;
struct hkpWorldOperationQueue_67232a66;
struct hkpWorld {
    hkReferencedObject _base;
    hkpSimulation_6510d48a* simulation;
    unsigned long long pad018;
    hkVector4 gravity;
    hkpSimulationIsland* fixedIsland;
    hkpRigidBody_ce35757a* fixedRigidBody;
    hkArray_RE__hkpSimulationIsland_4a2061d4 activeSimulationIslands;
    hkArray_RE__hkpSimulationIsland_4a2061d4 inactiveSimulationIslands;
    hkArray_RE__hkpSimulationIsland_4a2061d4 dirtySimulationIslands;
    hkpWorldMaintenanceMgr_068e62ed* maintenanceMgr;
    hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7 memoryWatchDog;
    bool assertOnRunningOutOfSolverMemory;
    unsigned char pad081;
    unsigned short pad082;
    unsigned int pad084;
    hkpBroadPhase_ceb45477* broadPhase;
    hkpTreeWorldManager_1468e6a5* kdTreeManager;
    bool autoUpdateTree;
    unsigned char pad099;
    unsigned short pad09A;
    unsigned int pad09C;
    hkpTypedBroadPhaseDispatcher_d891f99d* broadPhaseDispatcher;
    hkpPhantomBroadPhaseListener_e9e993cb* phantomBroadPhaseListener;
    hkpEntityEntityBroadPhaseListener_09be3500* entityEntityBroadPhaseListener;
    hkpBroadPhaseBorderListener_1b4a882d* broadPhaseBorderListener;
    hkpMtThreadStructure* multithreadedSimulationJobData;
    hkpProcessCollisionInput_c2f94de3* collisionInput;
    hkpCollisionFilter* collisionFilter;
    hkpCollisionDispatcher_f542eee0* collisionDispatcher;
    hkpConvexListFilter_8ec0d7aa* convexListFilter;
    hkpWorldOperationQueue_67232a66* pendingOperations;
    int pendingOperationsCount;
    int pendingBodyOperationsCount;
    int criticalOperationsLockCount;
    int criticalOperationsLockCountForPhantoms;
    bool blockExecutingPendingOperations;
    bool criticalOperationsAllowed;
    unsigned short pad102;
    unsigned int pad104;
    hkpDebugInfoOnPendingOperationQueues_c520c3bc* pendingOperationQueues;
    int pendingOperationQueueCount;
    hkMultiThreadCheck_64f82694 multiThreadCheck;
    bool processActionsInSingleThread;
    bool allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
    unsigned short pad122;
    unsigned int minDesiredIslandSize;
    hkCriticalSection_342cc62e* modifyConstraintCriticalSection;
    int isLocked;
    unsigned int pad134;
    hkCriticalSection_342cc62e* islandDirtyListCriticalSection;
    hkCriticalSection_342cc62e* propertyMasterLock;
    bool wantSimulationIslands;
    bool useHybridBroadphase;
    unsigned short pad14A;
    float snapCollisionToConvexEdgeThreshold;
    float snapCollisionToConcaveEdgeThreshold;
    bool enableToiWeldRejection;
    bool wantDeactivation;
    bool shouldActivateOnRigidBodyTransformChange;
    unsigned char pad153;
    float deactivationReferenceDistance;
    float toiCollisionResponseRotateNormal;
    int maxSectorsPerMidphaseCollideTask;
    int maxSectorsPerNarrowphaseCollideTask;
    bool processToisMultithreaded;
    unsigned char pad169;
    unsigned short pad16A;
    int maxEntriesPerToiMidphaseCollideTask;
    int maxEntriesPerToiNarrowphaseCollideTask;
    int maxNumToiCollisionPairsSinglethreaded;
    unsigned char simulationType;  // SimulationType in the PDB is wider than this slot
    unsigned char pad179;
    unsigned short pad17A;
    float numToisTillAllowedPenetrationSimplifiedToi;
    float numToisTillAllowedPenetrationToi;
    float numToisTillAllowedPenetrationToiHigher;
    float numToisTillAllowedPenetrationToiForced;
    unsigned int lastEntityUID;
    unsigned int lastIslandUID;
    unsigned int lastConstraintUID;
    hkArray_RE__hkpPhantom_f69d7a63 phantoms;
    hkArray_RE__hkpActionListener_f7c648a8 actionListeners;
    hkArray_RE__hkpEntityListener_e73758e9 entityListeners;
    hkArray_RE__hkpPhantomListener_3d5082c5 phantomListeners;
    hkArray_RE__hkpConstraintListener_88bf3c0e constraintListeners;
    hkArray_RE__hkpWorldDeletionListener_7deaa4f8 worldDeletionListeners;
    hkArray_RE__hkpIslandActivationListener_89bb72b5 islandActivationListeners;
    hkArray_RE__hkpWorldPostSimulationListener_36a98abc worldPostSimulationListeners;
    hkArray_RE__hkpWorldPostIntegrateListener_a93f74a0 worldPostIntegrateListeners;
    hkArray_RE__hkpWorldPostCollideListener_a278f904 worldPostCollideListeners;
    hkArray_RE__hkpIslandPostIntegrateListener_03a3e4a0 islandPostIntegrateListeners;
    hkArray_RE__hkpIslandPostCollideListener_7dd216a9 islandPostCollideListeners;
    hkArray_RE__hkpContactListener_5bc7bc9f contactListeners;
    hkArray_RE__hkpContactImpulseLimitBreachedListener_80cea655 contactImpulseLimitBreachedListeners;
    hkArray_RE__hkpWorldExtension_f3b97616 worldExtensions;
    hkpViolatedConstraintArray_53135bbf* violatedConstraintArray;
    hkpBroadPhaseBorder_8abc8c87* broadPhaseBorder;
    hkdWorld* destructionWorld;
    hknpWorld_00ead89c* npWorld;
    unsigned long long pad2A8;
    hkpWorldDynamicsStepInfo dynamicsStepInfo;
    unsigned char broadPhaseExtents_raw[32];
    int broadPhaseNumMarkers;
    int sizeOfToiEventQueue;
    int broadPhaseQuerySize;
    int broadPhaseUpdateSize;
    unsigned char contactPointGeneration;  // ContactPointGeneration in the PDB is wider than this slot
    unsigned char pad421;
    unsigned short pad422;
    unsigned int pad424;
    unsigned long long pad428;
};
static_assert(sizeof(hkpWorld) == 1072, "hkpWorld layout differs from the PDB");
