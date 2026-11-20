// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1575700 BSShaderMaterial::CopyMembers
// Adapted bodies: none
#include "BSShaderMaterial.h"

void BSShaderMaterial::CopyMembers(BSShaderMaterial* a_other)
{
    texCoordOffset[0] = a_other->texCoordOffset[0];
    texCoordOffset[1] = a_other->texCoordOffset[1];
    texCoordScale[0] = a_other->texCoordScale[0];
    texCoordScale[1] = a_other->texCoordScale[1];
}
