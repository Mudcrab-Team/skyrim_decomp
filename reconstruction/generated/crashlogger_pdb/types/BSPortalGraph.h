// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortalGraph; size 0xc8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "BSTArray_RE__NiPointer_RE__NiNode_8289c001.h"
#include "NiPointer_RE__BSPortalSharedNode_02c079bc.h"
#include "NiRefObject_f24a9221.h"
#include "NiTPointerList_RE__BSOcclusionShape_43204e46.h"
#include "NiTPointerList_RE__BSPortal_a993057f.h"
struct BSPortalGraph {
    NiRefObject_f24a9221 _base;
    NiTPointerList_RE__BSOcclusionShape_43204e46 occlusionShapes;
    NiTPointerList_RE__BSPortal_a993057f portals;
    BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6 rooms;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 alwaysRenderChildren;
    NiPointer_RE__BSPortalSharedNode_02c079bc portalSharedNode;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 unk78;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 unk90;
    BSTArray_RE__NiPointer_RE__NiNode_8289c001 unkA8;
    unsigned int cellID;
    unsigned int padC4;
};
static_assert(sizeof(BSPortalGraph) == 200, "BSPortalGraph layout differs from the PDB");
