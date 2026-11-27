// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfee400 BSCullingProcess::FlushAlphaGroupQueue
#include "BSCullingProcess_fee400.h"

void BSCullingProcess::FlushAlphaGroupQueue()
{
    while (alphaGroupIndex >= static_cast<int>(alphaGroups.count._size)) {
        AlphaGroupQueue* queue = new AlphaGroupQueue();
        alphaGroups.Append(queue);
    }

    CullQueueEntry* entry;
    do {
        entry = cullQueue.active.PopFreeQueueEntry();
        if (entry) {
            const int groupIndex = entry->groupIndex;
            if (groupIndex > -1) {
                AlphaGroupQueue* queue = alphaGroups[static_cast<std::uint32_t>(groupIndex)];
                queue->Push(entry->object);
                cullQueue.freeList.PushQueueEntry(entry);
            } else {
                AppendNonAccum(entry->object, entry->flags);
                cullQueue.freeList.PushQueueEntry(entry);
            }
        }
    } while (entry != nullptr);
}
