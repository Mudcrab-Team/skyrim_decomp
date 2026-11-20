// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraAttachedArrows3D; size 0x30
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__ExtraAttachedArrows3D__DataItem_12ac7174.h"
struct ExtraAttachedArrows3D {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__ExtraAttachedArrows3D__DataItem_12ac7174 data;
    unsigned short nextStorage;
    unsigned short oldestStorage;
    unsigned int pad2C;
};
static_assert(sizeof(ExtraAttachedArrows3D) == 48, "ExtraAttachedArrows3D layout differs from the PDB");
