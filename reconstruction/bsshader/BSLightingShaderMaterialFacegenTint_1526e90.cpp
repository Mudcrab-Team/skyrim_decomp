// Source exposure: mixed (pinned image and published community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderMaterial, BSLightingShaderMaterialBase, BSLightingShaderMaterial, BSLightingShaderMaterialSnow, BSLightingShaderMaterialHairTint, BSLightingShaderMaterialFacegenTint, Create, CopyMembers, DoIsCopy, ComputeCRC32, GetDefault, GetFeature, GetType, OnLoadTextureSet, ClearTextures, ReceiveValuesFromRootMaterial, GetTextures, SaveBinary, LoadBinary, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderMemoryManager, shaderMemoryManager, Initialize, Allocate, state, TintColor, tint, snow, defaults, fields: GUESS(low) STANDIN
// Creator entry, allocation size, base-constructor call and complete initialization: OBSERVED
// Code origin: original creators and heap wrapper; declarations and constructor shapes adapted from existing reconstruction/bsshader material units. Adapted bodies: constructor initialization only.
// CI hash: 0x1526e90 ?Create@BSLightingShaderMaterialFacegenTint@@UEAAPEAVBSShaderMaterial@@XZ
// 0x1526e90 BSLightingShaderMaterialFacegenTint::Create
// CI hash: 0x1526f70 ?ComputeCRC32@BSLightingShaderMaterialFacegenTint@@UEAAII@Z
// 0x1526f70 BSLightingShaderMaterialFacegenTint::ComputeCRC32
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
#include "BSLightingShaderMaterialFacegenTint_1526e90.h"

BSLightingShaderMaterialFacegenTint::BSLightingShaderMaterialFacegenTint() : tint{} {}

BSShaderMaterial* BSLightingShaderMaterialFacegenTint::Create()
{
    return new BSLightingShaderMaterialFacegenTint();
}

// The observed checksum input contains an unwritten word after the three color channels.
// Preserve that shipped behavior; the word's original purpose is unknown.
std::uint32_t BSLightingShaderMaterialFacegenTint::ComputeCRC32(unsigned int seed)
{
    struct ChecksumFields
    {
        NiColor color;
        std::uint32_t unrecovered0C;
        std::uint32_t baseCRC;
    } fields;
    fields.color = tint;
    fields.baseCRC = BSLightingShaderMaterialBase::ComputeCRC32(seed);
    std::uint32_t result;
    CRC32Bytes_ce2510(&result, &fields, sizeof(fields));
    return result;
}
