// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Entry; size 0x10
#pragma once
struct Entry {
    unsigned char undefined_0[16];
};
static_assert(sizeof(Entry) == 16, "Entry layout differs from the PDB");
