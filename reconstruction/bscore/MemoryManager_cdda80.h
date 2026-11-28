// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// MemoryManager, QPoolExists: CRASHLOGGER_PDB(59818@2026.10.24)
// MemoryPoolTable, GetPoolCount, unk00, poolTable: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class MemoryPoolTable
{
public:
    std::uint32_t GetPoolCount() const;
};

class MemoryManager
{
public:
    bool QPoolExists(std::uint32_t poolIndex) const;

    std::uint64_t    unk00[134];  // 000
    MemoryPoolTable* poolTable;   // 430
};
static_assert(sizeof(MemoryManager) == 0x438, "MemoryManager size");
