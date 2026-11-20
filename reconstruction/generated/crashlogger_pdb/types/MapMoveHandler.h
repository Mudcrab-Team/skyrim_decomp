// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapMoveHandler; size 0x20
#pragma once

#include "BSTPoint2_float_af46c5cb.h"
#include "MapInputHandler.h"
struct MapMoveHandler {
    MapInputHandler _base;
    BSTPoint2_float_af46c5cb unk18;
};
static_assert(sizeof(MapMoveHandler) == 32, "MapMoveHandler layout differs from the PDB");
