// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBindable; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkRefPtr_RE__hkbVariableBindingSet_accb26b7_eac793d2.h"
#include "hkReferencedObject.h"
struct hkbBindable {
    hkReferencedObject _base;
    hkRefPtr_RE__hkbVariableBindingSet_accb26b7_eac793d2 variableBindingSet;
    hkArray_RE__hkRefVariant_9938e2d5 cachedBindables;
    bool areBindablesCached;
    unsigned char pad29;
    unsigned short pad2A;
    unsigned int pad2C;
};
static_assert(sizeof(hkbBindable) == 48, "hkbBindable layout differs from the PDB");
