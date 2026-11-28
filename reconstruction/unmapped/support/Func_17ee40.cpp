// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard17ee40 constructor and destructor, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17ee40 Func_17ee40::CountNodes
#include "Func_17ee40.h"

// Acquires the embedded read lock and counts all nodes in the singly linked list.
std::uint32_t Func_17ee40::CountNodes()
{
    ReadGuard17ee40 guard(&lock);
    std::uint32_t count = 0;
    for (Node17ee40* cur = head; cur != nullptr; cur = cur->next)
    {
        ++count;
    }
    return count;
}
