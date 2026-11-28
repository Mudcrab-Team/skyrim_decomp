// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard197050 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Lock197050, ReadGuard197050, Obj197050, GetQueuedCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Lock197050
{
    void LockForRead();
    void UnlockForRead();

    std::uint64_t state;  // 00
};

struct ReadGuard197050
{
    explicit ReadGuard197050(Lock197050& a_lock) : lock(&a_lock)
    {
        lock->LockForRead();
    }

    ~ReadGuard197050()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

    Lock197050* lock;  // 00
};

struct Obj197050
{
    std::uint32_t GetQueuedCount();  // compared: 0x197050

    std::uint8_t unk00[0x74];  // 00
    std::uint32_t unk74;       // 74
    std::uint32_t unk78;       // 78
    std::uint8_t unk7C[0x24];  // 7C
    Lock197050 lock;           // A0
};
