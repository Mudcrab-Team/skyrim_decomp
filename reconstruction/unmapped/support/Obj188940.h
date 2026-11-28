// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard188940 constructor and destructor, Obj188940::Begin and End, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard and BSTArray::begin and BSTArray::end (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, include/RE/B/BSTArray.h:489, include/RE/B/BSTArray.h:493, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Alias188940, Instance188940, Lock188940, ReadGuard188940, Obj188940, HasAliasFlag10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Alias188940
{
    std::uint64_t unk00[3];  // 00
    std::uint32_t unk18;     // 18
    std::uint32_t flags1C;   // 1C
};

struct Instance188940
{
    std::uint64_t unk00;  // 00
    Alias188940* alias;   // 08
};

struct Lock188940
{
    void LockForRead();
    void UnlockForRead();

    std::uint64_t state;  // 00
};

struct ReadGuard188940
{
    explicit ReadGuard188940(Lock188940& a_lock) : lock(&a_lock)
    {
        lock->LockForRead();
    }

    ~ReadGuard188940()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

    Lock188940* lock;  // 00
};

struct Obj188940
{
    Instance188940** Begin() const
    {
        return size ? data : 0;
    }

    Instance188940** End() const
    {
        return size ? data + size : 0;
    }

    bool HasAliasFlag10();  // compared: 0x188940

    std::uint64_t unk00;    // 00
    std::uint64_t unk08;    // 08
    Instance188940** data;  // 10
    std::uint32_t capacity; // 18
    std::uint32_t unk1C;    // 1C
    std::uint32_t size;     // 20
    std::uint32_t unk24;    // 24
    Lock188940 lock;        // 28
};
