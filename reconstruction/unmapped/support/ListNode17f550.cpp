// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ListNode17f550::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x17f550 ListNode17f550::RemoveAll
#include "ListNode17f550.h"

// Removes and destroys all trailing nodes in the linked list and clears the head item.
void ListNode17f550::RemoveAll(void (*a_delete)(ListNode17f550*, void*), void* a_data)
{
    while (next) {
        ListNode17f550* curNext = next->next;
        next->next = 0;
        if (a_delete) {
            a_delete(next, a_data);
        } else {
            delete next;
        }
        next = curNext;
    }
    item = 0;
}
