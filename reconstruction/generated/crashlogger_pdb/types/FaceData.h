// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FaceData; size 0x5c
#pragma once
struct FaceData {
    float morphs[19];
    int parts[4];
};
static_assert(sizeof(FaceData) == 92, "FaceData layout differs from the PDB");
