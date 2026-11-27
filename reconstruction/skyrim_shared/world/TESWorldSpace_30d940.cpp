// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; observed coordinate arithmetic and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x30d940 TESWorldSpace::GetMinimumCellCoord
// Adapted bodies: none
#include "TESWorldSpace_30d940.h"

void TESWorldSpace::GetMinimumCellCoord(std::int32_t& x, std::int32_t& y) const
{
    const float wholeX = static_cast<float>(static_cast<std::int32_t>(minimumCoords.x));
    x = static_cast<std::int32_t>(minimumCoords.x - wholeX >= 0.0f ? wholeX : wholeX - 1.0f) >> 12;
    const float wholeY = static_cast<float>(static_cast<std::int32_t>(minimumCoords.y));
    y = static_cast<std::int32_t>(minimumCoords.y - wholeY >= 0.0f ? wholeY : wholeY - 1.0f) >> 12;
}
