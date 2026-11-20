// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMaterialObject; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__NiPointer_RE__NiProperty_f8095621_f0dcce78.h"
#include "DIRECTIONAL_DATA_71dc29a6.h"
struct BSMaterialObject_vtbl;
struct BSMaterialObject_b118a84b {
    BSMaterialObject_vtbl* __vftable;
    DIRECTIONAL_DATA_71dc29a6 directionalData;
    BSTArray_RE__NiPointer_RE__NiProperty_f8095621_f0dcce78 properties;
};
static_assert(sizeof(BSMaterialObject_b118a84b) == 88, "BSMaterialObject_b118a84b layout differs from the PDB");
