// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialLODLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLODLandscape::GetFeature: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the image passes two pointer arguments after the five booleans that NG declares
// a_unknown6, a_unknown7, unkA0, unkA8, unkB0, textureA0, textureA8, textureB0, unkB8, unkC0, unknownC4: GUESS(low); types and meanings not evidenced (the body forwards the pointers and reads only A0, A8 and B0)
// Code origin: bodies written from the local listing of the pinned image; names and declarations follow CommonLibSSE-NG.
#pragma once

#include <cstdint>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialLODLandscape();
    virtual ~BSLightingShaderMaterialLODLandscape();  // compared: 0x1528ff0 (scalar deleting destructor)
    virtual Feature GetFeature() const;  // compared: 0x1527fb0
    // compared: 0x1527e60; the image passes two pointer-sized arguments after the five booleans, as the
    // base call in this body shows
    virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unknown6, void* a_unknown7);

    // The matched constructor initialises the storage as integers; ReceiveValuesFromRootMaterial uses
    // the same slots as texture pointers.
    union { std::uint64_t unkA0; NiPointer<NiSourceTexture> textureA0; };  // A0
    union { std::uint64_t unkA8; NiPointer<NiSourceTexture> textureA8; };  // A8
    union { std::uint64_t unkB0; NiPointer<NiSourceTexture> textureB0; };  // B0
    std::uint64_t unkB8;               // B8
    std::uint32_t unkC0;               // C0
    std::uint32_t unknownC4;           // C4
};
static_assert(sizeof(BSLightingShaderMaterialLODLandscape) == 0xC8, "BSLightingShaderMaterialLODLandscape size");
