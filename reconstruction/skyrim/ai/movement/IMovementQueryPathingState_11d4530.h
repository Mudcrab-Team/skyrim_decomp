// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMovementQueryPathingState: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementPathingState11d4530, Func11_1410C1B10, unk00, unk04, unk08, unk28, unk2C, unk30, unk38, unk48, lock: GUESS(low); stand-in implementation class for IMovementQueryPathingState interface, keeping listed placeholder method name
// 0x11d4530 MovementPathingState11d4530::Func11_1410C1B10
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

class IMovementQueryPathingState
{
public:
    virtual bool Func11_1410C1B10() = 0;
};

class MovementPathingState11d4530 : public IMovementQueryPathingState
{
public:
    bool Func11_1410C1B10() override;

    std::uint8_t unk08[0x20];
    std::uint32_t unk28;
    std::uint32_t unk2C;
    void* unk30;
    std::uint8_t unk38[0x10];
    BSReadWriteLock unk48;
};

static_assert(offsetof(MovementPathingState11d4530, unk28) == 0x28, "unk28 offset");
static_assert(offsetof(MovementPathingState11d4530, unk30) == 0x30, "unk30 offset");
static_assert(offsetof(MovementPathingState11d4530, unk48) == 0x48, "unk48 offset");
