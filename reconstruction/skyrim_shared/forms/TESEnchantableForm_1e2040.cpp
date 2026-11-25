// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESEnchantableForm.cpp:106
// 0x1e2040 TESEnchantableForm::GetFormBaseCharge
#include "TESEnchantableForm_1e2040.h"

std::uint16_t TESEnchantableForm::GetFormBaseCharge(TESForm* a_form, const ExtraDataList* a_extra)
{
    std::uint16_t result = 0;
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(a_form);
    if (enchantable) {
        result = enchantable->amountofEnchantment;
        if (result)
            return result;
    }
    if (a_extra)
        return a_extra->GetBaseCharge();
    return result;
}
