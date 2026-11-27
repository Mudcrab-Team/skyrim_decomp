// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x150b5b0 BSImagespaceShader150b5b0::Render
#include "ImageSpaceEffect_150b5b0.h"

void BSImagespaceShader150b5b0::Render(BSTriShape* a_shape, ImageSpaceEffectParam*)
{
    effectTextures.data[1]->Function1555120(1);
    Function1554640(2, effectTextures.data[1], 1);
    Function1554640(3, effectTextures.data[1], 1);
    BSImagespaceShader::Render(a_shape, &shaderParam);
}
