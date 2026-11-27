// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMovementQueryPathFollowing: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementPathFollowing1228580, Func4_141113220, unk00, unk04, unk08, unk10, unk14, unk78, lock: GUESS(low); stand-in implementation class for IMovementQueryPathFollowing interface, keeping listed placeholder method name
// 0x1228580 MovementPathFollowing1228580::Func4_141113220
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
public:
    virtual bool Func4_141113220() = 0;
};

class MovementPathFollowing1228580 : public IMovementQueryPathFollowing
{
public:
    bool Func4_141113220() override;

    std::uint8_t unk08[0x08];
    std::uint32_t unk10;
    std::uint8_t unk14[0x64];
    BSReadWriteLock unk78;
};

static_assert(offsetof(MovementPathFollowing1228580, unk10) == 0x10, "unk10 offset");
static_assert(offsetof(MovementPathFollowing1228580, unk78) == 0x78, "unk78 offset");
