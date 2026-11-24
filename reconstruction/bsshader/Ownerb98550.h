// Code origin: original; declarations from CommonLibSSE-NG, bodies written from the listing of the pinned image. Stamped as a twin of matched 0x153b3c0 (bsshader/BSShaderTextureSet): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Texture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG nests it in BSTextureSet::Textures
// as std::int32_t, signed here because the target sign-extends the index (MOVSXD)
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Ownerb98550: GUESS(low) STANDIN
// BSTextureSet, texturePaths, texturePathStrings: GUESS(low) STANDIN
#pragma once
#include "BSShaderTextureSet.h"

class Ownerb98550 : public BSTextureSet
{
public:
    virtual void LoadBinary(NiStream& a_stream) override;
    virtual bool IsEqual(NiObject* a_object) override;
    virtual const char* GetTexturePath(Texture a_texture);

    // reads them by index as plain pointers, and LoadBinary fills them as fixed strings.
    union
    {
        const char* texturePaths[0x9];            // 10
        BSFixedString texturePathStrings[0x9];    // 10
    };
};
static_assert(sizeof(Ownerb98550) == 0x58, "Ownerb98550 size");
