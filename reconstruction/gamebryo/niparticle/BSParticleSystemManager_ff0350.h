// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: reconstruction from the pinned image listing; see Adapted bodies.
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSParticleSystemManager, BSParticleSystemManager::GetMasterParticleSystemAt, BSMasterParticleSystem, BSReadWriteLock, LockForRead, UnlockForRead: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadLockGuard, gParticleSystemManagerLock, childrenData, childrenSize, unknown00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSMasterParticleSystem;

class BSReadWriteLock
{
public:
    void LockForRead();
    void UnlockForRead();

    std::uint32_t writerThread;
    std::uint32_t lock;
};

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& a_lock) : lock(a_lock)
    {
        lock.LockForRead();
    }

    ~BSReadLockGuard()
    {
        lock.UnlockForRead();
    }

    BSReadWriteLock& lock;
};

extern BSReadWriteLock gParticleSystemManagerLock;

class BSParticleSystemManager
{
public:
    BSMasterParticleSystem* GetMasterParticleSystemAt(std::uint32_t a_index);  // compared: 0xff0350

    std::uint8_t unknown00[0x118];
    BSMasterParticleSystem** childrenData;  // 118
    std::uint16_t childrenSize;             // 120
};
static_assert(offsetof(BSParticleSystemManager, childrenData) == 0x118, "childrenData offset");
static_assert(offsetof(BSParticleSystemManager, childrenSize) == 0x120, "childrenSize offset");
