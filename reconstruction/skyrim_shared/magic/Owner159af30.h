// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier. Stamped as a twin of matched 0x14fd00 (skyrim_shared/magic/IngredientItem): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function159af30, Owner159af30: GUESS(low) STANDIN
// GetAssociatedSkill, Data, costOverride, flags, data, GetIngredientSkillUseModifier, unk08: GUESS(low) STANDIN
#pragma once
#include "IngredientItem.h"

class Owner159af30
{
public:
    struct Data
    {
        std::int32_t costOverride;  // 00
        std::uint32_t flags;  // 04
    };

    virtual std::uint32_t GetAssociatedSkill() const;
    Data* Function159af30();
    float GetIngredientSkillUseModifier() const;

    std::uint8_t unk08[0x128];  // 08
    Data data;  // 130
};

