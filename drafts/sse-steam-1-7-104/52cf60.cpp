// Near miss: 11.7% | inline-set
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; observed iteration and flag tests
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x52cf60 TESWaterSystem::FindReflection

#include "include/52cf60/TESWaterSystem_52cf60.h"

TESWaterReflections* TESWaterSystem::FindReflection(std::uint8_t interior)
{
    for (std::uint32_t i = 0; i < reflectionCount; ++i) {
        if (!interior && (waterReflections[i]->flags & 4)) {
            return waterReflections[i];
        }
        if (interior && (waterReflections[i]->flags & 2)) {
            return waterReflections[i];
        }
    }
    return nullptr;
}
