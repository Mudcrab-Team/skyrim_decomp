// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x180460 ExtraAnimGraphManager::GetAnimGraphManager
// Adapted bodies: none
#include <intrin.h>

#include "ExtraAnimGraphManager_180460.h"

bool ExtraAnimGraphManager::GetAnimGraphManager(BSAnimationGraphManager*& a_out) const
{
    BSAnimationGraphManager* manager = animGraphMgr;
    BSAnimationGraphManager* previous = a_out;
    if (manager != previous)
    {
        if (manager)
        {
            _InterlockedIncrement(&manager->refCount);  // atomic intrusive reference count, as the engine's smart pointers do
        }
        a_out = manager;
        if (previous && _InterlockedExchangeAdd(&previous->refCount, -1) == 1)  // atomic release of the old reference
        {
            delete previous;
        }
    }
    return a_out != nullptr;
}
