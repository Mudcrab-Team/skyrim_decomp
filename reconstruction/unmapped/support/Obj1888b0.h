// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard1888b0 constructor and destructor, Obj1888b0::Begin and End, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard and BSTArray::begin and BSTArray::end (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, include/RE/B/BSTArray.h:489, include/RE/B/BSTArray.h:493, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Alias1888b0, Instance1888b0, Lock1888b0, ReadGuard1888b0, Obj1888b0, HasAliasFlag6: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Alias1888b0
{
    std::uint64_t unk00[3];  // 00
    std::uint32_t unk18;     // 18
    std::uint32_t flags1C;   // 1C
};

struct Instance1888b0
{
    std::uint64_t unk00;  // 00
    Alias1888b0* alias;   // 08
};

struct Lock1888b0
{
    void LockForRead();
    void UnlockForRead();

    std::uint64_t state;  // 00
};

struct ReadGuard1888b0
{
    explicit ReadGuard1888b0(Lock1888b0& a_lock) : lock(&a_lock)
    {
        lock->LockForRead();
    }

    ~ReadGuard1888b0()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

    Lock1888b0* lock;  // 00
};

struct Obj1888b0
{
    Instance1888b0** Begin() const
    {
        return size ? data : 0;
    }

    Instance1888b0** End() const
    {
        return size ? data + size : 0;
    }

    bool HasAliasFlag6();  // compared: 0x1888b0

    std::uint64_t unk00;    // 00
    std::uint64_t unk08;    // 08
    Instance1888b0** data;  // 10
    std::uint32_t capacity; // 18
    std::uint32_t unk1C;    // 1C
    std::uint32_t size;     // 20
    std::uint32_t unk24;    // 24
    Lock1888b0 lock;        // 28
};
