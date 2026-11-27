// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1554740 ImageSpaceEffectOption::vfunc_1
#include "ImageSpaceEffectOption_1554740.h"

void ImageSpaceEffectOption::vfunc_1(void* a_arg1, void* a_arg2)
{
    VFunc04(a_arg2);

    for (std::uint32_t i = 0; i < static_cast<std::uint32_t>(effectCount); ++i) {
        if (!enabledFlags[i]) {
            continue;
        }

        ImageSpaceEffect* eff = effects[i];
        TextureBindingPair* pairArr = bindings[i];
        std::uint32_t baseIdx = baseTexIndices[i];
        std::uint16_t cap = eff->textures.capacity;

        for (std::int32_t j = 1; j < cap; ++j) {
            std::int32_t texIdx = pairArr[j - 1].texIndex;
            if (texIdx >= 0) {
                std::uint32_t arg = pairArr[j - 1].arg;
                ImageSpaceEffectTexture* tex = textures[static_cast<std::uint32_t>(texIdx)];
                eff->textures.SetAt(static_cast<std::uint32_t>(j), tex);
                if (tex) {
                    tex->Function1555120(arg);
                }
            }
        }

        ImageSpaceEffectTexture* baseTex = textures[baseIdx];
        eff->textures.SetAt(0, baseTex);
        if (baseTex) {
            baseTex->Function1555120(0);
        }

        VFunc07(a_arg2);
        void* param = effectParams[i];
        VFunc08(param);
        effects[i]->VFunc01(a_arg1, param);
        VFunc09(param);
    }

    VFunc05();
}
