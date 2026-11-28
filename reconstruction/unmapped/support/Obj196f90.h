// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard196f90 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Lock196f90, ReadGuard196f90, Obj196f90, GetQueuedCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Lock196f90
{
    void LockForRead();
    void UnlockForRead();

    std::uint64_t state;  // 00
};

struct ReadGuard196f90
{
    explicit ReadGuard196f90(Lock196f90& a_lock) : lock(&a_lock)
    {
        lock->LockForRead();
    }

    ~ReadGuard196f90()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

    Lock196f90* lock;  // 00
};

struct Obj196f90
{
    std::uint32_t GetQueuedCount();  // compared: 0x196f90

    std::uint8_t unk00[0x14];  // 00
    std::uint32_t unk14;       // 14
    std::uint32_t unk18;       // 18
    std::uint8_t unk1C[0x7C];  // 1C
    Lock196f90 lock;           // 98
};
