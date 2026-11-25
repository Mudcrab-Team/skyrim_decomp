// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: original hand-written reconstruction; community names and minimal declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, TESForm, TESObjectWEAP, TESObjectBOOK, BGSMenuDisplayObject, BaseFormComponent, FormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// formType, firstPersonModelObject, inventoryModel, GetMenuDisplayObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Spell, Shout, MagicEffect, Weapon, Book: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Inventory3DManager::GetInventoryModel, GetMenuDisplayComponent: GUESS(low); inferred form model selection
#pragma once
#include <cstdint>

enum class FormType : std::uint8_t { MagicEffect = 0x12, Spell = 0x16, Book = 0x1B, Weapon = 0x29, Shout = 0x77 };
struct TESForm
{
    std::uint8_t unused[0x1A];
    FormType formType;
};
struct TESObjectWEAP : TESForm
{
    std::uint8_t unused1b[0x200 - 0x1B];
    TESForm* firstPersonModelObject;
};
struct TESObjectBOOK : TESForm
{
    std::uint8_t unused1b[0x120 - 0x1B];
    TESForm* inventoryModel;
};
class BaseFormComponent;
class BGSMenuDisplayObject
{
public:
    virtual ~BGSMenuDisplayObject();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent*);
    virtual TESForm* GetMenuDisplayObject() const;
};
// InitializeDataComponent, ClearDataComponent, CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unused, unused1b: GUESS(low); unrepresented fields
BGSMenuDisplayObject* GetMenuDisplayComponent(TESForm* form);
class Inventory3DManager
{
public:
    // 0x93e6b0 Inventory3DManager::GetInventoryModel
    TESForm* GetInventoryModel(TESForm* form);
};
