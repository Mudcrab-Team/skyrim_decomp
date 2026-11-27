// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x1008ba0 Renderer::RequestWindowResize
#include "Renderer_1008ba0.h"

void Renderer::RequestWindowResize(std::uint32_t width, std::uint32_t height)
{
    if ((!g_rendererResizeRestricted &&
         (width != data.renderWindows[0].windowWidth || height != data.renderWindows[0].windowHeight)) ||
        (!data.fullScreen &&
         (width != data.renderWindows[0].windowWidth || height != data.renderWindows[0].windowHeight))) {
        data.requestedWindowSizeChange = true;
        data.newWidth = width;
        data.newHeight = height;
    }
}
