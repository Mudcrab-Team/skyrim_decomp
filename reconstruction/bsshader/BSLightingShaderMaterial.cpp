// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1524940 BSLightingShaderMaterial::GetFeature
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x4b4a00 BSLightingShaderMaterial::~BSLightingShaderMaterial
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#include "BSLightingShaderMaterial.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared. The destructor itself stays undefined here so that
// the compiler calls the separate complete destructor, as the listing does.
BSLightingShaderMaterial::BSLightingShaderMaterial()
{
}

BSShaderMaterial::Feature BSLightingShaderMaterial::GetFeature() const
{
    return Feature::kDefault;
}
