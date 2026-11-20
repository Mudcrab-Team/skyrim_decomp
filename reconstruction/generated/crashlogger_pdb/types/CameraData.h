// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CameraData; size 0xc
#pragma once
struct CameraData {
    float minHeight;
    float maxHeight;
    float initialPitch;
};
static_assert(sizeof(CameraData) == 12, "CameraData layout differs from the PDB");
