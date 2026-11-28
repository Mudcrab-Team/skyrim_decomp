// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry22a980::GetEntryA, GetEntryB and GetStatusFlags, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetItemOwnership and ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1376
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter22a980, ExtraDataList22a980, ExtraListNode22a980, InventoryEntry22a980, GetExtraA, GetExtraB, GetCombinedExtra22a980, GetEntryA, GetEntryB, GetStatusFlags, unk40, item, next, object, extraLists, gPlayer22a980: GUESS(low)
#pragma once

#include <cstdint>

// guess: the player singleton (the same address 0x25e600 passes as both references).
struct PlayerCharacter22a980
{
    std::uint8_t unk00[0x40];  // 00
    void* unk40;               // 40
};

extern PlayerCharacter22a980* gPlayer22a980;

class ExtraDataList22a980
{
public:
    void* GetExtraA() const;
    void* GetExtraB() const;
};

void* GetCombinedExtra22a980(void* object, ExtraDataList22a980* list);

struct ExtraListNode22a980
{
    ExtraDataList22a980* item;  // 00
    ExtraListNode22a980* next;  // 08
};

class InventoryEntry22a980
{
public:
    void* GetEntryA() const
    {
        if (extraLists && extraLists->item)
        {
            ExtraDataList22a980* list = extraLists->item;
            if (list->GetExtraA())
            {
                return list->GetExtraA();
            }
        }
        return nullptr;
    }

    void* GetEntryB() const
    {
        if (extraLists)
        {
            ExtraDataList22a980* list = extraLists->item;
            if (list && list->GetExtraB())
            {
                return list->GetExtraB();
            }
        }
        return nullptr;
    }

    std::uint32_t GetStatusFlags() const;

    void* object;                    // 00
    ExtraListNode22a980* extraLists; // 08
};
