// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x405e60 TrapEntry::Func2_1403A6560
#include "TrapEntry_405e60.h"

// Notify each linked trap node in order, saving the next link before each virtual call.
void TrapEntry::Func2_1403A6560(void* a_arg)
{
    TrapNode405e60* node = head;
    while (node) {
        TrapNode405e60* next = node->next;
        node->OnNotify(this, a_arg);
        node = next;
    }
}
