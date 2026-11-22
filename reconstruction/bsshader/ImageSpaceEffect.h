// Source exposure: mixed (community headers and the helper-generated skeleton).
// 0x1565300 compared function
// Code origin: partial class declaration adapted from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceEffect, ImageSpaceEffect::IsActive, ImageSpaceEffect::~ImageSpaceEffect, ImageSpaceEffect::Render, ImageSpaceEffect::Setup, ImageSpaceEffect::ShutDown, ImageSpaceEffect::BorrowTextures, ImageSpaceEffect::ReturnTextures, ImageSpaceEffect::UpdateParams, ImageSpaceEffect::SetRenderStates, ImageSpaceEffect::RestoreRenderStates: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTriShape, ImageSpaceEffectParam, ImageSpaceManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffect::active: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown09: GUESS(low)
#pragma once

#include <cstdint>

class BSTriShape;
class ImageSpaceEffectParam;
class ImageSpaceManager;

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();  // 00
    virtual void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param);  // 01
    virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param);  // 02
    virtual void ShutDown();  // 03
    virtual void BorrowTextures(ImageSpaceEffectParam* a_param);  // 04
    virtual void ReturnTextures();  // 05
    virtual bool IsActive();  // compared: 0x150b480  // slot 06
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);  // 07
    virtual bool SetRenderStates(ImageSpaceEffectParam* a_param);  // 08
    virtual bool RestoreRenderStates(ImageSpaceEffectParam* a_param);  // 09

    bool active;  // 08
    std::uint8_t unknown09[0x87];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");
