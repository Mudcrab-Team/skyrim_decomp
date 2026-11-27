// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// g_sunriseEnd, g_sunsetBegin, kSunTimeScale: GUESS(low); the scale value is not read from the listing
// Globals g_sunriseEnd, g_sunsetBegin keep external linkage, as the target's compiler re-reads the flag word after the store.
// 0x419d00 Sky::CalcSunriseEnd
// 0x419d50 Sky::CalcSunsetBegin
#include "Sky_419d00.h"

float g_sunriseEnd;
float g_sunsetBegin;
static const float kSunTimeScale = 1.0f / 255.0f;

float Sky::CalcSunriseEnd()
{
    if ((this->flags & kUpdateSunriseEnd) && this->currentClimate)
    {
        g_sunriseEnd = static_cast<float>(this->currentClimate->sunriseEnd) * kSunTimeScale;
        this->flags &= ~kUpdateSunriseEnd;
    }
    return g_sunriseEnd;
}

float Sky::CalcSunsetBegin()
{
    if ((this->flags & kUpdateSunsetBegin) && this->currentClimate)
    {
        g_sunsetBegin = static_cast<float>(this->currentClimate->sunsetBegin) * kSunTimeScale;
        this->flags &= ~kUpdateSunsetBegin;
    }
    return g_sunsetBegin;
}
