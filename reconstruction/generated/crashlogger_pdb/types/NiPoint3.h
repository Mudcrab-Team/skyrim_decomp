// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPoint3; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct NiPoint3 {
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 12, "NiPoint3 layout differs from the PDB");
