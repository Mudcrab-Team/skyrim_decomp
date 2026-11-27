// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderWaterFlow::Function1586860: GUESS(low); the name comes from the inventory
// BSImagespaceShaderWaterFlow, SlotOwner, Texture, Texture::Function1555260: STANDIN GUESS(low); names made up for the callee at 0x1555260 and the objects read from the listing
// g_flowA, g_flowB, g_flowC, g_flowD, g_flowE, g_flowF, g_flowG, g_flowH, g_flowI, kFlowDefault: GUESS(low); globals in the image, the values are not read from the listing
// unkD8, texture: GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

struct FlowPair
{
    float first;
    float second;
};

extern const FlowPair kFlowDefault;

class Texture
{
public:
    void Function1555260(int a_value);  // callee at 0x1555260, not compared
};

struct SlotOwner
{
    std::uint8_t unk00[8];
    Texture* texture;  // 08
};

class BSImagespaceShaderWaterFlow
{
public:
    void Function1586860();  // compared: 0x1586860

    std::uint8_t unk00[0xd8];
    SlotOwner* unkD8;  // D8
};
static_assert(offsetof(BSImagespaceShaderWaterFlow, unkD8) == 0xd8, "layout");
