// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfeee50 CullQueue::PushQueueEntry
// CI hash: 0xfeee50 ?PushQueueEntry@CullQueue@@QEAAXPEAUCullEntry@@@Z
#include "CullQueue_feee50.h"

#include <intrin.h>

void CullQueue::PushQueueEntry(CullEntry* entry)
{
    long write = writeClaim;
    for (;;) {
        if (((write + 1) & slotMask) == (readComplete & slotMask)) {
            Sleep(0);
            write = writeClaim;
        } else if (_InterlockedCompareExchange(&writeClaim, write + 1, write) == write) {  // Reserve this slot against concurrent producers.
            break;
        } else {
            write = writeClaim;
        }
    }
    slots[write & slotMask] = entry;
    // Publish consecutive populated slots after reserving the write position atomically.
    long complete = writeComplete;
    while (slots[complete & slotMask] && writeComplete != writeClaim) {
        if (_InterlockedCompareExchange(&writeComplete, complete + 1, complete) != complete)  // Publish the populated slot once.
            break;
        complete = writeComplete;
    }
}
