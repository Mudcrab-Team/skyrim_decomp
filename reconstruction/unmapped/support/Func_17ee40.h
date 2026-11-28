// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard17ee40 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Lock17ee40: GUESS(low)
// ReadGuard17ee40: GUESS(low)
// Node17ee40: GUESS(low)
// Func_17ee40: GUESS(low)
#pragma once

#include <cstdint>

// guess: a read-write lock; the CrashLogger PDB names the entry call MutexRW::EnterReadLock.
struct Lock17ee40
{
    void LockForRead();
    void UnlockForRead();
    std::uint64_t unk00;
};

struct ReadGuard17ee40
{
    explicit ReadGuard17ee40(Lock17ee40* target)
        : lock(target)
    {
        lock->LockForRead();
    }

    ~ReadGuard17ee40()
    {
        if (lock != nullptr)
        {
            lock->UnlockForRead();
        }
    }

    Lock17ee40* lock;
};

struct Node17ee40
{
    std::uint64_t unk00;
    Node17ee40* next;
};

struct Func_17ee40
{
    std::uint32_t CountNodes();

    std::uint64_t unk00;
    Node17ee40* head;
    std::uint64_t unk10;
    Lock17ee40 lock;
};
