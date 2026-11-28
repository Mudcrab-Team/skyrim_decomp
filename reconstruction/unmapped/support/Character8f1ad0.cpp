// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x8f1ad0 Character8f1ad0::ComputeScaledValue
// Cookbook: 0x8f1ad0 48
// Adapted bodies: none
#include "Character8f1ad0.h"

#include <cmath>

// Scales baseValue by clamped powf(factor, count - 1) when factor < 1 and the target id matches.
float Character8f1ad0::ComputeScaledValue()
{
    Data8f1ad0* data = GetData();
    float result = data->baseValue;
    if (data->factor < 1.0f && id == g_targetId8f1ad0) {
        std::uint32_t count = g_manager8f1ad0->count;
        if (count > 1) {
            float scale = std::powf(data->factor, static_cast<float>(count) - 1.0f);
            if (scale < g_minScale8f1ad0) {
                scale = g_minScale8f1ad0;
            }
            result *= scale;
        }
    }
    return result;
}
