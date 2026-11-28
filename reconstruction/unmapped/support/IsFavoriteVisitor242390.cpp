// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x242390 IsFavoriteVisitor242390::Visit
// Adapted bodies: none
#include "IsFavoriteVisitor242390.h"

// Check whether the matching inventory entry has a favorited extra data list.
std::uint32_t IsFavoriteVisitor242390::Visit(Entry242390* entry)
{
    std::uint32_t result = 1;
    if (entry->object == targetForm)
    {
        for (ExtraListNode242390* node = entry->extraLists; node != nullptr; node = node->next)
        {
            if (!node->extraList || result != 1)
            {
                break;
            }
            if (node->extraList->HasHotkey())
            {
                isFavorite = true;
                result = 0;
            }
        }
    }
    return result;
}
