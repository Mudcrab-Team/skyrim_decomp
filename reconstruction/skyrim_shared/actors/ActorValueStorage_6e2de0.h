// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueStorage, GetBaseValue: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LocalMapFloat6e2de0, g_actorValueLock6e2de0, unk00, unk04, keys, values, baseValues, lock: GUESS(low)
// 0x6e2de0 ActorValueStorage::GetBaseValue
#pragma once

#include <cstddef>
#include <cstdint>

class BSReadWriteLock
{
public:
    void LockForRead();
    void UnlockForRead();

    std::uint32_t unk00;
    std::uint32_t unk04;
};

extern BSReadWriteLock g_actorValueLock6e2de0;

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& a_lock) : lock(a_lock) { lock.LockForRead(); }
    ~BSReadLockGuard() { lock.UnlockForRead(); }

private:
    BSReadWriteLock& lock;
};

struct LocalMapFloat6e2de0
{
    std::uint8_t* keys;
    float* values;
};

class ActorValueStorage
{
public:
    bool GetBaseValue(std::uint32_t a_actorValue, float& a_out);

    LocalMapFloat6e2de0 baseValues;
};

static_assert(offsetof(LocalMapFloat6e2de0, values) == 0x8, "values offset");
