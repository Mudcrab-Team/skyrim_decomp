// Source exposure: mixed (pinned image listings and RTTI, project layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original bodies using the pinned listings and the cited declarations.
// Adapted bodies: GetData1 follows CommonLibSSE-NG@b93280e include/RE/A/AlchemyItem.h:78, include/RE/I/IngredientItem.h:93, and include/RE/S/SpellItem.h:87 (MIT).
// 0x146428 AlchemyItem::~AlchemyItem
// 0x146434 AlchemyItem::~AlchemyItem
// 0x146440 AlchemyItem::~AlchemyItem
// 0x146464 AlchemyItem::~AlchemyItem
// 0x146470 AlchemyItem::~AlchemyItem
// 0x14647c AlchemyItem::~AlchemyItem
// 0x146488 AlchemyItem::~AlchemyItem
// 0x1466c0 AlchemyItem::GetData1
// 0x14fb04 IngredientItem::~IngredientItem
// 0x14fb10 IngredientItem::~IngredientItem
// 0x14fb34 IngredientItem::~IngredientItem
// 0x14fb40 IngredientItem::~IngredientItem
// 0x14fb4c IngredientItem::~IngredientItem
// 0x14fb58 IngredientItem::~IngredientItem
// 0x14fb64 IngredientItem::~IngredientItem
// 0x14fd10 IngredientItem::GetData1
// 0x1502a0 SpellItem::Function1502a0
// 0x150db0 SpellItem::Function150db0
// 0x150dd0 SpellItem::Function150dd0
// 0x154be4 ScrollItem::~ScrollItem
// 0x154bf0 ScrollItem::~ScrollItem
// 0x154bfc ScrollItem::~ScrollItem
// 0x154c08 ScrollItem::~ScrollItem
// 0x154c2c ScrollItem::~ScrollItem
// 0x154c38 ScrollItem::~ScrollItem
// 0x154c44 ScrollItem::~ScrollItem
// 0x154c50 ScrollItem::~ScrollItem
// 0x154d00 SpellItem::GetData1
// 0x155bf4 SpellItem::~SpellItem
// 0x155c00 SpellItem::~SpellItem
// 0x155c0c SpellItem::~SpellItem
// 0x28f198 TESSoulGem::~TESSoulGem
// 0x28f1a4 TESSoulGem::~TESSoulGem
// 0x28f1b0 TESSoulGem::~TESSoulGem
// 0x28f1bc TESSoulGem::~TESSoulGem
// 0x28f1c8 TESSoulGem::~TESSoulGem
// 0x28f1d4 TESSoulGem::~TESSoulGem
// 0x4221e0 TESSoulGem::GetSoulLevel
#include "MagicItem_146428.h"

// lesserSoulMinimumLevel, commonSoulMinimumLevel, greaterSoulMinimumLevel, grandSoulMinimumLevel: GUESS(low)
extern const std::uint32_t lesserSoulMinimumLevel;
extern const std::uint32_t commonSoulMinimumLevel;
extern const std::uint32_t greaterSoulMinimumLevel;
extern const std::uint32_t grandSoulMinimumLevel;

AlchemyItem::AlchemyItem()
{
}

IngredientItem::IngredientItem()
{
}

ScrollItem::ScrollItem()
{
}

SpellItem::SpellItem()
{
}

TESSoulGem::TESSoulGem()
{
}

const MagicItem::Data* AlchemyItem::GetData1() const
{
    return &data;
}

const MagicItem::Data* IngredientItem::GetData1() const
{
    return &data;
}

const MagicItem::Data* SpellItem::GetData1() const
{
    return &data;
}

bool SpellItem::Function1502a0() const
{
    return GetDelivery() == MagicSystem::Delivery::kSelf;
}

bool SpellItem::Function150db0() const
{
    if (const auto* request = preloadedItem) {
        return request->unk0C == 5;
    }
    return false;
}

std::uint32_t SpellItem::Function150dd0() const
{
    std::uint32_t pending = 0;
    if (const auto* request = preloadedItem) {
        pending = request->unk0C != 5;
    }
    return pending;
}

SOUL_LEVEL TESSoulGem::GetSoulLevel(std::uint32_t actorLevel, bool useGrandSoul)
{
    if (useGrandSoul || actorLevel >= grandSoulMinimumLevel) {
        return SOUL_LEVEL::kGrand;
    }
    if (actorLevel >= greaterSoulMinimumLevel) {
        return SOUL_LEVEL::kGreater;
    }
    if (actorLevel >= commonSoulMinimumLevel) {
        return SOUL_LEVEL::kCommon;
    }
    return actorLevel < lesserSoulMinimumLevel ? SOUL_LEVEL::kPetty : SOUL_LEVEL::kLesser;
}
