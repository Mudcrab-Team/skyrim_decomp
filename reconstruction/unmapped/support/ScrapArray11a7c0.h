// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ScrapAllocator11a7c0, ArrayBase11a7c0, ScrapArray11a7c0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct ScrapAllocator11a7c0
{
    ScrapAllocator11a7c0() : allocator(nullptr), buffer(nullptr), capacity(0) {}

    void* allocator;         // 0x00
    void* buffer;            // 0x08
    std::uint32_t capacity;  // 0x10
};

struct ArrayBase11a7c0
{
    ArrayBase11a7c0();

    std::uint32_t size;  // 0x00
};

struct ScrapArray11a7c0 : public ScrapAllocator11a7c0, public ArrayBase11a7c0
{
    ScrapArray11a7c0();  // compared: 0x11a7c0
};
