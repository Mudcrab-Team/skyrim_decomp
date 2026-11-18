// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSGrassShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSLightingShaderProperty: STANDIN EXE_RTTI
// BSGrassShaderProperty::IsEqual: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown88: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../bsengine/BSShaderProperty.h"

class BSLightingShaderProperty : public BSShaderProperty
{
public:
};

class BSGrassShaderProperty : public BSLightingShaderProperty
{
public:
    virtual std::uint32_t QShader() const;
    virtual bool IsEqual(NiObject* a_object);  // compared: 0x151d6d0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown88[0x148];  // 88
};
static_assert(sizeof(BSGrassShaderProperty) == 0x1D0, "BSGrassShaderProperty size");
