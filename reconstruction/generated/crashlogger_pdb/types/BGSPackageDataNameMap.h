// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPackageDataNameMap; size 0x20
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BGSPackageDataNameMap__NameMapData_9670dff0.h"
struct BGSPackageDataNameMap {
    BSIntrusiveRefCounted _base;
    unsigned int pad04;
    BSTArray_RE__BGSPackageDataNameMap__NameMapData_9670dff0 nameMap;
};
static_assert(sizeof(BGSPackageDataNameMap) == 32, "BGSPackageDataNameMap layout differs from the PDB");
