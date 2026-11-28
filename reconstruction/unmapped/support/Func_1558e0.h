// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Func_1558e0: GUESS(low)
#pragma once

#include <cstdint>

struct Func_1558e0
{
    void CopyFrom(const Func_1558e0* other);

    std::uint8_t unk00[0x1A];
    std::uint8_t formType;
    std::uint8_t unk1B[0xA5];
    std::uint32_t fieldC0;
    std::uint32_t fieldC4;
    std::uint32_t fieldC8;
    std::uint32_t fieldCC;
    std::uint32_t fieldD0;
    std::uint32_t fieldD4;
    std::uint32_t fieldD8;
    std::uint32_t fieldDC;
    std::uint64_t fieldE0;
};
