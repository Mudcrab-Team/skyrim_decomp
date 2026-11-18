// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1533bd0 BSParticleShaderProperty::GetBaseTexture
// 0x1532ca0 BSParticleShaderProperty::SetupGeometry
#include "BSParticleShaderProperty.h"

NiSourceTexture* BSParticleShaderProperty::GetBaseTexture()
{
    return particleShaderTexture;
}

bool BSParticleShaderProperty::SetupGeometry(BSGeometry* a_geometry)
{
    particleShaderGeometry = a_geometry;
    return true;
}

// Accepted leaf retained from the integrated version.
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSParticleShaderProperty::QShader() const
{
    return 0x5;
}
