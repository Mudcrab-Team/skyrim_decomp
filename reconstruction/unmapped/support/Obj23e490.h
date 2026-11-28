// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj23e490::FindExtraIndex, treated as adapted: shaped like a grouped list index search in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:624
// SPDX-License-Identifier: CC0-1.0
// ExtraNode23e490, EntryData23e490, EntryNode23e490, Obj23e490, FindExtraIndex, item, next, object, extraLists, entryList: GUESS(low)
#pragma once

#include <cstdint>

struct ExtraNode23e490
{
    void* item;            // 00
    ExtraNode23e490* next; // 08
};

struct EntryData23e490
{
    void* object;                // 00
    ExtraNode23e490* extraLists; // 08
};

struct EntryNode23e490
{
    EntryData23e490* item; // 00
    EntryNode23e490* next; // 08
};

class Obj23e490
{
public:
    std::int32_t FindExtraIndex(void* object, void* target) const;

    EntryNode23e490* entryList;  // 00
};
