// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Array24aea0, Function24aea0, unk00, data, unk10, size, array, target: GUESS(low)
#pragma once

#include <cstdint>

struct Array24aea0
{
    std::uint64_t unk00;  // 0x00
    void** data;          // 0x08
    std::uint32_t unk10;  // 0x10
    std::uint32_t size;   // 0x14
};
static_assert(sizeof(Array24aea0) == 0x18, "Array24aea0 size");

std::uint32_t Function24aea0(const Array24aea0* array, const void* target);
