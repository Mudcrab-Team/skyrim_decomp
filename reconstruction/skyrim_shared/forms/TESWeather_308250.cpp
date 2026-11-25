// Source exposure: mixed (community headers; pinned-image observations).
// Code origin: original; pinned-image observations and community layout names
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWeather: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWeather::Function308250: GUESS(low); address-based placeholder
// 0x308250 TESWeather::Function308250
// Adapted bodies: none
#include "TESWeather_308250.h"

float TESWeather::Function308250(std::int32_t layer, std::int32_t time) const
{
    if (numCloudLayers > 0) {
        if (layer >= numCloudLayers)
            layer = 0;
        return cloudAlpha[layer][time];
    }
    return WeatherDefaultCloudAlpha;
}
