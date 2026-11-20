// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGeometryListCullingProcess; size 0x30200
#pragma once

#include "BSCullingProcess.h"
struct BSGeometryListCullingProcess {
    BSCullingProcess _base;
    int lightIndex;
    unsigned char undefined_301fc[4];
};
static_assert(sizeof(BSGeometryListCullingProcess) == 197120, "BSGeometryListCullingProcess layout differs from the PDB");
