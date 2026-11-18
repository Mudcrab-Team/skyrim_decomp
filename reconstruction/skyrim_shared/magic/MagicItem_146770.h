// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent, TESForm, TESObject, TESBoundObject: STANDIN EXE_RTTI
// MagicItem::GetMaxEffectCount, MagicItem::IsMedicine, MagicItem::LoadMagicItemChunk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08, unknown20, unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESFile;

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
    virtual std::uint32_t GetMaxEffectCount() const;  // compared: 0x146770
    virtual bool IsMedicine() const;  // compared: 0x14e7c0
    virtual void LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID);  // compared: 0x14e830

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0x60];  // 30
};
static_assert(sizeof(MagicItem) == 0x90, "MagicItem size");
