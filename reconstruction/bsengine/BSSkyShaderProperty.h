// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSSkyShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSSkyShaderProperty::QShader, BSSkyShaderProperty::GetBaseTexture: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown88, unk98: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSShaderProperty.h"

class BSSkyShaderProperty : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();  // compared: 0x1553540
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x1553930

    std::uint8_t     unknown88[0x10];  // 88
    NiSourceTexture* unk98;            // 98
    std::uint8_t     unkA0[0x28];      // A0
};
static_assert(sizeof(BSSkyShaderProperty) == 0xC8, "BSSkyShaderProperty size");
