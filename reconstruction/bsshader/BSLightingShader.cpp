// Source exposure: community-headers (declarations); compared bodies written from the local listing.
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG and powerof3 CommonLibSSE.
// 0x15896a0 BSLightingShader::GetVertexTechnique
// 0x154af70 BSLightingShader::Function154af70
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
