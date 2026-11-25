// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x2b6f90 ReconstructedTESLandTexture::TESLandTexture::Function2b6f90
// 0x2b72e0 ReconstructedTESLandTexture::TESLandTexture::Function2b72e0
// 0x2b7300 ReconstructedTESLandTexture::TESLandTexture::Function2b7300
// 0x2b7260 ReconstructedTESLandTexture::TESLandTexture::Function2b7260
#include "TESLandTexture_2b6f90.h"



namespace ReconstructedTESLandTexture {

// Return the land texture grass list.
LandGrassList* TESLandTexture::Function2b6f90()
{
    return &grasses;
}

// Read the unsigned specular exponent.
std::uint8_t TESLandTexture::Function2b72e0() const
{
    return specularExponent;
}

// Test whether a shader texture index is present.
bool TESLandTexture::Function2b7300() const
{
    return shaderTextureIndex != 0;
}

// Read the material ID, using zero when there is no material.
std::uint32_t TESLandTexture::Function2b7260() const
{
    return materialType ? materialType->materialID : 0;
}

}
