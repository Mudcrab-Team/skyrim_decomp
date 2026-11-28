// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Worker199690, Manager199690, Obj199690, gManager199690, ReleaseWorker: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();
    __declspec(dllimport) std::int32_t __stdcall ReleaseSemaphore(void* a_handle, std::int32_t a_count, std::int32_t* a_prev);
}

struct Worker199690
{
    void Signal();

    std::uint8_t unk00[0x40];  // 00
    std::uint32_t threadId;    // 40
    std::uint8_t unk44[0x14];  // 44
    void* semHandle;           // 58
};

struct Manager199690
{
    std::uint8_t unk00[0xB0];  // 00
    Worker199690* worker;      // B0
};

extern Manager199690* gManager199690;

struct Obj199690
{
    static void ReleaseWorker();  // compared: 0x199690
};
