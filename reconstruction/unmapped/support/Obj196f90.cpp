// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard196f90 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x196f90 Obj196f90::GetQueuedCount
#include "Obj196f90.h"

// Returns the difference between head and tail counters at offsets 0x14 and 0x18 under a read lock.
std::uint32_t Obj196f90::GetQueuedCount()
{
    ReadGuard196f90 guard(lock);
    return unk14 - unk18;
}
