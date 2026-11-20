// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBehaviorGraphStringData; size 0x50
#pragma once

#include "hkArray_RE__hkStringPtr_582be5ff.h"
#include "hkReferencedObject.h"
struct hkbBehaviorGraphStringData {
    hkReferencedObject _base;
    hkArray_RE__hkStringPtr_582be5ff eventNames;
    hkArray_RE__hkStringPtr_582be5ff attributeNames;
    hkArray_RE__hkStringPtr_582be5ff variableNames;
    hkArray_RE__hkStringPtr_582be5ff characterPropertyNames;
};
static_assert(sizeof(hkbBehaviorGraphStringData) == 80, "hkbBehaviorGraphStringData layout differs from the PDB");
