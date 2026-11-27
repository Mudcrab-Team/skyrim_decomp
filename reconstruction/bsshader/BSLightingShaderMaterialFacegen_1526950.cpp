// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSLightingShaderMaterialFacegen::CopyMembers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ba0000_o2.cpp:4100
// 0x1526950 BSLightingShaderMaterialFacegen::CopyMembers
#include "BSLightingShaderMaterialFacegen_1526950.h"

// Copies the base fields, then shares the three face textures with the other material.
void BSLightingShaderMaterialFacegen::CopyMembers(BSShaderMaterial* a_other)
{
    BSLightingShaderMaterialBase::CopyMembers(a_other);
    auto* other = static_cast<BSLightingShaderMaterialFacegen*>(a_other);
    tintTexture = other->tintTexture;
    detailTexture = other->detailTexture;
    subsurfaceTexture = other->subsurfaceTexture;
}
