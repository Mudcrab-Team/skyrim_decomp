// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SimpleList254ff0::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// SimpleList254ff0, RemoveAll, item, next: GUESS(low)
#pragma once

class SimpleList254ff0
{
public:
    ~SimpleList254ff0()
    {
        RemoveAll(nullptr, nullptr);
    }

    void RemoveAll(void (*deleter)(SimpleList254ff0*, void*), void* userData);

    void* item;              // 00
    SimpleList254ff0* next;  // 08
};

static_assert(sizeof(SimpleList254ff0) == 0x10, "SimpleList254ff0 size");
