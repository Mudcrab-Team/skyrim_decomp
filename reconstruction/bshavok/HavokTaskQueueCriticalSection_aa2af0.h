// Source exposure: mixed (community-generated names/layout and local binary analysis).
// Code origin: original reconstruction; minimal declarations from the assigned local pack.
// HavokTaskQueueCriticalSection, recursionCount, nativeCriticalSection, g_havokTaskQueue, g_havokTaskQueueTlsIndex: GUESS(low); local lock stand-ins.
// TlsGetValue, TlsSetValue, EnterCriticalSection: GUESS(low); inferred imported API roles.
// EnterHavokTaskQueueCriticalSection_1409C6B70: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xaa2af0 HavokTaskQueueCriticalSection::EnterHavokTaskQueueCriticalSection_1409C6B70
#pragma once
#include <cstddef>
#include <cstdint>
class HavokTaskQueueCriticalSection
{
public:
    static void EnterHavokTaskQueueCriticalSection_1409C6B70();
    std::uint8_t unknown00[0x14];
    std::uint32_t recursionCount;
    std::uint8_t unknown18[0x10];
    std::uint8_t nativeCriticalSection[0x28];
};
static_assert(offsetof(HavokTaskQueueCriticalSection, recursionCount) == 0x14, "recursion count offset");
static_assert(offsetof(HavokTaskQueueCriticalSection, nativeCriticalSection) == 0x28, "critical section offset");
extern HavokTaskQueueCriticalSection* g_havokTaskQueue;
extern unsigned long g_havokTaskQueueTlsIndex;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
