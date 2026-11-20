// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBoundRoom; size 0x198
#pragma once

#include "BSMultiBoundNode.h"
#include "BSTArray_RE__BSLight_d206b33f_151e133f.h"
#include "NiTPointerList_RE__BSOcclusionShape_f4acfd64.h"
#include "NiTPointerList_RE__BSPortal_b3a21497.h"
#include "NiTPointerList_RE__NiPointer_RE__BSMultiBound_312b5efe.h"
struct BSMultiBoundRoom {
    BSMultiBoundNode _base;
    NiTPointerList_RE__BSPortal_b3a21497 portalList;
    NiTPointerList_RE__BSOcclusionShape_f4acfd64 occluderList;
    NiTPointerList_RE__NiPointer_RE__BSMultiBound_312b5efe joinedMultiBoundList;
    BSTArray_RE__BSLight_d206b33f_151e133f lights;
};
static_assert(sizeof(BSMultiBoundRoom) == 408, "BSMultiBoundRoom layout differs from the PDB");
