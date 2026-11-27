// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// AbstractHeap, IMemoryHeap, BSCriticalSection, AbstractHeap::criticalSection: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* a_criticalSection);

struct BSCriticalSection
{
    std::uint8_t raw[0x28];
};

class IMemoryHeap
{
  public:
    virtual ~IMemoryHeap();
};

class AbstractHeap : public IMemoryHeap
{
  public:
    AbstractHeap();
    ~AbstractHeap() override
    {
        DeleteCriticalSection(&criticalSection);
    }

    BSCriticalSection criticalSection;
    std::uint8_t unk30[0x2A8 - 0x30];
};

static_assert(sizeof(AbstractHeap) == 0x2A8, "AbstractHeap size");
