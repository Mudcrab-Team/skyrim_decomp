// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2b74e0::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x2b74e0 Obj2b74e0::RemoveAll
#include "Obj2b74e0.h"

// Unlinks and destroys tail nodes in a singly linked list, then clears this node's item.
void Obj2b74e0::RemoveAll(DestroyFn a_fn, void* a_context)
{
    while (next) {
        Obj2b74e0* after = next->next;
        next->next = nullptr;
        if (a_fn) {
            a_fn(next, a_context);
        } else {
            delete next;
        }
        next = after;
    }
    item = nullptr;
}
