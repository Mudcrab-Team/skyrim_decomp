// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228900::GetEnchantment, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList228900, ExtraListNode228900, InventoryEntry228900, GetEnchantment, item, next, object, extraLists: GUESS(low)
#pragma once

class ExtraDataList228900
{
public:
    void* GetEnchantment() const;
};

struct ExtraListNode228900
{
    ExtraDataList228900* item;  // 00
    ExtraListNode228900* next;  // 08
};

class InventoryEntry228900
{
public:
    void* GetEnchantment() const;

    void* object;                    // 00
    ExtraListNode228900* extraLists; // 08
};
