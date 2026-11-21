// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WORLD_MAP_OFFSET_DATA; size 0x10
#pragma once
struct WORLD_MAP_OFFSET_DATA {
    float mapScale;
    float mapOffsetX;
    float mapOffsetY;
    float mapOffsetZ;
};
static_assert(sizeof(WORLD_MAP_OFFSET_DATA) == 16, "WORLD_MAP_OFFSET_DATA layout differs from the PDB");
