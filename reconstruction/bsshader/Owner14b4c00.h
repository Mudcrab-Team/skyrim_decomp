// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x1553930 (bsshader/BSSkyShaderProperty): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner14b4c00: GUESS(low) STANDIN
// unknown88, textures, unkB0: GUESS(low) STANDIN
#pragma once
#include "BSSkyShaderProperty.h"

class Owner14b4c00 : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();
    virtual NiSourceTexture* GetBaseTexture();
    virtual std::int32_t ForEachTexture(ForEachVisitor& a_visitor) override;

    std::uint8_t     unknown88[0x10];  // 88
    NiSourceTexture* textures[3];      // 98
    std::uint8_t     unkB0[0x18];      // B0
};
static_assert(sizeof(Owner14b4c00) == 0xC8, "Owner14b4c00 size");
