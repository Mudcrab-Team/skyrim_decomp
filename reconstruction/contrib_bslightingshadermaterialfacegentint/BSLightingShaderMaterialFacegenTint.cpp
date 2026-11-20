// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1526fd0 BSLightingShaderMaterialFacegenTint::SaveBinary
// 0x1527010 BSLightingShaderMaterialFacegenTint::LoadBinary
// Adapted bodies: none
#include "BSLightingShaderMaterialFacegenTint.h"

void BSLightingShaderMaterialFacegenTint::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    tintColor.SaveBinary2(a_stream);
}

void BSLightingShaderMaterialFacegenTint::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    tintColor.LoadBinary2(a_stream);
}
