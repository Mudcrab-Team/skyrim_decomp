// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResourceWeakLib; size 0x50
#pragma once

#include "GFxResourceLibBase.h"
#include "GHashSet_RE__GFxResourceWeakLib__ResourceNode_RE__GFxResourceWeakLib__ResourceNode__Has_9e13280e.h"
#include "GLock.h"
#include "GPtr_RE__GMemoryHeap_7de77900.h"
struct GFxResourceLib;
struct GFxResourceWeakLib {
    GFxResourceLibBase _base;
    GFxResourceLib* strongLib;
    GLock resourceLock;
    GHashSet_RE__GFxResourceWeakLib__ResourceNode_RE__GFxResourceWeakLib__ResourceNode__Has_9e13280e resources;
    GPtr_RE__GMemoryHeap_7de77900 imageHeap;
};
static_assert(sizeof(GFxResourceWeakLib) == 80, "GFxResourceWeakLib layout differs from the PDB");
