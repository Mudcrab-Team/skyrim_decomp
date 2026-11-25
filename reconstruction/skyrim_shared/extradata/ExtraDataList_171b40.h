// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// ExtraDataList, BaseExtraList, PresenceBitfield, bits, data, presence, _extraData, _lock, BSReadWriteLock, LockForRead, UnlockForRead, BSReadLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// table, lock, writerThread, state: GUESS(low); reduced storage declarations.
// GetTalkToPlayer: SYMBOLS(tesv-2013-map)
// Candidate identity confidence: low; inferred from the presence query for type 124.
// 0x171b40 ExtraDataList::GetTalkToPlayer
#pragma once
#include <cstdint>
#include <cstddef>
class BSReadWriteLock {
public:
    void LockForRead();
    void UnlockForRead();
    std::uint32_t writerThread;
    std::uint32_t state;
};
class BSReadLockGuard {
public:
    explicit BSReadLockGuard(BSReadWriteLock& value) : lock(&value) { lock->LockForRead(); }
    ~BSReadLockGuard() { if (lock) lock->UnlockForRead(); }
private:
    BSReadWriteLock* lock;
};
class BaseExtraList {
public:
    struct PresenceBitfield { std::uint8_t bits[24]; };
    void* table;
    void* data;
    PresenceBitfield* presence;
};
class ExtraDataList {
public:
    bool GetTalkToPlayer();
    BaseExtraList _extraData;
    BSReadWriteLock _lock;
};
static_assert(offsetof(BaseExtraList, presence) == 0x10, "presence offset");
static_assert(offsetof(ExtraDataList, _lock) == 0x18, "lock offset");
