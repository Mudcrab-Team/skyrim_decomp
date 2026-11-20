// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Cxform; size 0x20
#pragma once
struct Cxform {
    float matrix[2][4];
};
static_assert(sizeof(Cxform) == 32, "Cxform layout differs from the PDB");
