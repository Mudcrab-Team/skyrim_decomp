// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from powerof3/CommonLibSSE.
// Adapted bodies: none.
// 0x1558cb0 BSDistantTreeShaderProperty::SetupGeometry
// 0x1558dc0 BSDistantTreeShaderProperty::Function1558dc0
// 0x1558eb0 BSDistantTreeShaderProperty::GetBaseTexture
#include "BSDistantTreeShaderProperty.h"

NiSourceTexture* BSDistantTreeShaderProperty::GetBaseTexture()
{
    return baseTexture;
}

bool BSDistantTreeShaderProperty::SetupGeometry(BSGeometry*)
{
    return true;
}

void BSDistantTreeShaderProperty::Function1558dc0()
{
    GetRenderPasses();
}
