// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1902c0::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Obj1902c0, RemoveAll, item, next: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Obj1902c0
{
    ~Obj1902c0()
    {
        RemoveAll(0, 0);
    }

    void RemoveAll(void (*a_delete)(Obj1902c0*, void*), void* a_data);  // compared: 0x1902c0

    void* item;       // 00
    Obj1902c0* next;  // 08
};
