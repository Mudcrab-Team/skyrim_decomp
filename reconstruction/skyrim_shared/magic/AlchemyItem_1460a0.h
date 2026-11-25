// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AlchemyItem, Data, data, costOverride, flags, addictionItem, addictionChance, consumptionSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItem, SpellItem, BGSSoundDescriptorForm, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMagicItemData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk1B, unk90: GUESS(low); unrecovered base and component storage
#pragma once

#include <cstddef>
#include <cstdint>

class SpellItem;
class BGSSoundDescriptorForm;
class MagicItem
{
public:
    unsigned char unk00[0x1A];
    std::uint8_t formType; // 1A
    unsigned char unk1B[0x75];
};
static_assert(sizeof(MagicItem) == 0x90, "magic item base extent");

class AlchemyItem : public MagicItem
{
public:
    class Data
    {
    public:
        std::int32_t costOverride; // 00
        std::uint32_t flags; // 04
        SpellItem* addictionItem; // 08
        float addictionChance; // 10
        BGSSoundDescriptorForm* consumptionSound; // 18
    };
    void CopyMagicItemData(MagicItem* source);
    unsigned char unk90[0xA8]; // omitted secondary base components
    Data data; // 138
};
static_assert(offsetof(AlchemyItem, data) == 0x138, "alchemy data offset");
static_assert(offsetof(AlchemyItem::Data, consumptionSound) == 0x18, "sound offset");
