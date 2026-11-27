// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x150b7c0 BSImagespaceShaderCopyCustomViewport::Function150b7c0
#include "BSImagespaceShaderCopyCustomViewport_150b7c0.h"

#include <cstring>

// alignas(16): the constant is a 16-byte aligned vector in the image
alignas(16) static const ViewportRect kDefaultViewport = { 0.0f, 1.0f, 1.0f, 0.0f };

void BSImagespaceShaderCopyCustomViewport::Function150b7c0()
{
    Function1564d90(0);
    ViewportRect rect;
    std::memcpy(&rect, &kDefaultViewport, sizeof(rect));
    viewport.x = 0.0f;
    viewport.y = 1.0f;
    viewport.z = 1.0f;
    viewport.w = 0.0f;
    g_viewportState.Function101cd00(&rect);
}
