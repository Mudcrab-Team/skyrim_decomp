// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj260200::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Obj260200, Obj260200::RemoveAll: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj260200
{
public:
    using DestroyFn = void (*)(Obj260200*, void*);

    ~Obj260200()
    {
        RemoveAll(nullptr, nullptr);
    }

    void RemoveAll(DestroyFn a_fn, void* a_context);

    void* item;       // 0x00
    Obj260200* next;  // 0x08
};

static_assert(sizeof(Obj260200) == 0x10, "Obj260200 size");
static_assert(offsetof(Obj260200, next) == 0x08, "next offset");
