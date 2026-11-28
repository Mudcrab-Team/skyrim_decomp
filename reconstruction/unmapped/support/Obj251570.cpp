// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj251570::CountNonNull, treated as adapted: shaped like a linked list item count in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:39869
// SPDX-License-Identifier: CC0-1.0
// 0x251570 Obj251570::CountNonNull
#include "Obj251570.h"

// Count linked-list nodes that hold a non-null item pointer.
std::uint32_t Obj251570::CountNonNull(const Node251570* head)
{
    std::uint32_t count = 0;
    for (const Node251570* node = head; node != nullptr; node = node->next)
    {
        if (node->item != nullptr)
        {
            ++count;
        }
    }
    return count;
}
