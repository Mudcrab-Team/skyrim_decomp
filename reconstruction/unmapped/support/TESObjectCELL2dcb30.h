// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESObjectCELL2dcb30::GetChildNode, treated as adapted: shaped like TESObjectCELL::GetChildNode in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:345
// SPDX-License-Identifier: CC0-1.0
// TESObjectCELL2dcb30, GetChildNode, TESObjectCELL2dcb30::GetChildNode: CRASHLOGGER_PDB(59818@2026.10.24)
// Inner2dcb30: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Inner2dcb30
{
    std::uint64_t unk00[35];  // 0x00
    void** m_items;           // 0x118
    std::uint32_t unk120;     // 0x120
    std::uint16_t m_count;    // 0x124
};
static_assert(offsetof(Inner2dcb30, m_items) == 0x118, "m_items offset");
static_assert(offsetof(Inner2dcb30, m_count) == 0x124, "m_count offset");

class TESObjectCELL2dcb30
{
public:
    Inner2dcb30* GetInner() const;
    void* GetChildNode(std::uint32_t a_index) const;
};
