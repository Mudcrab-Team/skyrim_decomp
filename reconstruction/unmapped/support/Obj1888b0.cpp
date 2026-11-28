// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ReadGuard1888b0 constructor and destructor, Obj1888b0::Begin and End, treated as adapted: shaped like BSReadLockGuard::BSReadLockGuard and BSReadLockGuard::~BSReadLockGuard and BSTArray::begin and BSTArray::end (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:114, src/RE/B/BSAtomic.cpp:120, include/RE/B/BSTArray.h:489, include/RE/B/BSTArray.h:493, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1888b0 Obj1888b0::HasAliasFlag6
#include "Obj1888b0.h"

// Checks under a read lock whether any alias instance has bit 6 set in flags1C.
bool Obj1888b0::HasAliasFlag6()
{
    ReadGuard1888b0 guard(lock);
    bool found = false;
    for (Instance1888b0** it = Begin(), **end = End(); it != end; ++it) {
        Instance1888b0* item = *it;
        if (item && item->alias) {
            found = ((item->alias->flags1C >> 6) & 1) != 0;
            if (found) {
                break;
            }
        }
    }
    return found;
}
