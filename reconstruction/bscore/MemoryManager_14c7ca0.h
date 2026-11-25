// Source exposure: mixed (sibling game-code names; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryManager.h:8
// MemoryManager, Instance, Deallocate, operator delete: SIBLING(fo4-private@1b765c70, author-permission)
// UpdateInitState, storage: GUESS(low)
#pragma once

class MemoryManager
{
public:
    static MemoryManager& Instance();
    static void UpdateInitState(void* storage, unsigned int* fence);
    void Deallocate(void* memory, bool aligned);

    unsigned char storage[1160];
};

void operator delete(void* memory);  // compared: 0x14c7ca0
