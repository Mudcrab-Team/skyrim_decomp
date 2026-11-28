// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x258ea0 Obj258ea0::FindInvalidEntry
// Adapted bodies: none
#include "Obj258ea0.h"

// Recursively find the first region entry with a missing weight or density value.
NodeItem258ea0* Obj258ea0::FindInvalidEntry(ListOwner258ea0* owner, NodeItem258ea0* parent)
{
    for (Node258ea0* node = owner ? &owner->head : nullptr; node && node->item; node = node->next)
    {
        NodeItem258ea0* entry = node->item;
        if (entry->form && dynamic_cast<BoundObject258ea0*>(entry->form) != nullptr)
        {
            if (entry->unk1A == 0)
            {
                return entry;
            }
            if (parent && parent->form && dynamic_cast<BoundObject258ea0*>(parent->form) != nullptr && entry->unk18 == 0)
            {
                return entry;
            }
        }
        if (entry->children != nullptr)
        {
            NodeItem258ea0* found = FindInvalidEntry(entry->children, entry);
            if (found != nullptr)
            {
                return found;
            }
        }
    }
    return nullptr;
}
