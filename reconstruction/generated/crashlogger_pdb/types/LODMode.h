// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LODMode; size 0x2
#pragma once
struct LODMode {
    unsigned short index : 7;
    unsigned short singleLevel : 1;
    unsigned short index_2 : 7;
    unsigned short singleLevel_2 : 1;
};
static_assert(sizeof(LODMode) == 2, "LODMode layout differs from the PDB");
