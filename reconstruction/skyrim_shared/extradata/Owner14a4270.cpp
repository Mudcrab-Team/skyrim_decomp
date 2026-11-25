// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1804c0 (skyrim_shared/extradata/ExtraAnimGraphManager_1804c0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x14a4270 Owner14a4270::Function14a4270
#include "Owner14a4270.h"
#include <intrin.h>

// guess: same compiled code as matched 0x1804c0 apart from relocated fields; its role here is not established.
void Owner14a4270::Function14a4270(BSAnimationGraphManager* const& a_in)
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
