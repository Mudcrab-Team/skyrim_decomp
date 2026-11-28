// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228bc0::GetSoulValue, treated as adapted: shaped like InventoryEntryData::GetSoulLevel (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:154, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseForm228bc0, SoulGem228bc0, ExtraDataList228bc0, ExtraListNode228bc0, InventoryEntry228bc0, GetSoulLevel, GetSoulValue228bc0, GetSoulValue, formType, soulLevel, item, next, object, extraLists: GUESS(low)
#pragma once

#include <cstdint>

struct BaseForm228bc0
{
    std::uint8_t unk00[0x1A];  // 00
    std::uint8_t formType;     // 1A
};

struct SoulGem228bc0 : BaseForm228bc0
{
    std::uint8_t unk1B[0xED];  // 01B
    std::uint8_t soulLevel;    // 108
};

class ExtraDataList228bc0
{
public:
    std::uint32_t GetSoulLevel() const;
};

std::int32_t GetSoulValue228bc0(std::uint32_t soulLevel);

struct ExtraListNode228bc0
{
    ExtraDataList228bc0* item;  // 00
    ExtraListNode228bc0* next;  // 08
};

class InventoryEntry228bc0
{
public:
    std::int32_t GetSoulValue() const;

    BaseForm228bc0* object;          // 00
    ExtraListNode228bc0* extraLists; // 08
};
