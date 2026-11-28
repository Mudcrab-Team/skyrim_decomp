// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2555a0::FindByID, treated as adapted: shaped like TESRegionList::Find in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist_h_unit.cpp:102
// SPDX-License-Identifier: CC0-1.0
// 0x2555a0 Obj2555a0::FindByID
#include "Obj2555a0.h"

// Search the owner's form list for the entry matching the given form ID.
Form2555a0* Obj2555a0::FindByID(ListOwner2555a0* owner, std::uint32_t formID)
{
    Node2555a0* node = owner ? &owner->head : nullptr;
    while (node != nullptr)
    {
        if (node->item && node->item->formID == formID)
        {
            return node->item;
        }
        node = node->next;
    }
    return nullptr;
}
