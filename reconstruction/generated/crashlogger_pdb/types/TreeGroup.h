// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TreeGroup; size 0x28
#pragma once

#include "BSTArray_RE__BGSDistantTreeBlock__InstanceData_d7e2cf9e.h"
#include "NiPointer_RE__BSMultiStreamInstanceTriShape_59b3bbf8.h"
struct TreeGroup {
    NiPointer_RE__BSMultiStreamInstanceTriShape_59b3bbf8 geometry;
    BSTArray_RE__BGSDistantTreeBlock__InstanceData_d7e2cf9e instances;
    unsigned int num;
    bool shaderPropertyUpToDate;
    unsigned char treeType;
    unsigned short pad26;
};
static_assert(sizeof(TreeGroup) == 40, "TreeGroup layout differs from the PDB");
