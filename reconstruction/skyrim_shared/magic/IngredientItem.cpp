// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14fcd0 IngredientItem::GetAssociatedSkill
// 0x14fd00 IngredientItem::GetData2
// 0x14f510 IngredientItem::GetIngredientSkillUseModifier
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
