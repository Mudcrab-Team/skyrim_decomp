// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// CriticalSectiond6eb10, InitSpinCountFn_d6eb10, Lockd6eb10, g_spinInitResolved_d6eb10, g_initSpinCountFn_d6eb10, cs, storage, spinCount, GetModuleHandleA, GetProcAddress, InitializeCriticalSection: GUESS(low)
#pragma once

#include <cstdint>

struct CriticalSectiond6eb10
{
    std::uint64_t storage[5];  // 0x00
};
static_assert(sizeof(CriticalSectiond6eb10) == 0x28, "CriticalSectiond6eb10 size");

using InitSpinCountFn_d6eb10 = int(__stdcall*)(CriticalSectiond6eb10*, std::uint32_t);

extern "C" {
__declspec(dllimport) void* __stdcall GetModuleHandleA(const char* moduleName);
__declspec(dllimport) void* __stdcall GetProcAddress(void* module, const char* procName);
__declspec(dllimport) void __stdcall InitializeCriticalSection(CriticalSectiond6eb10* cs);
}

extern bool g_spinInitResolved_d6eb10;
extern InitSpinCountFn_d6eb10 g_initSpinCountFn_d6eb10;

struct Lockd6eb10
{
    CriticalSectiond6eb10 cs;  // 0x00

    explicit Lockd6eb10(std::uint32_t spinCount);
};
