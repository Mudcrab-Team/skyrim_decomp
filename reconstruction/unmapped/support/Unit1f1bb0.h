// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// EntryArray1f1bb0, Unit1f1bb0, RemoveEntry1f1bb0, data, unk08, count, unk00, array: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct EntryArray1f1bb0
{
    void** data;               // 00
    std::uint8_t unk08[0x10];  // 08
    std::uint32_t count;       // 18
};
static_assert(offsetof(EntryArray1f1bb0, count) == 0x18, "EntryArray1f1bb0::count offset");

struct Unit1f1bb0
{
    std::uint64_t unk00;     // 00
    EntryArray1f1bb0* array; // 08

    void RemoveEntry1f1bb0(const void* a_entry, bool a_preserveOrder);  // compared: 0x1f1bb0
};
static_assert(offsetof(Unit1f1bb0, array) == 0x08, "Unit1f1bb0::array offset");
