// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BaseForm258ea0, BoundObject258ea0, NodeItem258ea0, Node258ea0, ListOwner258ea0, Obj258ea0, FindInvalidEntry, form, unk18, unk1A, children, item, next, head: GUESS(low)
#pragma once

#include <cstdint>

struct ListOwner258ea0;

struct BaseForm258ea0
{
    virtual ~BaseForm258ea0();
};

struct BoundObject258ea0 : BaseForm258ea0
{
};

struct NodeItem258ea0
{
    std::uint64_t unk00;        // 00
    BaseForm258ea0* form;       // 08
    std::uint8_t unk10[8];      // 10
    std::uint16_t unk18;        // 18
    std::uint16_t unk1A;        // 1A
    std::uint8_t unk1C[0x24];   // 1C
    ListOwner258ea0* children;  // 40
};

struct Node258ea0
{
    NodeItem258ea0* item;  // 00
    Node258ea0* next;      // 08
};

struct ListOwner258ea0
{
    std::uint64_t unk00;  // 00
    Node258ea0 head;      // 08
};

class Obj258ea0
{
public:
    static NodeItem258ea0* FindInvalidEntry(ListOwner258ea0* owner, NodeItem258ea0* parent);
};
