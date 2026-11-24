// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf and original reconstruction of Function51c570, kept unchanged;
// Function51ada0 is independently decoded from the pinned image listing, a fresh reconstruction
// from the observed instruction shapes, with no copied community body.
// Adapted bodies: none.
// BGSQueuedTerrainInitialLoad: EXE_RTTI
// SPDX-License-Identifier: CC0-1.0
// 0x51ada0 BGSQueuedTerrainInitialLoad::Function51ada0
// 0x51c750 BGSQueuedTerrainInitialLoad::Slot5
// 0x51c570 BGSQueuedTerrainInitialLoad::Function51c570
#include "BGSQueuedTerrainInitialLoad.h"
// Unknown5111E0: GUESS(low); callee at 0x5111e0, declared only, given the node's field 0x28.
void Unknown5111E0(void* a_value);
// Unknown514E00: GUESS(low); callee at 0x514e00, declared only, given the replaced node.
void Unknown514E00(void* a_replaced);
// Slot5: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t BGSQueuedTerrainInitialLoad::Slot5() const
{
    return 0x2;
}
// Function51ada0: GUESS(low); behaviour decoded from the listing of 0x51ada0.
void BGSQueuedTerrainInitialLoad::Function51ada0()
{
    Unknown5111E0(unknown18->unknown28);
    QueuedLoadNode* head = unknown08;
    QueuedLoadNode* pending = unknown18;
    QueuedLoadNode* previous = head->unknown08;
    if (pending != previous)
    {
        unknown18 = nullptr;
        head->unknown08 = pending;
        Unknown514E00(previous);
    }
    head = unknown08;
    head->flags &= ~0x1Au;
    head->flags |= 4u;
    for (QueuedLoadNode* node = unknown08->unknown38; node != nullptr; node = node->unknown38)
    {
        if (!TestBit(node->flags, 1))
        {
            break;
        }
        node->flags = (node->flags & ~0x16u) | 8u;
    }
}

void BGSQueuedTerrainInitialLoad::Function51c570()
{
    if (void* prev = target) {
        target = nullptr;
        ReleaseQueuedTerrain(prev);
    }
}
