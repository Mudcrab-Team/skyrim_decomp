// Source exposure: mixed (pinned image and published community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderMaterial, BSLightingShaderMaterialBase, BSLightingShaderMaterial, BSLightingShaderMaterialSnow, BSLightingShaderMaterialHairTint, BSLightingShaderMaterialFacegenTint, Create, CopyMembers, DoIsCopy, ComputeCRC32, GetDefault, GetFeature, GetType, OnLoadTextureSet, ClearTextures, ReceiveValuesFromRootMaterial, GetTextures, SaveBinary, LoadBinary, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderMemoryManager, shaderMemoryManager, Initialize, Allocate, state, TintColor, tint, snow, defaults, fields: GUESS(low) STANDIN
// Creator entry, allocation size, base-constructor call and complete initialization: OBSERVED
// Code origin: original creators and heap wrapper; declarations and constructor shapes adapted from existing reconstruction/bsshader material units. Adapted bodies: constructor initialization only.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include "BSLightingShaderMaterialBase_1528000.h"

class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialHairTint();
    ~BSLightingShaderMaterialHairTint() override;
    BSShaderMaterial* Create() override;
    void CopyMembers(BSShaderMaterial*) override;
    void SaveBinary(NiStream&) override;
    void LoadBinary(NiStream&) override;
    Feature GetFeature() const override;
    unsigned int ComputeCRC32(unsigned int seed) override;
    NiColor tint;
};
static_assert(sizeof(BSLightingShaderMaterialHairTint) == 0xB0, "material allocation size");
