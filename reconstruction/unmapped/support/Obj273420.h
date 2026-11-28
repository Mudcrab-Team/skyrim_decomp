// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj273420::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Obj273420, Obj273420::RemoveAll: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj273420
{
public:
    using DestroyFn = void (*)(Obj273420*, void*);

    ~Obj273420()
    {
        RemoveAll(nullptr, nullptr);
    }

    void RemoveAll(DestroyFn a_fn, void* a_context);

    void* item;       // 0x00
    Obj273420* next;  // 0x08
};

static_assert(sizeof(Obj273420) == 0x10, "Obj273420 size");
static_assert(offsetof(Obj273420, next) == 0x08, "next offset");
