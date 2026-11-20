// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Vector4; size 0x10
#pragma once
struct Vector4 {
    unsigned char undefined_0[4];
    float y;
    float z;
    float w;
};
static_assert(sizeof(Vector4) == 16, "Vector4 layout differs from the PDB");
