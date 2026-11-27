// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x306520 TESWaterForm::InitializeData
#include "TESWaterForm_306520.h"

void TESWaterForm::InitializeData()
{
    alpha = 0x4B;
    flags = 0;
    waterSound = nullptr;
    materialType = nullptr;
    imageSpace = nullptr;
    angularVelocity.x = g_defaultAngularVelocityX;
    angularVelocity.y = g_defaultAngularVelocityY;
    angularVelocity.z = g_defaultAngularVelocityZ;
    for (std::size_t i = 0; i < 3; ++i)
    {
        linearVelocity[i] = angularVelocity[i];
    }
    data.Function305f40();
    waterWeatherControl[0] = nullptr;
    waterWeatherControl[1] = nullptr;
    waterWeatherControl[2] = nullptr;
}
