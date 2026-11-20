// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshEdgeExtraInfo; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSNavmeshTriangleEdgePortal.h"
#include "EDGE_EXTRA_INFO_TYPE.h"
struct BSNavmeshEdgeExtraInfo {
    EDGE_EXTRA_INFO_TYPE type;
    BSNavmeshTriangleEdgePortal Portal_4;
};
static_assert(sizeof(BSNavmeshEdgeExtraInfo) == 12, "BSNavmeshEdgeExtraInfo layout differs from the PDB");
