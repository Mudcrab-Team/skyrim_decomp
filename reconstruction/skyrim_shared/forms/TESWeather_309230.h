// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWeather, TESWeather::InitializeData, TESWeather::cloudAlpha, TESWeather::cloudLayerDisabledBits, TESWeather::fogData, TESWeather::numCloudLayers, TESWeather::imageSpaces, TESWeather::sunGlareLensFlare, TESWeather::volumetricLighting, TESWeather::precipitationData, TESWeather::referenceEffect, TESImageSpace, BGSLensFlare, BGSVolumetricLighting, BGSShaderParticleGeometryData, BGSReferenceEffect: CRASHLOGGER_PDB(59818@2026.10.24)
// Color, Color::red, Color::green, Color::blue, Color::alpha, TESWeather::kTotalLayers, TESWeather::ColorTimes, TESWeather::ColorTime, TESWeather::ColorTimes::kSunrise, TESWeather::ColorTimes::kDay, TESWeather::ColorTimes::kSunset, TESWeather::ColorTimes::kNight, TESWeather::ColorTimes::kTotal, TESWeather::ColorTypes, TESWeather::ColorTypes::kSkyUpper, TESWeather::ColorTypes::kFogNear, TESWeather::ColorTypes::kUnknown, TESWeather::ColorTypes::kAmbient, TESWeather::ColorTypes::kSunlight, TESWeather::ColorTypes::kSun, TESWeather::ColorTypes::kStars, TESWeather::ColorTypes::kSkyLower, TESWeather::ColorTypes::kHorizon, TESWeather::ColorTypes::kEffectLighting, TESWeather::ColorTypes::kCloudLODDiffuse, TESWeather::ColorTypes::kCloudLODAmbient, TESWeather::ColorTypes::kFogFar, TESWeather::ColorTypes::kSkyStatics, TESWeather::ColorTypes::kWaterMultiplier, TESWeather::ColorTypes::kSunGlare, TESWeather::ColorTypes::kMoonGlare, TESWeather::ColorTypes::kTotal, TESWeather::Data, TESWeather::Data::Color3, TESWeather::Data::Color3::red, TESWeather::Data::Color3::green, TESWeather::Data::Color3::blue, TESWeather::Data::windSpeed, TESWeather::Data::unk01, TESWeather::Data::unk02, TESWeather::Data::transDelta, TESWeather::Data::sunGlare, TESWeather::Data::sunDamage, TESWeather::Data::precipitationBeginFadeIn, TESWeather::Data::precipitationEndFadeOut, TESWeather::Data::thunderLightningBeginFadeIn, TESWeather::Data::thunderLightningEndFadeOut, TESWeather::Data::thunderLightningFrequency, TESWeather::Data::flags, TESWeather::Data::lightningColor, TESWeather::Data::visualEffectBegin, TESWeather::Data::visualEffectEnd, TESWeather::Data::windDirection, TESWeather::Data::windDirectionRange, TESWeather::FogData, TESWeather::FogData::dayNear, TESWeather::FogData::dayFar, TESWeather::FogData::nightNear, TESWeather::FogData::nightFar, TESWeather::FogData::dayPower, TESWeather::FogData::nightPower, TESWeather::FogData::dayMax, TESWeather::FogData::nightMax, TESWeather::cloudLayerSpeedY, TESWeather::cloudLayerSpeedX, TESWeather::cloudColorData, TESWeather::data, TESWeather::colorData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk7A8, unk7F8: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESImageSpace;
class BGSLensFlare;
class BGSVolumetricLighting;
class BGSShaderParticleGeometryData;
class BGSReferenceEffect;

struct Color
{
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha;
};
static_assert(sizeof(Color) == 0x4, "Color size");

class TESWeather
{
public:
    enum
    {
        kTotalLayers = 32
    };

    struct ColorTimes
    {
        enum ColorTime : std::uint32_t
        {
            kSunrise = 0,
            kDay,
            kSunset,
            kNight,

            kTotal
        };
    };
    using ColorTime = ColorTimes::ColorTime;

    struct ColorTypes
    {
        enum
        {
            kSkyUpper = 0,
            kFogNear,
            kUnknown,
            kAmbient,
            kSunlight,
            kSun,
            kStars,
            kSkyLower,
            kHorizon,
            kEffectLighting,
            kCloudLODDiffuse,
            kCloudLODAmbient,
            kFogFar,
            kSkyStatics,
            kWaterMultiplier,
            kSunGlare,
            kMoonGlare,

            kTotal
        };
    };

    struct Data
    {
        struct Color3
        {
            std::int8_t red;
            std::int8_t green;
            std::int8_t blue;
        };
        static_assert(sizeof(Color3) == 0x3, "Data::Color3 size");

        std::uint8_t windSpeed;
        std::int8_t unk01;
        std::int8_t unk02;
        std::int8_t transDelta;
        std::int8_t sunGlare;
        std::int8_t sunDamage;
        std::int8_t precipitationBeginFadeIn;
        std::int8_t precipitationEndFadeOut;
        std::int8_t thunderLightningBeginFadeIn;
        std::int8_t thunderLightningEndFadeOut;
        std::int8_t thunderLightningFrequency;
        std::uint8_t flags;
        Color3 lightningColor;
        std::int8_t visualEffectBegin;
        std::int8_t visualEffectEnd;
        std::int8_t windDirection;
        std::int8_t windDirectionRange;
    };
    static_assert(sizeof(Data) == 0x13, "TESWeather::Data size");

    struct FogData
    {
        float dayNear;
        float dayFar;
        float nightNear;
        float nightFar;
        float dayPower;
        float nightPower;
        float dayMax;
        float nightMax;
    };
    static_assert(sizeof(FogData) == 0x20, "TESWeather::FogData size");

    void InitializeData();  // compared: 0x309230

    std::uint8_t unk00[0x220];
    std::int8_t cloudLayerSpeedY[kTotalLayers];                     // 220
    std::int8_t cloudLayerSpeedX[kTotalLayers];                     // 240
    Color cloudColorData[kTotalLayers][ColorTime::kTotal];          // 260
    float cloudAlpha[kTotalLayers][ColorTime::kTotal];              // 460
    std::uint32_t cloudLayerDisabledBits;                           // 660
    Data data;                                                      // 664
    FogData fogData;                                                // 678
    Color colorData[ColorTypes::kTotal][ColorTime::kTotal];         // 698
    std::uint8_t unk7A8[0x7d0 - 0x7a8];                             // 7A8
    std::uint32_t numCloudLayers;                                   // 7D0
    TESImageSpace* imageSpaces[ColorTime::kTotal];                  // 7D8
    std::uint8_t unk7F8[0x8a0 - 0x7f8];                             // 7F8
    BGSLensFlare* sunGlareLensFlare;                                // 8A0
    BGSVolumetricLighting* volumetricLighting[ColorTime::kTotal];   // 8A8
    BGSShaderParticleGeometryData* precipitationData;               // 8C8
    BGSReferenceEffect* referenceEffect;                            // 8D0
};
static_assert(offsetof(TESWeather, cloudColorData) == 0x260, "TESWeather cloudColorData offset");
static_assert(offsetof(TESWeather, data) == 0x664, "TESWeather data offset");
static_assert(offsetof(TESWeather, fogData) == 0x678, "TESWeather fogData offset");
static_assert(offsetof(TESWeather, colorData) == 0x698, "TESWeather colorData offset");
static_assert(offsetof(TESWeather, numCloudLayers) == 0x7d0, "TESWeather numCloudLayers offset");
static_assert(offsetof(TESWeather, referenceEffect) == 0x8d0, "TESWeather referenceEffect offset");
