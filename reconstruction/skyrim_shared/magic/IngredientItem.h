// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// IngredientItem: EXE_RTTI
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IngredientItem::GetData2, IngredientItem::IsFood, IngredientItem::InitChunk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// IngredientItem::GetIngredientSkillUseModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// gIngredientSkillUseModifier, gSkillUseModifierIdentity, gIngredientSkillUseModifierFallback: GUESS(low); float globals read by GetIngredientSkillUseModifier
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
extern "C" float gIngredientSkillUseModifier;
extern "C" float gSkillUseModifierIdentity;
extern "C" float gIngredientSkillUseModifierFallback;
struct IngredientData
{
    std::int32_t cost;   // 00
    std::uint32_t flags;  // 04
};
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class IngredientItem
{
public:
    virtual std::uint32_t GetAssociatedSkill() const;
    virtual IngredientData* GetData2();
    float GetIngredientSkillUseModifier();

private:
    std::uint64_t pad[0x130 / 8 - 1];  // 08 .. 130
    IngredientData data;  // 130
};
