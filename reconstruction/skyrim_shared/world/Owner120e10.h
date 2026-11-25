// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the cited CommonLibSSE-NG layout. Stamped as a twin of matched 0x295680 (skyrim_shared/world/BGSLightingTemplate_295600): source copied, names replaced by placeholders.
// Function120e10, Owner120e10: GUESS(low) STANDIN
// GetAmbientColor, GetNearFogColor, GetFarFogColor, GetNearFogDistance, GetFarFogDistance, GetFogPower, GetFogClamp, GetLightFadeStart, GetLightFadeEnd, GetFresnelPower, GetDirectionalAmbientColor, data, directionalAmbientLightingColors: GUESS(low) STANDIN
#pragma once
#include "BGSLightingTemplate_295600.h"

class Owner120e10
{
public:
    PackedColor GetAmbientColor() const;
    PackedColor Function120e10() const;
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
    std::uint8_t padding00[0x20];
    INTERIOR_DATA data;
    BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;
};
