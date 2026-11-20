// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortalGraph; size 0xc8
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6_b6e00dd9.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101.h"
#include "BSTArray_RE__NiPointer_RE__NiNode_8289c001.h"
#include "NiPointer_RE__BSPortalSharedNode_02c079bc.h"
#include "NiRefObject.h"
#include "NiTPointerList_RE__BSOcclusionShape_43204e46.h"
#include "NiTPointerList_RE__BSPortal_a993057f.h"
struct BSPortalGraph_399cc2f4 {
    NiRefObject _base;
    NiTPointerList_RE__BSOcclusionShape_43204e46 occlusionShapes;
    NiTPointerList_RE__BSPortal_a993057f portals;
    BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6_b6e00dd9 rooms;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101 alwaysRenderChildren;
    NiPointer_RE__BSPortalSharedNode_02c079bc portalSharedNode;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101 pendingAlwaysRenderAdds;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101 pendingAlwaysRenderRemoves;
    BSTArray_RE__NiPointer_RE__NiNode_8289c001 loadedCellNodes;
    unsigned int cellID;
    unsigned int padC4;
};
static_assert(sizeof(BSPortalGraph_399cc2f4) == 200, "BSPortalGraph_399cc2f4 layout differs from the PDB");
