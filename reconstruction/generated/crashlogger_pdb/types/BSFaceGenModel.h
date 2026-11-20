// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenModel; size 0x20
#pragma once

#include "BSTSmartPointer_RE__BSFaceGenModelMeshData_380ca265.h"
#include "NiRefObject_f24a9221.h"
struct BSFaceGenModel {
    NiRefObject_f24a9221 _base;
    BSTSmartPointer_RE__BSFaceGenModelMeshData_380ca265 modelMeshData;
    unsigned int unk18;
    unsigned int pad1C;
};
static_assert(sizeof(BSFaceGenModel) == 32, "BSFaceGenModel layout differs from the PDB");
