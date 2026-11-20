// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BufferType; size 0x1
#pragma once
struct BufferType {
    unsigned char undefined_0[1];
};
static_assert(sizeof(BufferType) == 1, "BufferType layout differs from the PDB");
