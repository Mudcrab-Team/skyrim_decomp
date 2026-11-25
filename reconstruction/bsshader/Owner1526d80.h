// Source exposure: mixed (class and member names from community headers; sizes, offsets and the
// compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: declarations follow CommonLibSSE-NG names; offsets, sizes and the compared bodies are read from the local listings. Stamped as a twin of matched 0x1528820 (bsshader/BSLightingShaderMaterialMultiLayerParallax): source copied, names replaced by placeholders.
// Owner1526d80: GUESS(low) STANDIN
// GetFeature, Ctor, GetTextures, ReceiveValuesFromRootMaterial, ComputeCRC32, m_texA0, m_texA8, m_texB0, m_flagB8, m_fBC, m_fC0, m_fC4, m_fC8, unkCC: GUESS(low) STANDIN
#pragma once
#include "BSLightingShaderMaterialMultiLayerParallax.h"
#include <cstring>
#include <new>

class Owner1526d80 : public BSLightingShaderMaterialBase
{
public:
    Feature GetFeature() const override;
	Owner1526d80();
	static void* operator new(std::size_t a_size) throw();
	static void* operator new(std::size_t, void* a_place) throw() { return a_place; }
	BSShaderMaterial* Create() override;
	// the deleting destructor (slot 0) is emitted with the constructor; the plain one is external
	virtual ~Owner1526d80();
	Owner1526d80* Ctor();
	virtual std::uint32_t GetTextures(NiSourceTexture** a_textures);
	virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_extra7, void* a_extra8);
	virtual std::uint32_t ComputeCRC32(std::uint32_t a_seed);
	virtual void SaveBinary(NiStream& a_stream);
	virtual void LoadBinary(NiStream& a_stream);

	NiSourceTexture* m_texA0;  // 0xA0
	NiSourceTexture* m_texA8;  // 0xA8
	NiSourceTexture* m_texB0;  // 0xB0
	std::uint32_t m_flagB8;  // 0xB8
	float m_fBC;  // 0xBC
	float m_fC0;  // 0xC0
	float m_fC4;  // 0xC4
	float m_fC8;  // 0xC8
	std::uint8_t unkCC[0x4];  // 0xCC
};
static_assert(sizeof(Owner1526d80) == 0xD0, "Owner1526d80 size");
