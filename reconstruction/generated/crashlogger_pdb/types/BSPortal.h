// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortal; size 0x130
#pragma once

#include "BSOcclusionPlane.h"
#include "NiPointer_RE__BSPortalSharedNode_02c079bc.h"
struct BSMultiBoundRoom;
struct BSPortal {
    BSOcclusionPlane _base;
    BSMultiBoundRoom* entranceRoom;
    BSMultiBoundRoom* exitRoom;
    NiPointer_RE__BSPortalSharedNode_02c079bc portalSharedNode;
};
static_assert(sizeof(BSPortal) == 304, "BSPortal layout differs from the PDB");
