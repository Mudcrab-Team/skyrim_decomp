// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESLandTexture::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted initialization.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESLandTexture.cpp:27
// TESLandTexture and members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/forms/TESForm_2b68d0.h"
#include <cstdint>
class BGSTextureSet;
class BGSMaterialType;
class TESLandTexture : public TESForm {
public:
    void InitializeData() override;
    BGSTextureSet* textureSet;
    std::uint8_t friction;
    std::uint8_t restitution;
    BGSMaterialType* materialType;
    std::int8_t specularExponent;
    std::int32_t shaderTextureIndex;
};
