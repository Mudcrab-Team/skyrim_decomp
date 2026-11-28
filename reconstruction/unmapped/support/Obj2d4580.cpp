// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d4580::GetFifthItem and Inner2d4580::GetAt, treated as adapted: shaped like TESObjectCELL::GetChildNode in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:345
// SPDX-License-Identifier: CC0-1.0
// 0x2d4580 Obj2d4580::GetFifthItem
#include "Obj2d4580.h"

// Guess: return the element at index 4 when the nested container holds enough entries.
void* Obj2d4580::GetFifthItem() const
{
    if (m_holder && m_holder->m_inner)
    {
        return m_holder->m_inner->GetAt(4);
    }
    return nullptr;
}
