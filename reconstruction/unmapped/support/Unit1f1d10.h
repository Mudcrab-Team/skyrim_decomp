// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// EntryArray1f1d10, Unit1f1d10, RemoveEntry1f1d10, unk00, data, unk18, count, array: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct EntryArray1f1d10
{
    std::uint8_t unk00[0x10];  // 00
    void** data;               // 10
    std::uint64_t unk18;       // 18
    std::uint32_t count;       // 20
};
static_assert(offsetof(EntryArray1f1d10, data) == 0x10, "EntryArray1f1d10::data offset");
static_assert(offsetof(EntryArray1f1d10, count) == 0x20, "EntryArray1f1d10::count offset");

struct Unit1f1d10
{
    std::uint64_t unk00;     // 00
    EntryArray1f1d10* array; // 08

    void RemoveEntry1f1d10(const void* a_entry, bool a_preserveOrder);  // compared: 0x1f1d10
};
static_assert(offsetof(Unit1f1d10, array) == 0x08, "Unit1f1d10::array offset");
