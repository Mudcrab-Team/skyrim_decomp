// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacterData; size 0xb0
#pragma once

#include "hkArray_RE__hkbVariableInfo_6109a65a.h"
#include "hkArray_int_16774380.h"
#include "hkRefPtr_RE__hkReferencedObject_80d781c0.h"
#include "hkRefPtr_RE__hkbCharacterStringData_519628eb.h"
#include "hkRefPtr_RE__hkbFootIkDriverInfo_1467ccf4.h"
#include "hkRefPtr_RE__hkbHandIkDriverInfo_be00a261.h"
#include "hkRefPtr_RE__hkbVariableValueSet_e5ac4f49.h"
#include "hkReferencedObject.h"
struct hkbCharacterData {
    hkReferencedObject _base;
    unsigned char characterControllerSetup[24];
    float modelUpMS[4];
    float modelForwardMS[4];
    float modelRightMS[4];
    hkArray_RE__hkbVariableInfo_6109a65a characterPropertyInfos;
    hkArray_int_16774380 numBonesPerLod;
    hkRefPtr_RE__hkbVariableValueSet_e5ac4f49 characterPropertyValues;
    hkRefPtr_RE__hkbFootIkDriverInfo_1467ccf4 footIkDriverInfo;
    hkRefPtr_RE__hkbHandIkDriverInfo_be00a261 handIkDriverInfo;
    hkRefPtr_RE__hkReferencedObject_80d781c0 aiControlDriverInfo;
    hkRefPtr_RE__hkbCharacterStringData_519628eb stringData;
    char32_t* mirroredSkeletonInfo;
    float scale;
    short numHands;
    short numFloatSlots;
};
static_assert(sizeof(hkbCharacterData) == 176, "hkbCharacterData layout differs from the PDB");
