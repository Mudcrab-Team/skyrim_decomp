// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228b40::GetSoulLevel, treated as adapted: shaped like InventoryEntryData::GetSoulLevel (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:154, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseForm228b40, SoulGem228b40, ExtraDataList228b40, ExtraListNode228b40, InventoryEntry228b40, GetSoulLevel, formType, soulLevel, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

struct BaseForm228b40
{
    std::uint8_t unk00[0x1A];  // 00
    std::uint8_t formType;     // 1A
};

struct SoulGem228b40 : BaseForm228b40
{
    std::uint8_t unk1B[0xED];  // 01B
    std::uint8_t soulLevel;    // 108
};

class ExtraDataList228b40
{
public:
    std::uint32_t GetSoulLevel() const;
};

struct ExtraListNode228b40
{
    ExtraDataList228b40* item;  // 00
    ExtraListNode228b40* next;  // 08
};

class InventoryEntry228b40
{
public:
    std::uint32_t GetSoulLevel() const;

    BaseForm228b40* object;          // 00
    ExtraListNode228b40* extraLists; // 08
};
