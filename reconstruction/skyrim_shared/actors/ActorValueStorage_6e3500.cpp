// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6e3500 ActorValueStorage::FindModifiers
#include "ActorValueStorage_6e3500.h"

// Look up the modifier triple for a_actorValue in the sorted local map under the read lock.
Modifiers6e3500* ActorValueStorage::FindModifiers(std::uint32_t a_actorValue)
{
    std::uint8_t key = static_cast<std::uint8_t>(a_actorValue) + 1;
    BSReadLockGuard guard(g_avStorageLock6e3500);
    std::uint8_t* cur = modifiers.keys;
    std::uint8_t val = *cur;
    while (val < key && val != 0) {
        val = *++cur;
    }
    Modifiers6e3500* result;
    if (val == key && modifiers.values) {
        result = &modifiers.values[cur - modifiers.keys];
    } else {
        result = nullptr;
    }
    return result;
}
