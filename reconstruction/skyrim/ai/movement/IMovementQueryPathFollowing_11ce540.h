// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMovementQueryPathFollowing, MovementAgentPathFollowerStandard: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function11ce540, unk00, unk04, unkE8, unkF0, lock: GUESS(low)
// 0x11ce540 MovementAgentPathFollowerStandard::Function11ce540
// Adapted bodies: none
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

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& a_lock) : lock(&a_lock) { lock->LockForRead(); }
    ~BSReadLockGuard()
    {
        if (lock) {
            lock->UnlockForRead();
        }
    }

private:
    BSReadWriteLock* lock;
};

class IMovementQueryPathFollowing
{
};

class MovementAgentPathFollowerStandard : public IMovementQueryPathFollowing
{
public:
    bool Function11ce540();

    std::uint8_t unk00[0xE8];
    BSReadWriteLock unkE8;
    std::uint32_t unkF0;
};

static_assert(offsetof(MovementAgentPathFollowerStandard, unkE8) == 0xE8, "unkE8 offset");
static_assert(offsetof(MovementAgentPathFollowerStandard, unkF0) == 0xF0, "unkF0 offset");
