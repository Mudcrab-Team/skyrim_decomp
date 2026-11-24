// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSoundCategory, BSISoundCategory, BSISoundCategory::Matches, ::GetCategoryVolume, ::SetCategoryVolume, ::GetCategoryFrequency, ::SetCategoryFrequency, ::GetCategoryAttenuation, ::SetCategoryAttenuation, ::Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSoundCategory::Function3299f0, ::unk08, ::unk18, ::parent: GUESS(low); parent is NG's parentCategory, unk18 is NG's unk48; this class is a view of NG's BSISoundCategory subobject at +0x30 of BGSSoundCategory
// BGSSoundCategoryForm, BGSSoundCategoryForm::category, ::unk00: GUESS(low); the full form, only its interface subobject at +0x30 is used
#pragma once

#include <cstdint>
#include <cstddef>

// BSISoundCategory: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 00 to 08
class BSISoundCategory
{
public:
    virtual ~BSISoundCategory();                                    // 00
    virtual bool Matches(const BSISoundCategory* a_category) const;  // 01
    virtual float GetCategoryVolume() const;                         // 02
    virtual void SetCategoryVolume(float a_value);                   // 03
    virtual float GetCategoryFrequency() const;                      // 04
    virtual void SetCategoryFrequency(float a_value);                // 05
    virtual std::uint16_t GetCategoryAttenuation() const;            // 06
    virtual void SetCategoryAttenuation(std::uint16_t a_value);      // 07
    virtual bool Unk_08();                                           // 08
};

struct BGSSoundCategoryForm
{
    std::uint8_t unk00[0x30];
    BSISoundCategory category;  // 30
};

class BGSSoundCategory : public BSISoundCategory
{
public:
    // compared: 0x3299f0; true when this category's bit 1 is set or any parent reports true
    bool Function3299f0();

    std::uint64_t unk08;            // 08
    BGSSoundCategoryForm* parent;   // 10
    std::uint16_t unk18;            // 18; NG's unk48 (uint16) of the full form
};
static_assert(offsetof(BGSSoundCategory, parent) == 0x10, "parent offset");
static_assert(offsetof(BGSSoundCategory, unk18) == 0x18, "unk18 offset");
