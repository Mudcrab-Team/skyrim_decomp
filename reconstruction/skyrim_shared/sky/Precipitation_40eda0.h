// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Precipitation, Precipitation::Ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// OcclusionMapData, kPrecipitationScaleDefault, g_precipitationFlagSource, g_precipitationFlag, g_precipitationScale, unk08, unk70, unk78, unk80, unk84, unk88: STANDIN GUESS(low); names made up from the offsets in the listing; the constructor of the member at 10 is the callee at 0x40ffe0
#pragma once

#include <cstdint>
#include <cstddef>

class OcclusionMapData
{
public:
    OcclusionMapData();  // callee at 0x40ffe0, not compared here
    std::uint8_t unk00[0x60];
};

extern float kPrecipitationScaleDefault;
extern float g_precipitationScale;
extern std::uint8_t g_precipitationFlagSource;
extern std::uint8_t g_precipitationFlag;

class Precipitation
{
public:
    Precipitation();  // compared: 0x40eda0
    virtual ~Precipitation();

    std::uint8_t unk08[8];
    OcclusionMapData occlusion;  // 10
    void* unk70;                 // 70
    void* unk78;                 // 78
    float unk80;                 // 80
    float unk84;                 // 84
    float unk88;                 // 88
};
static_assert(offsetof(Precipitation, unk88) == 0x88, "layout");
