// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Density; size 0x10
#pragma once
struct Density {
    float contribution;
    float size;
    float windSpeed;
    float fallingSpeed;
};
static_assert(sizeof(Density) == 16, "Density layout differs from the PDB");
