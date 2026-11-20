// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OFFSET_DATA; size 0x18
#pragma once
struct OFFSET_DATA {
    unsigned char unk00[8];
    float minCoords[2];
    float maxCoords[2];
};
static_assert(sizeof(OFFSET_DATA) == 24, "OFFSET_DATA layout differs from the PDB");
