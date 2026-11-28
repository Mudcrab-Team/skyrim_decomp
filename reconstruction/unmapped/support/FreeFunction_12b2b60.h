// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// CriticalSection_12b2b60, g_map_12b2b60, g_lock_12b2b60, EnterCriticalSection, LeaveCriticalSection, Function12b2b60, storage, cs, key: GUESS(low)
#pragma once

#include <cstdint>
#include <map>

struct CriticalSection_12b2b60
{
    std::uint64_t storage[5];  // 0x00
};
static_assert(sizeof(CriticalSection_12b2b60) == 0x28, "CriticalSection_12b2b60 size");

extern "C" {
__declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection_12b2b60* cs);
__declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection_12b2b60* cs);
}

extern std::map<std::uint64_t, void*> g_map_12b2b60;
extern CriticalSection_12b2b60 g_lock_12b2b60;

void* Function12b2b60(std::uint64_t key);
