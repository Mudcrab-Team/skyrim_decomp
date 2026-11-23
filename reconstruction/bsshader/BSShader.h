// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShader::SetupMaterial, BSShader::RestoreMaterial, BSShader::GetTechniqueName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../gamebryo/nimain/NiRefObject.h"

class BSShaderMaterial;

class BSShader : public NiRefObject
{
public:
    virtual void SetupMaterial(const BSShaderMaterial* a_material);  // compared: 0x1578910
    virtual void RestoreMaterial(const BSShaderMaterial* a_material);  // compared: 0x1578920
    virtual void GetTechniqueName(std::uint32_t a_techniqueID, char* a_buffer, std::uint32_t a_bufferSize);  // compared: 0x1578ac0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x80];  // 10
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");
