// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x40eda0 Precipitation::Ctor
#include "Precipitation_40eda0.h"

Precipitation::Precipitation()
{
    float scale = kPrecipitationScaleDefault;
    unk70 = nullptr;
    unk78 = nullptr;
    unk80 = 4096.0f;
    unk84 = 1.0f;
    unk88 = 1.0f;
    g_precipitationFlag = g_precipitationFlagSource;
    g_precipitationScale = scale;
}
