// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj23e490::FindExtraIndex, treated as adapted: shaped like a grouped list index search in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:624
// SPDX-License-Identifier: CC0-1.0
// 0x23e490 Obj23e490::FindExtraIndex
#include "Obj23e490.h"

// Find the index of an extra data list under the matching item entry, or -1 if absent.
std::int32_t Obj23e490::FindExtraIndex(void* object, void* target) const
{
    if (!object || !target)
    {
        return -1;
    }
    EntryNode23e490* node = entryList;
    while (node)
    {
        EntryData23e490* entry = node->item;
        node = node->next;
        if (entry && entry->object == object)
        {
            std::int32_t index = 0;
            for (ExtraNode23e490* extra = entry->extraLists; extra; extra = extra->next)
            {
                if (extra->item && extra->item == target)
                {
                    return index;
                }
                ++index;
            }
            return -1;
        }
    }
    return -1;
}
