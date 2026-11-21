// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: D3DVECTOR; size 0xc
#pragma once
struct D3DVECTOR {
    float x;
    float y;
    float z;
};
static_assert(sizeof(D3DVECTOR) == 12, "D3DVECTOR layout differs from the PDB");
