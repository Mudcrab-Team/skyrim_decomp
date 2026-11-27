// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x52d3a0 TESWaterSystem::SetUnderwaterVariables
#include "TESWaterSystem_52d3a0.h"

WaterRenderer* g_waterRenderer;
bool g_isUnderwater;

void TESWaterSystem::SetUnderwaterVariables(bool a_underwater, float a_value)
{
    if (a_underwater)
    {
        unkC0 = a_value;
    }
    if (a_underwater != unkB8)
    {
        g_waterRenderer->Function524080(a_underwater);
    }
    unkB8 = a_underwater;
    g_isUnderwater = a_underwater;
}
