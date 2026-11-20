// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Receiver; size 0x8
#pragma once
struct Receiver {
    float* amplitude;
};
static_assert(sizeof(Receiver) == 8, "Receiver layout differs from the PDB");
