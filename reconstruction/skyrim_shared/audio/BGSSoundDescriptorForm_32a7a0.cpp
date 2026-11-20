// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x32a7a0 BGSSoundDescriptorForm::Function32a7a0
// 0x32a7e0 BGSSoundDescriptorForm::GetDescriptorType
// 0x559a10 BGSSoundDescriptorForm::Function559a10
// 0x559a70 BGSSoundDescriptorForm::Function559a70
#include "BGSSoundDescriptorForm_32a7a0.h"

// GetFormForID, Function559b30, SoundDescriptorFromForm, soundType, soundRecordType: GUESS(low)
TESForm* GetFormForID(std::uint32_t formID);
TESForm* Function559b30(const char* editorID);

static BGSSoundDescriptorForm* SoundDescriptorFromForm(TESForm* form)
{
    constexpr auto soundType = static_cast<FormType>(0x0F);
    constexpr auto soundRecordType = static_cast<FormType>(0x80);
    BGSSoundDescriptorForm* descriptor = nullptr;
    if (form) {
        const auto type = form->formType;
        if (type == soundType) {
            const auto initialized = static_cast<std::uint8_t>(form->formFlags >> 3) & 1u;
            if (!initialized) {
                form->InitItemImpl();
            }
            return static_cast<TESSound*>(form)->descriptor;
        }
        if (type == soundRecordType) {
            descriptor = static_cast<BGSSoundDescriptorForm*>(form);
        }
    }
    return descriptor;
}

float BGSSoundDescriptorForm::Function32a7a0() const
{
    if (soundDescriptor) {
        return soundDescriptor->Unk_06();
    }
    return 0.0f;
}

std::uint32_t BGSSoundDescriptorForm::GetDescriptorType()
{
    return soundDescriptor->GetType();
}

BGSSoundDescriptorForm* BGSSoundDescriptorForm::Function559a10(std::uint32_t id)
{
    return SoundDescriptorFromForm(GetFormForID(id));
}

BGSSoundDescriptorForm* BGSSoundDescriptorForm::Function559a70(const char* editorID)
{
    return SoundDescriptorFromForm(Function559b30(editorID));
}
