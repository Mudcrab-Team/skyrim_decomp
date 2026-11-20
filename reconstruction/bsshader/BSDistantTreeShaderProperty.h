// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSDistantTreeShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSDistantTreeShaderProperty::GetBaseTexture: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSDistantTreeShaderProperty::SetupGeometry: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) OBSERVED; the shared base declares a void slot without arguments, so this unit declares its own bool form taking the geometry
// BSGeometry: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declaration only
// unknown88, Function1558dc0: GUESS(low); purposes unrecovered, names invented for the measured offsets
#pragma once

#include <cstdint>
#include "BSShaderProperty.h"

class BSGeometry;

class BSDistantTreeShaderProperty : public BSShaderProperty
{
public:
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x1558eb0
    virtual bool SetupGeometry(BSGeometry* a_geometry);  // compared: 0x1558cb0
    void Function1558dc0();

    std::uint8_t unknown88[0x8];  // 88
    // baseTexture: GUESS(low)
    NiSourceTexture* baseTexture;  // 90
    std::uint8_t unknown98[0x18];  // 98
};
static_assert(sizeof(BSDistantTreeShaderProperty) == 0xB0, "BSDistantTreeShaderProperty size");
