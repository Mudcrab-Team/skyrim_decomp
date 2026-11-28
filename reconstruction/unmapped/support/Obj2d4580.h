// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d4580::GetFifthItem and Inner2d4580::GetAt, treated as adapted: shaped like TESObjectCELL::GetChildNode in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:345
// SPDX-License-Identifier: CC0-1.0
// Inner2d4580, Holder2d4580, Obj2d4580, Obj2d4580::GetFifthItem: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Inner2d4580
{
    void* GetAt(std::uint16_t a_index) const
    {
        if (a_index < m_count)
        {
            return m_items[a_index];
        }
        return nullptr;
    }

    std::uint64_t unk00[35];  // 0x00
    void** m_items;           // 0x118
    std::uint32_t unk120;     // 0x120
    std::uint16_t m_count;    // 0x124
};
static_assert(offsetof(Inner2d4580, m_items) == 0x118, "m_items offset");
static_assert(offsetof(Inner2d4580, m_count) == 0x124, "m_count offset");

struct Holder2d4580
{
    std::uint64_t unk00;   // 0x00
    Inner2d4580* m_inner;  // 0x08
};
static_assert(offsetof(Holder2d4580, m_inner) == 0x08, "m_inner offset");

class Obj2d4580
{
public:
    void* GetFifthItem() const;

    std::uint64_t unk00[38];  // 0x00
    Holder2d4580* m_holder;   // 0x130
};
static_assert(offsetof(Obj2d4580, m_holder) == 0x130, "m_holder offset");
