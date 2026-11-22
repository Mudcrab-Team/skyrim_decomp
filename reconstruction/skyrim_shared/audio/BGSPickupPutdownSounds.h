// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: original declarations from the pinned image and labelled community layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPickupPutdownSounds: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSPickupPutdownSounds::ClearDataComponent, BGSPickupPutdownSounds::InitializeDataComponent, BGSPickupPutdownSounds::~BGSPickupPutdownSounds: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sound descriptor pointer types: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm: STANDIN EXE_RTTI
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESForm : public BaseFormComponent {};
class BGSSoundDescriptorForm;

class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    BGSPickupPutdownSounds();
    virtual void ClearDataComponent();  // compared: 0x1db710
    virtual void InitializeDataComponent();  // compared: 0x1db6f0
    virtual ~BGSPickupPutdownSounds();  // compared: 0x1db880 (scalar deleting destructor)

    static BGSSoundDescriptorForm* GetPickupSound(TESForm* a_form);
    static BGSSoundDescriptorForm* GetPutdownSound(TESForm* a_form);

    BGSSoundDescriptorForm* field08;  // 08
    BGSSoundDescriptorForm* field10;  // 10
};
static_assert(sizeof(BGSPickupPutdownSounds) == 0x18, "BGSPickupPutdownSounds size");
