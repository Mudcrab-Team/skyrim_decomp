// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Child1ff700, Node1ff700, Unit1ff700, GetRtti, unk08, flag, unk00, children, unk120, childCount, FindChild1ff700, g_rtti1ff700: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Child1ff700
{
    virtual ~Child1ff700();
    virtual void Slot01();
    virtual const void* GetRtti() const;

    std::uint8_t unk08[0x138];  // 008
    bool flag;                  // 140
};
static_assert(offsetof(Child1ff700, flag) == 0x140, "Child1ff700::flag offset");

struct Node1ff700
{
    std::uint8_t unk00[0x118];  // 000
    Child1ff700** children;     // 118
    std::uint16_t unk120;       // 120
    std::uint16_t childCount;   // 122
};
static_assert(offsetof(Node1ff700, children) == 0x118, "Node1ff700::children offset");
static_assert(offsetof(Node1ff700, childCount) == 0x122, "Node1ff700::childCount offset");

extern const char g_rtti1ff700;

struct Unit1ff700
{
    Child1ff700* FindChild1ff700(const Node1ff700* a_node, bool a_flag) const;  // compared: 0x1ff700
};
