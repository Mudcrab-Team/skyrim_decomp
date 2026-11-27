// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; handwritten from pinned-image observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RenderTargetManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RenderTargetManager::SetDepthStencilRenderTarget: CRASHLOGGER_PDB(59818@2026.10.24)
// depthTarget, depthMode, depthSlice, renderDirtyFlags: GUESS(low); descriptive global state names
#pragma once
#include <cstdint>

extern std::uint32_t depthTarget;
extern std::uint32_t depthMode;
extern std::uint32_t depthSlice;
extern std::uint32_t renderDirtyFlags;

class RenderTargetManager
{
public:
    void SetDepthStencilRenderTarget(std::uint32_t target, std::uint32_t mode, std::uint32_t slice);
};
