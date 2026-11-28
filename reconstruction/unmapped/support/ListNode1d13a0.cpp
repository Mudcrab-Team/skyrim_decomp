// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ListNode1d13a0::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x1d13a0 ListNode1d13a0::RemoveAll
#include "ListNode1d13a0.h"

// Frees every successor node using the optional callback or delete, then clears the head item.
void ListNode1d13a0::RemoveAll(void (*a_delete)(ListNode1d13a0*, void*), void* a_data)
{
    while (next) {
        ListNode1d13a0* following = next->next;
        next->next = nullptr;
        if (a_delete) {
            a_delete(next, a_data);
        } else {
            delete next;
        }
        next = following;
    }
    item = nullptr;
}
