// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSDirectoryEntry; size 0x1
#pragma once
struct BSDirectoryEntry {
    unsigned char _pad_0[1];
};
static_assert(sizeof(BSDirectoryEntry) == 1, "BSDirectoryEntry layout differs from the PDB");
