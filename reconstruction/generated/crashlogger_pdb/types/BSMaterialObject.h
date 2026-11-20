// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMaterialObject; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__NiPointer_RE__NiProperty_f8095621.h"
#include "DIRECTIONAL_DATA.h"
struct BSMaterialObject_vtbl;
struct BSMaterialObject {
    BSMaterialObject_vtbl* __vftable;
    DIRECTIONAL_DATA directionalData;
    BSTArray_RE__NiPointer_RE__NiProperty_f8095621 properties;
};
static_assert(sizeof(BSMaterialObject) == 88, "BSMaterialObject layout differs from the PDB");
