// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and layout labels as marked below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// 0x5117b0 BGSTerrainBlock::SetTerrainBlockHidden
// 0x5117e0 BGSTerrainBlock::ClearTerrainBlockHidden
// 0x511520 BGSTerrainBlock::GetChunkMaterialTexture
#include "BGSTerrainBlock.h"

// Mark both scene nodes of the block hidden.
void BGSTerrainBlock::SetTerrainBlockHidden()
{
    if (unknown08 != nullptr) {
        unknown08->flags |= TerrainBlockNode::kHidden;
    }
    if (unknown10 != nullptr) {
        unknown10->flags |= TerrainBlockNode::kHidden;
    }
}

// Clear the hidden mark on both scene nodes of the block.
void BGSTerrainBlock::ClearTerrainBlockHidden()
{
    if (unknown08 != nullptr) {
        unknown08->flags &= ~TerrainBlockNode::kHidden;
    }
    if (unknown10 != nullptr) {
        unknown10->flags &= ~TerrainBlockNode::kHidden;
    }
}

// Return the diffuse or the normal texture of the lighting material of the block's scene node.
NiSourceTexture* BGSTerrainBlock::GetChunkMaterialTexture(std::int32_t a_useNormal)
{
    TerrainBlockNode* pNode = unknown08;
    if (pNode == nullptr) {
        return nullptr;
    }
    BSLightingShaderProperty* pProperty = pNode->unknown128;
    if (pProperty == nullptr) {
        return nullptr;
    }
    if (pProperty->GetRTTI() != &NiRTTI_BSLightingShaderProperty) {
        return nullptr;
    }
    BSLightingShaderMaterialBase* pMaterial = pProperty->material;
    if (a_useNormal == 0) {
        return pMaterial->diffuseTexture;
    }
    return pMaterial->normalTexture;
}
