// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original minimal opaque ABI declarations from observed slot 14; original; handwritten from pinned-image behavior
// ID3D11DeviceContext, ID3D11Resource, D3D11_MAP, D3D11_MAPPED_SUBRESOURCE, Map: GUESS(low) STANDIN; opaque ABI declarations
// SPDX-License-Identifier: CC0-1.0
// Renderer, Function100e410, rendererContext: GUESS(low) STANDIN; observed context call
#pragma once

enum D3D11_MAP : int;
struct ID3D11Resource;
struct D3D11_MAPPED_SUBRESOURCE;

// Opaque interface prefix; the observed call selects virtual slot 14.
struct ID3D11DeviceContext
{
    virtual void UnknownSlot0() = 0;
    virtual void UnknownSlot1() = 0;
    virtual void UnknownSlot2() = 0;
    virtual void UnknownSlot3() = 0;
    virtual void UnknownSlot4() = 0;
    virtual void UnknownSlot5() = 0;
    virtual void UnknownSlot6() = 0;
    virtual void UnknownSlot7() = 0;
    virtual void UnknownSlot8() = 0;
    virtual void UnknownSlot9() = 0;
    virtual void UnknownSlot10() = 0;
    virtual void UnknownSlot11() = 0;
    virtual void UnknownSlot12() = 0;
    virtual void UnknownSlot13() = 0;
    virtual long Map(ID3D11Resource* resource, unsigned subresource, D3D11_MAP mode,
                     unsigned flags, D3D11_MAPPED_SUBRESOURCE* mapped) = 0;
};

extern ID3D11DeviceContext* rendererContext;

class Renderer
{
public:
    bool Function100e410(ID3D11Resource** resource, D3D11_MAP mode,
                        D3D11_MAPPED_SUBRESOURCE* mapped);
};
