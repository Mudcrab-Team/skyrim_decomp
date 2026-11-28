// Source exposure: mixed (community-generated layout and the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing; array count (3312 / 24 = 138) from TESDataHandler_1c3680.h.
// SPDX-License-Identifier: CC0-1.0
// Array1ba870, Obj1ba870, FindIndex: GUESS(low)
// formArrays10 count (138 = 3312 / 24): CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

struct Array1ba870
{
    void** data;          // 00
    std::uint64_t cap;    // 08
    std::uint32_t size;   // 10
};

struct Obj1ba870
{
    std::int32_t FindIndex(std::uint8_t a_slot, void* a_item) const;  // compared: 0x1ba870

    std::uint8_t unk00[0x10];       // 000
    Array1ba870 formArrays10[138];  // 010 (3312 bytes; matches TESDataHandler::formArrays_raw)
};
