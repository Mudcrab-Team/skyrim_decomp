// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: IngredientItem::LearnNextEffect and LearnEffect from CommonLibSSE-NG b93280e, src/RE/I/IngredientItem.cpp, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IngredientItem, LearnNextEffect, LearnEffect, knownEffectFlags, virtual names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// Body source: adapted LearnNextEffect/LearnEffect, src/RE/I/IngredientItem.cpp at b93280e (MIT); return convention and layout independently checked locally.
// unknown08: GUESS(low); unaccessed range.
// 0x14ef80 IngredientItem::LearnNextEffect

#pragma once
#include <cstdint>
class TESFile;
class IngredientItem
{
public:
    virtual ~IngredientItem();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(void* rhs);
    virtual void InitializeData();
    virtual void ClearData();
    virtual bool Load(TESFile* file);
    virtual bool LoadPartial(TESFile* file);
    virtual bool LoadEdit(TESFile* file);
    virtual IngredientItem* CreateDuplicateForm(bool editorID, void* arg);
    virtual bool AddChange(std::uint32_t flags);
    std::uint32_t LearnNextEffect();
    bool LearnEffect(std::uint32_t index)
    {
        if (index < 4) {
            knownEffectFlags |= 1u << index;
            AddChange(0x80000000u);
            return true;
        }
        return false;
    }
    std::uint8_t unknown08[0x130];  // 08
    std::uint16_t knownEffectFlags;  // 138
};
