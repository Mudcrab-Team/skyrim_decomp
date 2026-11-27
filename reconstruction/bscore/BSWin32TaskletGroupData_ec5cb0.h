// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSWin32TaskletGroupData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSWin32TaskletGroupData::Cancel: CRASHLOGGER_PDB(59818@2026.10.24)
// CriticalSection, CriticalSection::debugInfo, CriticalSection::lockCount, CriticalSection::recursionCount, CriticalSection::owningThread, CriticalSection::lockSemaphore, CriticalSection::spinCount, EnterCriticalSection, LeaveCriticalSection, BSWin32TaskletGroupData::unk00, BSWin32TaskletGroupData::lock, BSWin32TaskletGroupData::unk40, BSWin32TaskletGroupData::unk41, BSWin32TaskletGroupData::cancelled: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct CriticalSection
{
    void* debugInfo;
    std::int32_t lockCount;
    std::int32_t recursionCount;
    void* owningThread;
    void* lockSemaphore;
    std::uint64_t spinCount;
};
static_assert(sizeof(CriticalSection) == 0x28, "CriticalSection size");

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection* a_section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection* a_section);

class BSWin32TaskletGroupData
{
public:
    void Cancel();

    std::uint8_t unk00[0x18];
    CriticalSection lock;
    bool unk40;
    bool unk41;
    bool cancelled;
};
static_assert(offsetof(BSWin32TaskletGroupData, lock) == 0x18, "lock offset");
static_assert(offsetof(BSWin32TaskletGroupData, unk41) == 0x41, "unk41 offset");
static_assert(offsetof(BSWin32TaskletGroupData, cancelled) == 0x42, "cancelled offset");
