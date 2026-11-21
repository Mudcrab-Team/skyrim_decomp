// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorld; size 0x430
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__hkpWorldCinfo__ContactPointGeneration_unsigned_char_c81da7b7.h"
#include "EnumSet_RE__hkpWorldCinfo__SimulationType_unsigned_char_ad4db224.h"
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
#include "hkMultiThreadCheck.h"
#include "hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7.h"
#include "hkReferencedObject_2e7f2489.h"
#include "hkVector4_f554a678.h"
#include "hkpWorldDynamicsStepInfo_fd1d8780.h"
struct bhkSerializable;
struct hkCriticalSection;
struct hkdWorld;
struct hknpWorld;
struct hkpBroadPhase;
struct hkpBroadPhaseBorder;
struct hkpBroadPhaseBorderListener;
struct hkpCollisionDispatcher;
struct hkpCollisionFilter_72b1bb08;
struct hkpConvexListFilter;
struct hkpDebugInfoOnPendingOperationQueues;
struct hkpEntityEntityBroadPhaseListener;
struct hkpMtThreadStructure;
struct hkpPhantomBroadPhaseListener;
struct hkpProcessCollisionInput;
struct hkpRigidBody;
struct hkpSimulation;
struct hkpSimulationIsland_f82b975f;
struct hkpTreeWorldManager;
struct hkpTypedBroadPhaseDispatcher;
struct hkpViolatedConstraintArray;
struct hkpWorldMaintenanceMgr;
struct hkpWorldOperationQueue;
struct hkpWorld_938ebb10 {
    hkReferencedObject_2e7f2489 _base;
    hkpSimulation* simulation;
    bhkSerializable* serializable;
    hkVector4_f554a678 gravity;
    hkpSimulationIsland_f82b975f* fixedIsland;
    hkpRigidBody* fixedRigidBody;
    hkArray_RE__hkpSimulationIsland_4a2061d4 activeSimulationIslands;
    hkArray_RE__hkpSimulationIsland_4a2061d4 inactiveSimulationIslands;
    hkArray_RE__hkpSimulationIsland_4a2061d4 dirtySimulationIslands;
    hkpWorldMaintenanceMgr* maintenanceMgr;
    hkRefPtr_RE__hkWorldMemoryAvailableWatchDog_1807a2b7 memoryWatchDog;
    bool assertOnRunningOutOfSolverMemory;
    unsigned char pad081;
    unsigned short pad082;
    unsigned int pad084;
    hkpBroadPhase* broadPhase;
    hkpTreeWorldManager* kdTreeManager;
    bool autoUpdateTree;
    unsigned char pad099;
    unsigned short pad09A;
    unsigned int pad09C;
    hkpTypedBroadPhaseDispatcher* broadPhaseDispatcher;
    hkpPhantomBroadPhaseListener* phantomBroadPhaseListener;
    hkpEntityEntityBroadPhaseListener* entityEntityBroadPhaseListener;
    hkpBroadPhaseBorderListener* broadPhaseBorderListener;
    hkpMtThreadStructure* multithreadedSimulationJobData;
    hkpProcessCollisionInput* collisionInput;
    hkpCollisionFilter_72b1bb08* collisionFilter;
    hkpCollisionDispatcher* collisionDispatcher;
    hkpConvexListFilter* convexListFilter;
    hkpWorldOperationQueue* pendingOperations;
    int pendingOperationsCount;
    int pendingBodyOperationsCount;
    int criticalOperationsLockCount;
    int criticalOperationsLockCountForPhantoms;
    bool blockExecutingPendingOperations;
    bool criticalOperationsAllowed;
    unsigned short pad102;
    unsigned int pad104;
    hkpDebugInfoOnPendingOperationQueues* pendingOperationQueues;
    int pendingOperationQueueCount;
    hkMultiThreadCheck multiThreadCheck;
    bool processActionsInSingleThread;
    bool allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
    unsigned short pad122;
    unsigned int minDesiredIslandSize;
    hkCriticalSection* modifyConstraintCriticalSection;
    int isLocked;
    unsigned int pad134;
    hkCriticalSection* islandDirtyListCriticalSection;
    hkCriticalSection* propertyMasterLock;
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
    EnumSet_RE__hkpWorldCinfo__SimulationType_unsigned_char_ad4db224 simulationType;
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
    hkpViolatedConstraintArray* violatedConstraintArray;
    hkpBroadPhaseBorder* broadPhaseBorder;
    hkdWorld* destructionWorld;
    hknpWorld* npWorld;
    unsigned long long pad2A8;
    hkpWorldDynamicsStepInfo_fd1d8780 dynamicsStepInfo;
    unsigned char broadPhaseExtents_raw[32];
    int broadPhaseNumMarkers;
    int sizeOfToiEventQueue;
    int broadPhaseQuerySize;
    int broadPhaseUpdateSize;
    EnumSet_RE__hkpWorldCinfo__ContactPointGeneration_unsigned_char_c81da7b7 contactPointGeneration;
    unsigned char pad421;
    unsigned short pad422;
    unsigned int pad424;
    unsigned long long pad428;
};
static_assert(sizeof(hkpWorld_938ebb10) == 1072, "hkpWorld_938ebb10 layout differs from the PDB");
