// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSReadWriteLock, BSReadWriteLock::_writerThread, ::_lock, ::LockForRead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadWriteLock::kLockWrite, ::kLockCountMask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SpinBackoff, SpinBackoff::SpinBackoff, SpinBackoff::Pause, SpinBackoff::spins: GUESS(low); original names for a one-member spin counter object, the shape is read from the pinned image listing
// GetCurrentThreadId, Sleep: OBSERVED; kernel32 imports called by the target
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

class SpinBackoff
{
public:
    SpinBackoff();
    void Pause();

private:
    std::uint32_t spins;  // 0
};

inline SpinBackoff::SpinBackoff()
    : spins()
{
}

inline void SpinBackoff::Pause()
{
    if (spins < 10000) {
        ++spins;
        ::Sleep(0);
    } else {
        ::Sleep(1);
    }
}

class BSReadWriteLock
{
public:
    enum : std::uint32_t
    {
        kLockWrite = 0x80000000,
        kLockCountMask = 0xFFFFFFF
    };

    void LockForRead();  // compared: 0xce3250

private:
    std::uint32_t _writerThread;   // 0
    volatile std::uint32_t _lock;  // 4
};
