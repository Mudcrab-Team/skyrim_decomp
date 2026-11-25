// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only. IsEqual and GetTexturePath are the existing bodies, unchanged.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: the NiBinaryStream read template in BSShaderTextureSet.h is adapted from
// CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiBinaryStream.h under its MIT licence.
// 0x153b1b0 BSShaderTextureSet::LoadBinary
// 0x153b2d0 BSShaderTextureSet::IsEqual
// 0x153b3c0 BSShaderTextureSet::GetTexturePath
#include "BSShaderTextureSet.h"

// LoadBinary: reads the texture count and then one fixed string per slot.
void BSShaderTextureSet::LoadBinary(NiStream& a_stream)
{
    NiObject::LoadBinary(a_stream);

    std::int32_t numTextures = 0;
    a_stream.iStr->read(&numTextures, 1);
    for (std::int32_t i = 0; i < numTextures; i++) {
        a_stream.LoadFixedStringLegacy(texturePathStrings[i]);
    }
}

// Body done: RVA 0x153b3c0, 9 bytes, BSShaderTextureSet::GetTexturePath.
const char* BSShaderTextureSet::GetTexturePath(Texture a_texture)
{
    return texturePaths[a_texture];
}

// IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
bool BSShaderTextureSet::IsEqual(NiObject*)
{
    return false;
}
