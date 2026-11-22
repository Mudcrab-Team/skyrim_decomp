// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned image and labelled declarations.
// Adapted bodies: none.
// 0x15896a0 BSLightingShader::GetVertexTechnique
// 0x154af70 BSLightingShader::Function154af70
// SPDX-License-Identifier: CC0-1.0
// 0x1547660 BSLightingShader::Function1547660
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SetShaderPartnerParameters, firstParameterGroup, secondParameterGroup: GUESS(low)
#include "BSLightingShader.h"

std::uint32_t BSLightingShader::GetVertexTechnique(std::uint32_t a_technique)
{
    std::uint32_t result = a_technique & 0x48007;
    if ((a_technique & 0x20A00) != 0) {
        result |= 0x200;
    }
    return result | (a_technique & 0x3F000000);
}

void BSLightingShader::Function154af70()
{
    ++counterC8;
}

// Register this shader's two parameter groups with the render partner.
bool BSLightingShader::Function1547660(void* a_arg)
{
    SetShaderPartnerParameters(g_shaderPartnerManager, a_arg, firstParameterGroup, secondParameterGroup);
    return true;
}
