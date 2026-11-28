// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry229080::CountFlagged, treated as adapted: shaped like ItemChange::GetExtraTotalCount in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:353
// SPDX-License-Identifier: CC0-1.0
// ExtraDataList229080, ExtraListNode229080, InventoryEntry229080, HasFlag, GetCount, CountFlagged, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

class ExtraDataList229080
{
public:
    bool HasFlag() const;
    std::int16_t GetCount() const;
};

struct ExtraListNode229080
{
    ExtraDataList229080* item;  // 00
    ExtraListNode229080* next;  // 08
};

class InventoryEntry229080
{
public:
    std::int32_t CountFlagged() const;

    void* object;                    // 00
    ExtraListNode229080* extraLists; // 08
};
