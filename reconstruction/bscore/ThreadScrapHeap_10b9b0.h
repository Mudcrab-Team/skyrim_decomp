// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ThreadScrapHeap: GUESS(low)
// Instance, UpdateInitState: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

class ThreadScrapHeap
{
public:
    static ThreadScrapHeap& Instance();  // compared: 0x10b9b0
    static void UpdateInitState(void* storage, unsigned int* fence);
    unsigned char storage[1160];
};
