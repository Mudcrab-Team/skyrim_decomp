// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj241140::CountNonNull, treated as adapted: shaped like a linked list item count in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:39869
// SPDX-License-Identifier: CC0-1.0
// 0x241140 Obj241140::CountNonNull
#include "Obj241140.h"

// Count linked-list nodes that hold a non-null item pointer.
std::uint32_t Obj241140::CountNonNull(const Node241140* head)
{
    std::uint32_t count = 0;
    for (const Node241140* node = head; node != nullptr; node = node->next)
    {
        if (node->item != nullptr)
        {
            ++count;
        }
    }
    return count;
}
