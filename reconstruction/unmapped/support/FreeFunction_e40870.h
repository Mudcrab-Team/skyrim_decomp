// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// WideBuffer_e40870, Functione40870, At, data, size, index, buffer: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct WideBuffer_e40870
{
    const std::uint16_t* data;  // 0x00
    std::size_t size;           // 0x08

    const std::uint16_t* At(std::size_t index) const
    {
        if (data != nullptr && index < size) {
            return &data[index];
        }
        return nullptr;
    }
};
static_assert(sizeof(WideBuffer_e40870) == 0x10, "WideBuffer_e40870 size");

std::size_t Functione40870(const WideBuffer_e40870* buffer);
