// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WORLD_MAP_DATA; size 0x1c
#pragma once

#include "CameraData.h"
struct WORLD_MAP_DATA {
    unsigned int usableWidth;
    unsigned int usableHeight;
    short nwCellX;
    short nwCellY;
    short seCellX;
    short seCellY;
    CameraData cameraData;
};
static_assert(sizeof(WORLD_MAP_DATA) == 28, "WORLD_MAP_DATA layout differs from the PDB");
