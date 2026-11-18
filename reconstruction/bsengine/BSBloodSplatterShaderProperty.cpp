// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x152d8a0 BSBloodSplatterShaderProperty::QShader
// 0x152db70 BSBloodSplatterShaderProperty::GetBaseTexture
#include "BSBloodSplatterShaderProperty.h"

std::int32_t BSBloodSplatterShaderProperty::QShader()
{
    return 12;
}

NiSourceTexture* BSBloodSplatterShaderProperty::GetBaseTexture()
{
    return unk88;
}
