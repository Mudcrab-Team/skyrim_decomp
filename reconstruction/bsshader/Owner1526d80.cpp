// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG. Stamped as a twin of matched 0x1528820 (bsshader/BSLightingShaderMaterialMultiLayerParallax): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: bodies written from local listings of the pinned image; names and declarations follow CommonLibSSE-NG; the reference-count release spelling follows cookbook rule 29.
// 0x1526d80 Owner1526d80::GetTextures
#include "Owner1526d80.h"
#include <cstring>
#include <new>

Owner1526d80::Owner1526d80() :
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

// guess: same compiled code as matched 0x1528820 apart from relocated fields; its role here is not established.
std::uint32_t Owner1526d80::GetTextures(NiSourceTexture** a_textures)
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
