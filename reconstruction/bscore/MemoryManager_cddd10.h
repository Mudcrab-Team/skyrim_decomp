// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// MemoryManager, GetIMemoryHeap: CRASHLOGGER_PDB(59818@2026.10.24)
// IMemoryHeap, PointerInHeap, unk00, heapCount, unk04, heaps, Unk_01..Unk_09: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class IMemoryHeap
{
public:
    virtual ~IMemoryHeap();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09();
    virtual bool PointerInHeap(const void* ptr) const;  // 50
};

class MemoryManager
{
public:
    IMemoryHeap* GetIMemoryHeap(const void* ptr) const;

    std::uint16_t unk00;      // 00
    std::uint16_t heapCount;  // 02
    std::uint32_t unk04;      // 04
    IMemoryHeap** heaps;      // 08
};
static_assert(sizeof(MemoryManager) == 0x10, "MemoryManager size");
