// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TableType; size 0x10
#pragma once
struct TableType {
    unsigned long long entryCount;
    unsigned long long sizeMask;
};
static_assert(sizeof(TableType) == 16, "TableType layout differs from the PDB");
