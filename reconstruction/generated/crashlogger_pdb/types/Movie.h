// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Movie; size 0x1
#pragma once
struct Movie {
    unsigned char _pad_0[1];
};
static_assert(sizeof(Movie) == 1, "Movie layout differs from the PDB");
