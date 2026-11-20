// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPortalGraphEntry; size 0x140
#pragma once

#include "BSCompoundFrustum.h"
#include "BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6.h"
#include "BSTScatterTable_RE__BSCRC32_RE__NiNode_std__equal_to_RE__NiNode_RE__BSTScatterTableTrai_1733360a.h"
#include "NiPointer_RE__BSMultiBoundRoom_f572e4cf.h"
#include "NiRefObject_f24a9221.h"
struct BSPortalGraph;
struct BSPortalGraphEntry {
    NiRefObject_f24a9221 _base;
    BSPortalGraph* portalGraph;
    BSTArray_RE__NiPointer_RE__BSMultiBoundRoom_27978ea6 multiBoundRoomAccumList;
    NiPointer_RE__BSMultiBoundRoom_f572e4cf multiBoundRoomRoot;
    BSTScatterTable_RE__BSCRC32_RE__NiNode_std__equal_to_RE__NiNode_RE__BSTScatterTableTrai_1733360a visibilityMap;
    BSCompoundFrustum compoundFrustum;
    bool visibleUnboundSpace;
    bool enableAccumulation;
    unsigned char pad132[2];
    unsigned int unk134;
    unsigned int cellId;
    unsigned char undefined_13c[4];
};
static_assert(sizeof(BSPortalGraphEntry) == 320, "BSPortalGraphEntry layout differs from the PDB");
