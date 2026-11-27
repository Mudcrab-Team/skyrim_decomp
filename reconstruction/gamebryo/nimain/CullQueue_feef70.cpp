// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfeef70 CullQueue::PopFreeQueueEntry
// CI hash: 0xfeef70 ?PopFreeQueueEntry@CullQueue@@QEAAPEAUCullEntry@@XZ
#include "CullQueue_feef70.h"

#include <intrin.h>

CullEntry* CullQueue::PopFreeQueueEntry()
{
    long read = readClaim;
    while (read != writeComplete) {
        if (_InterlockedCompareExchange(&readClaim, read + 1, read) == read) {  // Reserve this slot against concurrent consumers.
            CullEntry* entry = slots[read & slotMask];
            slots[read & slotMask] = nullptr;
            // Publish consecutive cleared slots after reserving the read position atomically.
            long complete = readComplete;
            while (!slots[readComplete & slotMask] && readComplete != readClaim) {
                if (_InterlockedCompareExchange(&readComplete, complete + 1, complete) != complete)  // Publish the cleared slot once.
                    break;
                complete = readComplete;
            }
            return entry;
        }
        read = readClaim;
    }
    return nullptr;
}
