// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IngredientItem, IngredientItem::LearnAllEffects, IngredientItem::AddChange, IngredientItem::knownEffectFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// IngredientItem::unk00, IngredientItem::pad08, IngredientItem::LearnEffectBit: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class IngredientItem
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual bool AddChange(std::uint32_t changeFlags);  // slot 0x0A

    void LearnAllEffects();  // compared: 0x14ef30

    std::uint8_t pad08[0x130];
    std::uint16_t knownEffectFlags;  // 0x138
};
