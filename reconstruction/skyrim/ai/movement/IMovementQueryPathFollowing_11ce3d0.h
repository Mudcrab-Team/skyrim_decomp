// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMovementQueryPathFollowing, MovementAgentPathFollowerStandard: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PathTarget11ce3d0, PathData11ce3d0, Function11ce3d0, unk00, unk04, unk80, unk84, unk8C, unk90, unkE8, unkF0, unkF4, unkF8, unk100, lock: GUESS(low)
// 0x11ce3d0 MovementAgentPathFollowerStandard::Function11ce3d0
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

struct PathTarget11ce3d0
{
    std::uint8_t unk00[0x90];
    float unk90;
};

struct PathData11ce3d0
{
    std::uint8_t unk00[0x80];
    std::uint32_t unk80;
    std::uint8_t unk84[0x8];
    std::uint32_t unk8C;
};

class IMovementQueryPathFollowing
{
};

class MovementAgentPathFollowerStandard : public IMovementQueryPathFollowing
{
public:
    bool Function11ce3d0();

    std::uint8_t unk00[0xE8];
    BSReadWriteLock unkE8;
    std::uint32_t unkF0;
    std::uint32_t unkF4;
    PathTarget11ce3d0* unkF8;
    PathData11ce3d0* unk100;
};

static_assert(offsetof(MovementAgentPathFollowerStandard, unkE8) == 0xE8, "unkE8 offset");
static_assert(offsetof(MovementAgentPathFollowerStandard, unkF0) == 0xF0, "unkF0 offset");
static_assert(offsetof(MovementAgentPathFollowerStandard, unkF8) == 0xF8, "unkF8 offset");
static_assert(offsetof(MovementAgentPathFollowerStandard, unk100) == 0x100, "unk100 offset");
static_assert(offsetof(PathTarget11ce3d0, unk90) == 0x90, "unk90 offset");
static_assert(offsetof(PathData11ce3d0, unk80) == 0x80, "unk80 offset");
static_assert(offsetof(PathData11ce3d0, unk8C) == 0x8C, "unk8C offset");
