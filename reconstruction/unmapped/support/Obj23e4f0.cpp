// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj23e4f0::GetExtraAtIndex, treated as adapted: shaped like a grouped list index search in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:624
// SPDX-License-Identifier: CC0-1.0
// 0x23e4f0 Obj23e4f0::GetExtraAtIndex
#include "Obj23e4f0.h"

// Return the extra data list at the given index under the matching item entry, or null.
void* Obj23e4f0::GetExtraAtIndex(void* object, std::int32_t index) const
{
    if (!object || index == -1)
    {
        return nullptr;
    }
    EntryNode23e4f0* node = entryList;
    while (node)
    {
        EntryData23e4f0* entry = node->item;
        node = node->next;
        if (entry && entry->object == object)
        {
            std::int32_t current = 0;
            for (ExtraNode23e4f0* extra = entry->extraLists; extra; extra = extra->next)
            {
                void* item = extra->item;
                if (current == index)
                {
                    return item;
                }
                ++current;
            }
            return nullptr;
        }
    }
    return nullptr;
}
