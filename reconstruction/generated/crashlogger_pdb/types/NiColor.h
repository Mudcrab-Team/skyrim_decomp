// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiColor; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct NiColor {
    float r;
    float g;
    float b;
};
static_assert(sizeof(NiColor) == 12, "NiColor layout differs from the PDB");
