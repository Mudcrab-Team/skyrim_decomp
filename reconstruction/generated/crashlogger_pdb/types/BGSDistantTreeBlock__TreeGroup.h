// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDistantTreeBlock::TreeGroup; size 0x28
#pragma once

#include "BSTArray_BGSDistantTreeBlock__InstanceData.h"
#include "NiPointer_BSMultiStreamInstanceTriShape_3743ed77.h"
struct BGSDistantTreeBlock__TreeGroup {
    NiPointer_BSMultiStreamInstanceTriShape_3743ed77 Geometry_0;
    BSTArray_BGSDistantTreeBlock__InstanceData Instances_8;
    int Num_20;
    bool ShaderPropertyUpToDate_24;
    char TreeType_25;
    char _pad_26[2];
};
static_assert(sizeof(BGSDistantTreeBlock__TreeGroup) == 40, "BGSDistantTreeBlock__TreeGroup layout differs from the PDB");
