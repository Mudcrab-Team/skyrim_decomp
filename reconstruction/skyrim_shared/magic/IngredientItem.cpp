// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier.; written for this reconstruction from the listing; names from the header, vtable slot placeholders are guess(low)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14fcd0 IngredientItem::GetAssociatedSkill
// 0x14fd00 IngredientItem::GetData2
// 0x14f510 IngredientItem::GetIngredientSkillUseModifier
// 0x14ef00 IngredientItem::Function14ef00
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "IngredientItem.h"

std::uint32_t IngredientItem::GetAssociatedSkill() const
{
    return 0x10;
}

IngredientItem::Data* IngredientItem::GetData2()
{
    return &data;
}

float IngredientItem::GetIngredientSkillUseModifier() const
{
    float value = g_fAlchemyIngredientInitMult;
    if (value == -1.0f) {
        return g_fAlchemySkillUsageMult;
    }
    return value;
}

// IngredientItem::Function14ef00: GUESS(low)
void IngredientItem::Function14ef00(std::uint32_t bit)
{
    bitFlags = static_cast<std::uint16_t>(bitFlags | (1u << bit));
    return OnFlagsChanged(0x80000000u);
}
