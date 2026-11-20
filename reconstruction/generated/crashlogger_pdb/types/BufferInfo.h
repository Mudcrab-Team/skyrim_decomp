// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BufferInfo; size 0x20
#pragma once
struct BufferInfo {
    void* buffer;
    unsigned int totalSize;
    unsigned int bufferAllocSize;
    unsigned int bufferReadSize;
    unsigned int bufferPos;
    unsigned int streamPos;
    unsigned int pad1C;
};
static_assert(sizeof(BufferInfo) == 32, "BufferInfo layout differs from the PDB");
