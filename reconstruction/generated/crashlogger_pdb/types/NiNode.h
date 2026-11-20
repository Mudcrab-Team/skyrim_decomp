// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiNode; size 0x128
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiAVObject.h"
#include "NiTObjectArray_RE__NiPointer_RE__NiAVObject_3d1d987f.h"
struct NiNode {
    NiAVObject _base;
    NiTObjectArray_RE__NiPointer_RE__NiAVObject_3d1d987f children;
};
static_assert(sizeof(NiNode) == 296, "NiNode layout differs from the PDB");
