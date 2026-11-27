// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderCopyCustomViewport::Function150ba00: GUESS(low); the name comes from the inventory
// ShaderBase, ShaderBase::Function1564a80, ViewportRect, ViewportState, ViewportState::Function101cd00, g_viewportState: STANDIN GUESS(low); names made up for the two callees and the global
#pragma once

#include <cstdint>
#include <cstddef>

struct ViewportRect
{
    float values[4];
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
    void Function1564a80(std::uint32_t a_first, std::uint32_t a_second);  // callee at 0x1564a80, not compared
    std::uint8_t unk00[0x1a8];
};

class BSImagespaceShaderCopyCustomViewport : public ShaderBase
{
public:
    void Function150ba00();  // compared: 0x150ba00

    ViewportRect viewport;  // 1A8
};
static_assert(offsetof(BSImagespaceShaderCopyCustomViewport, viewport) == 0x1a8, "viewport offset");
