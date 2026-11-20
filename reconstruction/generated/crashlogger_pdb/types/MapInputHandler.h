// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapInputHandler; size 0x18
#pragma once

#include "MenuEventHandler.h"
struct MapMenu;
struct MapInputHandler {
    MenuEventHandler _base;
    MapMenu* mapMenu;
};
static_assert(sizeof(MapInputHandler) == 24, "MapInputHandler layout differs from the PDB");
