// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BSLightingShaderMaterialMultiLayerParallax, BSLightingShaderMaterialBase, BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiPointer, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiSourceTexture;

// NiPointer: _ptr keeps NG's default member initializer, so a default-constructed pointer is
// set by its own constructor rather than value-initialised
template <class T>
class NiPointer
{
public:
	T* _ptr{ nullptr };  // 00
};

// sizeof BSShaderMaterial 0x38, sizeof BSLightingShaderMaterialBase 0xA0: OBSERVED; members not used here are padding
class BSShaderMaterial
{
public:
	virtual ~BSShaderMaterial();  // 00

	std::uint8_t unk08[0x30];  // 08
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "layout");

class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
	BSLightingShaderMaterialBase();
	~BSLightingShaderMaterialBase() override;

	std::uint8_t unk38[0x68];  // 38
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "layout");

// layerTexture, envTexture, envMaskTexture, parallaxLayerThickness, parallaxRefractionScale, parallaxInnerLayerUScale, parallaxInnerLayerVScale, envmapScale, padCC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's members at the same offsets
class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
{
public:
	BSLightingShaderMaterialMultiLayerParallax();
	~BSLightingShaderMaterialMultiLayerParallax() override;

	NiPointer<NiSourceTexture> layerTexture;              // A0
	NiPointer<NiSourceTexture> envTexture;                // A8
	NiPointer<NiSourceTexture> envMaskTexture;            // B0
	float                      parallaxLayerThickness;    // B8
	float                      parallaxRefractionScale;   // BC
	float                      parallaxInnerLayerUScale;  // C0
	float                      parallaxInnerLayerVScale;  // C4
	float                      envmapScale;               // C8
	std::uint32_t              padCC;                     // CC
};
static_assert(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0, "layout");
