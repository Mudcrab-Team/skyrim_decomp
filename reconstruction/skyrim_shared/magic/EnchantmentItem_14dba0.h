// Source exposure: mixed (community declarations, permitted sibling, local target).
// Code origin: minimal declarations reconstructed using the labelled sources and local layout observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnchantmentItem, EnchantmentItem::Data, EnchantmentItem::data, costOverride, flags, castingType, chargeOverride, delivery, spellType, chargeTime, pad1C, baseEnchantment, wornRestrictions, BGSListForm, MagicSystem, CastingType, Delivery, SpellType, kScroll, kTotal, kEnchantment: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EnchantmentItem::InitializeData, MagicItem::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88: GUESS(low); unaccessed storage.
// 0x14dba0 EnchantmentItem::InitializeData
#pragma once

#include <cstddef>
#include <cstdint>

namespace MagicSystem
{
    enum class CastingType : std::int32_t { kScroll = 3 };
    enum class Delivery : std::int32_t { kTotal = 5 };
    enum class SpellType : std::int32_t { kEnchantment = 6 };
}

class BGSListForm;

class MagicItem
{
public:
    void InitializeData();
    std::uint64_t unk00, unk08, unk10, unk18, unk20, unk28;
    std::uint64_t unk30, unk38, unk40, unk48, unk50, unk58;
    std::uint64_t unk60, unk68, unk70, unk78, unk80, unk88;
};

class EnchantmentItem : public MagicItem
{
public:
    struct Data
    {
        std::int32_t costOverride;
        std::uint32_t flags;
        MagicSystem::CastingType castingType;
        std::int32_t chargeOverride;
        MagicSystem::Delivery delivery;
        MagicSystem::SpellType spellType;
        float chargeTime;
        std::uint32_t pad1C;
        EnchantmentItem* baseEnchantment;
        BGSListForm* wornRestrictions;
    };

    void InitializeData();
    Data data;
};

static_assert(sizeof(MagicItem) == 0x90, "Magic item prefix");
static_assert(offsetof(EnchantmentItem::Data, chargeTime) == 0x18, "Charge time offset");
static_assert(offsetof(EnchantmentItem::Data, baseEnchantment) == 0x20, "Base enchantment offset");
static_assert(sizeof(EnchantmentItem) == 0xC0, "Enchantment layout");
