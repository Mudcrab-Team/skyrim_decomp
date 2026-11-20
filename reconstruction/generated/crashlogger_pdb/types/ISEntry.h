// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ISEntry; size 0x1
#pragma once
struct ISEntry {
    unsigned char _pad_0[1];
};
static_assert(sizeof(ISEntry) == 1, "ISEntry layout differs from the PDB");
