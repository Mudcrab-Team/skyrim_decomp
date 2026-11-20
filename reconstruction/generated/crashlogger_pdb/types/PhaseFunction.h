// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PhaseFunction; size 0x8
#pragma once
struct PhaseFunction {
    float contribution;
    float scattering;
};
static_assert(sizeof(PhaseFunction) == 8, "PhaseFunction layout differs from the PDB");
