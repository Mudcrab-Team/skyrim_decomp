// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1528ff0 BSLightingShaderMaterialLODLandscape::~BSLightingShaderMaterialLODLandscape
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// 0x1527fb0 BSLightingShaderMaterialLODLandscape::GetFeature
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#include "BSLightingShaderMaterialLODLandscape.h"

// TODO body: RVA 0x1527fb0, 6 bytes, BSLightingShaderMaterialLODLandscape::GetFeature.
BSShaderMaterial::Feature BSLightingShaderMaterialLODLandscape::GetFeature() const
{
    return static_cast<Feature>(0x12);
}

// Defined so that the compiler emits the vftable and the deleting destructor; the complete destructor stays undefined.
BSLightingShaderMaterialLODLandscape::BSLightingShaderMaterialLODLandscape()
{
}
