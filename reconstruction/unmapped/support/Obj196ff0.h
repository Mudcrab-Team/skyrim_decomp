// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard196ff0 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Lock196ff0, ReadGuard196ff0, Obj196ff0, GetQueuedCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Lock196ff0
{
    void LockForRead();
    void UnlockForRead();

    std::uint64_t state;  // 00
};

struct ReadGuard196ff0
{
    explicit ReadGuard196ff0(Lock196ff0& a_lock) : lock(&a_lock)
    {
        lock->LockForRead();
    }

    ~ReadGuard196ff0()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

    Lock196ff0* lock;  // 00
};

struct Obj196ff0
{
    std::uint32_t GetQueuedCount();  // compared: 0x196ff0

    std::uint8_t unk00[0x44];  // 00
    std::uint32_t unk44;       // 44
    std::uint32_t unk48;       // 48
    std::uint8_t unk4C[0x4C];  // 4C
    Lock196ff0 lock;           // 98
};
