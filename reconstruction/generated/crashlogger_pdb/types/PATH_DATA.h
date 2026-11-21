// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PATH_DATA; size 0x1
#pragma once
struct PATH_DATA {
    unsigned char flags;  // PathFlags in the PDB is wider than this slot
};
static_assert(sizeof(PATH_DATA) == 1, "PATH_DATA layout differs from the PDB");
