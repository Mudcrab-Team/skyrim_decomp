// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GHashSetTable; size 0x10
#pragma once
struct GHashSetTable {
    unsigned long long entryCount;
    unsigned long long sizeMask;
};
static_assert(sizeof(GHashSetTable) == 16, "GHashSetTable layout differs from the PDB");
