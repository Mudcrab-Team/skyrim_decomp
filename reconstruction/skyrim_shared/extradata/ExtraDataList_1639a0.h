// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList, _extraData, _lock, BaseExtraList, PresenceBitfield, bits, data, presence: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadWriteLock, LockForRead, UnlockForRead, _writerThread: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasAlias: SYMBOLS(tesv-2013-map); candidate name for the FromAlias presence query
// table, lock: GUESS(low); minimal layout and scoped lock handle
// 0x1639a0 ExtraDataList::HasAlias
#pragma once
#include <cstdint>
#include <cstddef>

class BSReadWriteLock
{
public:
    void LockForRead();
    void UnlockForRead();
    std::uint32_t _writerThread;
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
    bool HasAlias();
    BaseExtraList _extraData;
    BSReadWriteLock _lock;
};
static_assert(offsetof(BaseExtraList, presence) == 16, "presence offset");
static_assert(offsetof(ExtraDataList, _lock) == 24, "lock offset");
