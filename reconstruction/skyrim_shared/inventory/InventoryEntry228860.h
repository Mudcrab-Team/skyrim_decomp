// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228860::GetItemCharge, treated as adapted: shaped like InventoryEntryData::GetEnchantmentCharge (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:105, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList228860, ExtraListNode228860, InventoryEntry228860, GetCharge, GetMaxCharge228860, GetItemCharge, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

class ExtraDataList228860
{
public:
    float GetCharge() const;
};

std::uint16_t GetMaxCharge228860(void* object, ExtraDataList228860* list);

struct ExtraListNode228860
{
    ExtraDataList228860* item;  // 00
    ExtraListNode228860* next;  // 08
};

class InventoryEntry228860
{
public:
    float GetItemCharge() const;

    void* object;                    // 00
    ExtraListNode228860* extraLists; // 08
};
