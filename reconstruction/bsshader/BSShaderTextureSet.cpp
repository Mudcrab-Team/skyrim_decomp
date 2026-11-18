// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x153b3c0 BSShaderTextureSet::GetTexturePath
#include "BSShaderTextureSet.h"

// Body done: RVA 0x153b3c0, 9 bytes, BSShaderTextureSet::GetTexturePath.
const char* BSShaderTextureSet::GetTexturePath(Texture a_texture)
{
    return texturePaths[a_texture];
}
