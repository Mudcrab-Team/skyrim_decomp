// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// IngredientItem: EXE_RTTI
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// IngredientItem::knownEffectFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "declarations/TESForm.h"
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class IngredientItem : public TESForm
{
public:
    virtual std::uint32_t GetAssociatedSkill() const;

    bool Function14ef00(std::uint32_t a_index);

    std::uint8_t  padding[0x138 - 0x20];  // 020
    std::uint16_t knownEffectFlags;       // 138
    std::uint16_t pad13A;                 // 13A
    std::uint32_t pad13C;                 // 13C
};
static_assert(sizeof(IngredientItem) == 0x140, "IngredientItem size");
