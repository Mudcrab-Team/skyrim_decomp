// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Obj1bd9f0, UpdateMinTempFormId, minIdD50, flagDA9: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Obj1bd9f0
{
    void UpdateMinTempFormId(std::uint32_t a_formId);  // compared: 0x1bd9f0

    std::uint8_t unk00[0xD50];   // 000
    std::uint32_t minIdD50;      // D50
    std::uint8_t unkD54[0x55];   // D54
    std::uint8_t flagDA9;        // DA9
};
