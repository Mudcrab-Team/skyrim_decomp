// Source exposure: mixed (pinned image and published community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original equality reconstruction from local observations; community interface declarations. Adapted bodies: none.
// BSLightingShaderMaterialBase, BSShaderMaterial, DoIsCopy, GetFeature, GetTexturePath, kDiffuse, textureSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// first, second: GUESS(low); observed texture-set member and diffuse path comparison.
// CI hash: 0x1523970 ?DoIsCopy@BSLightingShaderMaterialBase@@UEAA_NPEAVBSShaderMaterial@@@Z
// 0x1523970 BSLightingShaderMaterialBase::DoIsCopy
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
#include "BSLightingShaderMaterialBase_1528000.h"


// Compare base state, material feature and diffuse texture paths.
bool BSLightingShaderMaterialBase::DoIsCopy(BSShaderMaterial* other)
{
    if (!BSShaderMaterial::DoIsCopy(other)) return false;
    const auto feature = other->GetFeature();
    if (GetFeature() != feature) return false;
    auto* material = static_cast<BSLightingShaderMaterialBase*>(other);
    const char* first = textureSet.texture ? textureSet.texture->GetTexturePath(BSTextureSet::kDiffuse) : nullptr;
    const char* second = material->textureSet.texture ? material->textureSet.texture->GetTexturePath(BSTextureSet::kDiffuse) : nullptr;
    if (first != second) {
        if (!first || !second || _stricmp(first, second) != 0) return false;
    }
    return true;
}
