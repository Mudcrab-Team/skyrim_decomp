// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ExtraDataList2288c0, ExtraListNode2288c0, InventoryEntry2288c0, GetMaxCharge2288c0, GetItemMaxCharge, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

class ExtraDataList2288c0;

std::uint16_t GetMaxCharge2288c0(void* object, ExtraDataList2288c0* list);

struct ExtraListNode2288c0
{
    ExtraDataList2288c0* item;  // 00
    ExtraListNode2288c0* next;  // 08
};

class InventoryEntry2288c0
{
public:
    float GetItemMaxCharge() const;

    void* object;                    // 00
    ExtraListNode2288c0* extraLists; // 08
};
