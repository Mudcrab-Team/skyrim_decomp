// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x525040 BGSWaterCollisionManager::BGSWaterUpdateI::Unlink
#include "BGSWaterUpdateI_525040.h"

// Remove this water-update node from the global singly linked list.
void BGSWaterCollisionManager::BGSWaterUpdateI::Unlink()
{
    BGSWaterCollisionManager::BGSWaterUpdateI* cur = gWaterUpdateList;
    BGSWaterCollisionManager::BGSWaterUpdateI* prev = nullptr;
    while (cur) {
        if (cur == this) {
            if (prev) {
                prev->next = next;
            } else {
                gWaterUpdateList = next;
            }
            next = nullptr;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
