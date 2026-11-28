// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard197050 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x197050 Obj197050::GetQueuedCount
#include "Obj197050.h"

// Returns the difference between head and tail counters at offsets 0x74 and 0x78 under a read lock.
std::uint32_t Obj197050::GetQueuedCount()
{
    ReadGuard197050 guard(lock);
    return unk74 - unk78;
}
