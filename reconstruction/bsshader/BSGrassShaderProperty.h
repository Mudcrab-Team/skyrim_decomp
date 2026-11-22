// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x151db90 compared function
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSGrassShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSLightingShaderProperty: STANDIN EXE_RTTI
// BSGrassShaderProperty::IsEqual: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSGrassShaderProperty::GetRenderPasses_ShadowMapOrMask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown88, unk180, unk184, Function151de70, Function151de80: GUESS(low); purposes unrecovered, names invented for the measured offset
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSShaderProperty.h"

class BSLightingShaderProperty : public BSShaderProperty
{
public:
};

class BSGrassShaderProperty : public BSLightingShaderProperty
{
public:
    virtual std::uint32_t QShader() const;
    virtual bool IsEqual(NiObject* a_object);  // compared: 0x151d6d0
    virtual void GetRenderPasses_ShadowMapOrMask();
    std::uint32_t Function151de70() const;
    void Function151de80(std::uint32_t a_value);

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown88[0xF8];  // 88
    std::uint32_t unk180;  // 180
    std::uint8_t unk184[0x4C];  // 184
};
static_assert(sizeof(BSGrassShaderProperty) == 0x1D0, "BSGrassShaderProperty size");
