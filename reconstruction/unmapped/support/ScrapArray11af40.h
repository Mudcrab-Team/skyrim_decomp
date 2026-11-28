// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ScrapAllocator11af40, ArrayBase11af40, ScrapArray11af40: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct ScrapAllocator11af40
{
    ScrapAllocator11af40() : allocator(nullptr), buffer(nullptr), capacity(0) {}

    void* allocator;         // 0x00
    void* buffer;            // 0x08
    std::uint32_t capacity;  // 0x10
};

struct ArrayBase11af40
{
    ArrayBase11af40();

    std::uint32_t size;  // 0x00
};

struct ScrapArray11af40 : public ScrapAllocator11af40, public ArrayBase11af40
{
    ScrapArray11af40();  // compared: 0x11af40
};
