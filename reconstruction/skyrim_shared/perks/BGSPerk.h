// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, bases, members and declarations
// from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); no body is copied from any source.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPerk, BGSPerk::InitializeData, BGSPerk::~BGSPerk, BGSPerk::ClearData, BGSPerk::Load, BGSPerk::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFullName, TESDescription, TESTexture, TESIcon, TESCondition, BSFixedString, BSTArray, BGSPerkEntry, PerkData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFullName::fullName, TESDescription::fileOffset, TESDescription::descriptionText, TESTexture::textureName, PerkData::trait, PerkData::level, PerkData::numRanks, PerkData::playable, PerkData::hidden, BGSPerk::data, BGSPerk::pad55, BGSPerk::pad56, BGSPerk::perkConditions, BGSPerk::perkEntries, BGSPerk::nextPerk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSFixedString::_data, TESCondition::head, BSTArray::_data, BSTArray::_capacity, BSTArray::_pad0C, BSTArray::_size, BSTArray::_pad14: STANDIN GUESS(low); layout-only placeholders
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class BGSPerkEntry;
class TESConditionItem;
class TESForm;

class BSFixedString
{
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

// Layout of NG's BSTArray with the default heap allocator: data and capacity first, then the element count.
template <class T>
class BSTArray
{
public:
    T* _data;  // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t _pad0C;  // 0C
    std::uint32_t _size;  // 10
    std::uint32_t _pad14;  // 14
};
static_assert(sizeof(BSTArray<void*>) == 0x18, "BSTArray size");

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual std::uint32_t GetFullNameLength() const;  // 04
    virtual const char* GetFullName() const;  // 05

    BSFixedString fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");

class TESDescription : public BaseFormComponent
{
public:
    ~TESDescription() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    std::uint32_t fileOffset;  // 08
    std::uint32_t descriptionText;  // 0C, NG: BGSLocalizedStringDL (one 32-bit id)
};
static_assert(sizeof(TESDescription) == 0x10, "TESDescription size");

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual std::uint32_t GetMaxAllowedSize();  // 04
    virtual const char* GetAsNormalFile(void* a_out) const;  // 05
    virtual const char* GetDefaultPath() const;  // 06

    BSFixedString textureName;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");

class TESIcon : public TESTexture
{
public:
    ~TESIcon() override;  // 00
    const char* GetDefaultPath() const override;  // 06
};
static_assert(sizeof(TESIcon) == 0x10, "TESIcon size");

class TESCondition
{
public:
    TESConditionItem* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

struct PerkData
{
    bool trait;  // 0
    std::int8_t level;  // 1
    std::int8_t numRanks;  // 2
    bool playable;  // 3
    bool hidden;  // 4
};
static_assert(sizeof(PerkData) == 0x5, "PerkData size");

class BGSPerk : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
public:
    ~BGSPerk() override;  // 00
    void InitializeData() override;  // 04, compared: 0x396b40
    void ClearData() override;  // 05
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13

    PerkData data;  // 50
    std::uint8_t pad55;  // 55
    std::uint16_t pad56;  // 56
    TESCondition perkConditions;  // 58
    BSTArray<BGSPerkEntry*> perkEntries;  // 60
    BGSPerk* nextPerk;  // 78
};
static_assert(sizeof(BGSPerk) == 0x80, "BGSPerk size");
static_assert(offsetof(BGSPerk, data) == 0x50, "data offset");
static_assert(offsetof(BGSPerk, nextPerk) == 0x78, "nextPerk offset");
