// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry17e420: GUESS(low)
// Func_17e420: GUESS(low)
#pragma once

#include <cstdint>

struct Entry17e420
{
    Entry17e420()
        : ptr(nullptr),
          flag(0)
    {
    }

    void* ptr;
    std::uint8_t flag;
};

static_assert(sizeof(Entry17e420) == 0x10, "Entry17e420 size");

struct Func_17e420
{
    void ConstructRange(std::uint32_t startIndex, std::uint32_t count);

    Entry17e420* data;
};
