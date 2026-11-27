// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueStorage: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindModifiers, Modifiers6e3500, LocalMap6e3500, g_avStorageLock6e3500, unk00, unk04, keys, values, baseKeys, baseValues, modifiers, lock, f0, f1, f2: GUESS(low); stand-in read-only lookup name because PDB name ResetBaseValue does not match behavior
// 0x6e3500 ActorValueStorage::FindModifiers
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

extern BSReadWriteLock g_avStorageLock6e3500;

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& a_lock) : lock(a_lock) { lock.LockForRead(); }
    ~BSReadLockGuard() { lock.UnlockForRead(); }

private:
    BSReadWriteLock& lock;
};

struct Modifiers6e3500
{
    float f0;
    float f1;
    float f2;
};

struct LocalMap6e3500
{
    std::uint8_t* keys;
    Modifiers6e3500* values;
};

class ActorValueStorage
{
public:
    Modifiers6e3500* FindModifiers(std::uint32_t a_actorValue);

    std::uint8_t* baseKeys;
    float* baseValues;
    LocalMap6e3500 modifiers;
};

static_assert(sizeof(Modifiers6e3500) == 0xC, "Modifiers6e3500 size");
static_assert(offsetof(ActorValueStorage, modifiers) == 0x10, "modifiers offset");
