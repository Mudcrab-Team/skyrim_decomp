// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x1558eb0 (bsshader/BSDistantTreeShaderProperty): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSGeometry: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declaration only
// Owner12ca6c0: GUESS(low) STANDIN
// unknown88, Function1558dc0, baseTexture: GUESS(low) STANDIN
#pragma once
#include "BSDistantTreeShaderProperty.h"

class Owner12ca6c0 : public BSShaderProperty
{
public:
    virtual NiSourceTexture* GetBaseTexture();
    virtual bool SetupGeometry(BSGeometry* a_geometry);
    void Function1558dc0();

    std::uint8_t unknown88[0x8];  // 88
    NiSourceTexture* baseTexture;  // 90
    std::uint8_t unknown98[0x18];  // 98
};
static_assert(sizeof(Owner12ca6c0) == 0xB0, "Owner12ca6c0 size");
