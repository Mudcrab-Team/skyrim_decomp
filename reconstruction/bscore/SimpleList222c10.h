// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SimpleList222c10::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// SimpleList222c10, RemoveAll, item, next: GUESS(low)
#pragma once

class SimpleList222c10
{
public:
    ~SimpleList222c10()
    {
        RemoveAll(nullptr, nullptr);
    }

    void RemoveAll(void (*deleter)(SimpleList222c10*, void*), void* userData);

    void* item;              // 00
    SimpleList222c10* next;  // 08
};

static_assert(sizeof(SimpleList222c10) == 0x10, "SimpleList222c10 size");
