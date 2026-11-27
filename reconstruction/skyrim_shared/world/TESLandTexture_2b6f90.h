// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Code origin: declarations retained from the labelled existing local unit; new members inferred from the local listing.
// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESLandTexture::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted initialization.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESLandTexture.cpp:27
// TESLandTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>

namespace ReconstructedTESLandTexture {

#include "../forms/TESForm_2b68d0.h"
#include <cstdint>
class BGSTextureSet;
class TESGrass;
// BGSMaterialType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSMaterialType { public: std::uint8_t unknown00[0x30]; std::uint32_t materialID; };
// LandGrassList: GUESS(low); partial representation of the existing grass-list node.
struct LandGrassList { TESGrass* item; LandGrassList* next; };

class TESLandTexture : public TESForm {
public:
    std::uint32_t Function2b7260() const;

public:
    bool Function2b7300() const;

public:
    std::uint8_t Function2b72e0() const;

public:
    LandGrassList* Function2b6f90();

public:
    void InitializeData() override;
    BGSTextureSet* textureSet;
    std::uint8_t friction;
    std::uint8_t restitution;
    BGSMaterialType* materialType;
    std::uint8_t specularExponent;
    std::int32_t shaderTextureIndex;
    LandGrassList grasses;
};


}
