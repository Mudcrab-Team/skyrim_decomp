// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSUtilityShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShader: STANDIN EXE_RTTI
// BSUtilityShader::RestoreMaterial: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// RestoreMaterial name source: powerof3/CommonLibSSE@654e55f, GPL-3.0. Only the declared name is taken; the body is written here.
// BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10, unknown90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../netimmerse/NiRefObject.h"

class BSShaderMaterial;

class BSShader : public NiRefObject
{
public:
    std::uint8_t unknown10[0x80];  // 10
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");

class BSUtilityShader : public BSShader
{
public:
    virtual void RestoreMaterial(const BSShaderMaterial* a_material);  // compared: 0x15673e0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown90[0x8];  // 90
};
static_assert(sizeof(BSUtilityShader) == 0x98, "BSUtilityShader size");
