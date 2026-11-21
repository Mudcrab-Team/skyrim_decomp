// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiQuaternion; size 0x10
#pragma once
struct NiQuaternion {
    float w;
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiQuaternion) == 16, "NiQuaternion layout differs from the PDB");
