// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1565920 ImageSpaceEffectRefraction::Render
#include "ImageSpaceEffectRefraction_1565920.h"

void ImageSpaceEffectRefraction::Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param)
{
    if (unk09) {
        unk09 = UpdateParams(a_param);
    }

    BSImagespaceShader* shader = static_cast<BSImagespaceShader*>(effects.data[0]);
    ImageSpaceEffectParam* param = effectParams.data[0];
    shader->Function1554640(0, effectTextures.data[0], 0);
    shader->Function1554640(1, effectTextures.data[1], 1);
    shader->Function1554640(2, &unk90, 0);
    shader->Render(a_shape, param);
    shader->Function1554640(0, nullptr, 0);
    shader->Function1554640(1, nullptr, 0);
    shader->Function1554640(2, nullptr, 0);
    g_refractionFlag0 = false;
    g_refractionFlag1 = false;
}
