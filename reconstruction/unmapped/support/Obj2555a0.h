// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2555a0::FindByID, treated as adapted: shaped like TESRegionList::Find in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist_h_unit.cpp:102
// SPDX-License-Identifier: CC0-1.0
// Form2555a0, Node2555a0, ListOwner2555a0, Obj2555a0, FindByID, formID, item, next, head: GUESS(low)
#pragma once

#include <cstdint>

struct Form2555a0
{
    std::uint8_t unk00[0x14];  // 00
    std::uint32_t formID;      // 14
};

struct Node2555a0
{
    Form2555a0* item;  // 00
    Node2555a0* next;  // 08
};

struct ListOwner2555a0
{
    std::uint64_t unk00;  // 00
    Node2555a0 head;      // 08
};

class Obj2555a0
{
public:
    static Form2555a0* FindByID(ListOwner2555a0* owner, std::uint32_t formID);
};
