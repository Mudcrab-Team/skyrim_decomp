// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Code origin: original; the listing and community declarations only
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// IngredientItem: EXE_RTTI
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// IngredientItem::Function14ef00: GUESS(low); marks one effect as known and records the change
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14fcd0 IngredientItem::GetAssociatedSkill
// 0x14ef00 IngredientItem::Function14ef00
#include "IngredientItem.h"
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t IngredientItem::GetAssociatedSkill() const
{
    return 0x10;
}

bool IngredientItem::Function14ef00(std::uint32_t a_index)
{
    knownEffectFlags |= 1 << a_index;
    return AddChange(0x80000000);
}
