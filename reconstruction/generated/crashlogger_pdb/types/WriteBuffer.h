// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WriteBuffer; size 0x18
#pragma once
struct WriteBuffer {
    unsigned long long size;
    void* startPtr;
    void* curPtr;
};
static_assert(sizeof(WriteBuffer) == 24, "WriteBuffer layout differs from the PDB");
