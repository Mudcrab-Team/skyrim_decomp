// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228cb0::GetExtraPtr, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList228cb0, ExtraListNode228cb0, InventoryEntry228cb0, GetExtraPtr, item, next, object, extraLists: GUESS(low)
#pragma once

class ExtraDataList228cb0
{
public:
    void* GetExtraPtr() const;
};

struct ExtraListNode228cb0
{
    ExtraDataList228cb0* item;  // 00
    ExtraListNode228cb0* next;  // 08
};

class InventoryEntry228cb0
{
public:
    void* GetExtraPtr() const;

    void* object;                    // 00
    ExtraListNode228cb0* extraLists; // 08
};
