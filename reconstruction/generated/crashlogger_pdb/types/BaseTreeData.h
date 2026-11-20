// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BaseTreeData; size 0x38
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BoneData_7255723e.h"
#include "BSTArray_RE__NiMatrix3_3183ca3c.h"
struct BaseTreeData {
    BSIntrusiveRefCounted _base;
    unsigned int pad04;
    BSTArray_RE__BoneData_7255723e branchBoneData;
    BSTArray_RE__NiMatrix3_3183ca3c parentWorldBoneRotations;
};
static_assert(sizeof(BaseTreeData) == 56, "BaseTreeData layout differs from the PDB");
