// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_17f3f0::Clear and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Func_17f3f0: GUESS(low)
#pragma once

struct Func_17f3f0
{
    ~Func_17f3f0()
    {
        Clear(nullptr, nullptr);
    }

    void Clear(void (*deleter)(Func_17f3f0*, void*), void* userData);

    void* item;
    Func_17f3f0* next;
};

static_assert(sizeof(Func_17f3f0) == 0x10, "Func_17f3f0 size");
