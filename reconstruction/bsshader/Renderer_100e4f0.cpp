// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original project-source reuse; Renderer_100e410.cpp and Renderer_100e480.cpp Map spelling (CC0-1.0)
// SPDX-License-Identifier: CC0-1.0
// 0x100e4f0 Renderer::Function100e4f0
// Adapted bodies: none
#include "Renderer_100e4f0.h"

bool Renderer::Function100e4f0(ID3D11Resource** resource, D3D11_MAP mode,
                              D3D11_MAPPED_SUBRESOURCE* mapped)
{
    if (resource) {
        return rendererContext->Map(*resource, 0, mode, 0, mapped) == 0;
    }
    return false;
}
