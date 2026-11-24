// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: bodies written from the local listing of the pinned image; names and declarations follow CommonLibSSE-NG.
// 0x1527a90 BSLightingShaderMaterialLODLandscape::Function1527a90
// Function1527a90: GUESS(low); the constructor, bound by hint
// 0x1527fb0 BSLightingShaderMaterialLODLandscape::GetFeature
// 0x1528ff0 BSLightingShaderMaterialLODLandscape::~BSLightingShaderMaterialLODLandscape
// 0x1527e60 BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial
#include "BSLightingShaderMaterialLODLandscape.h"

// BaseReceiveValues: GUESS(low); the base function as the image calls it, with two pointer arguments
// after the five booleans
void BaseReceiveValues(BSLightingShaderMaterialBase* a_this, bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unk6, void* a_unk7);  // 0x1523f00

// RVA 0x1527fb0, 6 bytes, BSLightingShaderMaterialLODLandscape::GetFeature.
BSShaderMaterial::Feature BSLightingShaderMaterialLODLandscape::GetFeature() const
{
    return static_cast<Feature>(0x12);
}

// Also emits the vftable, and with it the deleting destructor; the complete destructor stays undefined.
BSLightingShaderMaterialLODLandscape::BSLightingShaderMaterialLODLandscape() :
    unkA0(0),
    unkA8(0),
    unkB0(0),
    unkB8(0),
    unkC0(0)
{
}

// RVA 0x1527e60, 163 bytes. The image forwards its arguments to the base and then fills the three
// texture pointers that are still null with the default texture.
void BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unknown6, void* a_unknown7)
{
    BaseReceiveValues(this, a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_unknown6, a_unknown7);
    if (!textureB0) {
        textureB0 = g_defaultTexture;
    }
    if (!textureA8) {
        textureA8 = g_defaultTexture;
    }
    if (!textureA0) {
        textureA0 = g_defaultTexture;
    }
}
