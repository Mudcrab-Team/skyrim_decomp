// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2957a0 BGSLightingTemplate::GetDataAmbientColor
// Adapted bodies: BGSLightingTemplate::GetDataAmbientColor follows fo4-private@1b765c70 src/Shared/TESForms/World/BGSLightingTemplate.cpp:129
#include "BGSLightingTemplate_2957a0.h"

void BGSLightingTemplate::GetDataAmbientColor(NiColor& acolColor)
{
    unsigned int iAmbient = Data.iAmbient;
    acolColor.r = (float)(unsigned __int8)iAmbient * 0.0039215689f;
    acolColor.g = (float)(unsigned __int8)((unsigned __int16)iAmbient >> 8) * 0.0039215689f;
    acolColor.b = (float)(unsigned __int8)(iAmbient >> 16) * 0.0039215689f;
}
