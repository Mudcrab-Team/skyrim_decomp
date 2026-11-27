// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESRaceForm.cpp:74
// TESRaceForm, TESRaceForm::~TESRaceForm, InitializeDataComponent, ClearDataComponent, CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRaceForm::GetFormRace: SIBLING(fo4-private@1b765c70, author-permission)
// race: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the sibling names the member pFormRace
// TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"
#include "declarations/TESForm.h"

class TESRace;

class TESRaceForm : public BaseFormComponent
{
public:
    ~TESRaceForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    static TESRace* GetFormRace(TESForm* a_form);  // compared: 0x1ef880

    TESRace* race;  // 08
};
static_assert(sizeof(TESRaceForm) == 0x10, "TESRaceForm size");
