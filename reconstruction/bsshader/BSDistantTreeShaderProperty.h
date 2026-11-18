// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSDistantTreeShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSDistantTreeShaderProperty::GetBaseTexture: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown88: GUESS(low)
#pragma once

#include <cstdint>
#include "BSShaderProperty.h"

class BSDistantTreeShaderProperty : public BSShaderProperty
{
public:
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x1558eb0

    std::uint8_t unknown88[0x8];  // 88
    // baseTexture: GUESS(low)
    NiSourceTexture* baseTexture;  // 90
    std::uint8_t unknown98[0x18];  // 98
};
static_assert(sizeof(BSDistantTreeShaderProperty) == 0xB0, "BSDistantTreeShaderProperty size");
