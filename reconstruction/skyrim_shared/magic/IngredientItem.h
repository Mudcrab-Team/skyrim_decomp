// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IngredientItem, GetAssociatedSkill, GetData2, Data, costOverride, flags, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// GetIngredientSkillUseModifier, g_fAlchemyIngredientInitMult, g_fAlchemySkillUsageMult, unk08: GUESS(low)
// Function14ef00, OnFlagsChanged, bitFlags, VFunc01..VFunc09: GUESS(low)
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
    // VFunc01: GUESS(low)
    virtual void VFunc01();  // slot 01 guess(low)
    // VFunc02: GUESS(low)
    virtual void VFunc02();  // slot 02 guess(low)
    // VFunc03: GUESS(low)
    virtual void VFunc03();  // slot 03 guess(low)
    // VFunc04: GUESS(low)
    virtual void VFunc04();  // slot 04 guess(low)
    // VFunc05: GUESS(low)
    virtual void VFunc05();  // slot 05 guess(low)
    // VFunc06: GUESS(low)
    virtual void VFunc06();  // slot 06 guess(low)
    // VFunc07: GUESS(low)
    virtual void VFunc07();  // slot 07 guess(low)
    // VFunc08: GUESS(low)
    virtual void VFunc08();  // slot 08 guess(low)
    // VFunc09: GUESS(low)
    virtual void VFunc09();  // slot 09 guess(low)
    // OnFlagsChanged: GUESS(low)
    virtual void OnFlagsChanged(std::uint32_t mask);  // slot 10 guess(low)
    Data* GetData2();
    float GetIngredientSkillUseModifier() const;

    std::uint8_t unk08[0x128];  // 08
    Data data;  // 130
    std::uint16_t bitFlags;  // 138
    void Function14ef00(std::uint32_t bit);
};
