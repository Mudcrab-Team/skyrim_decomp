// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkMeshMaterial; size 0x8
#pragma once

#include "MATERIAL_ID.h"
#include "hkpMeshMaterial.h"
struct bhkMeshMaterial {
    hkpMeshMaterial _base;
    MATERIAL_ID materialID;
};
static_assert(sizeof(bhkMeshMaterial) == 8, "bhkMeshMaterial layout differs from the PDB");
