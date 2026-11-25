// 0x93e6b0 Inventory3DManager::GetInventoryModel
// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: original hand-written reconstruction; community names and minimal declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager::GetInventoryModel: GUESS(low); inferred form model selection
#include "Inventory3DManager_93e6b0.h"

TESForm* Inventory3DManager::GetInventoryModel(TESForm* form)
{
    const auto type = form->formType;
    if (type == FormType::Spell || type == FormType::Shout || type == FormType::MagicEffect) {
        auto* component = GetMenuDisplayComponent(form);
        return component ? component->GetMenuDisplayObject() : nullptr;
    }
    if (type == FormType::Weapon) {
        return static_cast<TESObjectWEAP*>(form)->firstPersonModelObject;
    }
    if (type == FormType::Book) {
        return static_cast<TESObjectBOOK*>(form)->inventoryModel;
    }
    return form;
}
