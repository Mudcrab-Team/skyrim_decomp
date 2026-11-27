// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1585740 ImageSpaceEffectNoise::Render
#include "ImageSpaceEffectNoise_1585740.h"

void ImageSpaceEffectNoise::Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param)
{
    if (unk09) {
        unk09 = VFunc07(a_param);
    }

    ImageSpaceEffect* eff0 = effects[0];
    ImageSpaceEffectParam* param0 = effectParams[0];
    param0->Function152b170(0, g_noise_130, g_noise_134, 0.0f, 0.0f);
    param0->Function152b170(1, g_noise_140, g_noise_144, 0.0f, 0.0f);
    param0->Function152b170(2, g_noise_150, g_noise_154, 0.0f, 0.0f);
    param0->Function152b170(3, g_noise_120, 0.0f, 0.0f, 0.0f);
    param0->Function152b170(4, g_noise_160, g_noise_164, g_noise_168, 0.0f);
    param0->Function152b170(5, g_noise_170, g_noise_174, g_noise_178, 0.0f);

    eff0->Function1554640(0, &texB0, 0);
    eff0->Function1554640(1, textures[1], 1);
    textures[0]->Function1555130(3);
    textures[1]->Function1555130(3);
    eff0->Render(a_shape, param0);

    ImageSpaceEffect* eff1 = effects[1];
    ImageSpaceEffectParam* param1 = effectParams[1];
    param1->Function152b170(0, g_noise_130, g_noise_134, 0.0f, 0.0f);
    param1->Function152b170(1, g_noise_140, g_noise_144, 0.0f, 0.0f);
    param1->Function152b170(2, g_noise_150, g_noise_154, 0.0f, 0.0f);
    param1->Function152b170(3, g_noise_120, 0.0f, 0.0f, 0.0f);

    eff1->Function1554640(0, textures[0], 0);
    eff1->Function1554640(1, &texB0, 0);
    textures[0]->Function1555130(3);
    textures[1]->Function1555130(3);
    eff1->Render(a_shape, param1);
}
