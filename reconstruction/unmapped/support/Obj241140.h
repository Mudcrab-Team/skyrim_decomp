// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj241140::CountNonNull, treated as adapted: shaped like a linked list item count in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:39869
// SPDX-License-Identifier: CC0-1.0
// Node241140, Obj241140, CountNonNull, item, next: GUESS(low)
#pragma once

#include <cstdint>

struct Node241140
{
    void* item;        // 00
    Node241140* next;  // 08
};

class Obj241140
{
public:
    static std::uint32_t CountNonNull(const Node241140* head);
};
