// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSTimer, smoothingBuffer, qpcBaseline, clamp, clampRemainder, delta, realTimeDelta, smoothedRunTimeMS, runTimeMS, runTimeMSBaseline, pauseCount, useGlobalTimeMultiplierTarget: CRASHLOGGER_PDB(59818@2026.10.24)
// QueryPerformanceFrequency, QueryPerformanceCounter: OBSERVED
// gTicksPerMS, gTicksPerUS, InitTimer, ReadPerformanceCounter: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(std::int64_t* a_freq);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(std::int64_t* a_counter);

extern float gTicksPerMS;
extern float gTicksPerUS;

class BSTimer
{
public:
    void InitTimer(std::uint32_t a_runTimeMS);  // compared: 0xce8350

    float* smoothingBuffer;                    // 00
    std::int64_t qpcBaseline;                  // 08
    float clamp;                               // 10
    float clampRemainder;                      // 14
    float delta;                               // 18
    float realTimeDelta;                       // 1C
    std::uint32_t smoothedRunTimeMS;           // 20
    std::uint32_t runTimeMS;                   // 24
    std::uint32_t runTimeMSBaseline;           // 28
    std::uint32_t pausedSmoothedRunTimeOffset; // 2C
    std::uint32_t pausedRunTimeOffset;         // 30
    std::uint32_t pauseCount;                  // 34
    std::uint8_t smoothingSampleCount;         // 38
    std::uint8_t smoothingBufferIndex;         // 39
    bool useGlobalTimeMultiplierTarget;        // 3A
    std::uint8_t reserved3B;                   // 3B
    std::uint32_t reserved3C;                  // 3C
};
static_assert(sizeof(BSTimer) == 0x40, "BSTimer size");
