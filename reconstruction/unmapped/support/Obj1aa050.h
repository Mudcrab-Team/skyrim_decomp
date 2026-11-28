// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Geom1aa050, Node1aa050, Obj1aa050, CountTriangles: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Geom1aa050
{
    std::uint8_t unk00[0xF4];   // 000
    std::uint8_t flagsF4;       // 0F4
    std::uint8_t unkF5[0x65];   // 0F5
    std::uint16_t triCount15A;  // 15A
};

struct Node1aa050
{
    virtual ~Node1aa050();
    virtual void Slot1();
    virtual void Slot2();
    virtual Node1aa050* AsNode();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual Geom1aa050* AsGeometry();

    std::uint8_t unk08[0x110];  // 008
    Node1aa050** children118;   // 118
    std::uint16_t unk120;       // 120
    std::uint16_t count122;     // 122
};

struct Obj1aa050
{
    static std::uint32_t CountTriangles(Node1aa050* a_node, bool a_includeHidden);  // compared: 0x1aa050
};
