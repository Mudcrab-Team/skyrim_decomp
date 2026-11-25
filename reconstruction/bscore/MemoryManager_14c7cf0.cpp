// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x14c7cf0 operator delete
// CI hash: 0x14c7cf0 ??3@YAXPEAX@Z
// Adapted bodies: operator delete from fo4-private@1b765c70 src/BSCore/MemoryManager.h:8
#include "MemoryManager_14c7cf0.h"

inline MemoryManager& MemoryManager::Instance()
{
    static char cbuffer[sizeof(MemoryManager)];
    static unsigned int uiinitFence;
    if (uiinitFence != 2)
        UpdateInitState(cbuffer, &uiinitFence);
    return *reinterpret_cast<MemoryManager*>(cbuffer);
}

void operator delete(void* memory)
{
    MemoryManager::Instance().Deallocate(memory, false);
}
