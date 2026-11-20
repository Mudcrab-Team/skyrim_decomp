// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GMatrix2D; size 0x18
#pragma once
struct GMatrix2D {
    float data[3][2];
};
static_assert(sizeof(GMatrix2D) == 24, "GMatrix2D layout differs from the PDB");
