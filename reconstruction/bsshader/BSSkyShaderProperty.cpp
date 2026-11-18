// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x1553540 BSSkyShaderProperty::QShader
// 0x1553930 BSSkyShaderProperty::GetBaseTexture
#include "BSSkyShaderProperty.h"

std::int32_t BSSkyShaderProperty::QShader()
{
    return 10;
}

NiSourceTexture* BSSkyShaderProperty::GetBaseTexture()
{
    return unk98;
}
