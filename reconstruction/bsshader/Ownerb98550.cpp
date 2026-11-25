// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only. IsEqual and GetTexturePath are the existing bodies, unchanged. Stamped as a twin of matched 0x153b3c0 (bsshader/BSShaderTextureSet): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiBinaryStream.h under its MIT licence.
// 0xb98550 Ownerb98550::GetTexturePath
#include "Ownerb98550.h"

const char* Ownerb98550::GetTexturePath(Texture a_texture)
{
    return texturePaths[a_texture];
}
