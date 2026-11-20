// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the cited CommonLibSSE-NG layout.
// BGSLightingTemplate: EXE_RTTI
// GetAmbientColor, GetDirectionalColor, GetNearFogColor, GetFarFogColor, GetNearFogDistance: GUESS(low)
// GetFarFogDistance, GetFogPower, GetFogClamp, GetLightFadeStart, GetLightFadeEnd: GUESS(low)
// GetFresnelPower, GetDirectionalAmbientColor: GUESS(low)
#pragma once

#include <cstdint>

// PackedColor: STANDIN GUESS(low)
using PackedColor = std::uint32_t;

// INTERIOR_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct INTERIOR_DATA
{
    PackedColor ambient;
    PackedColor directional;
    PackedColor fogColorNear;
    float fogNear;
    float fogFar;
    std::uint8_t padding14[0x10];
    float fogPower;
    std::uint8_t padding28[0x20];
    PackedColor fogColorFar;
    float fogClamp;
    float lightFadeStart;
    float lightFadeEnd;
    std::uint8_t padding58[8];
};
static_assert(sizeof(INTERIOR_DATA) == 0x60, "interior data size");

// BGSDirectionalAmbientLightingColors, fresnelPower: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BGSDirectionalAmbientLightingColors
{
    // directional: STANDIN GUESS(low)
    PackedColor directional[6];
    PackedColor specular;
    float fresnelPower;
};

class BGSLightingTemplate
{
public:
    PackedColor GetAmbientColor() const;
    PackedColor GetDirectionalColor() const;
    PackedColor GetNearFogColor() const;
    PackedColor GetFarFogColor() const;
    float GetNearFogDistance() const;
    float GetFarFogDistance() const;
    float GetFogPower() const;
    float GetFogClamp() const;
    float GetLightFadeStart() const;
    float GetLightFadeEnd() const;
    PackedColor GetDirectionalAmbientColor(std::int32_t index) const;
    float GetFresnelPower() const;

private:
    // data, directionalAmbientLightingColors: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding00[0x20];
    INTERIOR_DATA data;
    BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;
};
