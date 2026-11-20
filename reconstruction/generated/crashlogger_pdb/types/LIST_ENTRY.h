// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _LIST_ENTRY; size 0x10
#pragma once
struct LIST_ENTRY {
    LIST_ENTRY* Flink;
    LIST_ENTRY* Blink;
};
static_assert(sizeof(LIST_ENTRY) == 16, "LIST_ENTRY layout differs from the PDB");
