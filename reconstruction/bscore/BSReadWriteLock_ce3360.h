// Source exposure: mixed (community headers; pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSReadWriteLock, LockForRead, _writerThread, _lock, kLockCountMask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kSpinLimit: GUESS(low)
#pragma once
#include <cstdint>
#include <intrin.h>
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
class BSReadWriteLock {
public:
    void LockForRead();
    enum : std::uint32_t { kLockCountMask = 0x0fffffff, kSpinLimit = 10000 };
    std::uint32_t _writerThread;
    volatile std::uint32_t _lock;
};
