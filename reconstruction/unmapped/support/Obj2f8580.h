// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// ThreadAlloc2f8580, ThreadCtx2f8580, gTlsIndex2f8580, Obj2f8580: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long a_tlsIndex);

class ThreadAlloc2f8580
{
public:
    virtual ~ThreadAlloc2f8580();
    virtual void Slot01();
    virtual void Free(void* a_ptr, std::int32_t a_bytes);
};

struct ThreadCtx2f8580
{
    std::uint64_t unk00[11];      // 0x00
    ThreadAlloc2f8580* m_alloc;   // 0x58
};
static_assert(offsetof(ThreadCtx2f8580, m_alloc) == 0x58, "m_alloc offset");

extern unsigned long gTlsIndex2f8580;

class Obj2f8580
{
public:
    static void operator delete(void* a_ptr, std::size_t a_size);

    std::uint64_t unk00;          // 0x00
    std::uint16_t m_memSize;      // 0x08
};
