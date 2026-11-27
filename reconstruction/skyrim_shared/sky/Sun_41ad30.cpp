// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x41ad30 Sun::GetSunOcclusionPercent
#include "Sun_41ad30.h"

float Sun::GetSunOcclusionPercent()
{
    std::uint32_t saved = g_threadMarker_tls_0x768;
    g_threadMarker_tls_0x768 = 0x5D;
    float result = 0.0f;
    if (unk50)
    {
        result = unk50->occlusion;
    }
    g_threadMarker_tls_0x768 = saved;
    return result;
}
