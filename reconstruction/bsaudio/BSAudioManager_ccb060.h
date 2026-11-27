// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSAudioManager, BSAudioManager::SignalWorker, WorkerState, count, handle, active, worker: GUESS(low)
// ReleaseSemaphore: GUESS(medium); Win32 import taking a handle, a count and a null previous-count pointer
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* a_handle, long a_releaseCount, long* a_previousCount);

// Minimal stand-in: worker state with a pending count, an active flag and a semaphore handle.
struct WorkerState
{
    std::uint8_t unk00[0x40];
    std::uint32_t count;
    std::uint8_t unk44[0x0C];
    void* handle;
    std::uint8_t unk58[0x09];
    std::uint8_t active;
};

class BSAudioManager
{
public:
    void SignalWorker();  // compared: 0xccb060

    std::uint8_t unk00[0xF8];
    WorkerState* worker;
};
