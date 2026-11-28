// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap, IMemoryStore, ScrapHeap::baseAddress: CRASHLOGGER_PDB(59818@2026.10.24)
// VirtualFree: OBSERVED; Windows API declaration
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, std::size_t size, unsigned long type);

class IMemoryStore
{
public:
    virtual ~IMemoryStore();
};

class ScrapHeap : public IMemoryStore
{
public:
    ScrapHeap();
    ~ScrapHeap() override;

    std::uint8_t unk08[0x40];
    void* baseAddress;
    std::uint8_t unk50[0x40];
};

static_assert(offsetof(ScrapHeap, baseAddress) == 0x48, "baseAddress offset");
static_assert(sizeof(ScrapHeap) == 0x90, "ScrapHeap size");
