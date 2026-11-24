// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSFeaturedItemMessage.cpp:51
// BGSSkinForm, BGSSkinForm::~BGSSkinForm, BGSSkinForm::InitializeDataComponent, BGSSkinForm::ClearDataComponent, BGSSkinForm::CopyComponent, skin: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSkinForm::GetSkin: GUESS(low); the sibling names the same shape GetFeaturedItemMessage
// TESObjectARMO: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/BaseFormComponent.h"
#include "declarations/TESForm.h"

class TESObjectARMO;

class BGSSkinForm : public BaseFormComponent
{
public:
    ~BGSSkinForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    static TESObjectARMO* GetSkin(TESForm* a_form);  // compared: 0x1dba20

    TESObjectARMO* skin;  // 08
};
static_assert(sizeof(BGSSkinForm) == 0x10, "BGSSkinForm size");
