// Source exposure: mixed (local target analysis and permitted sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESLandTexture::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted initialization.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESLandTexture.cpp:27
// TESLandTexture and members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// 0x2b68d0 TESLandTexture::InitializeData
#include "TESLandTexture.h"
void TESLandTexture::InitializeData() {
    friction = 30;
    restitution = 30;
    specularExponent = 30;
    textureSet = nullptr;
    materialType = nullptr;
    shaderTextureIndex = 0;
}
