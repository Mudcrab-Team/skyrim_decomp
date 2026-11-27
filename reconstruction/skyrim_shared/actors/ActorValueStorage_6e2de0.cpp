// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6e2de0 ActorValueStorage::GetBaseValue
#include "ActorValueStorage_6e2de0.h"

// Look up the stored base float value for a_actorValue, writing 0.0f if absent.
bool ActorValueStorage::GetBaseValue(std::uint32_t a_actorValue, float& a_out)
{
    std::uint8_t key = static_cast<std::uint8_t>(a_actorValue) + 1;
    BSReadLockGuard guard(g_actorValueLock6e2de0);
    std::uint8_t* cur = baseValues.keys;
    std::uint8_t val = *cur;
    while (val < key && val != 0) {
        val = *++cur;
    }
    bool found;
    float value;
    if (baseValues.values && val == key) {
        found = true;
        value = baseValues.values[cur - baseValues.keys];
    } else {
        found = false;
        value = 0.0f;
    }
    a_out = value;
    return found;
}
