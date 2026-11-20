// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the pinned listings using the cited declarations.
// Adapted bodies: none
// 0x295600 BGSLightingTemplate::GetAmbientColor
// 0x295680 BGSLightingTemplate::GetDirectionalColor
// 0x295780 BGSLightingTemplate::GetNearFogColor
// 0x295790 BGSLightingTemplate::GetFarFogColor
// 0x295880 BGSLightingTemplate::GetNearFogDistance
// 0x2958a0 BGSLightingTemplate::GetFarFogDistance
// 0x2958c0 BGSLightingTemplate::GetFogPower
// 0x2958e0 BGSLightingTemplate::GetFogClamp
// 0x295920 BGSLightingTemplate::GetLightFadeStart
// 0x295940 BGSLightingTemplate::GetLightFadeEnd
// 0x295960 BGSLightingTemplate::GetDirectionalAmbientColor
// 0x295980 BGSLightingTemplate::GetFresnelPower
#include "BGSLightingTemplate_295600.h"

PackedColor BGSLightingTemplate::GetAmbientColor() const
{
    return data.ambient;
}

PackedColor BGSLightingTemplate::GetDirectionalColor() const
{
    return data.directional;
}

PackedColor BGSLightingTemplate::GetNearFogColor() const
{
    return data.fogColorNear;
}

PackedColor BGSLightingTemplate::GetFarFogColor() const
{
    return data.fogColorFar;
}

float BGSLightingTemplate::GetNearFogDistance() const
{
    return data.fogNear;
}

float BGSLightingTemplate::GetFarFogDistance() const
{
    return data.fogFar;
}

float BGSLightingTemplate::GetFogPower() const
{
    return data.fogPower;
}

float BGSLightingTemplate::GetFogClamp() const
{
    return data.fogClamp;
}

float BGSLightingTemplate::GetLightFadeStart() const
{
    return data.lightFadeStart;
}

float BGSLightingTemplate::GetLightFadeEnd() const
{
    return data.lightFadeEnd;
}

PackedColor BGSLightingTemplate::GetDirectionalAmbientColor(std::int32_t index) const
{
    return directionalAmbientLightingColors.directional[index];
}

float BGSLightingTemplate::GetFresnelPower() const
{
    return directionalAmbientLightingColors.fresnelPower;
}
