// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IngredientItem, GetAssociatedSkill, GetData2, Data, costOverride, flags, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// GetIngredientSkillUseModifier, g_fAlchemyIngredientInitMult, g_fAlchemySkillUsageMult, unk08: GUESS(low)
#pragma once
#include <cstdint>

extern float g_fAlchemyIngredientInitMult;
extern float g_fAlchemySkillUsageMult;

class IngredientItem
{
public:
    struct Data
    {
        std::int32_t costOverride;  // 00
        std::uint32_t flags;  // 04
    };

    virtual std::uint32_t GetAssociatedSkill() const;
    Data* GetData2();
    float GetIngredientSkillUseModifier() const;

    std::uint8_t unk08[0x128];  // 08
    Data data;  // 130
};
