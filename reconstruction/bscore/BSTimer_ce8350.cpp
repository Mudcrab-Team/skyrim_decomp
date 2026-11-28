// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// CI hash: 0xce8350 ?InitTimer@BSTimer@@QEAAXI@Z
// 0xce8350 BSTimer::InitTimer
#include "BSTimer_ce8350.h"

namespace
{
    inline std::int64_t ReadPerformanceCounter()
    {
        std::int64_t counter = 0;
        QueryPerformanceCounter(&counter);
        return counter;
    }
}

// Calibrates the tick rate once, then resets the timer state and its baselines.
// The CrashLogger name BSTimer does not fit this body, which is written as what it does (a guess).
void BSTimer::InitTimer(std::uint32_t a_runTimeMS)
{
    if (gTicksPerMS == 0.0f) {
        std::int64_t frequency;
        QueryPerformanceFrequency(&frequency);
        gTicksPerMS = static_cast<float>(frequency) * 0.001f;
        gTicksPerUS = gTicksPerMS * 0.001f;
    }

    qpcBaseline = ReadPerformanceCounter();
    pauseCount = 0;
    clamp = 0.0f;
    clampRemainder = 0.0f;
    delta = 0.0f;
    realTimeDelta = 0.0f;
    smoothedRunTimeMS = 0;

    if (a_runTimeMS == 0) {
        runTimeMSBaseline = static_cast<std::uint32_t>(
            static_cast<double>(ReadPerformanceCounter() - qpcBaseline) / gTicksPerMS);
    } else {
        runTimeMSBaseline = a_runTimeMS;
    }

    useGlobalTimeMultiplierTarget = false;
}
