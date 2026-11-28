// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1d5de0 Unit1d5de0::FindThresholdHealth1d5de0
// Adapted bodies: none
#include "Unit1d5de0.h"

// Searches destruction stages below the current health percentage for a matching payload threshold.
float Unit1d5de0::FindThresholdHealth1d5de0(std::uint8_t a_currentPercent, float a_minMetric, float a_maxLimit, StagePayload1d5de0** a_outPayload)
{
    for (std::uint32_t i = 0; i < list->count; ++i) {
        StageEntry1d5de0* stage = list->stages[i];
        if (stage->healthPercent < a_currentPercent && stage->payload) {
            if (GetPayloadMetric1d5de0(stage->payload) >= a_minMetric && !(a_maxLimit > stage->payload->metricLimit)) {
                float health = static_cast<float>(stage->healthPercent) * 0.01f * static_cast<float>(list->maxHealth);
                if (a_outPayload) {
                    *a_outPayload = stage->payload;
                }
                return health;
            }
        }
    }
    return g_defaultReturn1d5de0;
}
