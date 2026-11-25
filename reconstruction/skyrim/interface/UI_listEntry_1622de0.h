// Source exposure: binary-analysis.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// UI_listEntry, QueryPoint, QueryResult: STANDIN GUESS(low)
// UI_listEntry::Function1622de0, left, top, right, bottom, value, selected, minimumCoordinate: GUESS(low)
#pragma once
#include <cstdint>

struct QueryPoint { float x; float y; };
class UI_listEntry;
struct QueryResult
{
    UI_listEntry* selected;
    std::uint8_t unknown08[0xC];
    std::uint32_t value;
};
class UI_listEntry
{
public:
    bool Function1622de0(const QueryPoint& point, QueryResult& result);
    std::uint8_t unknown00[0xC];
    float left;
    float top;
    float right;
    float bottom;
    std::uint8_t unknown1C[0x34];
    std::uint32_t value;
};
extern const float minimumCoordinate;
