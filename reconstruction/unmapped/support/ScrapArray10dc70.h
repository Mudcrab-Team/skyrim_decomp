// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ScrapAllocator10dc70, ArrayBase10dc70, ScrapArray10dc70: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct ScrapAllocator10dc70
{
    ScrapAllocator10dc70() : allocator(nullptr), buffer(nullptr), capacity(0) {}

    void* allocator;         // 0x00
    void* buffer;            // 0x08
    std::uint32_t capacity;  // 0x10
};

struct ArrayBase10dc70
{
    ArrayBase10dc70();

    std::uint32_t size;  // 0x00
};

struct ScrapArray10dc70 : public ScrapAllocator10dc70, public ArrayBase10dc70
{
    ScrapArray10dc70();  // compared: 0x10dc70
};
