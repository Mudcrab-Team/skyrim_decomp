// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj244360, Serialize, rowCount, unk04, colCount, rows, hasExtra: GUESS(low)
#pragma once

#include <cstdint>

class Obj244360
{
public:
    bool Serialize(std::uint8_t* buffer, std::uint32_t bufferSize) const;

    std::uint32_t rowCount;    // 00
    std::uint32_t unk04;       // 04
    std::int32_t colCount;     // 08
    float** rows;              // 10
    std::uint64_t unk18;       // 18
    bool hasExtra;             // 20
};
