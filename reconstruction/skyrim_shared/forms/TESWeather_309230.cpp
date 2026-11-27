// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x309230 TESWeather::InitializeData
#include "TESWeather_309230.h"

#include <cstring>

void TESWeather::InitializeData()
{
    numCloudLayers = 3u;
    std::memset(colorData, 0, sizeof(colorData[0]) * ColorTypes::kWaterMultiplier);
    std::memset(&data, 0, sizeof(data));
    fogData.dayNear = 0.0f;
    fogData.dayFar = 0.0f;
    fogData.nightNear = 0.0f;
    fogData.nightFar = 0.0f;
    fogData.dayPower = 1.0f;
    fogData.nightPower = 1.0f;
    fogData.dayMax = 1.0f;
    fogData.nightMax = 1.0f;
    std::memset(cloudLayerSpeedY, 0x7f, sizeof(cloudLayerSpeedY));
    std::memset(cloudLayerSpeedX, 0x7f, sizeof(cloudLayerSpeedX));
    std::memset(cloudColorData, 0, sizeof(cloudColorData));
    for (std::uint32_t i = 0; i < kTotalLayers; ++i)
    {
        cloudAlpha[i][ColorTimes::kSunrise] = 1.0f;
        cloudAlpha[i][ColorTimes::kDay] = 1.0f;
        cloudAlpha[i][ColorTimes::kSunset] = 1.0f;
        cloudAlpha[i][ColorTimes::kNight] = 1.0f;
    }
    std::memset(imageSpaces, 0, sizeof(imageSpaces));
    std::memset(volumetricLighting, 0, sizeof(volumetricLighting));
    precipitationData = nullptr;
    referenceEffect = nullptr;
    cloudLayerDisabledBits = 0u;
    for (std::uint32_t i = 0; i < ColorTime::kTotal; ++i)
    {
        colorData[ColorTypes::kWaterMultiplier][i].red = 255;
        colorData[ColorTypes::kWaterMultiplier][i].green = 255;
        colorData[ColorTypes::kWaterMultiplier][i].blue = 255;
        colorData[ColorTypes::kWaterMultiplier][i].alpha = 0;
    }
    for (std::uint32_t i = 0; i < ColorTime::kTotal; ++i)
    {
        colorData[ColorTypes::kMoonGlare][i].red = 255;
        colorData[ColorTypes::kMoonGlare][i].green = 255;
        colorData[ColorTypes::kMoonGlare][i].blue = 255;
        colorData[ColorTypes::kMoonGlare][i].alpha = 0;
    }
    for (std::uint32_t i = 0; i < ColorTime::kTotal; ++i)
    {
        colorData[ColorTypes::kSunGlare][i].red = 255;
        colorData[ColorTypes::kSunGlare][i].green = 255;
        colorData[ColorTypes::kSunGlare][i].blue = 255;
        colorData[ColorTypes::kSunGlare][i].alpha = 0;
    }
    sunGlareLensFlare = nullptr;
}
