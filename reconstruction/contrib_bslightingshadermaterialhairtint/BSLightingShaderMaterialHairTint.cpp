// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x15271f0 BSLightingShaderMaterialHairTint::SaveBinary
// 0x1527230 BSLightingShaderMaterialHairTint::LoadBinary
// Adapted bodies: none
#include "BSLightingShaderMaterialHairTint.h"

void BSLightingShaderMaterialHairTint::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    tintColor.SaveBinary2(a_stream);
}

void BSLightingShaderMaterialHairTint::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    tintColor.LoadBinary2(a_stream);
}
