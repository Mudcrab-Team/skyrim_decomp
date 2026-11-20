// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GMatrix3D; size 0x40
#pragma once
struct GMatrix3D {
    float data[4][4];
};
static_assert(sizeof(GMatrix3D) == 64, "GMatrix3D layout differs from the PDB");
