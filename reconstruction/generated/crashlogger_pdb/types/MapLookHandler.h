// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapLookHandler; size 0x20
#pragma once

#include "MapInputHandler.h"
struct MapLookHandler {
    MapInputHandler _base;
    unsigned long long unk18;
};
static_assert(sizeof(MapLookHandler) == 32, "MapLookHandler layout differs from the PDB");
