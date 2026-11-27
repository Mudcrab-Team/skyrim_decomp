// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1804c0 ExtraAnimGraphManager::SetAnimGraphManager
// Adapted bodies: none
#include <intrin.h>

#include "ExtraAnimGraphManager_1804c0.h"

void ExtraAnimGraphManager::SetAnimGraphManager(BSAnimationGraphManager* const& a_in)
{
    BSAnimationGraphManager* manager = a_in;
    BSAnimationGraphManager* previous = animGraphMgr;
    if (manager != previous)
    {
        if (manager)
        {
            _InterlockedIncrement(&manager->refCount);  // atomic intrusive reference count, as the engine's smart pointers do
        }
        animGraphMgr = manager;
        if (previous && _InterlockedExchangeAdd(&previous->refCount, -1) == 1)  // atomic release of the old reference
        {
            delete previous;
        }
    }
}
