// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the cited CommonLibSSE-NG layout. Stamped as a twin of matched 0x295780 (skyrim_shared/world/BGSLightingTemplate_295600): source copied, names replaced by placeholders.
// Function1116d40, Owner1116d40: GUESS(low) STANDIN
// GetAmbientColor, GetDirectionalColor, GetFarFogColor, GetNearFogDistance, GetFarFogDistance, GetFogPower, GetFogClamp, GetLightFadeStart, GetLightFadeEnd, GetFresnelPower, GetDirectionalAmbientColor, data, directionalAmbientLightingColors: GUESS(low) STANDIN
#pragma once
#include "BGSLightingTemplate_295600.h"

class Owner1116d40
{
public:
    PackedColor GetAmbientColor() const;
    PackedColor GetDirectionalColor() const;
    PackedColor Function1116d40() const;
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
    std::uint8_t padding00[0x20];
    INTERIOR_DATA data;
    BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;
};

