// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x258d10 Obj258d10::FindRecursive
// Adapted bodies: none
#include "Obj258d10.h"

// Recursively search a region hierarchy for the node matching a form ID.
NodeItem258d10* Obj258d10::FindRecursive(ListOwner258d10* owner, std::uint32_t formID)
{
    if (formID == 0)
    {
        return nullptr;
    }

    for (Node258d10* node = owner ? &owner->head : nullptr; node && node->item; node = node->next)
    {
        if (node->item->GetForm() && node->item->GetForm()->formID == formID)
        {
            return node->item;
        }
        ListOwner258d10* childList = node->item->children;
        NodeItem258d10* found = FindRecursive(childList, formID);
        if (found != nullptr)
        {
            return found;
        }
    }
    return nullptr;
}
