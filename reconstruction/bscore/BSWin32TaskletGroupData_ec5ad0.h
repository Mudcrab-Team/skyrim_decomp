// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletGroupData, BSWin32TaskletGroupData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// CriticalSection, CriticalSection::debugInfo, CriticalSection::lockCount, CriticalSection::recursionCount, CriticalSection::owningThread, CriticalSection::lockSemaphore, CriticalSection::spinCount, DeleteCriticalSection, CloseHandle, BSTaskletGroupData::Wait, BSTaskletGroupData::Finish, BSTaskletGroupData::allComplete, BSTaskletGroupData::completionSemaphore, BSTaskletGroupData::lock, BSTaskletGroupData::unk40: GUESS(low)
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

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CriticalSection* a_section);
extern "C" __declspec(dllimport) std::int32_t __stdcall CloseHandle(void* a_handle);

class BSTaskletGroupData
{
public:
    virtual ~BSTaskletGroupData();
    virtual void Wait(bool a_flag);

    void Finish()
    {
        if (!allComplete) {
            Wait(false);
        }
    }

    bool allComplete;
    void* completionSemaphore;
    CriticalSection lock;
    std::uint8_t unk40[0x10];
};
static_assert(offsetof(BSTaskletGroupData, allComplete) == 0x08, "allComplete offset");
static_assert(offsetof(BSTaskletGroupData, completionSemaphore) == 0x10, "completionSemaphore offset");
static_assert(offsetof(BSTaskletGroupData, lock) == 0x18, "lock offset");
static_assert(sizeof(BSTaskletGroupData) == 0x50, "BSTaskletGroupData size");

class BSWin32TaskletGroupData : public BSTaskletGroupData
{
public:
    BSWin32TaskletGroupData();
    ~BSWin32TaskletGroupData() override;
};
static_assert(sizeof(BSWin32TaskletGroupData) == 0x50, "BSWin32TaskletGroupData size");
