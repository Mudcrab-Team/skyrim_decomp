// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryStats; size 0x30
#pragma once
struct MemoryStats {
    unsigned char* name;
    unsigned long long usedSize;
    unsigned long long committedSize;
    unsigned long long reservedSize;
    unsigned int overhead;
    unsigned int pad24;
    unsigned long long freeSize;
};
static_assert(sizeof(MemoryStats) == 48, "MemoryStats layout differs from the PDB");
