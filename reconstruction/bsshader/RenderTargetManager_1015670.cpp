// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; handwritten from pinned-image observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1015670 RenderTargetManager::SetDepthStencilRenderTarget
// Adapted bodies: none
#include "RenderTargetManager_1015670.h"

void RenderTargetManager::SetDepthStencilRenderTarget(std::uint32_t target, std::uint32_t mode, std::uint32_t slice)
{
    if (depthTarget != target || depthMode != mode || mode != 3 || depthSlice != slice) {
        renderDirtyFlags |= 1;
        depthTarget = target;
        depthSlice = slice;
        depthMode = mode;
    }
}
