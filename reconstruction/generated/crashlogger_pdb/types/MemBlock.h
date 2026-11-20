// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemBlock; size 0x1
#pragma once
struct MemBlock {
    unsigned char _pad_0[1];
};
static_assert(sizeof(MemBlock) == 1, "MemBlock layout differs from the PDB");
