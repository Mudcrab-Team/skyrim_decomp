// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderTextureSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTextureSet: STANDIN EXE_RTTI
// BSShaderTextureSet::GetTexturePath, BSShaderTextureSet::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// texturePaths: GUESS(low); element count is the padding that was split off, the target indexes it by Texture
// Texture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG nests it in BSTextureSet::Textures
// as std::uint32_t, signed here because the target sign-extends the index (MOVSXD)
#pragma once

#include <cstdint>
#include "gamebryo/nimain/NiObject.h"

enum Texture : std::int32_t
{
};

class BSTextureSet : public NiObject
{
public:
};
static_assert(sizeof(BSTextureSet) == 0x10, "BSTextureSet size");

class BSShaderTextureSet : public BSTextureSet
{
public:
    virtual bool IsEqual(NiObject* a_object) override;
    virtual const char* GetTexturePath(Texture a_texture);  // compared: 0x153b3c0

    // Path pointers, one per texture slot, read by index in GetTexturePath.
    const char* texturePaths[0x9];  // 10
};
static_assert(sizeof(BSShaderTextureSet) == 0x58, "BSShaderTextureSet size");
