// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// CriticalSection_ea4a00, g_initialized_ea4a00, g_lock_ea4a00, Functionea4a00, EnterCriticalSection, unk00: GUESS(low)
#pragma once

#include <cstdint>

struct CriticalSection_ea4a00
{
    std::uint8_t unk00[0x28];  // 0x00
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection_ea4a00* lpCriticalSection);

extern bool g_initialized_ea4a00;
extern CriticalSection_ea4a00 g_lock_ea4a00;

std::uint32_t Functionea4a00();
