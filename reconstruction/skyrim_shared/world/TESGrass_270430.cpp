// Source exposure: mixed (pinned image listings, community declarations and a permitted sibling reconstruction).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: project code based on the listings and the sources named below.
// Adapted bodies: new TESGrass getters and setters use the method notes in CommonLibSSE-NG@b93280e include/RE/T/TESGrass.h (MIT).
// Licence: fo4-private reused with author permission conditional on anonymity.
// TESGrass::SetPositionRange: SIBLING(fo4-private@1b765c70, author-permission)
// TESGrass::SetHeightRange: SIBLING(fo4-private@1b765c70, author-permission)
// TESGrass::SetColorRange: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:64
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:73
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:82
// 0x2709a0 TESGrass::GetPositionRange
// 0x270430 TESGrass::SetPositionRange
// 0x270460 TESGrass::SetHeightRange
// 0x270490 TESGrass::SetColorRange
// 0x2709e0 TESGrass::GetWavePeriod
// 0x2709d0 TESGrass::GetVertexLighting
// 0x270a70 TESGrass::SetVertexLighting
// 0x270a40 TESGrass::SetUniformScaling
// 0x270a00 TESGrass::SetFitToSlope
#include "TESGrass_270430.h"

// CI hash: 0x2709a0 ?GetPositionRange@TESGrass@@UEBAMXZ
float TESGrass::GetPositionRange() const
{
	return data.positionRange;
}

// CI hash: 0x270430 ?SetPositionRange@TESGrass@@UEAA_NM@Z
bool TESGrass::SetPositionRange(float a_positionRange)
{
	if (!(a_positionRange >= 0.0f) || a_positionRange > 512.0f) {
		return false;
	}
	data.positionRange = a_positionRange;
	return true;
}

// CI hash: 0x270460 ?SetHeightRange@TESGrass@@UEAA_NM@Z
bool TESGrass::SetHeightRange(float a_heightRange)
{
	if (!(a_heightRange >= 0.0f) || a_heightRange > 1.0f) {
		return false;
	}
	data.heightRange = a_heightRange;
	return true;
}

// CI hash: 0x270490 ?SetColorRange@TESGrass@@UEAA_NM@Z
bool TESGrass::SetColorRange(float a_colorRange)
{
	if (!(a_colorRange >= 0.0f) || a_colorRange > 1.0f) {
		return false;
	}
	data.colorRange = a_colorRange;
	return true;
}

// CI hash: 0x2709e0 ?GetWavePeriod@TESGrass@@UEBAMXZ
float TESGrass::GetWavePeriod() const
{
	return data.wavePeriod;
}

// CI hash: 0x2709d0 ?GetVertexLighting@TESGrass@@UEBA_NXZ
bool TESGrass::GetVertexLighting() const
{
	return (data.flags & GRASS_DATA::kVertexLighting) != 0;
}

// CI hash: 0x270a70 ?SetVertexLighting@TESGrass@@UEAAX_N@Z
void TESGrass::SetVertexLighting(bool a_set)
{
	if (a_set) {
		data.flags |= GRASS_DATA::kVertexLighting;
	} else {
		data.flags &= ~GRASS_DATA::kVertexLighting;
	}
}

// CI hash: 0x270a40 ?SetUniformScaling@TESGrass@@UEAAX_N@Z
void TESGrass::SetUniformScaling(bool a_set)
{
	if (a_set) {
		data.flags |= GRASS_DATA::kUniformScale;
	} else {
		data.flags &= ~GRASS_DATA::kUniformScale;
	}
}

// CI hash: 0x270a00 ?SetFitToSlope@TESGrass@@UEAAX_N@Z
void TESGrass::SetFitToSlope(bool a_set)
{
	if (a_set) {
		data.flags |= GRASS_DATA::kFitSlope;
	} else {
		data.flags &= ~GRASS_DATA::kFitSlope;
	}
}
