// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj243ed0, GetValue, rowCount, baseRow, rows: GUESS(low)
#pragma once

#include <cstdint>

class Obj243ed0
{
public:
    float GetValue(std::int32_t row, std::int32_t col) const;

    std::int32_t rowCount;  // 00
    std::int32_t baseRow;   // 04
    std::uint64_t unk08;    // 08
    float** rows;           // 10
};
