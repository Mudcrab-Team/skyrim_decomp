// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshEdgeExtraInfo; size 0xc
// one of 2 different PDB types sharing this name
#pragma once

#include "BSNavmeshTriangleEdgePortal_6caa9608.h"
#include "EDGE_EXTRA_INFO_TYPE.h"
struct BSNavmeshEdgeExtraInfo_fad836c2 {
    EDGE_EXTRA_INFO_TYPE type;
    BSNavmeshTriangleEdgePortal_6caa9608 portal;
};
static_assert(sizeof(BSNavmeshEdgeExtraInfo_fad836c2) == 12, "BSNavmeshEdgeExtraInfo_fad836c2 layout differs from the PDB");
