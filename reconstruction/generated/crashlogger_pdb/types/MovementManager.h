// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementManager; size 0x38
#pragma once

#include "BSTSingletonExplicit_RE__MovementManager_89d5b384.h"
#include "BSTSmartPointer_RE__BSPathingSolution_e2b16ca6.h"
#include "BSTSmartPointer_RE__IMovementPlayIdleResult_5c56cfe8.h"
#include "BSTSmartPointer_RE__MovementArbitrationAverageFloat_0f314102.h"
#include "BSTSmartPointer_RE__MovementArbitrationMaxWeightParameters_a6c362e0.h"
#include "BSTSmartPointer_RE__MovementArbitrationMaxWeightPoint_9bdcca72.h"
#include "BSTSmartPointer_RE__MovementMessageBlocked_c2c46c9a.h"
struct MovementManager {
    BSTSingletonExplicit_RE__MovementManager_89d5b384 _base;
    unsigned char undefined_1[7];
    BSTSmartPointer_RE__MovementArbitrationAverageFloat_0f314102 floatAverage;
    BSTSmartPointer_RE__MovementArbitrationMaxWeightPoint_9bdcca72 vectorMaxWeight;
    BSTSmartPointer_RE__MovementArbitrationMaxWeightParameters_a6c362e0 parametersMaxWeight;
    BSTSmartPointer_RE__MovementMessageBlocked_c2c46c9a movementBlockedMessage;
    BSTSmartPointer_RE__IMovementPlayIdleResult_5c56cfe8 nullPlayIdleResult;
    BSTSmartPointer_RE__BSPathingSolution_e2b16ca6 emptySolution;
};
static_assert(sizeof(MovementManager) == 56, "MovementManager layout differs from the PDB");
