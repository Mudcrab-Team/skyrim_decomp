// Source exposure: community-headers (declarations); compared bodies written from the local listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSLightingShader, BSLightingShader::GetVertexTechnique: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); signature from the community header
// BSShader, BSShaderMaterial, BSRenderPass: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function154af70, refCountC8, unknown10, unknown90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "gamebryo/nimain/NiRefObject.h"

class BSShaderMaterial;
class BSRenderPass;

class BSShader : public NiRefObject
{
public:
    ~BSShader() override;  // 00
    virtual bool SetupTechnique(std::uint32_t a_technique) = 0;  // 02
    virtual void RestoreTechnique(std::uint32_t a_technique) = 0;  // 03
    virtual void SetupMaterial(const BSShaderMaterial* a_material);  // 04
    virtual void RestoreMaterial(const BSShaderMaterial* a_material);  // 05
    virtual void SetupGeometry(BSRenderPass* a_currentPass, std::uint32_t a_flags) = 0;  // 06
    virtual void RestoreGeometry(BSRenderPass* a_currentPass, std::uint32_t a_renderFlags) = 0;  // 07
    virtual void GetTechniqueName(std::uint32_t a_techniqueID, char* a_buffer, std::uint32_t a_bufferSize);  // 08
    virtual void ReloadShaders(bool a_clear);  // 09
    std::uint8_t unknown10[0x80];  // 10
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");

class BSLightingShader : public BSShader
{
public:
    static std::uint32_t GetVertexTechnique(std::uint32_t a_technique);  // compared: 0x15896a0
    void Function154af70();  // compared: 0x154af70

    std::uint8_t unknown90[0x38];  // 90
    std::uint32_t counterC8;  // C8
    std::uint8_t unknownCC[0x2C];  // CC
};
static_assert(sizeof(BSLightingShader) == 0xF8, "BSLightingShader size");
