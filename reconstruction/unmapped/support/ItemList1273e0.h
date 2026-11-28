// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Item1273e0, ItemList1273e0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct Item1273e0
{
    std::uint8_t unk00;  // 0x00
};

struct ItemList1273e0
{
    ~ItemList1273e0();  // compared: 0x1273e0

    std::vector<Item1273e0*> items;  // 0x00
};
