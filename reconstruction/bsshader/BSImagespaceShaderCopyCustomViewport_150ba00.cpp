// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x150ba00 BSImagespaceShaderCopyCustomViewport::Function150ba00
#include "BSImagespaceShaderCopyCustomViewport_150ba00.h"

#include <cstring>

void BSImagespaceShaderCopyCustomViewport::Function150ba00()
{
    Function1564a80(0, 0);
    ViewportRect rect;
    std::memcpy(&rect, &viewport, sizeof(rect));
    g_viewportState.Function101cd00(&rect);
}
