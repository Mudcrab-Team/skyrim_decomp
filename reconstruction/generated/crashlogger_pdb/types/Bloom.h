// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Bloom; size 0x18
#pragma once
struct Bloom {
    unsigned char empty_raw[24];
};
static_assert(sizeof(Bloom) == 24, "Bloom layout differs from the PDB");
