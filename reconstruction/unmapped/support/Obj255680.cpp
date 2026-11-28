// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj255680::FindByEditorID, treated as adapted: shaped like TESRegionList::Find in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist_h_unit.cpp:102
// SPDX-License-Identifier: CC0-1.0
// 0x255680 Obj255680::FindByEditorID
#include "Obj255680.h"

// Search the form list case-insensitively by editor ID string.
Form255680* Obj255680::FindByEditorID(ListOwner255680* owner, const char* editorID)
{
    Node255680* node = owner ? &owner->head : nullptr;
    if (editorID != nullptr)
    {
        while (node != nullptr)
        {
            if (node->item && _stricmp(node->item->GetEditorID(), editorID) == 0)
            {
                return node->item;
            }
            node = node->next;
        }
    }
    return nullptr;
}
