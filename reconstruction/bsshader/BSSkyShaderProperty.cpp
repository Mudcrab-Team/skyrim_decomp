// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original body written from the local listing; declarations from powerof3/CommonLibSSE and CommonLibSSE-NG.
// Adapted bodies: none
// 0x1553750 BSSkyShaderProperty::ForEachTexture
// 0x1553540 BSSkyShaderProperty::QShader
// 0x1553930 BSSkyShaderProperty::GetBaseTexture
#include "BSSkyShaderProperty.h"

std::int32_t BSSkyShaderProperty::QShader()
{
    return 10;
}

NiSourceTexture* BSSkyShaderProperty::GetBaseTexture()
{
    return textures[0];
}

std::int32_t BSSkyShaderProperty::ForEachTexture(ForEachVisitor& a_visitor)
{
    std::int32_t result;
    for (std::int64_t i = 0; i < 3; ++i) {
        result = a_visitor.Accept(textures[i]);
        if (result <= 0) {
            break;
        }
    }
    return result;
}
