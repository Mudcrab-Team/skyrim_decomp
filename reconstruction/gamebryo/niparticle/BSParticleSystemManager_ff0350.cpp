// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: BSReadLockGuard::BSReadLockGuard, BSReadLockGuard::~BSReadLockGuard, treated as adapted (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:116 and src/RE/B/BSAtomic.cpp:121, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xff0350 BSParticleSystemManager::GetMasterParticleSystemAt
#include "BSParticleSystemManager_ff0350.h"

BSMasterParticleSystem* BSParticleSystemManager::GetMasterParticleSystemAt(std::uint32_t a_index)
{
    BSReadLockGuard guard(gParticleSystemManagerLock);
    BSMasterParticleSystem* result = nullptr;
    if (a_index < childrenSize) {
        result = childrenData[a_index];
    }
    return result;
}
