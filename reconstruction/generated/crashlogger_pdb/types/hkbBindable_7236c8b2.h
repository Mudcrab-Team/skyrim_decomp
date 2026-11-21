// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBindable; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkRefPtr_RE__hkbVariableBindingSet_accb26b7.h"
#include "hkReferencedObject_2e7f2489.h"
struct hkbBindable_7236c8b2 {
    hkReferencedObject_2e7f2489 _base;
    hkRefPtr_RE__hkbVariableBindingSet_accb26b7 variableBindingSet;
    hkArray_RE__hkRefVariant_9938e2d5 cachedBindables;
    bool areBindablesCached;
    unsigned char pad29;
    unsigned short pad2A;
    unsigned int pad2C;
};
static_assert(sizeof(hkbBindable_7236c8b2) == 48, "hkbBindable_7236c8b2 layout differs from the PDB");
