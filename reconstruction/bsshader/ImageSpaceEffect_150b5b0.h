// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceEffect, ImageSpaceEffect::Render, ::effects, ::effectParams, ::effectTextures, ::effectInputs, ImageSpaceEffectParam, BSTriShape, BSShader, BSImagespaceShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceShaderParam, ::unk08, ::SLIMode, ::unk10, ::unk18, ::unk20, ::unk24, ::unk28, ::unk2C, ::vertexConstantGroup, ::vertexConstantGroupSize, ::pixelConstantGroup, ::pixelConstantGroupSize, ::textures, ::textureFilterModes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the two array types are shown as the plain array shape
// NiTPrimitiveArray, ImageSpaceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the layout needs
// BSImagespaceShader150b5b0, shaderParam, ImageSpaceEffect::Function1554640, ImageSpaceTexture::Function1555120: GUESS(low); the owner class is unidentified and the callees at 0x1554640 and 0x1555120 are unnamed
// The inventory calls 0x150b5b0 ImageSpaceEffect::Function150b5b0; the argument and base call show an override of the Render slot.
#pragma once

#include <cstdint>
#include <cstddef>

class BSTriShape;

class ImageSpaceEffectParam
{
public:
    virtual ~ImageSpaceEffectParam();
};

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    T* data;                  // 08
    std::uint16_t capacity;   // 10
    std::uint16_t size;       // 12
    std::uint16_t emptySlot;  // 14
    std::uint16_t growthSize; // 16
};
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "array size");

class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
public:
    std::uint32_t unk08;                      // 08
    bool SLIMode;                             // 0C
    std::uint64_t unk10;                      // 10
    std::uint64_t unk18;                      // 18
    std::uint8_t unk20;                       // 20
    std::uint32_t unk24;                      // 24
    float unk28;                              // 28
    std::uint32_t unk2C;                      // 2C
    float* vertexConstantGroup;               // 30
    std::uint32_t vertexConstantGroupSize;    // 38
    float* pixelConstantGroup;                // 40
    std::uint32_t pixelConstantGroupSize;     // 48
    NiTPrimitiveArray<void*> textures;        // 50
    NiTPrimitiveArray<std::int32_t> textureFilterModes;  // 68
};
static_assert(sizeof(ImageSpaceShaderParam) == 0x80, "parameter size");

class ImageSpaceTexture
{
public:
    void Function1555120(int a_value);  // callee at 0x1555120, not compared
};

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param);

    void Function1554640(int a_slot, ImageSpaceTexture* a_texture, int a_flag);  // callee at 0x1554640, not compared

    bool active;                                          // 08
    NiTPrimitiveArray<ImageSpaceEffect*> effects;         // 10
    NiTPrimitiveArray<ImageSpaceEffectParam*> effectParams;  // 28
    NiTPrimitiveArray<ImageSpaceTexture*> effectTextures; // 40
    NiTPrimitiveArray<void*> effectInputs;                // 58
    std::uint8_t unk70[0x20];                             // 70
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "effect size");

class BSShader
{
public:
    virtual ~BSShader();

    std::uint8_t unk08[0x88];
};
static_assert(sizeof(BSShader) == 0x90, "shader size");

class BSImagespaceShader : public BSShader, public ImageSpaceEffect
{
public:
    void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param) override;  // callee at 0x1564e30, not compared

    std::uint8_t unk120[0x88];  // 120
};
static_assert(sizeof(BSImagespaceShader) == 0x1a8, "imagespace shader size");

class BSImagespaceShader150b5b0 : public BSImagespaceShader
{
public:
    void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param) override;  // compared: 0x150b5b0

    ImageSpaceShaderParam shaderParam;  // 1A8
};
static_assert(sizeof(BSImagespaceShader150b5b0) == 0x228, "layout");
