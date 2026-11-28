// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x525240 BGSWaterCollisionManager::BGSWaterUpdateI::Link
#include "BGSWaterUpdateI_525240.h"

// Prepend this water-update node to the global list if it is not already linked.
void BGSWaterCollisionManager::BGSWaterUpdateI::Link()
{
    bool found = false;
    BGSWaterCollisionManager::BGSWaterUpdateI* head = gWaterUpdateList;
    BGSWaterCollisionManager::BGSWaterUpdateI* cur = head;
    while (cur && !found) {
        if (cur == this) {
            found = true;
        } else {
            cur = cur->next;
        }
    }
    if (!found) {
        next = head;
        gWaterUpdateList = this;
    }
}
