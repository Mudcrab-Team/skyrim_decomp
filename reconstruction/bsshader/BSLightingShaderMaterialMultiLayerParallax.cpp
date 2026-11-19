// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1528330 BSLightingShaderMaterialMultiLayerParallax::Create
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1529070 BSLightingShaderMaterialMultiLayerParallax::~BSLightingShaderMaterialMultiLayerParallax
// 0x1528820 BSLightingShaderMaterialMultiLayerParallax::GetTextures
// 0x1528770 BSLightingShaderMaterialMultiLayerParallax::ReceiveValuesFromRootMaterial
#include <cstring>

#include "BSLightingShaderMaterialMultiLayerParallax.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
#include <new>

BSLightingShaderMaterialMultiLayerParallax::BSLightingShaderMaterialMultiLayerParallax() :
	m_texA0(nullptr),
	m_texA8(nullptr),
	m_texB0(nullptr),
	m_flagB8(0),
	m_fBC(1.0f),
	m_fC0(1.0f),
	m_fC4(1.0f),
	m_fC8(1.0f)
{
}

BSLightingShaderMaterialMultiLayerParallax* BSLightingShaderMaterialMultiLayerParallax::Ctor()
{
	return ::new (this) BSLightingShaderMaterialMultiLayerParallax;
}

void* BSLightingShaderMaterialMultiLayerParallax::operator new(std::size_t a_size) throw()
{
	if (g_memoryManagerGuard != 2) {
		InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
	}
	return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
}

BSShaderMaterial* BSLightingShaderMaterialMultiLayerParallax::Create()
{
	return new BSLightingShaderMaterialMultiLayerParallax;
}



// RVA 0x1528770, 163 bytes.
void BSLightingShaderMaterialMultiLayerParallax::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_extra7, void* a_extra8)
{
	BaseReceiveValues(this, a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_extra7, a_extra8);
	if (m_texA0 == nullptr) {
		NiSourceTexture* defaultTexture = g_defaultTexture._ptr;
		if (defaultTexture) {
			defaultTexture->IncRefCount();
			m_texA0 = defaultTexture;
		}
	}
	if (m_texA8 == nullptr) {
		NiSourceTexture* defaultMulti = g_defaultMultiLayerTexture._ptr;
		if (defaultMulti) {
			defaultMulti->IncRefCount();
			m_texA8 = defaultMulti;
		}
	}
	if (m_texB0 == nullptr) {
		NiSourceTexture* defaultTexture = g_defaultTexture._ptr;
		if (defaultTexture) {
			defaultTexture->IncRefCount();
			m_texB0 = defaultTexture;
		}
	}
}




// Retained generated leaf; its byte-match evidence is renewed with this unit.
// GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
BSShaderMaterial::Feature BSLightingShaderMaterialMultiLayerParallax::GetFeature() const
{
    return static_cast<Feature>(0xb);
}

std::uint32_t BSLightingShaderMaterialMultiLayerParallax::GetTextures(NiSourceTexture** a_textures)
{
	std::uint32_t count = 0;
	if (diffuseTexture) {
		a_textures[count++] = diffuseTexture._ptr;
	}
	if (normalTexture) {
		a_textures[count++] = normalTexture._ptr;
	}
	if (rimSoftLightingTexture) {
		a_textures[count++] = rimSoftLightingTexture._ptr;
	}
	if (specularBackLightingTexture) {
		a_textures[count++] = specularBackLightingTexture._ptr;
	}
	if (m_texA0) {
		a_textures[count++] = m_texA0;
	}
	if (m_texA8) {
		a_textures[count++] = m_texA8;
	}
	if (m_texB0) {
		a_textures[count++] = m_texB0;
	}
	return count;
}
