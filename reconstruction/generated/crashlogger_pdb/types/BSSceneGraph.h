// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSceneGraph; size 0x140
#pragma once

#include "NiNode.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct NiVisibleArray;
struct BSSceneGraph {
    NiNode _base;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    NiVisibleArray* visArray;
    bool menuSceneGraph;
    unsigned char pad139;
    unsigned short pad13A;
    float cameraFOV;
};
static_assert(sizeof(BSSceneGraph) == 320, "BSSceneGraph layout differs from the PDB");
