// Source exposure: mixed
// Code origin: adapted declarations and locking body from the labelled community source.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSpinLock, BSSpinLock::Lock, BSSpinLock::_owningThread, BSSpinLock::_lockCount, BSSpinLock::kFastSpinThreshold: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

#pragma once

#include <cstdint>

class BSSpinLock
{
public:
    enum { kFastSpinThreshold = 10000 };
    void Lock(std::uint32_t pauseAttempts);
    // volatile: owner publication participates in synchronization between threads.
    volatile std::uint32_t _owningThread;
    // volatile: recursive acquisition count is read and changed by competing threads.
    volatile std::uint32_t _lockCount;
};
