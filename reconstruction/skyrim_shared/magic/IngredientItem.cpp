// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14f510 IngredientItem::GetIngredientSkillUseModifier
// 0x14fd00 IngredientItem::GetData2
// 0x14fcd0 IngredientItem::GetAssociatedSkill
// Adapted bodies: none
#include "IngredientItem.h"
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t IngredientItem::GetAssociatedSkill() const
{
    return 0x10;
}
// IngredientItem::GetData2, IngredientItem::IsFood, IngredientItem::InitChunk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
IngredientData* IngredientItem::GetData2() { return &data; }
// IngredientItem::GetIngredientSkillUseModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
float IngredientItem::GetIngredientSkillUseModifier()
{
    const float modifier = gIngredientSkillUseModifier;
    if (modifier != gSkillUseModifierIdentity)
        return modifier;
    return gIngredientSkillUseModifierFallback;
}
