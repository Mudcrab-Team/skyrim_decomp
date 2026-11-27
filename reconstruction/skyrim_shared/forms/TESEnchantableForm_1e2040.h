// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESEnchantableForm.cpp:106
// TESEnchantableForm, ~TESEnchantableForm, InitializeDataComponent, ClearDataComponent, CopyComponent, GetCastingType, formEnchanting, castingType, amountofEnchantment, pad14, EnchantmentItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESEnchantableForm::GetFormBaseCharge: SIBLING(fo4-private@1b765c70, author-permission)
// GetBaseCharge: SIBLING(fo4-private@1b765c70, author-permission)
// ExtraDataList: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"
#include "declarations/TESForm.h"

class EnchantmentItem;

class ExtraDataList
{
public:
    std::uint16_t GetBaseCharge() const;
};

class TESEnchantableForm : public BaseFormComponent
{
public:
    ~TESEnchantableForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    virtual std::uint32_t GetCastingType() const;  // 04

    static std::uint16_t GetFormBaseCharge(TESForm* a_form, const ExtraDataList* a_extra);  // compared: 0x1e2040

    EnchantmentItem* formEnchanting;  // 08
    std::uint16_t castingType;  // 10
    std::uint16_t amountofEnchantment;  // 12
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(TESEnchantableForm) == 0x18, "TESEnchantableForm size");
