// Source exposure: mixed (community declarations, permitted sibling, local target).
// Code origin: minimal declarations reconstructed using the labelled sources and local layout observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnchantmentItem, MagicItem, EffectSetting, EffectSettingData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// effects, data, flags, archetype: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EnchantmentItem::CanAddEffect, EnchantmentItem::EnchantmentItemFilterValidationFunction, MagicItem::HasEffect: SIBLING(fo4-private@1b765c70, author-permission)
// EffectArchetypes: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectArchetypes::Archetypes: GUESS(low); stand-in name for the locally observed archetype table.
// EffectArray, ArchetypeData, associatedFormType, TestBit: GUESS(low); minimal array/table declarations and bit-index helper.
// unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk04, capacity, pad0C, size, pad14: GUESS(low); unaccessed storage or array bookkeeping.
// 0x14ddb0 EnchantmentItem::CanAddEffect
#pragma once

#include <cstddef>
#include <cstdint>

struct EffectSettingData
{
    std::uint32_t flags;
    std::uint32_t unk04;
    std::uint64_t unk08, unk10, unk18, unk20, unk28;
    std::uint64_t unk30, unk38, unk40, unk48, unk50;
    std::int32_t archetype;
};

class EffectSetting
{
public:
    std::uint64_t unk00, unk08, unk10, unk18, unk20, unk28;
    std::uint64_t unk30, unk38, unk40, unk48, unk50, unk58, unk60;
    EffectSettingData data;
};

struct EffectArray
{
    void** data;
    std::uint32_t capacity, pad0C;
    std::uint32_t size, pad14;
};

class MagicItem
{
public:
    bool HasEffect(std::uint32_t mask) const;
    std::uint64_t unk00, unk08, unk10, unk18, unk20, unk28;
    std::uint64_t unk30, unk38, unk40, unk48, unk50;
    EffectArray effects;
};

struct ArchetypeData
{
    std::int32_t associatedFormType;
    std::uint32_t unk04;
    std::uint64_t unk08, unk10;
};

class EffectArchetypes
{
public:
    static ArchetypeData Archetypes[];
};

class EnchantmentItem : public MagicItem
{
public:
    bool CanAddEffect(EffectSetting* effect);
    static bool EnchantmentItemFilterValidationFunction(EffectSetting* effect, void* validationItem);
};

static_assert(offsetof(EffectSetting, data) == 0x68, "Effect data offset");
static_assert(offsetof(EffectSettingData, archetype) == 0x58, "Archetype offset");
static_assert(offsetof(MagicItem, effects) + offsetof(EffectArray, size) == 0x68, "Effect count offset");
static_assert(sizeof(ArchetypeData) == 24, "Archetype table stride");
