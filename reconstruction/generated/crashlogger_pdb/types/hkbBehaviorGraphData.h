// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBehaviorGraphData; size 0x80
#pragma once

#include "hkArray_RE__hkbEventInfo_05ffc3b9.h"
#include "hkArray_RE__hkbVariableBounds_79d46152.h"
#include "hkArray_RE__hkbVariableInfo_6109a65a.h"
#include "hkArray_float_2ea7b9d8.h"
#include "hkRefPtr_RE__hkbBehaviorGraphStringData_716c3095.h"
#include "hkReferencedObject.h"
struct hkbVariableValueSet;
struct hkbBehaviorGraphData {
    hkReferencedObject _base;
    hkArray_float_2ea7b9d8 attributeDefaults;
    hkArray_RE__hkbVariableInfo_6109a65a variableInfos;
    hkArray_RE__hkbVariableInfo_6109a65a characterPropertyInfos;
    hkArray_RE__hkbEventInfo_05ffc3b9 eventInfos;
    hkArray_RE__hkbVariableBounds_79d46152 variableBounds;
    unsigned long long unk60;
    unsigned long long unk68;
    hkbVariableValueSet* variableInitialValues;
    hkRefPtr_RE__hkbBehaviorGraphStringData_716c3095 stringData;
};
static_assert(sizeof(hkbBehaviorGraphData) == 128, "hkbBehaviorGraphData layout differs from the PDB");
