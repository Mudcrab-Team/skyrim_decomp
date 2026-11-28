// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228c60::FindWornExtraList, treated as adapted: shaped like InventoryEntryData::IsWorn (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:223, MIT); ItemChange::GetWorn in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:505
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList228c60, ExtraListNode228c60, InventoryEntry228c60, IsWorn, FindWornExtraList, item, next, object, extraLists: GUESS(low)
#pragma once

class ExtraDataList228c60
{
public:
    bool IsWorn() const;
};

struct ExtraListNode228c60
{
    ExtraDataList228c60* item;  // 00
    ExtraListNode228c60* next;  // 08
};

class InventoryEntry228c60
{
public:
    ExtraDataList228c60* FindWornExtraList() const;

    void* object;                    // 00
    ExtraListNode228c60* extraLists; // 08
};
