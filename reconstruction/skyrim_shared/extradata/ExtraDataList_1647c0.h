// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction; reduced CommonLibSSE-NG declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList, BaseExtraList, PresenceBitfield, bits, data, presence, _extraData, _lock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCanNotWear: SYMBOLS(tesv-2013-map); candidate identity inferred from the queried extra-data type.
// table, lock, writerThread: GUESS(low); minimal layout and scoped read-lock handle.
// 0x1647c0 ExtraDataList::GetCanNotWear
#pragma once
#include <cstddef>
#include <cstdint>

class BSReadWriteLock
{
public:
    void LockForRead();
    void UnlockForRead();
    std::uint32_t writerThread;
    std::uint32_t _lock;
};

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& value) : lock(&value) { lock->LockForRead(); }
    ~BSReadLockGuard() { if (lock) lock->UnlockForRead(); }
private:
    BSReadWriteLock* lock;
};

class BaseExtraList
{
public:
    struct PresenceBitfield { std::uint8_t bits[24]; };
    void* table;
    void* data;
    PresenceBitfield* presence;
};

class ExtraDataList
{
public:
    bool GetCanNotWear();
    BaseExtraList _extraData;
    BSReadWriteLock _lock;
};
static_assert(offsetof(BaseExtraList, presence) == 0x10, "presence offset");
static_assert(offsetof(ExtraDataList, _lock) == 0x18, "lock offset");
