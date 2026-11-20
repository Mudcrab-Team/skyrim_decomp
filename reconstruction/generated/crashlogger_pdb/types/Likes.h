// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Likes; size 0x1
#pragma once
struct Likes {
    unsigned char _pad_0[1];
};
static_assert(sizeof(Likes) == 1, "Likes layout differs from the PDB");
