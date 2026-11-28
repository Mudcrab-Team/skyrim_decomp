// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Timerce8430, Functionce8430, QueryPerformanceCounter, lpPerformanceCount: GUESS(low)
#pragma once

#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(std::int64_t* lpPerformanceCount);

class Timerce8430
{
public:
    std::int64_t Functionce8430() const;
};
