// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// MutexImpl_e14600, LockWrapper_e14600, Functione14600, handle, unk08, lockCount, unk00, mutex, wrapper, WaitForSingleObject: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct MutexImpl_e14600
{
    void* handle;             // 0x00
    std::uint32_t unk08;      // 0x08
    std::uint32_t lockCount;  // 0x0C
};
static_assert(offsetof(MutexImpl_e14600, lockCount) == 0x0C, "lockCount offset");

struct LockWrapper_e14600
{
    std::uint64_t unk00[4];   // 0x00
    MutexImpl_e14600* mutex;  // 0x20
};
static_assert(offsetof(LockWrapper_e14600, mutex) == 0x20, "mutex offset");

unsigned long Functione14600(LockWrapper_e14600* wrapper);
