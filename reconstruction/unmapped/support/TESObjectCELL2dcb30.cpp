// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESObjectCELL2dcb30::GetChildNode, treated as adapted: shaped like TESObjectCELL::GetChildNode in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:345
// SPDX-License-Identifier: CC0-1.0
// 0x2dcb30 TESObjectCELL2dcb30::GetChildNode
#include "TESObjectCELL2dcb30.h"

// Guess: query the inner array and return the element at the given index.
void* TESObjectCELL2dcb30::GetChildNode(std::uint32_t a_index) const
{
    const Inner2dcb30* inner = GetInner();
    if (inner && a_index < inner->m_count)
    {
        return inner->m_items[a_index];
    }
    return nullptr;
}
