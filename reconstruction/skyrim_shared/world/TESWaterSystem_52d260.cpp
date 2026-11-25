// Source exposure: mixed (community names/layouts; pinned-image observations).
// Code origin: original; reconstructed from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x52d260 TESWaterSystem::Enable
// Adapted bodies: none
#include "TESWaterSystem_52d260.h"

bool TESWaterSystem::Enable()
{
    WaterEnableRequested = true;
    if (enabled || !WaterEnabledSetting)
        return false;
    enabled = true;
    waterVisible = true;
    for (std::uint32_t i = 0; i < waterObjectCount; ++i)
        waterObjects[i]->shape->flags &= ~1u;
    return true;
}
