// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Func_14e310: GUESS(low)
#pragma once

#include <cstdint>

struct Func_14e310
{
    void ByteSwapFields();

    std::uint8_t unk00[0x90];
    std::uint32_t field90;
    std::uint32_t field94;
    std::uint32_t field98;
    std::uint32_t field9C;
    std::uint32_t fieldA0;
    std::uint32_t fieldA4;
    std::uint32_t fieldA8;
    std::uint64_t fieldB0;
    std::uint64_t fieldB8;
};
