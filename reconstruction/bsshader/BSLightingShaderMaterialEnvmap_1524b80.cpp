// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x1524b80 BSLightingShaderMaterialEnvmap::Create
#include "BSLightingShaderMaterialEnvmap_1524b80.h"

// constructor: inlined into Create here; its own body is compared in BSLightingShaderMaterialEnvmap.cpp
BSLightingShaderMaterialEnvmap::BSLightingShaderMaterialEnvmap() :
	envMapScale(1.0f)
{
}

BSShaderMaterial* BSLightingShaderMaterialEnvmap::Create()
{
	return new BSLightingShaderMaterialEnvmap;
}
