// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Conditional; size 0x8
#pragma once
struct Conditional {
    int rank;
    unsigned char undefined_4[4];
};
static_assert(sizeof(Conditional) == 8, "Conditional layout differs from the PDB");
