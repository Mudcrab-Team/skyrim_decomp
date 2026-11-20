// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SceneGraph; size 0x150
#pragma once

#include "BSSceneGraph.h"
struct SceneGraph {
    BSSceneGraph _base;
    float customNearDistance;
    float customFarDistance;
    bool useCustomNear;
    bool useCustomFar;
    unsigned short pad14A;
    unsigned int pad14C;
};
static_assert(sizeof(SceneGraph) == 336, "SceneGraph layout differs from the PDB");
