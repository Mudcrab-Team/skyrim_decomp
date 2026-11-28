// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ListNode17f760::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// ListNode17f760, RemoveAll, item, next: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ListNode17f760
{
    ~ListNode17f760()
    {
        RemoveAll(0, 0);
    }

    void RemoveAll(void (*a_delete)(ListNode17f760*, void*), void* a_data);  // compared: 0x17f760

    std::uint32_t item;    // 00
    ListNode17f760* next;  // 08
};
