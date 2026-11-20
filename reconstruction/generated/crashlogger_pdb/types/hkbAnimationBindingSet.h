// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbAnimationBindingSet; size 0x30
#pragma once

#include "hkArray_RE__hkRefPtr_RE__hkbAssetBundle_cb33e9bc.h"
#include "hkArray_RE__hkbAnimationBindingWithTriggers_3daab103.h"
#include "hkReferencedObject.h"
struct hkbAnimationBindingSet {
    hkReferencedObject _base;
    hkArray_RE__hkbAnimationBindingWithTriggers_3daab103 bindings;
    hkArray_RE__hkRefPtr_RE__hkbAssetBundle_cb33e9bc assetBundles;
};
static_assert(sizeof(hkbAnimationBindingSet) == 48, "hkbAnimationBindingSet layout differs from the PDB");
