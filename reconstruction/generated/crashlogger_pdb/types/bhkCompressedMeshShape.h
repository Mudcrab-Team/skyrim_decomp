// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCompressedMeshShape; size 0x30
#pragma once

#include "NiPointer_RE__bhkCompressedMeshShapeData_1250e683.h"
#include "bhkShapeCollection.h"
struct bhkCompressedMeshShape {
    bhkShapeCollection _base;
    NiPointer_RE__bhkCompressedMeshShapeData_1250e683 data;
};
static_assert(sizeof(bhkCompressedMeshShape) == 48, "bhkCompressedMeshShape layout differs from the PDB");
