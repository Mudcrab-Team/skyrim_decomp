// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ImageEffect1554640::Function1554640, treated as adapted: shaped like NiTArray::SetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e include/NiTArray.h:93
// SPDX-License-Identifier: CC0-1.0
// Entry_1554640, ImageEffect1554640, Configure, Function1554640, unk00, entries, unk50, size, activeCount, index, entry, param: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Entry_1554640
{
    void Configure(std::uint32_t param);
};

class ImageEffect1554640
{
public:
    std::uint8_t unk00[0x48];  // 0x00
    Entry_1554640** entries;   // 0x48
    std::uint16_t unk50;       // 0x50
    std::uint16_t size;        // 0x52
    std::uint16_t activeCount; // 0x54

    void Function1554640(std::uint32_t index, Entry_1554640* entry, std::uint32_t param);
};
static_assert(offsetof(ImageEffect1554640, entries) == 0x48, "entries offset");
static_assert(offsetof(ImageEffect1554640, size) == 0x52, "size offset");
static_assert(offsetof(ImageEffect1554640, activeCount) == 0x54, "activeCount offset");
