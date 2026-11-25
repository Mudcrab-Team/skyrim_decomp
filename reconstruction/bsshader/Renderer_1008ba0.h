// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Renderer, RendererData, RendererWindow, RequestWindowResize, fullScreen, borderlessDisplay, readOnlyDepth, instantiated, requestedWindowSizeChange, newWidth, newHeight, presentInterval, forwarder, context, renderWindows, hWnd, windowX, windowY, windowWidth, windowHeight, data, unk00, unk08: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00: OBSERVED; unmodelled renderer configuration prefix.
// g_rendererResizeRestricted: GUESS(low); flag governing the first resize check.
#pragma once
#include <cstdint>

struct RendererWindow
{
    void* hWnd;
    std::int32_t windowX;
    std::int32_t windowY;
    std::int32_t windowWidth;
    std::int32_t windowHeight;
};
struct RendererData
{
    std::uint8_t unknown00[0x20];
    bool fullScreen;
    bool borderlessDisplay;
    bool readOnlyDepth;
    bool instantiated;
    bool requestedWindowSizeChange;
    std::uint32_t newWidth;
    std::uint32_t newHeight;
    std::uint32_t presentInterval;
    void* forwarder;
    void* context;
    RendererWindow renderWindows[1];
};
class Renderer
{
public:
    void RequestWindowResize(std::uint32_t width, std::uint32_t height);
    std::uint64_t unk00;
    std::uint64_t unk08;
    RendererData data;
};
extern bool g_rendererResizeRestricted;
