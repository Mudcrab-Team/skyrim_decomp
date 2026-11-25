// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original project-source reuse; Renderer_100e410.cpp Map spelling (CC0-1.0)
// SPDX-License-Identifier: CC0-1.0
// 0x100e480 Renderer::Function100e480
// Adapted bodies: none
#include "Renderer_100e480.h"

bool Renderer::Function100e480(ID3D11Resource** resource, D3D11_MAP mode,
                              D3D11_MAPPED_SUBRESOURCE* mapped)
{
    if (resource) {
        return rendererContext->Map(*resource, 0, mode, 0, mapped) == 0;
    }
    return false;
}
