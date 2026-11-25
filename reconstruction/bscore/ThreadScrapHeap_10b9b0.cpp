// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x10b9b0 ThreadScrapHeap::Instance
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryManager.h:5
#include "ThreadScrapHeap_10b9b0.h"

ThreadScrapHeap& ThreadScrapHeap::Instance()
{
    static char cbuffer[sizeof(ThreadScrapHeap)];
    static unsigned int uiinitFence;
    if (uiinitFence != 2)
        UpdateInitState(cbuffer, &uiinitFence);
    return *reinterpret_cast<ThreadScrapHeap*>(cbuffer);
}
