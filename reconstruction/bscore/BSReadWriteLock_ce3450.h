// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none declared; tools/check_origin.py reports none above its threshold (0.75)
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// BSReadWriteLock, BSReadWriteLock::_writerThread, ::_lock, ::UnlockForRead, ::UnlockForWrite: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadWriteLock::LockForRead, ::LockForWrite, ::TryLockForRead, ::TryLockForWrite: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb)
// BSReadWriteLock::kLockWrite, ::kLockCountMask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unit-local view of BSReadWriteLock: carries the members and declarations the functions of this unit need, so the shared BSReadWriteLock.h stays as it is.
#pragma once

#include <cstdint>

class BSReadWriteLock {
public:
    enum : std::uint32_t {
        kLockWrite = 0x80000000,
        kLockCountMask = 0xFFFFFFF
    };

    void LockForRead();
    void LockForWrite();
    bool TryLockForRead();
    bool TryLockForWrite();
    void UnlockForRead();
    void UnlockForWrite();

private:
    // Community declares both volatile. The owner word is plain here: it is only written under
    // the lock and compared against the current thread id, so no reload semantics are needed.
    std::uint32_t _writerThread;  // 00
    volatile std::uint32_t _lock; // 04
};
