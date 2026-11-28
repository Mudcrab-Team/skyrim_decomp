// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit205810::Unlock205810, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpinLock205810, Unit205810, g_spinLock205810, ownerThread, lockCount, Unlock205810: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct SpinLock205810
{
    std::uint32_t ownerThread;  // 00
    long lockCount;             // 04
};
static_assert(offsetof(SpinLock205810, lockCount) == 0x04, "SpinLock205810::lockCount offset");

extern SpinLock205810 g_spinLock205810;

struct Unit205810
{
    static void Unlock205810();  // compared: 0x205810
};
