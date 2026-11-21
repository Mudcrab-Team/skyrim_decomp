// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBoundNode; size 0x138
#pragma once

#include "BSCPCullingType.h"
#include "BSNiNode_57174b0c.h"
#include "NiPointer_RE__BSMultiBound_357f0b6a.h"
struct BSMultiBoundNode {
    BSNiNode_57174b0c _base;
    NiPointer_RE__BSMultiBound_357f0b6a multiBound;
    BSCPCullingType cullingMode;
    float lastAccumTime;
};
static_assert(sizeof(BSMultiBoundNode) == 312, "BSMultiBoundNode layout differs from the PDB");
