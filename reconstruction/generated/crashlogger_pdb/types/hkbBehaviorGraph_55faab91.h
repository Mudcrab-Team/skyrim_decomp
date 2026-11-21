// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBehaviorGraph; size 0x130
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkRefPtr_RE__hkbBehaviorGraphData_2bbf8b50.h"
#include "hkRefPtr_RE__hkbGenerator_b7ad52b6.h"
#include "hkRefPtr_RE__hkbVariableValueSet_e5ac4f49.h"
#include "hkRefVariant.h"
#include "hkbGenerator.h"
struct RE__hkArray_RE__hkbNodeInfo_0a879670;
struct hkbBehaviorGraph_55faab91 {
    hkbGenerator _base;
    unsigned char variableMode;  // VariableMode in the PDB is wider than this slot
    unsigned char pad49;
    unsigned short pad4A;
    unsigned int pad4C;
    hkArray_RE__hkRefVariant_9938e2d5 uniqueIDPool;
    hkRefVariant idToStateMachineTemplateMap;
    hkArray_RE__hkRefVariant_9938e2d5 mirroredExternalIDMap;
    hkRefVariant pseudoRandomGenerator;
    hkRefPtr_RE__hkbGenerator_b7ad52b6 rootGenerator;
    hkRefPtr_RE__hkbBehaviorGraphData_2bbf8b50 data;
    hkRefVariant rootGeneratorClone;
    RE__hkArray_RE__hkbNodeInfo_0a879670* activeNodes;
    hkRefVariant activeNodeTemplateToIndexMap;
    hkRefVariant activeNodesChildrenIndices;
    hkRefVariant globalTransitionData;
    hkRefVariant eventIDMap;
    hkRefVariant attributeIDMap;
    hkRefVariant variableIDMap;
    hkRefVariant characterPropertyIDMap;
    hkRefPtr_RE__hkbVariableValueSet_e5ac4f49 variableValueSet;
    hkRefVariant nodeTemplateToCloneMap;
    hkRefVariant nodeCloneToTemplateMap;
    hkRefVariant stateListenerTemplateToCloneMap;
    hkRefVariant nodePartitionInfo;
    int numIntermediateOutputs;
    unsigned int pad104;
    hkArray_RE__hkRefVariant_9938e2d5 jobs;
    hkArray_RE__hkRefVariant_9938e2d5 allPartitionMemory;
    short numStaticNodes;
    short nextUniqueID;
    bool isActive;
    bool isLinked;
    bool updateActiveNodes;
    bool stateOrTransitionChanged;
};
static_assert(sizeof(hkbBehaviorGraph_55faab91) == 304, "hkbBehaviorGraph_55faab91 layout differs from the PDB");
