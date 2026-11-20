// Source exposure: mixed (pinned image, RTTI, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the attributed methods follow the public headers, with flag polarity from the pinned image.
// Adapted bodies: LoadEdit and form flag accessors follow CommonLibSSE-NG@b93280e include/RE/T/TESForm.h:131 and :144 (MIT).
// 0x1466a0 TESForm::GetDangerous
// 0x1466f0 TESForm::GetDescriptionOwnerFile
// 0x146750 TESForm::GetKnown
// 0x146790 TESForm::GetMustUpdate
// 0x1467d0 TESForm::GetObstacle
// 0x1467e0 TESForm::GetOnLocalMap
// 0x1467f0 TESForm::GetPlayable
// 0x146800 TESForm::GetRandomAnim
// 0x146820 TESForm::GetSavedFormType
// 0x1469a0 TESForm::LoadEdit
// 0x146a10 TESForm::QHasCurrents
// 0x1e0d00 TESForm::Function1e0d00
// 0x1e6900 TESForm::Function1e6900
#include "TESForm_1466a0.h"

bool TESForm::GetDangerous() const
{
    return (formFlags >> 17) & 1u;
}

TESFile* TESForm::GetDescriptionOwnerFile() const
{
    return GetFile(-1);
}

bool TESForm::GetKnown() const
{
    return (formFlags >> 6) & 1u;
}

bool TESForm::GetMustUpdate() const
{
    return (formFlags >> 8) & 1u;
}

bool TESForm::GetObstacle() const
{
    return (formFlags >> 25) & 1u;
}

bool TESForm::GetOnLocalMap() const
{
    return ~(formFlags >> 9) & 1u;
}

bool TESForm::GetPlayable() const
{
    return ~(formFlags >> 2) & 1u;
}

bool TESForm::GetRandomAnim() const
{
    return static_cast<std::uint8_t>(formFlags >> 16) & 1u;
}

FormType TESForm::GetSavedFormType() const
{
    return formType;
}

bool TESForm::LoadEdit(TESFile* file)
{
    return Load(file);
}

bool TESForm::QHasCurrents() const
{
    return (formFlags >> 19) & 1u;
}

bool TESForm::Function1e0d00(const TESForm* form)
{
    return form && form->formID == 0xF;
}

bool TESForm::Function1e6900(TESFile& file)
{
    return file.Function1ce0d0(this);
}
