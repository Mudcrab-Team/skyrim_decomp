// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:169
// TESTexture, textureName, ~TESTexture, InitializeDataComponent, ClearDataComponent, CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture::GetTextureNameLength: SIBLING(fo4-private@1b765c70, author-permission)
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// QLength: GUESS(low); the sibling names its length accessor this way
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"
#include "declarations/TESForm.h"

struct BSFixedString
{
    std::uint32_t QLength() const;

    const char* data;  // 00
};

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    static std::uint32_t GetTextureNameLength(TESForm* a_form);  // compared: 0x1f3200

    BSFixedString textureName;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");
