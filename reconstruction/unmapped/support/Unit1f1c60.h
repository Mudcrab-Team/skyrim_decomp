// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// EntryArray1f1c60, Unit1f1c60, RemoveEntry1f1c60, unk00, data, unk10, count, array: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct EntryArray1f1c60
{
    std::uint64_t unk00;       // 00
    void** data;               // 08
    std::uint8_t unk10[0x0C];  // 10
    std::uint32_t count;       // 1C
};
static_assert(offsetof(EntryArray1f1c60, data) == 0x08, "EntryArray1f1c60::data offset");
static_assert(offsetof(EntryArray1f1c60, count) == 0x1C, "EntryArray1f1c60::count offset");

struct Unit1f1c60
{
    std::uint64_t unk00;     // 00
    EntryArray1f1c60* array; // 08

    void RemoveEntry1f1c60(const void* a_entry, bool a_preserveOrder);  // compared: 0x1f1c60
};
static_assert(offsetof(Unit1f1c60, array) == 0x08, "Unit1f1c60::array offset");
