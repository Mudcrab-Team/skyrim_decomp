// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function1082ca0, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpinLock_1082ca0, g_spinLock_1082ca0, GetCurrentThreadId, NotifyUnlock_1082ca0, Function1082ca0, ownerThread, lockCount: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

struct SpinLock_1082ca0
{
    std::uint32_t ownerThread;  // 0x00
    long lockCount;             // 0x04
};

extern SpinLock_1082ca0 g_spinLock_1082ca0;

void NotifyUnlock_1082ca0();
void Function1082ca0();
