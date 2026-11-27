// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectNoise, ImageSpaceEffectNoise::Render: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceEffect, ImageSpaceEffectParam, BSTriShape: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffect::effects, ImageSpaceEffect::effectParams, ImageSpaceEffect::Render: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffectTexture, textures, texB0, g_noise_120..g_noise_178, VFunc02..VFunc07, Function152b170, Function1554640, Function1555130, unk00, unk08, unk09, unk0A, unk20, unk38, unk50: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSTriShape;
class ImageSpaceEffectTexture
{
public:
    void Function1555130(std::int32_t a_arg);  // callee at 0x1555130, not compared

    std::uint8_t unk00[0x20];
};

class ImageSpaceEffectParam
{
public:
    void Function152b170(std::int32_t a_slot, float a_x, float a_y, float a_z, float a_w);  // callee at 0x152b170, not compared
};

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param);  // +0x08
    virtual void VFunc02();
    virtual void VFunc03();
    virtual void VFunc04();
    virtual void VFunc05();
    virtual void VFunc06();
    virtual bool VFunc07(ImageSpaceEffectParam* a_param);                      // +0x38

    void Function1554640(std::int32_t a_slot, ImageSpaceEffectTexture* a_tex, std::int32_t a_arg);  // callee at 0x1554640, not compared

    bool unk08;                             // 08
    bool unk09;                             // 09
    std::uint8_t unk0A[0x0E];               // 0A
    ImageSpaceEffect** effects;             // 18
    std::uint8_t unk20[0x10];               // 20
    ImageSpaceEffectParam** effectParams;   // 30
    std::uint8_t unk38[0x10];               // 38
    ImageSpaceEffectTexture** textures;     // 48
    std::uint8_t unk50[0x60];               // 50
    ImageSpaceEffectTexture texB0;          // B0
};
static_assert(offsetof(ImageSpaceEffect, texB0) == 0xB0, "texB0 offset");

extern float g_noise_120;
extern float g_noise_130;
extern float g_noise_134;
extern float g_noise_140;
extern float g_noise_144;
extern float g_noise_150;
extern float g_noise_154;
extern float g_noise_160;
extern float g_noise_164;
extern float g_noise_168;
extern float g_noise_170;
extern float g_noise_174;
extern float g_noise_178;

class ImageSpaceEffectNoise : public ImageSpaceEffect
{
public:
    void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param) override;  // compared: 0x1585740
};
