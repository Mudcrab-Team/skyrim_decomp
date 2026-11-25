// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; observed layout and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWorldSpace, NiPoint2, minimumCoords, x, y: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetMinimumCellCoord: SYMBOLS(tesv-2013-map)
// GetMinimumCellCoord: GUESS(low); candidate name fits the minimum-coordinate conversion.
#pragma once
#include <cstdint>
#include <cstddef>

struct NiPoint2 {
    float x;
    float y;
};

class TESWorldSpace {
public:
    void GetMinimumCellCoord(std::int32_t& x, std::int32_t& y) const;
    std::uint8_t unknown00[0x1C0];
    NiPoint2 minimumCoords;
};
static_assert(offsetof(TESWorldSpace, minimumCoords) == 0x1C0, "minimum-coordinate offset");
