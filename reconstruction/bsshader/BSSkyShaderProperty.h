// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSSkyShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSSkyShaderProperty::QShader, BSSkyShaderProperty::GetBaseTexture, BSSkyShaderProperty::ForEachTexture: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown88, textures, unkB0: GUESS(low); textures are the three slots from 0x98 that ForEachTexture visits
#pragma once

#include <cstdint>
#include "BSShaderProperty.h"

class BSSkyShaderProperty : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();  // compared: 0x1553540
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x1553930
    virtual std::int32_t ForEachTexture(ForEachVisitor& a_visitor) override;  // compared: 0x1553750

    std::uint8_t     unknown88[0x10];  // 88
    NiSourceTexture* textures[3];      // 98
    std::uint8_t     unkB0[0x18];      // B0
};
static_assert(sizeof(BSSkyShaderProperty) == 0xC8, "BSSkyShaderProperty size");
