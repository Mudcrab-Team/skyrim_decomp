// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_17b8e0::Clear and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// Func_17b8e0: GUESS(low)
#pragma once

#include <cstdint>

template <class T>
struct Func_17b8e0
{
    ~Func_17b8e0();
    void Clear(void (*deleter)(Func_17b8e0*, void*), void* userData);

    T item;
    Func_17b8e0* next;
};

template <class T>
inline void Func_17b8e0<T>::Clear(void (*deleter)(Func_17b8e0*, void*), void* userData)
{
    while (next != nullptr)
    {
        Func_17b8e0* following = next->next;
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
    item = T();
}

template <class T>
inline Func_17b8e0<T>::~Func_17b8e0()
{
    Clear(nullptr, nullptr);
}
