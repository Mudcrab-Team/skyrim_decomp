// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:169
// 0x1f3200 TESTexture::GetTextureNameLength
#include "TESTexture_1f3200.h"

std::uint32_t TESTexture::GetTextureNameLength(TESForm* a_form)
{
    TESTexture* texture = dynamic_cast<TESTexture*>(a_form);
    if (texture)
        return texture->textureName.QLength();
    return 0;
}
