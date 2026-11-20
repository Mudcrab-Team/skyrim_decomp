// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadOrderEntry; size 0x1
#pragma once
struct LoadOrderEntry {
    unsigned char _pad_0[1];
};
static_assert(sizeof(LoadOrderEntry) == 1, "LoadOrderEntry layout differs from the PDB");
