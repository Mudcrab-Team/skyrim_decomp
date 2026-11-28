// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// StringHeader_156e570, AllocRaw_156e570, Function156e570, capacity, refCount, length, bytes, source: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct StringHeader_156e570
{
    std::size_t capacity;  // 0x00
    std::size_t refCount;  // 0x08
    std::size_t length;    // 0x10
};
static_assert(sizeof(StringHeader_156e570) == 0x18, "StringHeader_156e570 size");

StringHeader_156e570* AllocRaw_156e570(std::size_t bytes);

char* Function156e570(const char* source);
