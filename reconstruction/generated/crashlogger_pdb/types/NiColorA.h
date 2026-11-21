// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiColorA; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct NiColorA {
    float Red_0;
    float Green_4;
    float Blue_8;
    float Alpha_C;
};
static_assert(sizeof(NiColorA) == 16, "NiColorA layout differs from the PDB");
