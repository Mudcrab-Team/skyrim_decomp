// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1551820 ImageSpaceEffectDepthOfField::BorrowTextures
#include "ImageSpaceEffectDepthOfField_1551820.h"

void ImageSpaceEffectDepthOfField::BorrowTextures()
{
    texC8.Function1554f40(g_global333d40a0->flag210 ? 25 : 26);
    textures.SetAt(2, &texC8);

    texE8.Function1554f40(g_global333d40a0->flag210 ? 23 : 22);
    textures.SetAt(3, &texE8);

    if (flags98[4]) {
        texA8.Function1554f40(12);
        textures.SetAt(6, &texA8);
    } else {
        textures.SetAt(6, nullptr);
    }

    tex108.Function1554f90(g_renderTargetTable.Function1015790());
    textures.SetAt(4, &tex108);

    std::int32_t offset = Function153c8f0() + 0x31;
    tex128.Function1554f40(offset);
    textures.SetAt(5, &tex128);
}
