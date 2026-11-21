// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortalSharedNode; size 0x148
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BSLight_d206b33f.h"
#include "NiNode_9cd97e9e.h"
struct BSPortalSharedNode {
    NiNode_9cd97e9e _base;
    BSTArray_RE__BSLight_d206b33f lights;
    void* portal;
};
static_assert(sizeof(BSPortalSharedNode) == 328, "BSPortalSharedNode layout differs from the PDB");
