// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG.
// Adapted bodies: none.
// 0x153b2d0 BSShaderTextureSet::IsEqual
// 0x153b3c0 BSShaderTextureSet::GetTexturePath
#include "BSShaderTextureSet.h"

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
