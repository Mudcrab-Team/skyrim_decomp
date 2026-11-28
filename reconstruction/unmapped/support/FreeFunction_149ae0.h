// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function149ae0: GUESS(low)
// StringData149ae0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct StringData149ae0
{
    const char* data;
    std::uint16_t length;
};

std::size_t Function149ae0(const StringData149ae0* str);
