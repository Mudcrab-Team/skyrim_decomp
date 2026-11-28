// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Form258d10, NodeItem258d10, Node258d10, ListOwner258d10, Obj258d10, GetForm, FindRecursive, formID, children, item, next, head: GUESS(low)
#pragma once

#include <cstdint>

struct ListOwner258d10;

struct Form258d10
{
    std::uint8_t unk00[0x14];  // 00
    std::uint32_t formID;      // 14
};

struct NodeItem258d10
{
    virtual void V00();
    virtual void V01();
    virtual Form258d10* GetForm();  // 10

    std::uint8_t unk08[0x38];   // 08
    ListOwner258d10* children;  // 40
};

struct Node258d10
{
    NodeItem258d10* item;  // 00
    Node258d10* next;      // 08
};

struct ListOwner258d10
{
    std::uint64_t unk00;  // 00
    Node258d10 head;      // 08
};

class Obj258d10
{
public:
    static NodeItem258d10* FindRecursive(ListOwner258d10* owner, std::uint32_t formID);
};
