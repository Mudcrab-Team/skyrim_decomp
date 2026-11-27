// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// InventoryEntryData, InventoryEntryData::Function22a560: GUESS(low)
// InventoryEntryData::unk10: OBSERVED
// InventoryEntryData::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class InventoryEntryData
{
public:
    void Function22a560(std::uint32_t value);
    std::uint8_t unknown00[16];
    std::uint32_t unk10;
};

static_assert(offsetof(InventoryEntryData, unk10) == 16, "field offset");
