// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from pinned-image behavior
// SPDX-License-Identifier: CC0-1.0
// 0x100e410 Renderer::Function100e410
// Adapted bodies: none
#include "Renderer_100e410.h"

bool Renderer::Function100e410(ID3D11Resource** resource, D3D11_MAP mode,
                              D3D11_MAPPED_SUBRESOURCE* mapped)
{
    if (resource)
        return rendererContext->Map(*resource, 0, mode, 0, mapped) == 0;
    return false;
}
