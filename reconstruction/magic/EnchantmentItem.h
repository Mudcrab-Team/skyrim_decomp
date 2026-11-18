// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// EnchantmentItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent, TESForm, TESObject, TESBoundObject, MagicItem: STANDIN EXE_RTTI
// EnchantmentItem::GetChunkID, EnchantmentItem::GetDataSize, EnchantmentItem::GetData1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItem::Data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08, unknown20, unknown30, unknown90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESForm : public BaseFormComponent
{
public:
};

class TESObject : public TESForm
{
public:
    std::uint8_t unknown08[0x18];  // 08
};
static_assert(sizeof(TESObject) == 0x20, "TESObject size");

class TESBoundObject : public TESObject
{
public:
    std::uint8_t unknown20[0x10];  // 20
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

class MagicItem : public TESBoundObject
{
public:
    struct Data;
    std::uint8_t unknown30[0x60];  // 30
};
static_assert(sizeof(MagicItem) == 0x90, "MagicItem size");

class EnchantmentItem : public MagicItem
{
public:
    virtual std::uint32_t GetChunkID();  // compared: 0x14e760
    virtual std::uint32_t GetDataSize() const;  // compared: 0x14e790
    virtual const MagicItem::Data* GetData1() const;  // compared: 0x14e780

    std::uint8_t unknown90[0x30];  // 90
};
static_assert(sizeof(EnchantmentItem) == 0xC0, "EnchantmentItem size");
