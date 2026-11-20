// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original body written from the local listing; declarations from CommonLibSSE-NG.
// Adapted bodies: none
// 0x152d950 BSBloodSplatterShaderProperty::ForEachTexture
// 0x152d8a0 BSBloodSplatterShaderProperty::QShader
// 0x152db70 BSBloodSplatterShaderProperty::GetBaseTexture
#include "BSBloodSplatterShaderProperty.h"

std::int32_t BSBloodSplatterShaderProperty::QShader()
{
    return 12;
}

NiSourceTexture* BSBloodSplatterShaderProperty::GetBaseTexture()
{
    return textures[0];
}

std::int32_t BSBloodSplatterShaderProperty::ForEachTexture(ForEachVisitor& a_visitor)
{
    std::int32_t result;
    for (std::uint32_t i = 0; i < 3; ++i) {
        result = a_visitor.Accept(textures[i]);
        if (result <= 0) {
            break;
        }
    }
    return result;
}
