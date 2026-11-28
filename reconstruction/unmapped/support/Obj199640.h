// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Worker199640, Manager199640, Obj199640, gManager199640, WaitForWorker: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();
    __declspec(dllimport) std::uint32_t __stdcall WaitForSingleObject(void* a_handle, std::uint32_t a_timeout);
}

struct Worker199640
{
    void Signal();

    std::uint8_t unk00[0x40];  // 00
    std::uint32_t threadId;    // 40
    std::uint8_t unk44[0x14];  // 44
    void* semHandle;         // 58
};

struct Manager199640
{
    std::uint8_t unk00[0xB0];  // 00
    Worker199640* worker;      // B0
};

extern Manager199640* gManager199640;

struct Obj199640
{
    static void WaitForWorker();  // compared: 0x199640
};
