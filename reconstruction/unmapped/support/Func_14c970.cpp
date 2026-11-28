// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_14c970::Clear and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x14c970 Func_14c970::Clear
#include "Func_14c970.h"

// Removes all chained tail nodes using deleter when supplied, or delete otherwise, and clears item.
void Func_14c970::Clear(void (*deleter)(Func_14c970*, void*), void* userData)
{
    while (next != nullptr)
    {
        Func_14c970* following = next->next;
        next->next = nullptr;
        if (deleter != nullptr)
        {
            deleter(next, userData);
        }
        else
        {
            delete next;
        }
        next = following;
    }
    item = nullptr;
}
