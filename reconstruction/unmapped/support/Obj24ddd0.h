// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj24ddd0, WaitAndReset, g_waitCount: GUESS(low)
#pragma once

#include <cstdint>

extern std::uint32_t g_waitCount;
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long a_milliseconds);

class Obj24ddd0
{
public:
    static void WaitAndReset();
};
