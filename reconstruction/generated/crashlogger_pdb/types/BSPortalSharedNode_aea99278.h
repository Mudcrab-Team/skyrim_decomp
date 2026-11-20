// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortalSharedNode; size 0x148
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BSLight_d206b33f_151e133f.h"
#include "NiNode.h"
struct BSPortal;
struct BSPortalSharedNode_aea99278 {
    NiNode _base;
    BSTArray_RE__BSLight_d206b33f_151e133f lights;
    BSPortal* portal;
};
static_assert(sizeof(BSPortalSharedNode_aea99278) == 328, "BSPortalSharedNode_aea99278 layout differs from the PDB");
