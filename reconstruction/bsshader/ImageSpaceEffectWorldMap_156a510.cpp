// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x156a510 ImageSpaceEffectWorldMap::UpdateParams
#include "ImageSpaceEffectWorldMap_156a510.h"

bool ImageSpaceEffectWorldMap::UpdateParams(ImageSpaceEffectParam* /*a_param*/)
{
    ImageSpaceEffectTexture* tex2 = effectTextures.data[2];
    tex2->Function1554f90(g_renderTargetTable.Function1015790());
    effectTextures.data[1]->Function1555120(1);

    float x = g_worldMapState->unk160;
    float y = g_worldMapState->unk164;
    ImageSpaceShaderParam* param = static_cast<ImageSpaceShaderParam*>(effectParams.data[0]);
    param->Function152b170(0, g_const0, x, y - x, y * x);
    param->Function152b170(1, g_worldMapVec[0], g_worldMapVec[1], g_worldMapVec[2], g_worldMapVec[3]);

    std::int32_t texIndex = effectTextures.data[0]->Function15550b0();
    const RenderTargetEntry& entry = g_renderTargetTable.entries[texIndex];
    param->Function152b170(2, g_const1 / static_cast<float>(entry.width), g_const1 / static_cast<float>(entry.height), 0.0f, 0.0f);
    return true;
}
