// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// TlsGetValue, g_tlsMemoryIndex, TlsAllocator, TlsAllocator::Unk_00, TlsAllocator::Unk_01, TlsAllocator::Free, TlsMemoryBlock, TlsMemoryBlock::unk00, TlsMemoryBlock::allocator, BShkbAnimationGraph::unk00, BShkbAnimationGraph::buffer0, BShkbAnimationGraph::buffer1, BShkbAnimationGraph::buffer2, BShkbAnimationGraph::buffer3: GUESS(low)
// BShkbAnimationGraph::ReleaseScratchBuffers: GUESS(low); honest stand-in replacing the PDB-listed name SetGraphVariableInt because this zero-parameter function releases four thread-local scratch buffers
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(std::uint32_t a_tlsIndex);

extern std::uint32_t g_tlsMemoryIndex;

class TlsAllocator
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Free(void* a_ptr, std::uint32_t a_size);
};

struct TlsMemoryBlock
{
    std::uint8_t unk00[0x60];
    TlsAllocator* allocator;
};
static_assert(offsetof(TlsMemoryBlock, allocator) == 0x60, "allocator offset");

class BShkbAnimationGraph
{
public:
    void ReleaseScratchBuffers();

    std::uint8_t unk00[0x2968];
    void* buffer0;
    void* buffer1;
    void* buffer2;
    void* buffer3;
};
static_assert(offsetof(BShkbAnimationGraph, buffer0) == 0x2968, "buffer0 offset");
static_assert(offsetof(BShkbAnimationGraph, buffer3) == 0x2980, "buffer3 offset");
