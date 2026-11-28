// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228760::GetValue, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); InventoryEntry228760::GetValue also shaped like the inventory entry script getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:31061
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraItem228760, ExtraDataList228760, ExtraListNode228760, InventoryEntry228760, GetExtra, GetValue, value10, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

struct ExtraItem228760
{
    std::uint8_t unk00[0x10];  // 00
    std::uint32_t value10;     // 10
};

class ExtraDataList228760
{
public:
    ExtraItem228760* GetExtra() const;
};

struct ExtraListNode228760
{
    ExtraDataList228760* item;  // 00
    ExtraListNode228760* next;  // 08
};

class InventoryEntry228760
{
public:
    std::uint32_t GetValue() const;

    void* object;                    // 00
    ExtraListNode228760* extraLists; // 08
};
