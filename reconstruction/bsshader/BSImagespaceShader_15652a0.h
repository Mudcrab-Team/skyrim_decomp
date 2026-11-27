// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSImagespaceShader, BSImagespaceShader::ShutDown: CRASHLOGGER_PDB(59818@2026.10.24); class name only, the method name is a guess from the virtual slot
// ShaderPrimary, ShaderPrimary::Function1579050, ImageSpaceEffect, ShaderResource, Function1589eb0: STANDIN GUESS(low); names made up for the two callees and the two bases; the bases only place the second one at 0x90
// ImageSpaceEffect::ShutDown: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; slot 03 of the effect interface
// unk120: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's placeholder name for the member range here
// resource, hasResource: GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class ShaderResource
{
public:
    virtual ~ShaderResource();
};

void Function1589eb0(ShaderResource* a_resource);  // callee at 0x1589eb0, not compared

class ShaderPrimary
{
public:
    virtual ~ShaderPrimary();
    void Function1579050();  // callee at 0x1579050, not compared
    std::uint8_t unk08[0x88];
};
static_assert(sizeof(ShaderPrimary) == 0x90, "ShaderPrimary size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(void* a_shape, void* a_param);
    virtual void Setup(void* a_manager, void* a_param);
    virtual void ShutDown();  // 03
    std::uint8_t unk08[0x88];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class BSImagespaceShader : public ShaderPrimary, public ImageSpaceEffect
{
public:
    ~BSImagespaceShader() override;
    void ShutDown() override;  // compared: 0x15652a0

    std::uint8_t unk120[0x78];      // 120
    ShaderResource* resource;       // 198
    std::uint8_t unk1a0;            // 1A0
    bool hasResource;               // 1A1
};
static_assert(offsetof(BSImagespaceShader, resource) == 0x198, "resource offset");
static_assert(offsetof(BSImagespaceShader, hasResource) == 0x1a1, "flag offset");
