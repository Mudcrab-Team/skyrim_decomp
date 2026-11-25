// Source exposure: mixed (community headers; pinned-image observations).
// Code origin: original; community layout names and observed behavior
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWeather, TESWeather::cloudAlpha, TESWeather::numCloudLayers: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWeather::Function308250: GUESS(low); address-based placeholder
// WeatherDefaultCloudAlpha: OBSERVED; data reference, value not assumed
#pragma once

#include <cstdint>
#include <cstddef>

extern float WeatherDefaultCloudAlpha;

class TESWeather
{
public:
    float Function308250(std::int32_t layer, std::int32_t time) const;

    std::uint8_t unobserved000[0x460];
    float cloudAlpha[32][4]; // 0x460
    std::uint8_t unobserved660[0x170];
    std::int32_t numCloudLayers; // 0x7D0; signed for the observed bounds test
};
static_assert(offsetof(TESWeather, cloudAlpha) == 0x460, "cloudAlpha offset");
static_assert(offsetof(TESWeather, numCloudLayers) == 0x7D0, "numCloudLayers offset");
