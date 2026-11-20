// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Vector3; size 0xc
#pragma once
struct Vector3 {
    unsigned char undefined_0[4];
    float y;
    float z;
};
static_assert(sizeof(Vector3) == 12, "Vector3 layout differs from the PDB");
