// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSTaskThread19e7c0, StopAndWake, StopThread, semHandle58, stopped60: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) std::int32_t __stdcall ReleaseSemaphore(void* a_handle, std::int32_t a_releaseCount, std::int32_t* a_prevCount);
}

struct BSTaskThread19e7c0
{
    void StopThread();
    void StopAndWake();  // compared: 0x19e7c0

    std::uint8_t unk00[0x58];  // 00
    void* semHandle58;         // 58
    std::uint8_t stopped60;    // 60
};
