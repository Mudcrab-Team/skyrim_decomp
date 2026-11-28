// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ScrapAllocator10f640, ArrayBase10f640, ScrapArray10f640: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct ScrapAllocator10f640
{
    ScrapAllocator10f640() : allocator(nullptr), buffer(nullptr), capacity(0) {}

    void* allocator;         // 0x00
    void* buffer;            // 0x08
    std::uint32_t capacity;  // 0x10
};

struct ArrayBase10f640
{
    ArrayBase10f640();

    std::uint32_t size;  // 0x00
};

struct ScrapArray10f640 : public ScrapAllocator10f640, public ArrayBase10f640
{
    ScrapArray10f640();  // compared: 0x10f640
};
