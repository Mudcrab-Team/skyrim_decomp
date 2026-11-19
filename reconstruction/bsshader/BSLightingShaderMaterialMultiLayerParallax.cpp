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
// 0x15284c0 BSLightingShaderMaterialMultiLayerParallax::ComputeCRC32
// 0x15288d0 BSLightingShaderMaterialMultiLayerParallax::SaveBinary
// 0x1528a00 BSLightingShaderMaterialMultiLayerParallax::LoadBinary
// Code origin: bodies written from local listings of the pinned image; names and declarations follow CommonLibSSE-NG; the reference-count release spelling follows cookbook rule 29.
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

// MultiLayerParallaxCrcRecord: GUESS(low); the 0x24-byte record hashed by ComputeCRC32
struct MultiLayerParallaxCrcRecord
{
	std::uint32_t ids[3];    // 00
	float         fB8;       // 0C
	float         fBC;       // 10
	float         fC0;       // 14
	float         fC4;       // 18
	float         fC8;       // 1C
	std::uint32_t flagHash;  // 20
};
static_assert(sizeof(MultiLayerParallaxCrcRecord) == 0x24, "MultiLayerParallaxCrcRecord size");

std::uint32_t BSLightingShaderMaterialMultiLayerParallax::ComputeCRC32(std::uint32_t a_seed)
{
	MultiLayerParallaxCrcRecord record;
	if (textureSet._ptr) {
		CRCTermFromValue(&record.ids[0], reinterpret_cast<BSTextureSetSlots*>(textureSet._ptr)->GetCRCSource(3), 0);
		CRCTermFromValue(&record.ids[1], reinterpret_cast<BSTextureSetSlots*>(textureSet._ptr)->GetCRCSource(4), 0);
		CRCTermFromValue(&record.ids[2], reinterpret_cast<BSTextureSetSlots*>(textureSet._ptr)->GetCRCSource(5), 0);
	}
	else {
		record.ids[0] = 0;
		record.ids[1] = 0;
		record.ids[2] = 0;
	}
	record.fB8 = reinterpret_cast<const float&>(m_flagB8);
	record.fBC = m_fBC;
	record.fC0 = m_fC0;
	record.fC4 = m_fC4;
	record.fC8 = m_fC8;
	record.flagHash = ComputeCRCBase(this, a_seed);
	std::uint32_t out[2];
	CRC32Calculator_SizeOfSize(out, &record, sizeof(record));
	return out[0];
}

void BSLightingShaderMaterialMultiLayerParallax::SaveBinary(NiStream& a_stream)
{
	BSLightingShaderMaterialBase::SaveBinary(a_stream);
	a_stream.oStr->write(&m_flagB8, 1);
	a_stream.oStr->write(&m_fBC, 1);
	a_stream.oStr->write(&m_fC0, 1);
	a_stream.oStr->write(&m_fC4, 1);
	a_stream.oStr->write(&m_fC8, 1);
}

// StreamVersion: GUESS(low); the stream word at +0x08 that LoadBinary compares with 0x4A
static std::uint32_t StreamVersion(const NiStream& a_stream)
{
	return *reinterpret_cast<const std::uint32_t*>(a_stream.unk08);
}

void BSLightingShaderMaterialMultiLayerParallax::LoadBinary(NiStream& a_stream)
{
	BSLightingShaderMaterialBase::LoadBinary(a_stream);
	a_stream.iStr->read(&m_flagB8, 1);
	a_stream.iStr->read(&m_fBC, 1);
	a_stream.iStr->read(&m_fC0, 1);
	a_stream.iStr->read(&m_fC4, 1);
	if (StreamVersion(a_stream) > 0x4A) {
		a_stream.iStr->read(&m_fC8, 1);
	}
	else {
		m_fC8 = 0.0f;
	}
}
