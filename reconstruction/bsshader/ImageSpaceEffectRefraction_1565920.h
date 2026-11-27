// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectRefraction::Render: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceEffectRefraction, ImageSpaceEffect, ImageSpaceEffectParam, ImageSpaceTexture, BSImagespaceShader, BSShader, BSTriShape, NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffect::Render, ImageSpaceEffect::effects, ImageSpaceEffect::effectParams, ImageSpaceEffect::effectTextures, ImageSpaceEffect::unk09, ImageSpaceEffect::unk70: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function1554640, g_refractionFlag0, g_refractionFlag1, UpdateParams, active, effectInputs, Unk_02..Unk_06, unk00, unk08, unk90, data, capacity, size, emptySlot, growthSize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSTriShape;
class ImageSpaceEffectParam;

class ImageSpaceTexture
{
public:
    std::uint8_t unk00[0x20];
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
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "NiTPrimitiveArray size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param);
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);

    void Function1554640(int a_slot, ImageSpaceTexture* a_texture, int a_flag);  // callee at 0x1554640, not compared

    bool active;                                           // 08
    bool unk09;                                            // 09
    NiTPrimitiveArray<ImageSpaceEffect*> effects;          // 10
    NiTPrimitiveArray<ImageSpaceEffectParam*> effectParams;  // 28
    NiTPrimitiveArray<ImageSpaceTexture*> effectTextures;  // 40
    NiTPrimitiveArray<void*> effectInputs;                 // 58
    std::uint8_t unk70[0x20];                              // 70
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class BSShader
{
public:
    virtual ~BSShader();
    std::uint8_t unk08[0x88];
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");

class BSImagespaceShader : public BSShader, public ImageSpaceEffect
{
public:
    void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param) override;
};

class ImageSpaceEffectRefraction : public ImageSpaceEffect
{
public:
    void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param) override;  // compared: 0x1565920

    ImageSpaceTexture unk90;  // 90
};
static_assert(offsetof(ImageSpaceEffectRefraction, unk90) == 0x90, "layout");

extern bool g_refractionFlag0;
extern bool g_refractionFlag1;
