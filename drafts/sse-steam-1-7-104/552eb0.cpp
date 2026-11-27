// Near miss: 1.0 alignment distance | register-schedule
// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IAnimationGraphManagerHolder, GetAnimationGraphManagerImpl, NotifyAnimationGraph, BSAnimationGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// HasAnimationGraphManager: SIBLING(fo4-private@1b765c70, author-permission); name hint only.
// ManagerReference, DeleteThis, refCount: GUESS(low); query and ownership inferred from local target.
// 0x552eb0 IAnimationGraphManagerHolder::HasAnimationGraphManager

#include "include/552eb0/IAnimationGraphManagerHolder_552eb0.h"

// Guess: query the manager interface while releasing the temporary owned reference.
bool IAnimationGraphManagerHolder::HasAnimationGraphManager() const
{
    struct ManagerReference
    {
        BSAnimationGraphManager* value = nullptr;
        ~ManagerReference() noexcept(false)
        {
            BSAnimationGraphManager* manager = value;
            // Atomically release the temporary manager reference.
            if (manager && _InterlockedExchangeAdd(&manager->refCount, -1) == 1) {
                manager->DeleteThis();
            }
        }
    } manager;
    return GetAnimationGraphManagerImpl(manager.value);
}
