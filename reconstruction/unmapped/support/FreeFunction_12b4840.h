// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// TableEntry_12b4840, g_table_12b4840, Function12b4840, value, key: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct TableEntry_12b4840
{
    std::uint32_t value;  // 0x00
    const void* key;      // 0x08
};
static_assert(sizeof(TableEntry_12b4840) == 0x10, "TableEntry_12b4840 size");
static_assert(offsetof(TableEntry_12b4840, key) == 0x08, "key offset");

extern TableEntry_12b4840 g_table_12b4840[200];

std::uint32_t Function12b4840(const void* key);
