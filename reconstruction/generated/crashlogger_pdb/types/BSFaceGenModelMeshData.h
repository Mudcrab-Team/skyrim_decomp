// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenModelMeshData; size 0x28
#pragma once

#include "NiPointer_RE__BSFaceGenMorphData_f952b764.h"
#include "NiPointer_RE__BSFaceGenNiNode_72d2b243.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
struct BSFaceGenModelMeshData {
    unsigned int unk00;
    unsigned int pad04;
    NiPointer_RE__BSFaceGenNiNode_72d2b243 faceNode;
    NiPointer_RE__BSTriShape_e1b1b3c6 faceShape;
    void* triData;
    NiPointer_RE__BSFaceGenMorphData_f952b764 morphData;
};
static_assert(sizeof(BSFaceGenModelMeshData) == 40, "BSFaceGenModelMeshData layout differs from the PDB");
