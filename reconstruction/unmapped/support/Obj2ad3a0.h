// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ShaderProp2ad3a0, Child2ad3a0, QuadNode2ad3a0, LandData2ad3a0, Obj2ad3a0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ShaderProp2ad3a0
{
    std::uint8_t unk00[0x108];  // 0x000
    float value108;             // 0x108
};

struct Child2ad3a0
{
    std::uint8_t unk00[0x128];  // 0x000
    ShaderProp2ad3a0* prop128;  // 0x128
};

struct QuadNode2ad3a0
{
    std::uint8_t unk00[0x118];  // 0x000
    Child2ad3a0** children;     // 0x118
    std::uint16_t unk120;       // 0x120
    std::uint16_t childCount;   // 0x122
};

struct LandData2ad3a0
{
    QuadNode2ad3a0* quads[4];  // 0x00
};

class Obj2ad3a0
{
public:
    void Function2ad3a0(float a_value);

    std::uint8_t unk00[0x40];  // 0x00
    LandData2ad3a0* data40;    // 0x40
};

static_assert(offsetof(ShaderProp2ad3a0, value108) == 0x108, "value108 offset");
static_assert(offsetof(Child2ad3a0, prop128) == 0x128, "prop128 offset");
static_assert(offsetof(QuadNode2ad3a0, children) == 0x118, "children offset");
static_assert(offsetof(QuadNode2ad3a0, childCount) == 0x122, "childCount offset");
static_assert(offsetof(Obj2ad3a0, data40) == 0x40, "data40 offset");
