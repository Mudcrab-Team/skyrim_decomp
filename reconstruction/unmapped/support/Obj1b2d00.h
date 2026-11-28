// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1b2d00::Unlock, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpinLock1b2d00, Obj1b2d00, Unlock, g_spinLock1b2d00, ownerThread, lockCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();
}

struct SpinLock1b2d00
{
    std::uint32_t ownerThread;  // 00
    long lockCount;             // 04
};
static_assert(offsetof(SpinLock1b2d00, lockCount) == 0x04, "SpinLock1b2d00::lockCount offset");

extern SpinLock1b2d00 g_spinLock1b2d00;

struct Obj1b2d00
{
    static void Unlock();  // compared: 0x1b2d00
};
