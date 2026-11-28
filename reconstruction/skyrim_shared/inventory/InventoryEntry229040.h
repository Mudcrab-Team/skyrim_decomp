// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry229040::HasAnyFlag, treated as adapted: shaped like InventoryEntryData::IsQuestObject (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:246, MIT); ItemChange::HasStolenData in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:289
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList229040, ExtraListNode229040, InventoryEntry229040, HasFlag, HasAnyFlag, item, next, object, extraLists: GUESS(low)
#pragma once

class ExtraDataList229040
{
public:
    bool HasFlag() const;
};

struct ExtraListNode229040
{
    ExtraDataList229040* item;  // 00
    ExtraListNode229040* next;  // 08
};

class InventoryEntry229040
{
public:
    bool HasAnyFlag() const;

    void* object;                    // 00
    ExtraListNode229040* extraLists; // 08
};
