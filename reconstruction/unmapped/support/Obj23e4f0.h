// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj23e4f0::GetExtraAtIndex, treated as adapted: shaped like a grouped list index search in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:624
// SPDX-License-Identifier: CC0-1.0
// ExtraNode23e4f0, EntryData23e4f0, EntryNode23e4f0, Obj23e4f0, GetExtraAtIndex, item, next, object, extraLists, entryList: GUESS(low)
#pragma once

#include <cstdint>

struct ExtraNode23e4f0
{
    void* item;            // 00
    ExtraNode23e4f0* next; // 08
};

struct EntryData23e4f0
{
    void* object;                // 00
    ExtraNode23e4f0* extraLists; // 08
};

struct EntryNode23e4f0
{
    EntryData23e4f0* item; // 00
    EntryNode23e4f0* next; // 08
};

class Obj23e4f0
{
public:
    void* GetExtraAtIndex(void* object, std::int32_t index) const;

    EntryNode23e4f0* entryList;  // 00
};
