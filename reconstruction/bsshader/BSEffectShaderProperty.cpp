// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x1529b30 BSEffectShaderProperty::QShader
// 0x152add0 BSEffectShaderProperty::Unk_3C
// 0x152ada0 BSEffectShaderProperty::GetBaseTexture
// 0x152adf0 BSEffectShaderProperty::SetMaterialAlpha
// 0x152ade0 BSEffectShaderProperty::QMaterialAlpha
// 0x152aa00 BSEffectShaderProperty::Function152aa00
// 0x152aa40 BSEffectShaderProperty::Function152aa40
#include "BSEffectShaderProperty.h"
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSEffectShaderProperty::QShader() const
{
    return 0x1;
}

bool BSEffectShaderProperty::Unk_3C() const
{
    return true;
}

std::uint32_t BSEffectShaderProperty::GetMaterialType() const
{
    return 0x1;
}

const NiRTTI* BSEffectShaderProperty::GetRTTI() const
{
    return &NiRTTI_BSEffectShaderProperty;
}

NiSourceTexture* BSEffectShaderProperty::GetBaseTexture()
{
    return material->sourceTexture;
}

void BSEffectShaderProperty::SetMaterialAlpha(float a)
{
    material->alpha = a > 0.0f ? a : 0.0f;
}

float BSEffectShaderProperty::QMaterialAlpha()
{
    return material->alpha;
}

void BSEffectShaderProperty::Function152aa00(void* buffer)
{
    std::uint32_t size = 16;
    NiBinaryStream* stream = readStream;
    stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, 16, &size, 1);
}

void BSEffectShaderProperty::Function152aa40(const void* buffer)
{
    std::uint32_t size = 16;
    NiBinaryStream* stream = writeStream;
    stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, 16, &size, 1);
}
