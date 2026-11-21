// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryStatistics; size 0x30
#pragma once
struct MemoryStatistics {
    long long allocated;
    long long inUse;
    long long peakInUse;
    long long available;
    long long totalAvailable;
    long long largestBlock;
};
static_assert(sizeof(MemoryStatistics) == 48, "MemoryStatistics layout differs from the PDB");
