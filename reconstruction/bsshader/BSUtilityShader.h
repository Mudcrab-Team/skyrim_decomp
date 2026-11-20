// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSUtilityShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShader: STANDIN EXE_RTTI
// BSUtilityShader::RestoreMaterial: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// RestoreMaterial name source: powerof3/CommonLibSSE@654e55f, GPL-3.0. Only the declared name is taken; the body is written here.
// BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10, unknown28, unknown58, unknown90, ShaderPartnerManager, Function15666e0, Function1562800, g_shaderPartnerManager: GUESS(low); purposes unrecovered, names invented for the measured offsets and callee
#pragma once

#include <cstdint>
#include <cstddef>
#include "gamebryo/nimain/NiRefObject.h"

class BSShaderMaterial;

// ShaderPartnerManager: GUESS(low); the image calls the function at 0x1562800 with the global pointer as this
class ShaderPartnerManager
{
public:
    void Function1562800(void* a_arg, void* a_first, void* a_second);
};
extern ShaderPartnerManager* g_shaderPartnerManager;

class BSShader : public NiRefObject
{
public:
    std::uint8_t unknown10[0x18];  // 10
    std::uint8_t unknown28[0x30];  // 28
    std::uint8_t unknown58[0x38];  // 58
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");

class BSUtilityShader : public BSShader
{
public:
    virtual void RestoreMaterial(const BSShaderMaterial* a_material);  // compared: 0x15673e0
    bool Function15666e0(void* a_arg);

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown90[0x8];  // 90
};
static_assert(sizeof(BSUtilityShader) == 0x98, "BSUtilityShader size");
