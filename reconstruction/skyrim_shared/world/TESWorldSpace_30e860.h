// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; observed layout and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWorldSpace, GetKeyForWorldCoord: SYMBOLS(tesv-2013-map)
// GetKeyForWorldCoord: GUESS(low); candidate name fits the packed cell-coordinate arithmetic.
// NiPoint3, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>

struct NiPoint3 {
    float x;
    float y;
    float z;
};

class TESWorldSpace {
public:
    static std::uint32_t GetKeyForWorldCoord(const NiPoint3& position);
};
