// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SimpleList241f70::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x241f70 SimpleList241f70::RemoveAll
#include "SimpleList241f70.h"

// Destroy all tail nodes and clear the head item.
void SimpleList241f70::RemoveAll(void (*deleter)(SimpleList241f70*, void*), void* userData)
{
    while (next)
    {
        SimpleList241f70* nextNode = next->next;
        next->next = nullptr;
        if (deleter)
        {
            deleter(next, userData);
        }
        else
        {
            delete next;
        }
        next = nextNode;
    }
    item = nullptr;
}
