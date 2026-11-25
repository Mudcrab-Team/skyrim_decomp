// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; observed arithmetic and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x30e860 TESWorldSpace::GetKeyForWorldCoord
// Adapted bodies: none
#include "TESWorldSpace_30e860.h"

std::uint32_t TESWorldSpace::GetKeyForWorldCoord(const NiPoint3& position)
{
    float x = static_cast<float>(static_cast<std::int32_t>(position.x));
    const std::int32_t cellX = static_cast<std::int32_t>(position.x - x >= 0.0f ? x : x - 1.0f) >> 12;
    float y = static_cast<float>(static_cast<std::int32_t>(position.y));
    const std::int32_t cellY = static_cast<std::int32_t>(position.y - y >= 0.0f ? y : y - 1.0f) >> 12;
    return (static_cast<std::uint32_t>(cellX) << 16) | static_cast<std::uint16_t>(cellY);
}
