// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj317d70::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Obj317d70, Obj317d70::RemoveAll: GUESS(low)
#pragma once

class Obj317d70
{
public:
    using FreeFn = void (*)(Obj317d70*, void*);

    ~Obj317d70()
    {
        RemoveAll(nullptr, nullptr);
    }

    void RemoveAll(FreeFn a_freeFn, void* a_context);

    void* m_item;       // 0x00
    Obj317d70* m_next;  // 0x08
};
static_assert(sizeof(Obj317d70) == 0x10, "Obj317d70 size");
