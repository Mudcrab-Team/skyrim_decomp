// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderCopyCustomViewport::Function150b7c0: GUESS(low); the name comes from the inventory
// ShaderBase, ShaderBase::Function1564d90, ViewportRect, ViewportState, ViewportState::Function101cd00, g_viewportState: STANDIN GUESS(low); names made up for the two callees and the global
// x, y, z, w, kDefaultViewport: GUESS(low); the values are not read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

struct ViewportRect
{
    float x;
    float y;
    float z;
    float w;
};

class ViewportState
{
public:
    void Function101cd00(const ViewportRect* a_rect);  // callee at 0x101cd00, not compared
};
extern ViewportState g_viewportState;

class ShaderBase
{
public:
    void Function1564d90(std::uint32_t a_value);  // callee at 0x1564d90, not compared
    std::uint8_t unk00[0x1a8];
};

class BSImagespaceShaderCopyCustomViewport : public ShaderBase
{
public:
    void Function150b7c0();  // compared: 0x150b7c0

    ViewportRect viewport;  // 1A8
};
static_assert(offsetof(BSImagespaceShaderCopyCustomViewport, viewport) == 0x1a8, "viewport offset");
