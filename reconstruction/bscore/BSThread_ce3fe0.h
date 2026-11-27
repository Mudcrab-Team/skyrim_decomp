// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSThread: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// CriticalSection, CriticalSection::debugInfo, CriticalSection::lockCount, CriticalSection::recursionCount, CriticalSection::owningThread, CriticalSection::lockSemaphore, CriticalSection::spinCount, EnterCriticalSection, LeaveCriticalSection, DeleteCriticalSection, GetCurrentThreadId, WaitForSingleObject, CloseHandle, BSThread::ThreadProc, BSThread::OnWaitTimeout, BSThread::Shutdown, BSThread::lock, BSThread::thread, BSThread::ownerThread, BSThread::threadID, BSThread::ownerThreadID, BSThread::initialized: GUESS(low)
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
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CriticalSection* a_section);
extern "C" __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) std::uint32_t __stdcall WaitForSingleObject(void* a_handle, std::uint32_t a_milliseconds);
extern "C" __declspec(dllimport) std::int32_t __stdcall CloseHandle(void* a_handle);

class BSThread
{
public:
    BSThread();
    virtual ~BSThread();
    virtual std::uint32_t ThreadProc();
    virtual void OnWaitTimeout();

    void Shutdown()
    {
        if (thread) {
            initialized = false;
            EnterCriticalSection(&lock);
            if (GetCurrentThreadId() != threadID) {
                while (WaitForSingleObject(thread, 10) == 0x102u) {
                    OnWaitTimeout();
                }
            }
            CloseHandle(thread);
            thread = nullptr;
            LeaveCriticalSection(&lock);
        }
    }

    CriticalSection lock;
    void* thread;
    void* ownerThread;
    std::uint32_t threadID;
    std::uint32_t ownerThreadID;
    bool initialized;
};
static_assert(offsetof(BSThread, lock) == 0x08, "lock offset");
static_assert(offsetof(BSThread, thread) == 0x30, "thread offset");
static_assert(offsetof(BSThread, threadID) == 0x40, "threadID offset");
static_assert(offsetof(BSThread, initialized) == 0x48, "initialized offset");
static_assert(sizeof(BSThread) == 0x50, "BSThread size");
